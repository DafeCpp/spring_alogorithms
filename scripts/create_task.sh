#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <task_number>"
    exit 1
fi

TASK_NUMBER=$1
TASK_DIR="task_$TASK_NUMBER"

# Create task directory structure
mkdir -p "$TASK_DIR/src"
mkdir -p "$TASK_DIR/include"
mkdir -p "$TASK_DIR/benchmark"

# Create main.cpp
cat > "$TASK_DIR/src/main.cpp" << 'EOL'
#include <iostream>
#include "../include/solution.hpp"

int main() {
    // Your testing code here
    return 0;
}
EOL

# Create test.cpp
cat > "$TASK_DIR/src/test.cpp" << 'EOL'
#include <gtest/gtest.h>
#include "../include/solution.hpp"

TEST(TestSuite, TestCase) {
    // Your test code here
    ASSERT_EQ(1, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
EOL

# Create benchmark.cpp
cat > "$TASK_DIR/benchmark/benchmark.cpp" << 'EOL'
#include <benchmark/benchmark.h>
#include "../include/solution.hpp"

// Базовый бенчмарк
static void BM_YourFunction(benchmark::State& state) {
    // Подготовка данных для тестирования
    for (auto _ : state) {
        // Тестируемый код
        benchmark::DoNotOptimize(/* ваш код */);
    }
}
BENCHMARK(BM_YourFunction);

// Бенчмарк с параметрами
static void BM_YourFunctionWithParams(benchmark::State& state) {
    int size = state.range(0);
    // Подготовка данных размера size
    for (auto _ : state) {
        // Тестируемый код с параметром size
        benchmark::DoNotOptimize(/* ваш код */);
    }
}
BENCHMARK(BM_YourFunctionWithParams)
    ->RangeMultiplier(2)
    ->Range(8, 8<<10);  // Тестируем размеры от 8 до 8192

// Бенчмарк с пользовательскими счетчиками
static void BM_YourFunctionWithCounters(benchmark::State& state) {
    int size = state.range(0);
    for (auto _ : state) {
        // Тестируемый код
        state.counters["items_per_second"] = benchmark::Counter(
            size, benchmark::Counter::kIsRate);
        state.counters["bytes_processed"] = benchmark::Counter(
            size * sizeof(int), benchmark::Counter::kIsRate);
    }
}
BENCHMARK(BM_YourFunctionWithCounters)
    ->Range(8, 8<<10);

BENCHMARK_MAIN();
EOL

# Create solution.hpp
cat > "$TASK_DIR/include/solution.hpp" << 'EOL'
#pragma once

// Your solution class/function declarations here

EOL

# Create solution.cpp
cat > "$TASK_DIR/src/solution.cpp" << 'EOL'
#include "../include/solution.hpp"

// Your solution implementations here

EOL

# Create CMakeLists.txt
cat > "$TASK_DIR/CMakeLists.txt" << 'EOL'
cmake_minimum_required(VERSION 3.10)
project(task_${TASK_NUMBER})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add gtest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Add benchmark
FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.8.3
)
FetchContent_MakeAvailable(benchmark)

# Add executable for testing
add_executable(test_task_${TASK_NUMBER}
    src/test.cpp
    src/solution.cpp
)

target_link_libraries(test_task_${TASK_NUMBER}
    gtest_main
    gmock_main
)

# Add executable for main
add_executable(main_task_${TASK_NUMBER}
    src/main.cpp
    src/solution.cpp
)

# Add executable for benchmark
add_executable(benchmark_task_${TASK_NUMBER}
    benchmark/benchmark.cpp
    src/solution.cpp
)

target_link_libraries(benchmark_task_${TASK_NUMBER}
    benchmark::benchmark
)
EOL

# Create README.md
cat > "$TASK_DIR/README.md" << 'EOL'
# Task ${TASK_NUMBER}

## Description
[Add task description here]

## Requirements
- C++17 or higher
- Google Test framework
- Google Benchmark framework

## Building
```bash
mkdir build && cd build
cmake ..
make
```

## Running Tests
```bash
./test_task_${TASK_NUMBER}
```

## Running Main
```bash
./main_task_${TASK_NUMBER}
```

## Running Benchmarks
```bash
./benchmark_task_${TASK_NUMBER}
```

## Benchmark Results
[Add benchmark results and analysis here]
EOL

echo "Task ${TASK_NUMBER} created successfully!"