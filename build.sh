#!/bin/bash

echo "=========================================="
echo "Building AMCI Compiler..."
echo "=========================================="

# Check for required tools
check_tool() {
    if ! command -v $1 &> /dev/null; then
        echo "Error: $1 is not installed."
        echo "Please run: ./install_dependencies.sh"
        echo "Or install manually: sudo apt-get install flex bison gcc"
        exit 1
    fi
}

echo "Checking dependencies..."
check_tool flex
check_tool bison
check_tool gcc
echo "✓ All dependencies found"
echo ""

# Clean previous build
echo "Cleaning previous build..."
rm -f lex.yy.c grammar.tab.c grammar.tab.h amci
echo "✓ Cleaned"
echo ""

# Generate lexer
echo "Generating lexer (flex)..."
flex scanner.l
if [ $? -ne 0 ]; then
    echo "Error: flex failed"
    exit 1
fi
echo "✓ Lexer generated"

# Generate parser
echo "Generating parser (bison)..."
bison -d grammar.y
if [ $? -ne 0 ]; then
    echo "Error: bison failed"
    exit 1
fi
echo "✓ Parser generated"

# Compile
echo "Compiling..."
gcc -o amci lex.yy.c grammar.tab.c -lm
if [ $? -ne 0 ]; then
    echo "Error: Compilation failed"
    exit 1
fi
echo "✓ Compilation successful"
echo ""

echo "=========================================="
echo "Build successful! Executable: ./amci"
echo "=========================================="
echo ""
echo "Usage:"
echo "  ./amci              - Interactive mode"
echo "  ./amci demo.edu     - Process file"
echo "  ./demo.sh           - Run all demos"
echo ""
