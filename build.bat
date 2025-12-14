@echo off
echo Building AMCI Compiler...

REM Generate lexer
flex scanner.l
if errorlevel 1 (
    echo Error: flex not found. Please install Flex.
    exit /b 1
)

REM Generate parser
bison -d grammar.y
if errorlevel 1 (
    echo Error: bison not found. Please install Bison.
    exit /b 1
)

REM Compile
gcc -o amci.exe lex.yy.c grammar.tab.c -lm
if errorlevel 1 (
    echo Error: gcc not found. Please install GCC/MinGW.
    exit /b 1
)

if exist amci.exe (
    echo Build successful! Executable: amci.exe
    echo.
    echo Usage:
    echo   amci.exe              - Interactive mode
    echo   amci.exe demo.edu     - Process file
) else (
    echo Build failed!
    exit /b 1
)

