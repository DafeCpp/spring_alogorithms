#!/usr/bin/env python3
"""
Скрипт для тестирования AI сервисов анализа кода
Использование: python test_ai_analysis.py <путь_к_файлу.cpp>
"""

import os
import sys
import requests
import json
import re
from typing import Optional, Dict, List

def analyze_with_huggingface(file_path: str, api_key: str) -> Optional[str]:
    """Анализ с помощью Hugging Face API"""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            code_content = f.read()
    except Exception as e:
        print(f"Ошибка чтения файла: {e}")
        return None

    headers = {
        'Authorization': f'Bearer {api_key}',
        'Content-Type': 'application/json'
    }

    prompt = f'''
    Analyze this C++ code and provide a brief review:

    {code_content[:800]}

    Focus on:
    - Code quality
    - Potential issues
    - Suggestions for improvement

    Keep response concise.
    '''

    data = {
        'inputs': prompt,
        'parameters': {
            'max_new_tokens': 300,
            'temperature': 0.3,
            'do_sample': True
        }
    }

    models = [
        'microsoft/DialoGPT-medium',
        'gpt2',
        'distilgpt2'
    ]

    for model in models:
        try:
            print(f"Пробуем модель: {model}")
            response = requests.post(
                f'https://api-inference.huggingface.co/models/{model}',
                headers=headers, json=data, timeout=30
            )

            if response.status_code == 200:
                result = response.json()
                if isinstance(result, list) and len(result) > 0:
                    return f"🤖 Hugging Face ({model}):\n{result[0].get('generated_text', 'Analysis completed')}"
                elif isinstance(result, dict) and 'generated_text' in result:
                    return f"🤖 Hugging Face ({model}):\n{result['generated_text']}"
        except Exception as e:
            print(f"Ошибка с моделью {model}: {e}")
            continue

    return None

def analyze_with_ollama(file_path: str) -> Optional[str]:
    """Анализ с помощью локального Ollama"""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            code_content = f.read()
    except Exception as e:
        print(f"Ошибка чтения файла: {e}")
        return None

    prompt = f'''
    Review this C++ code and provide feedback:

    {code_content[:500]}

    Provide brief feedback on code quality and potential issues.
    '''

    data = {
        'model': 'codellama:7b',
        'prompt': prompt,
        'stream': False
    }

    try:
        print("Пробуем Ollama...")
        response = requests.post('http://localhost:11434/api/generate',
                               json=data, timeout=60)
        if response.status_code == 200:
            result = response.json()
            return f"🤖 Ollama (CodeLlama):\n{result.get('response', 'Analysis completed')}"
    except Exception as e:
        print(f"Ollama недоступен: {e}")

    return None

def pattern_analysis(file_path: str) -> str:
    """Анализ на основе паттернов"""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            code_content = f.read()
    except Exception as e:
        return f"Ошибка чтения файла: {e}"

    lines = code_content.split('\n')
    issues = []
    suggestions = []
    good_practices = []

    patterns = {
        'memory_leak': (r'new\s+\w+\s*[^;]*$', 'Potential memory leak - new without delete'),
        'unsafe_function': (r'(strcpy|strcat|gets|scanf)\s*\(', 'Unsafe function usage'),
        'long_line': (r'.{120,}', 'Line too long (>120 characters)'),
        'namespace_std': (r'using\s+namespace\s+std;', 'Avoid using namespace std in headers'),
        'goto': (r'goto\s+\w+', 'Avoid using goto statements'),
        'magic_number': (r'\b\d{3,}\b', 'Consider using named constants'),
        'raw_pointer': (r'\w+\s*\*\s*\w+\s*=', 'Consider using smart pointers'),
        'efficient_container': (r'std::vector<\w+>\s+\w+\s*;', 'Good: Using std::vector'),
        'smart_pointer': (r'std::(unique_ptr|shared_ptr)<\w+>', 'Good: Using smart pointers'),
        'const_reference': (r'const\s+\w+&\s+\w+', 'Good: Using const references'),
        'range_based_for': (r'for\s*\(\s*auto\s*&?\s*\w+\s*:', 'Good: Using range-based for loop')
    }

    for i, line in enumerate(lines, 1):
        line = line.strip()

        for pattern_name, (regex, message) in patterns.items():
            if re.search(regex, line):
                if pattern_name.startswith('good_'):
                    good_practices.append(f'Line {i}: {message}')
                elif pattern_name in ['memory_leak', 'unsafe_function', 'goto']:
                    issues.append(f'Line {i}: {message}')
                else:
                    suggestions.append(f'Line {i}: {message}')
                break

    result = "📊 Pattern Analysis:\n\n"

    if issues:
        result += "🚨 Issues Found:\n"
        for issue in issues[:3]:
            result += f"- {issue}\n"
        result += "\n"

    if suggestions:
        result += "💡 Suggestions:\n"
        for suggestion in suggestions[:3]:
            result += f"- {suggestion}\n"
        result += "\n"

    if good_practices:
        result += "✅ Good Practices:\n"
        for practice in good_practices[:3]:
            result += f"- {practice}\n"
        result += "\n"

    if not issues and not suggestions:
        result += "✅ No obvious issues found. Code follows basic C++ practices.\n\n"

    return result

def main():
    if len(sys.argv) != 2:
        print("Использование: python test_ai_analysis.py <путь_к_файлу.cpp>")
        sys.exit(1)

    file_path = sys.argv[1]

    if not os.path.exists(file_path):
        print(f"Файл не найден: {file_path}")
        sys.exit(1)

    if not file_path.endswith(('.cpp', '.h', '.hpp', '.cc', '.cxx')):
        print("Поддерживаются только C++ файлы")
        sys.exit(1)

    print(f"🔍 Анализирую файл: {file_path}")
    print("="*60)

    # Пробуем разные методы анализа
    analysis_results = []

    # 1. Hugging Face
    api_key = os.getenv('HUGGINGFACE_API_KEY')
    if api_key:
        print("⏳ Пробуем Hugging Face...")
        result = analyze_with_huggingface(file_path, api_key)
        if result:
            analysis_results.append(result)
    else:
        print("⚠️ HUGGINGFACE_API_KEY не установлен")

    # 2. Ollama
    print("⏳ Пробуем Ollama...")
    result = analyze_with_ollama(file_path)
    if result:
        analysis_results.append(result)

    # 3. Pattern Analysis (всегда доступен)
    print("⏳ Выполняем паттерн-анализ...")
    result = pattern_analysis(file_path)
    analysis_results.append(result)

    # Выводим результаты
    print("\n" + "="*60)
    print("🤖 РЕЗУЛЬТАТЫ АНАЛИЗА")
    print("="*60)

    for i, result in enumerate(analysis_results, 1):
        print(f"\n--- Анализ {i} ---")
        print(result)
        print("-" * 40)

    # Сохраняем результаты
    output_file = f"{file_path}.ai_analysis.md"
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(f"# AI Analysis for {file_path}\n\n")
        for result in analysis_results:
            f.write(result + "\n\n---\n\n")

    print(f"\n💾 Результаты сохранены в: {output_file}")

    # Рекомендации
    print("\n💡 Рекомендации:")
    if not api_key:
        print("- Установите HUGGINGFACE_API_KEY для лучшего анализа")
    print("- Установите Ollama для локального AI анализа")
    print("- Используйте паттерн-анализ как базовую проверку")

if __name__ == "__main__":
    main()