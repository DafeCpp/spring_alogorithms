#!/bin/bash

# Create .git/hooks directory if it doesn't exist
mkdir -p .git/hooks

# Create pre-commit hook
cat > .git/hooks/pre-commit << 'EOF'
#!/bin/bash

# Get the list of staged C++ files
STAGED_FILES=$(git diff --cached --name-only --diff-filter=ACMR | grep -E "\.(cpp|h|hpp)$")

if [ -z "$STAGED_FILES" ]; then
    exit 0
fi

# Check if clang-format is installed
if ! command -v clang-format &> /dev/null; then
    echo "Error: clang-format is not installed. Please install it first."
    echo "On Ubuntu/Debian: sudo apt-get install clang-format"
    echo "On macOS: brew install clang-format"
    exit 1
fi

# Format each staged file
echo "Running clang-format on staged files..."
for file in $STAGED_FILES; do
    echo "Formatting $file"
    clang-format -i -style=file "$file"
    git add "$file"
done

echo "Formatting complete!"
exit 0
EOF

# Make the pre-commit hook executable
chmod +x .git/hooks/pre-commit

echo "Git pre-commit hook for code formatting has been set up successfully!"
echo "Now your code will be automatically formatted before each commit."