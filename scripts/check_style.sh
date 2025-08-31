#!/bin/bash

# Проверяем наличие clang-format
if ! command -v clang-format &> /dev/null; then
    echo "Error: clang-format is not installed"
    exit 1
fi

# Создаем временный файл для хранения списка файлов
TMP_FILE=$(mktemp)

# Находим все C++ файлы в проекте
find . -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) \
    -not -path "./build/*" \
    -not -path "./.git/*" \
    -not -path "./googletest/*" \
    > "$TMP_FILE"

# Проверяем стиль каждого файла
ERRORS=0
while IFS= read -r file; do
    echo "Checking $file..."
    if ! clang-format --style=Google --dry-run --Werror "$file" &> /dev/null; then
        echo "Style issues found in $file"
        clang-format --style=Google "$file" > "${file}.formatted"
        diff -u "$file" "${file}.formatted"
        rm "${file}.formatted"
        ERRORS=$((ERRORS + 1))
    fi
done < "$TMP_FILE"

# Удаляем временный файл
rm "$TMP_FILE"

if [ $ERRORS -gt 0 ]; then
    echo "Found $ERRORS files with style issues"
    exit 1
else
    echo "All files follow Google style guide"
    exit 0
fi