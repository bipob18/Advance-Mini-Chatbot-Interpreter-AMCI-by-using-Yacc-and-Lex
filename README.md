# AMCI - Advanced Mini Chatbot Interpreter

A Problem Solution Compiler System that processes natural language problem statements using Lexical Analysis (Flex) and Yacc Parsing (Bison).

## Overview

AMCI is an intelligent interpreter that understands natural English commands and solves arithmetic, logical, and reasoning problems. It maintains context across multiple statements and provides step-by-step solutions.

## Features

- **Natural Language Processing**: Accepts English problem statements in flexible formats
- **Arithmetic Operations**: Addition, subtraction, multiplication, division with step-by-step solutions
- **Logical Comparisons**: Greater than, smaller than comparisons
- **Reasoning Problems**: Tallest, youngest, and similar logical reasoning
- **Variable Management**: Store and use variables with symbol table
- **Multi-step Problems**: Maintain context across multiple sentences
- **Error Detection**: Handles undefined variables, invalid statements, division by zero
- **Conversational Interface**: Interactive mode with greetings and farewells
- **Search Functionality**: Built-in help system to search for commands and examples
- **Case Insensitive**: All commands work in any case (Hello, hello, HELLO)
- **Flexible Input**: Multiple ways to express the same operation

## Requirements

- Flex (Lex) 2.6+
- Bison (Yacc) 3.0+
- GCC compiler 4.8+

## Installation

### Linux/WSL/Ubuntu/Debian:

```bash
sudo apt-get update
sudo apt-get install -y flex bison gcc build-essential
```

Or use the automated installation script:
```bash
chmod +x install_dependencies.sh
./install_dependencies.sh
```

### Windows:

Install MinGW-w64 or MSYS2, then install flex and bison through the package manager.

## Building

```bash
chmod +x build.sh
./build.sh
```

This will:
1. Generate the lexical analyzer (lex.yy.c) from scanner.l
2. Generate the parser (grammar.tab.c, grammar.tab.h) from grammar.y
3. Compile everything into the `amci` executable

## Usage

### Interactive Mode (Recommended)

```bash
./amci
```

This starts an interactive session where you can type commands. The conversation continues until you press Ctrl+C.

Example session:
```
> Hello
Hi! I can solve arithmetic, logical, and reasoning problems.
Type 'Search' or 'Help' to see all available commands and examples.

> 5 sum 99
Result = 104

> x equals 10
Variable X = 10

> y = 5
Variable Y = 5

> x sum y
Result = 15

> Search
[Shows all available commands]

> Bye
Goodbye! (Type 'Hello' to continue or Ctrl+C to exit)
```

### File Mode

Process a file with multiple commands:
```bash
./amci demo.edu
```

### Run Demo Script

```bash
./demo.sh
```

## Supported Input Formats

### Arithmetic Operations

**Simple Format:**
- `5 sum 99` → Result = 104
- `10 plus 5` → Result = 15
- `5 multiply 3` → Result = 15
- `20 divide 4` → Result = 5
- `10 minus 5` → Result = 5

**Natural Language:**
- `Find sum 5 and 3` → Result = 8
- `Find sum of X and Y` → Result = (X + Y)
- `Calculate 8 times 2` → Result = 16
- `Calculate X + Y * 2` → Result with step-by-step

**Expression Format:**
- `Calculate 5 + 3 * 2` → Result = 11 (with steps)
- `Calculate X + Y * 2` → Result with variable substitution

### Variable Assignment

- `x equals 5` → Variable X = 5
- `x = 5` → Variable X = 5
- `Let X = 5.` → Variable X = 5

### Comparisons

- `10 greater 7` → 10 is greater than 7
- `10 greater than 7` → 10 is greater than 7
- `5 smaller 8` → 5 is smaller than 8
- `Which is greater 10 and 7` → Greater = 10
- `x greater y` → Variable comparison

### Reasoning Problems

- `A is taller than B. B is taller than C. Who is the tallest?` → A is the tallest.

### Help and Search

- `Search` → Shows all available commands and examples
- `Help` → Shows all available commands and examples
- `Search sum` → Shows sum-related examples
- `Search multiply` → Shows multiplication examples

## Example Inputs & Outputs

### Example 1: Simple Arithmetic
```
Input: 5 sum 99
Output: Result = 104
```

### Example 2: Variable Operations
```
Input:
x equals 5
y = 3
x sum y

Output:
Variable X = 5
Variable Y = 3
Result = 8
```

### Example 3: Multi-step Calculation
```
Input:
Let X = 5.
Let Y = 3.
Calculate X + Y * 2.

Output:
Variable X = 5
Variable Y = 3
Step: 3 * 2 = 6
Step: 5 + 6 = 11
Result = 11
```

### Example 4: Comparison
```
Input: 10 greater 7
Output: 10 is greater than 7
```

### Example 5: Reasoning
```
Input: A is taller than B. B is taller than C. Who is the tallest?
Output: A is the tallest.
```

### Example 6: Error Handling
```
Input: Find sum of X and Y (without defining X or Y)
Output: Error: Undefined variable X or Y.
```

## Project Structure

```
AMCI/
├── scanner.l              # Lexical analyzer (Flex)
├── grammar.y               # Grammar rules (Bison)
├── build.sh                # Build script (Linux/Mac)
├── build.bat               # Build script (Windows)
├── install_dependencies.sh # Dependency installer
├── demo.sh                 # Demo test script
├── demo.edu                # Sample input file 1
├── demo2.edu               # Sample input file 2
├── README.md               # This file
└── INSTALL.md              # Detailed installation guide
```

## Technical Details

- **Lexical Analysis**: Flex-based tokenizer with case-insensitive matching
- **Syntax Analysis**: Bison-based parser with operator precedence
- **Symbol Table**: Hash-based variable storage (26 variables A-Z)
- **Error Recovery**: Graceful error handling with informative messages
- **Operator Precedence**: Standard mathematical precedence (* before +)
- **Line Buffering**: Input/output properly buffered for interactive use

## Notes

- All commands are **case-insensitive** (Hello, hello, HELLO all work)
- Variable names are single letters (A-Z or a-z) - automatically converted to uppercase
- Numbers are integers only
- Multi-step problems maintain context across sentences
- The system uses standard operator precedence (multiplication before addition)
- All arithmetic follows standard C evaluation rules
- Press Ctrl+C to exit interactive mode

## Troubleshooting

**Build fails:**
1. Check if dependencies are installed: `flex --version`, `bison --version`, `gcc --version`
2. Install missing tools: `./install_dependencies.sh`
3. Rebuild: `./build.sh`

**"Command not found" errors:**
- Make sure build.sh is executable: `chmod +x build.sh`
- Check that all dependencies are in your PATH

**Syntax errors:**
- Check input format matches supported patterns
- Use `Search` command to see all available formats
- Variables must be defined before use

## License

This is an educational project for Compiler Design course.

## Author

Developed as part of Advanced Compiler Design coursework.
