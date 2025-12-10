#!/bin/bash

# Check if clang-format is installed
if ! command -v clang-format &> /dev/null; then
    echo "Error: clang-format is not installed. Please install it first."
    echo "On Ubuntu/Debian: sudo apt-get install clang-format"
    echo "On macOS: brew install clang-format"
    exit 1
fi

# Find all C++ files in the project
echo "Searching for C++ files..."
FILES=$(find . -type f \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -not -path "./build/*" -not -path "./.git/*")

if [ -z "$FILES" ]; then
    echo "No C++ files found to format."
    exit 0
fi

# Format each file
echo "Formatting files..."
for file in $FILES; do
    echo "Formatting $file"
    clang-format -i -style=file "$file"
done

echo "Formatting complete!"