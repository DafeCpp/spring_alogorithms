#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import re
from enum import Enum
import subprocess
import sys
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Tuple
import tempfile


TASK_NAME_RE = re.compile(r"^task_\d+$")


class CaseStatus(Enum):
    OK = "ok"
    FAIL = "fail"
    TIMEOUT = "timeout"
    NO_EXPECTED = "no_expected"
    EXEC_MISSING = "exec_missing"
    SLOW = "slow"
    ERROR = "error"
    MEM_EXCEEDED = "mem_exceeded"


@dataclass
class CaseResult:
    task: str
    case_name: str
    status: CaseStatus
    duration_ms: int
    message: str = ""
    peak_kb: Optional[int] = None


def find_repo_root(start: Path) -> Path:
    # Assumes this script is located at <root>/scripts/run_cases.py
    scripts_dir = start.parent
    return scripts_dir.parent


def discover_executables(build_dir: Path) -> Dict[str, Path]:
    executables: Dict[str, Path] = {}
    if not build_dir.exists():
        return executables

    for item in build_dir.iterdir():
        if not item.is_dir():
            continue
        name = item.name
        if not TASK_NAME_RE.match(name):
            continue
        exe_candidate = item / name
        if exe_candidate.exists() and exe_candidate.is_file() and os.access(exe_candidate, os.X_OK):
            executables[name] = exe_candidate
    return executables


def discover_tasks_from_tests(tests_dir: Path) -> List[str]:
    tasks: List[str] = []
    if not tests_dir.exists():
        return tasks
    for item in tests_dir.iterdir():
        if item.is_dir() and TASK_NAME_RE.match(item.name):
            tasks.append(item.name)
    return tasks


def discover_tasks_in_repo(repo_root: Path) -> List[str]:
    tasks: List[str] = []
    for item in repo_root.iterdir():
        if item.is_dir() and TASK_NAME_RE.match(item.name):
            tasks.append(item.name)
    return sorted(tasks)


def list_cases_for_task_central(tests_dir: Path, task: str) -> List[Tuple[Path, Path]]:
    """<tests_dir>/<task>/*.in with same-stem .out"""
    task_dir = tests_dir / task
    if not task_dir.exists():
        return []
    pairs: List[Tuple[Path, Path]] = []
    for input_file in sorted(task_dir.glob("*.in")):
        expected_file = input_file.with_suffix(".out")
        pairs.append((input_file, expected_file))
    return pairs


def list_cases_for_task_in_task(repo_root: Path, task: str) -> List[Tuple[Path, Path]]:
    """Search inside task dir: prefer task/tests/*.in, fallback to task/*.in"""
    task_dir = repo_root / task
    if not task_dir.exists():
        return []
    candidates: List[Path] = []
    tests_subdir = task_dir / "tests"
    if tests_subdir.exists():
        candidates.extend(sorted(tests_subdir.glob("*.in")))
    # Also allow inputs directly under the task directory
    candidates.extend(sorted(task_dir.glob("*.in")))
    # Deduplicate while preserving order
    seen: set[Path] = set()
    inputs: List[Path] = []
    for p in candidates:
        if p not in seen:
            seen.add(p)
            inputs.append(p)
    pairs: List[Tuple[Path, Path]] = []
    for input_file in inputs:
        expected_file = input_file.with_suffix(".out")
        pairs.append((input_file, expected_file))
    return pairs


def read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8")


def write_text(path: Path, content: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(content, encoding="utf-8")


def normalize(s: str, mode: str) -> str:
    s = s.replace("\r\n", "\n").replace("\r", "\n")
    if mode == "strip":
        return s.rstrip()
    if mode == "keep":
        return s
    if mode == "lines":
        # Normalize per-line trailing whitespace
        return "\n".join(line.rstrip() for line in s.split("\n")).rstrip()
    return s.rstrip()


def run_executable(exe: Path, stdin_data: str, timeout_sec: float) -> Tuple[int, str, str, float]:
    start = time.perf_counter()
    try:
        completed = subprocess.run(
            [str(exe)],
            input=stdin_data,
            capture_output=True,
            text=True,
            timeout=timeout_sec,
        )
        duration = time.perf_counter() - start
        return completed.returncode, completed.stdout, completed.stderr, duration
    except subprocess.TimeoutExpired as e:
        duration = time.perf_counter() - start
        return 124, e.stdout or "", e.stderr or "", duration


def find_time_tool() -> Optional[str]:
    # Prefer GNU time executable
    for candidate in ["/usr/bin/time", "/bin/time"]:
        if os.path.exists(candidate) and os.access(candidate, os.X_OK):
            return candidate
    return None


def run_executable_with_memory(
    exe: Path, stdin_data: str, timeout_sec: float, time_tool: str
) -> Tuple[int, str, str, float, Optional[int]]:
    # Use GNU time to measure peak RSS in KB via %M
    with tempfile.NamedTemporaryFile(prefix="runner_mem_", delete=False) as tmp:
        mem_file = tmp.name
    try:
        start = time.perf_counter()
        try:
            completed = subprocess.run(
                [time_tool, "-f", "MAXRSS=%M", "-o", mem_file, str(exe)],
                input=stdin_data,
                capture_output=True,
                text=True,
                timeout=timeout_sec,
            )
            duration = time.perf_counter() - start
            rc = completed.returncode
            stdout = completed.stdout
            stderr = completed.stderr
        except subprocess.TimeoutExpired as e:
            duration = time.perf_counter() - start
            rc = 124
            stdout = e.stdout or ""
            stderr = e.stderr or ""

        # Read memory usage if file exists
        peak_kb: Optional[int] = None
        try:
            data = Path(mem_file).read_text(encoding="utf-8").strip()
            # Expect a single line like MAXRSS=12345
            for line in data.splitlines():
                if line.startswith("MAXRSS="):
                    value = line.split("=", 1)[1].strip()
                    if value.isdigit():
                        peak_kb = int(value)
                    break
        except Exception:
            peak_kb = None
        return rc, stdout, stderr, duration, peak_kb
    finally:
        try:
            os.remove(mem_file)
        except OSError:
            pass


def compare_outputs(actual: str, expected: str) -> bool:
    return actual == expected


def format_ms(seconds: float) -> int:
    return int(round(seconds * 1000))


def main(argv: Optional[Iterable[str]] = None) -> int:
    parser = argparse.ArgumentParser(
        description=(
            "Run task executables and compare outputs. Supports tests in each task folder "
            "(task_xx/tests/*.in|.out or task_xx/*.in|.out) or a central tests directory."
        )
    )
    parser.add_argument(
        "--tests-dir",
        type=Path,
        default=None,
        help="Path to central tests directory (used when --tests-layout=central).",
    )
    parser.add_argument(
        "--tests-layout",
        choices=["in-task", "central"],
        default="in-task",
        help="Where tests reside: in each task dir (default) or central tests dir.",
    )
    parser.add_argument(
        "--build-dir",
        type=Path,
        default=None,
        help="Path to build directory (default: <repo>/build)",
    )
    parser.add_argument(
        "--tasks",
        nargs="*",
        default=[],
        help="Specific task names to run (e.g., task_01 task_03). Default: autodetect",
    )
    parser.add_argument(
        "--timeout",
        type=float,
        default=2.0,
        help="Per-case timeout in seconds (default: 2.0)",
    )
    parser.add_argument(
        "--mem-limit-mb",
        type=float,
        default=None,
        help=(
            "Soft per-case memory limit in MB. If exceeded, case is marked as MEM_EXCEEDED. "
            "Combine with --fail-on-mem to make it fail the run."
        ),
    )
    parser.add_argument(
        "--fail-on-mem",
        action="store_true",
        help=(
            "Exit with non-zero status if any case exceeds --mem-limit-mb (i.e., MEM_EXCEEDED)."
        ),
    )
    parser.add_argument(
        "--report-memtop",
        type=int,
        default=0,
        help=(
            "Print top-N highest memory usage cases in the summary (0 to disable)."
        ),
    )
    parser.add_argument(
        "--time-limit",
        type=float,
        default=None,
        help=(
            "Soft per-case time limit in seconds. If exceeded, case is marked as SLOW. "
            "Combine with --fail-on-slow to make it fail the run."
        ),
    )
    parser.add_argument(
        "--fail-on-slow",
        action="store_true",
        help=(
            "Exit with non-zero status if any case exceeds --time-limit (i.e., SLOW cases)."
        ),
    )
    parser.add_argument(
        "--report-slowest",
        type=int,
        default=0,
        help=(
            "Print top-N slowest cases in the summary (0 to disable)."
        ),
    )
    parser.add_argument(
        "--normalize",
        choices=["strip", "keep", "lines"],
        default="strip",
        help=(
            "Output normalization: strip=trim trailing whitespace; keep=exact; lines=trim per-line"
        ),
    )
    parser.add_argument(
        "--write-missing",
        action="store_true",
        help="If expected .out is missing, write it from current output",
    )
    parser.add_argument(
        "--update-expected",
        action="store_true",
        help="Overwrite existing .out files with current outputs",
    )
    parser.add_argument(
        "--save-actual",
        action="store_true",
        help="On mismatch, write <case>.out.actual with the produced output",
    )

    args = parser.parse_args(list(argv) if argv is not None else None)

    script_path = Path(__file__).resolve()
    repo_root = find_repo_root(script_path)
    tests_dir = args.tests_dir or (repo_root / "tests")
    build_dir = args.build_dir or (repo_root / "build")

    all_execs = discover_executables(build_dir)

    # Determine tasks to run
    requested: List[str] = list(args.tasks)
    if not requested:
        if args.tests_layout == "central":
            # Prefer tasks present in central tests dir; fallback to executables
            requested = sorted(
                set(discover_tasks_from_tests(tests_dir)) or set(all_execs.keys())
            )
        else:
            # From repo tasks; if none have .in files yet, still run for all discovered tasks
            repo_tasks = discover_tasks_in_repo(repo_root)
            requested = repo_tasks

    if not requested:
        print(
            "No tasks found. Ensure task folders like 'task_01' exist and are built."
        )
        return 2

    # Ensure executables for requested tasks
    missing_execs: List[str] = []
    task_to_exe: Dict[str, Path] = {}
    for task in requested:
        exe = all_execs.get(task)
        if exe is None:
            # Try an alternative common layout: build/<task>
            alt = build_dir / task
            if alt.exists() and alt.is_file() and os.access(alt, os.X_OK):
                exe = alt
        if exe is None:
            missing_execs.append(task)
        else:
            task_to_exe[task] = exe

    if missing_execs:
        for t in missing_execs:
            print(f"[WARN] Executable not found for {t}. Expected at '{build_dir / t / t}'")

    results: List[CaseResult] = []
    total_cases = 0

    # Decide whether to measure memory
    time_tool = find_time_tool()
    measure_memory = bool(time_tool) and (args.mem_limit_mb is not None or args.report_memtop)

    for task in sorted(requested):
        exe = task_to_exe.get(task)
        if args.tests_layout == "central":
            cases = list_cases_for_task_central(tests_dir, task)
            no_cases_hint = str(tests_dir / task)
        else:
            cases = list_cases_for_task_in_task(repo_root, task)
            no_cases_hint = f"{repo_root / task}/(tests|.)"
        if not cases:
            print(f"[INFO] No test cases for {task} in '{no_cases_hint}'. Skipping.")
            continue
        print(f"\n=== {task} ({len(cases)} case(s)) ===")
        for input_file, expected_file in cases:
            total_cases += 1
            case_name = input_file.stem
            if exe is None:
                results.append(
                    CaseResult(task, case_name, CaseStatus.EXEC_MISSING, 0, "Executable is missing")
                )
                print(f"{case_name}: EXEC MISSING")
                continue

            stdin_data = read_text(input_file)
            if measure_memory:
                rc, stdout, stderr, duration, peak_kb = run_executable_with_memory(
                    exe, stdin_data, args.timeout, time_tool  # type: ignore[arg-type]
                )
            else:
                rc, stdout, stderr, duration = run_executable(exe, stdin_data, args.timeout)
                peak_kb = None
            duration_ms = format_ms(duration)

            if rc == 124:  # timeout code used above
                results.append(CaseResult(task, case_name, CaseStatus.TIMEOUT, duration_ms, "Timed out", peak_kb))
                suffix = f", mem {peak_kb} KB" if peak_kb is not None else ""
                print(f"{case_name}: TIMEOUT ({duration_ms} ms{suffix})")
                continue

            actual_norm = normalize(stdout, args.normalize)

            if args.update_expected and expected_file.exists():
                write_text(expected_file, actual_norm + "\n")
                results.append(CaseResult(task, case_name, CaseStatus.OK, duration_ms, "updated expected", peak_kb))
                suffix = f", mem {peak_kb} KB" if peak_kb is not None else ""
                print(f"{case_name}: UPDATED ({duration_ms} ms{suffix})")
                continue

            if not expected_file.exists():
                if args.write_missing:
                    write_text(expected_file, actual_norm + "\n")
                    results.append(CaseResult(task, case_name, CaseStatus.OK, duration_ms, "wrote expected", peak_kb))
                    suffix = f", mem {peak_kb} KB" if peak_kb is not None else ""
                    print(f"{case_name}: WROTE EXPECTED ({duration_ms} ms{suffix})")
                else:
                    if args.save_actual:
                        write_text(expected_file.with_suffix(".out.actual"), actual_norm + "\n")
                    results.append(
                        CaseResult(task, case_name, CaseStatus.NO_EXPECTED, duration_ms, "expected .out missing", peak_kb)
                    )
                    suffix = f", mem {peak_kb} KB" if peak_kb is not None else ""
                    print(f"{case_name}: NO EXPECTED ({duration_ms} ms{suffix})")
                continue

            expected_norm = normalize(read_text(expected_file), args.normalize)
            if compare_outputs(actual_norm, expected_norm):
                # Check soft time limit if provided
                # Time soft limit
                if args.time_limit is not None and duration > args.time_limit:
                    limit_ms = format_ms(args.time_limit)
                    results.append(
                        CaseResult(task, case_name, CaseStatus.SLOW, duration_ms, f"exceeded {limit_ms} ms", peak_kb)
                    )
                    suffix = f", mem {peak_kb} KB" if peak_kb is not None else ""
                    print(f"{case_name}: SLOW ({duration_ms} ms > {limit_ms} ms{suffix})")
                else:
                    # Memory soft limit
                    if args.mem_limit_mb is not None and peak_kb is not None:
                        limit_kb = int(args.mem_limit_mb * 1024)
                        if peak_kb > limit_kb:
                            results.append(
                                CaseResult(
                                    task,
                                    case_name,
                                    CaseStatus.MEM_EXCEEDED,
                                    duration_ms,
                                    f"exceeded {limit_kb} KB",
                                    peak_kb,
                                )
                            )
                            print(
                                f"{case_name}: MEM_EXCEEDED ({peak_kb} KB > {limit_kb} KB, {duration_ms} ms)"
                            )
                        else:
                            results.append(CaseResult(task, case_name, CaseStatus.OK, duration_ms, "", peak_kb))
                            suffix = f", mem {peak_kb} KB" if peak_kb is not None else ""
                            print(f"{case_name}: OK ({duration_ms} ms{suffix})")
                    else:
                        results.append(CaseResult(task, case_name, CaseStatus.OK, duration_ms, "", peak_kb))
                        suffix = f", mem {peak_kb} KB" if peak_kb is not None else ""
                        print(f"{case_name}: OK ({duration_ms} ms{suffix})")
            else:
                if args.save_actual:
                    write_text(expected_file.with_suffix(".out.actual"), actual_norm + "\n")
                # Provide a short inline diff preview
                msg = "output differs"
                results.append(CaseResult(task, case_name, CaseStatus.FAIL, duration_ms, msg, peak_kb))
                suffix = f", mem {peak_kb} KB" if peak_kb is not None else ""
                print(f"{case_name}: FAIL ({duration_ms} ms{suffix})")

    # Summary
    if not results:
        print("\nNo cases were executed.")
        return 2

    passed = sum(1 for r in results if r.status == CaseStatus.OK)
    failed = sum(1 for r in results if r.status == CaseStatus.FAIL)
    timeouts = sum(1 for r in results if r.status == CaseStatus.TIMEOUT)
    missing_expected = sum(1 for r in results if r.status == CaseStatus.NO_EXPECTED)
    slow = sum(1 for r in results if r.status == CaseStatus.SLOW)
    missing_exec = sum(1 for r in results if r.status == CaseStatus.EXEC_MISSING)
    mem_exceeded = sum(1 for r in results if r.status == CaseStatus.MEM_EXCEEDED)

    print(
        f"\n=== Summary ===\n"
        f"Cases run: {passed + failed + timeouts + missing_expected + missing_exec + slow + mem_exceeded}\n"
        f"OK: {passed}, FAIL: {failed}, TIMEOUT: {timeouts}, SLOW: {slow}, MEM_EXCEEDED: {mem_exceeded}, NO_EXPECTED: {missing_expected}, EXEC_MISSING: {missing_exec}"
    )

    if args.report_slowest and results:
        # Consider only cases that actually ran (exclude exec_missing/no_expected) and sort by duration
        measured = [
            r for r in results
            if r.status in {CaseStatus.OK, CaseStatus.FAIL, CaseStatus.TIMEOUT, CaseStatus.SLOW}
        ]
        measured.sort(key=lambda r: r.duration_ms, reverse=True)
        top_n = measured[: max(0, args.report_slowest)]
        if top_n:
            print("\nTop slowest cases:")
            for r in top_n:
                print(f"- {r.task}/{r.case_name}: {r.duration_ms} ms [{r.status.value}] {r.message}")

    if args.report_memtop and results:
        mem_measured = [r for r in results if r.peak_kb is not None]
        mem_measured.sort(key=lambda r: r.peak_kb or 0, reverse=True)
        top_m = mem_measured[: max(0, args.report_memtop)]
        if top_m:
            print("\nTop memory usage cases:")
            for r in top_m:
                print(
                    f"- {r.task}/{r.case_name}: {r.peak_kb} KB [{r.status.value}] {r.message}"
                )

    if (
        failed
        or timeouts
        or missing_exec
        or missing_expected
        or (args.fail_on_slow and slow)
        or (args.fail_on_mem and mem_exceeded)
    ):
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())


