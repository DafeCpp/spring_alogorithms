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

# Форматируем каждый файл
FORMATTED=0
while IFS= read -r file; do
    echo "Formatting $file..."
    if ! clang-format --style=Google --dry-run --Werror "$file" &> /dev/null; then
        clang-format --style=Google -i "$file"
        FORMATTED=$((FORMATTED + 1))
    fi
done < "$TMP_FILE"

# Удаляем временный файл
rm "$TMP_FILE"

if [ $FORMATTED -gt 0 ]; then
    echo "Formatted $FORMATTED files"
else
    echo "All files are already formatted"
fi