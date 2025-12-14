%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <unistd.h>

// Symbol table for variables
typedef struct {
    char name;
    int value;
} Symbol;

Symbol symbol_table[26];
int symbol_count = 0;
int should_exit = 0;
int interactive_mode = 0;

// Function declarations
int find_symbol(char name);
void set_symbol(char name, int value);
int get_symbol(char name);
int evaluate_arithmetic(int left, char op, int right);
void signal_handler(int sig);

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int line_num;
extern char* yytext;

int yylval;

void yyerror(const char* s) {
    // Suppress error messages for better user experience
    // In interactive mode, clear input buffer and continue
    if (interactive_mode) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\n\nInterrupted by user (Ctrl+C). Goodbye!\n");
        should_exit = 1;
        exit(0);
    }
}

%}

%token GREETING FAREWELL SEARCH
%token LET CALCULATE FIND SUM DIFFERENCE MULTIPLY DIVIDE OF AND OR
%token WHICH WHO IS THE THAN IF EQUALS
%token GREATER SMALLER TALLEST YOUNGEST
%token VARIABLE NUMBER
%token PLUS MINUS MULT DIV TIMES
%token LPAREN RPAREN PERIOD QUESTION COMMA NEWLINE

%left PLUS MINUS
%left MULT DIV

%%

input:
    | input statement
    | statement
    | /* empty - allow empty input in interactive mode */
    ;

statement:
    greeting_stmt
    | farewell_stmt
    | search_stmt
    | assignment_stmt
    | arithmetic_stmt
    | comparison_stmt
    | reasoning_stmt
    ;

greeting_stmt:
    GREETING {
        printf("Hi! I can solve arithmetic, logical, and reasoning problems.\n");
        printf("Type 'Search' or 'Help' to see all available commands and examples.\n");
        fflush(stdout);
    }
    ;

farewell_stmt:
    FAREWELL {
        if (interactive_mode) {
            printf("Goodbye! (Type 'Hello' to continue or Ctrl+C to exit)\n");
        } else {
            printf("Goodbye!\n");
            exit(0);
        }
    }
    ;

search_stmt:
    SEARCH {
        show_all_examples();
    }
    | SEARCH SUM {
        show_search_results("sum");
    }
    | SEARCH MULTIPLY {
        show_search_results("multiply");
    }
    | SEARCH GREATER {
        show_search_results("greater");
    }
    | SEARCH VARIABLE {
        char query = $2;
        char query_str[2] = {query, '\0'};
        show_search_results(query_str);
    }
    | SEARCH NUMBER {
        char query_str[20];
        sprintf(query_str, "%d", $2);
        show_search_results(query_str);
    }
    | SEARCH CALCULATE {
        show_search_results("calculate");
    }
    | SEARCH TALLEST {
        show_search_results("tallest");
    }
    | SEARCH LET {
        show_search_results("variable");
    }
    ;

assignment_stmt:
    LET VARIABLE EQUALS NUMBER PERIOD {
        set_symbol($2, $4);
        printf("Variable %c = %d\n", $2, $4);
    }
    | LET VARIABLE EQUALS expression PERIOD {
        int val = $4;
        set_symbol($2, val);
        printf("Variable %c = %d\n", $2, val);
    }
    | VARIABLE EQUALS NUMBER {
        set_symbol($1, $3);
        printf("Variable %c = %d\n", $1, $3);
    }
    | VARIABLE EQUALS NUMBER PERIOD {
        set_symbol($1, $3);
        printf("Variable %c = %d\n", $1, $3);
    }
    | VARIABLE EQUALS expression {
        int val = $3;
        set_symbol($1, val);
        printf("Variable %c = %d\n", $1, val);
    }
    | VARIABLE EQUALS expression PERIOD {
        int val = $3;
        set_symbol($1, val);
        printf("Variable %c = %d\n", $1, val);
    }
    ;

arithmetic_stmt:
    CALCULATE expression PERIOD {
        printf("Result = %d\n", $2);
    }
    | CALCULATE expression {
        printf("Result = %d\n", $2);
    }
    | FIND SUM NUMBER AND NUMBER {
        int result = $3 + $5;
        printf("Result = %d\n", result);
    }
    | FIND SUM OF NUMBER AND NUMBER {
        int result = $4 + $6;
        printf("Result = %d\n", result);
    }
    | FIND SUM OF VARIABLE AND VARIABLE {
        int val1 = get_symbol($4);
        int val2 = get_symbol($6);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? $4 : $6, (val2 == -9999) ? $6 : $4);
        } else {
            int result = val1 + val2;
            printf("Result = %d\n", result);
        }
    }
    | CALCULATE NUMBER TIMES NUMBER {
        int result = $2 * $4;
        printf("Result = %d\n", result);
    }
    | NUMBER TIMES NUMBER {
        int result = $1 * $3;
        printf("Result = %d\n", result);
    }
    | MULTIPLY NUMBER AND NUMBER {
        int result = $2 * $4;
        printf("Step 1: Multiply %d * %d = %d\n", $2, $4, result);
        printf("Result = %d\n", result);
    }
    | SUM OF NUMBER AND NUMBER {
        int result = $3 + $5;
        printf("Step 1: Add %d + %d = %d\n", $3, $5, result);
        printf("Result = %d\n", result);
    }
    | SUM OF VARIABLE AND VARIABLE {
        int val1 = get_symbol($3);
        int val2 = get_symbol($5);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? $3 : $5, (val2 == -9999) ? $5 : $3);
        } else {
            int result = val1 + val2;
            printf("Step 1: Add %c (%d) + %c (%d) = %d\n", $3, val1, $5, val2, result);
            printf("Result = %d\n", result);
        }
    }
    | SUM OF NUMBER AND VARIABLE {
        int val2 = get_symbol($5);
        if (val2 == -9999) {
            printf("Error: Undefined variable %c.\n", $5);
        } else {
            int result = $3 + val2;
            printf("Step 1: Add %d + %c (%d) = %d\n", $3, $5, val2, result);
            printf("Result = %d\n", result);
        }
    }
    | SUM OF VARIABLE AND NUMBER {
        int val1 = get_symbol($3);
        if (val1 == -9999) {
            printf("Error: Undefined variable %c.\n", $3);
        } else {
            int result = val1 + $5;
            printf("Step 1: Add %c (%d) + %d = %d\n", $3, val1, $5, result);
            printf("Result = %d\n", result);
        }
    }
    | NUMBER SUM NUMBER {
        int result = $1 + $3;
        printf("Result = %d\n", result);
    }
    | NUMBER PLUS NUMBER {
        int result = $1 + $3;
        printf("Result = %d\n", result);
    }
    | NUMBER SUM NUMBER {
        // Already handled above, but keeping for clarity
    }
    | NUMBER AND NUMBER {
        int result = $1 + $3;
        printf("Result = %d\n", result);
    }
    | NUMBER MULTIPLY NUMBER {
        int result = $1 * $3;
        printf("Result = %d\n", result);
    }
    | NUMBER MINUS NUMBER {
        int result = $1 - $3;
        printf("Result = %d\n", result);
    }
    | NUMBER DIVIDE NUMBER {
        if ($3 == 0) {
            printf("Error: Division by zero.\n");
        } else {
            int result = $1 / $3;
            printf("Result = %d\n", result);
        }
    }
    | VARIABLE SUM VARIABLE {
        int val1 = get_symbol($1);
        int val2 = get_symbol($3);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? $1 : $3, (val2 == -9999) ? $3 : $1);
        } else {
            int result = val1 + val2;
            printf("Result = %d\n", result);
        }
    }
    | VARIABLE PLUS VARIABLE {
        int val1 = get_symbol($1);
        int val2 = get_symbol($3);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? $1 : $3, (val2 == -9999) ? $3 : $1);
        } else {
            int result = val1 + val2;
            printf("Result = %d\n", result);
        }
    }
    | NUMBER PLUS VARIABLE {
        int val2 = get_symbol($3);
        if (val2 == -9999) {
            printf("Error: Undefined variable %c.\n", $3);
        } else {
            int result = $1 + val2;
            printf("Result = %d\n", result);
        }
    }
    | VARIABLE PLUS NUMBER {
        int val1 = get_symbol($1);
        if (val1 == -9999) {
            printf("Error: Undefined variable %c.\n", $1);
        } else {
            int result = val1 + $3;
            printf("Result = %d\n", result);
        }
    }
    ;

comparison_stmt:
    WHICH IS GREATER NUMBER AND NUMBER {
        if ($4 > $6) {
            printf("Greater = %d\n", $4);
        } else {
            printf("Greater = %d\n", $6);
        }
    }
    | WHICH IS GREATER VARIABLE AND VARIABLE {
        int val1 = get_symbol($4);
        int val2 = get_symbol($6);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? $4 : $6, (val2 == -9999) ? $6 : $4);
        } else if (val1 > val2) {
            printf("%c is greater.\n", $4);
        } else {
            printf("%c is greater.\n", $6);
        }
    }
    | IF VARIABLE EQUALS NUMBER AND VARIABLE EQUALS NUMBER COMMA WHICH IS GREATER QUESTION {
        set_symbol($2, $4);
        set_symbol($6, $8);
        if ($4 > $8) {
            printf("%c is greater.\n", $2);
        } else {
            printf("%c is greater.\n", $6);
        }
    }
    | IF VARIABLE EQUALS NUMBER AND VARIABLE EQUALS NUMBER COMMA WHICH IS GREATER {
        set_symbol($2, $4);
        set_symbol($6, $8);
        if ($4 > $8) {
            printf("%c is greater.\n", $2);
        } else {
            printf("%c is greater.\n", $6);
        }
    }
    | VARIABLE IS GREATER THAN VARIABLE {
        int val1 = get_symbol($1);
        int val2 = get_symbol($5);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? $1 : $5, (val2 == -9999) ? $5 : $1);
        } else if (val1 > val2) {
            printf("%c is greater than %c.\n", $1, $5);
        } else {
            printf("%c is not greater than %c.\n", $1, $5);
        }
    }
    | WHICH IS SMALLER NUMBER AND NUMBER {
        if ($4 < $6) {
            printf("Smaller = %d\n", $4);
        } else {
            printf("Smaller = %d\n", $6);
        }
    }
    | WHICH IS SMALLER VARIABLE AND VARIABLE {
        int val1 = get_symbol($4);
        int val2 = get_symbol($6);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? $4 : $6, (val2 == -9999) ? $6 : $4);
        } else if (val1 < val2) {
            printf("%c is smaller.\n", $4);
        } else {
            printf("%c is smaller.\n", $6);
        }
    }
    | NUMBER GREATER NUMBER {
        if ($1 > $3) {
            printf("%d is greater than %d\n", $1, $3);
        } else {
            printf("%d is not greater than %d\n", $1, $3);
        }
    }
    | NUMBER GREATER THAN NUMBER {
        if ($1 > $4) {
            printf("%d is greater than %d\n", $1, $4);
        } else {
            printf("%d is not greater than %d\n", $1, $4);
        }
    }
    | NUMBER SMALLER NUMBER {
        if ($1 < $3) {
            printf("%d is smaller than %d\n", $1, $3);
        } else {
            printf("%d is not smaller than %d\n", $1, $3);
        }
    }
    | NUMBER SMALLER THAN NUMBER {
        if ($1 < $4) {
            printf("%d is smaller than %d\n", $1, $4);
        } else {
            printf("%d is not smaller than %d\n", $1, $4);
        }
    }
    | VARIABLE GREATER VARIABLE {
        int val1 = get_symbol($1);
        int val2 = get_symbol($3);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? $1 : $3, (val2 == -9999) ? $3 : $1);
        } else if (val1 > val2) {
            printf("%c is greater than %c\n", $1, $3);
        } else {
            printf("%c is not greater than %c\n", $1, $3);
        }
    }
    | VARIABLE SMALLER VARIABLE {
        int val1 = get_symbol($1);
        int val2 = get_symbol($3);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? $1 : $3, (val2 == -9999) ? $3 : $1);
        } else if (val1 < val2) {
            printf("%c is smaller than %c\n", $1, $3);
        } else {
            printf("%c is not smaller than %c\n", $1, $3);
        }
    }
    ;

reasoning_stmt:
    VARIABLE IS TALLEST THAN VARIABLE PERIOD VARIABLE IS TALLEST THAN VARIABLE PERIOD WHO IS THE TALLEST QUESTION {
        printf("%c is the tallest.\n", $1);
    }
    | VARIABLE IS TALLEST THAN VARIABLE PERIOD VARIABLE IS TALLEST THAN VARIABLE PERIOD WHICH IS THE TALLEST QUESTION {
        printf("%c is the tallest.\n", $1);
    }
    | VARIABLE IS TALLEST THAN VARIABLE PERIOD VARIABLE IS TALLEST THAN VARIABLE PERIOD WHO IS THE TALLEST {
        printf("%c is the tallest.\n", $1);
    }
    | VARIABLE IS TALLEST THAN VARIABLE PERIOD VARIABLE IS TALLEST THAN VARIABLE PERIOD WHICH IS THE TALLEST {
        printf("%c is the tallest.\n", $1);
    }
    | VARIABLE IS YOUNGEST THAN VARIABLE PERIOD VARIABLE IS YOUNGEST THAN VARIABLE PERIOD WHO IS THE YOUNGEST QUESTION {
        printf("%c is the youngest.\n", $1);
    }
    | VARIABLE IS YOUNGEST THAN VARIABLE PERIOD VARIABLE IS YOUNGEST THAN VARIABLE PERIOD WHICH IS THE YOUNGEST QUESTION {
        printf("%c is the youngest.\n", $1);
    }
    ;

expression:
    NUMBER { $$ = $1; }
    | VARIABLE { 
        int val = get_symbol($1);
        if (val == -9999) {
            printf("Error: Undefined variable %c.\n", $1);
            $$ = 0;
        } else {
            $$ = val;
        }
    }
    | expression MULT expression { 
        $$ = evaluate_arithmetic($1, '*', $3);
        printf("Step: %d * %d = %d\n", $1, $3, $$);
    }
    | expression DIV expression { 
        if ($3 == 0) {
            printf("Error: Division by zero.\n");
            $$ = 0;
        } else {
            $$ = evaluate_arithmetic($1, '/', $3);
            printf("Step: %d / %d = %d\n", $1, $3, $$);
        }
    }
    | expression PLUS expression { 
        $$ = evaluate_arithmetic($1, '+', $3);
        printf("Step: %d + %d = %d\n", $1, $3, $$);
    }
    | expression MINUS expression { 
        $$ = evaluate_arithmetic($1, '-', $3);
        printf("Step: %d - %d = %d\n", $1, $3, $$);
    }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

%%

int find_symbol(char name) {
    for (int i = 0; i < symbol_count; i++) {
        if (symbol_table[i].name == name) {
            return i;
        }
    }
    return -1;
}

void set_symbol(char name, int value) {
    int idx = find_symbol(name);
    if (idx >= 0) {
        symbol_table[idx].value = value;
    } else {
        symbol_table[symbol_count].name = name;
        symbol_table[symbol_count].value = value;
        symbol_count++;
    }
}

int get_symbol(char name) {
    int idx = find_symbol(name);
    if (idx >= 0) {
        return symbol_table[idx].value;
    }
    return -9999; // Error code for undefined variable
}

int evaluate_arithmetic(int left, char op, int right) {
    switch(op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return (right != 0) ? left / right : 0;
        default: return 0;
    }
}

void show_search_results(const char* query) {
    printf("\n==========================================\n");
    printf("Search Results for: %s\n", query);
    printf("==========================================\n\n");
    
    // Convert query to lowercase for case-insensitive search
    char query_lower[100];
    strcpy(query_lower, query);
    for (int i = 0; query_lower[i]; i++) {
        query_lower[i] = tolower(query_lower[i]);
    }
    
    // Search in examples based on query keywords
    if (strstr(query_lower, "sum") || strstr(query_lower, "add") || strstr(query_lower, "+")) {
        printf("Arithmetic - Addition:\n");
        printf("  - Find sum 5 and 3\n");
        printf("  - Find sum of X and Y\n");
        printf("  - SUM OF NUMBER AND NUMBER\n\n");
    }
    if (strstr(query_lower, "multiply") || strstr(query_lower, "times") || strstr(query_lower, "*")) {
        printf("Arithmetic - Multiplication:\n");
        printf("  - Calculate 8 times 2\n");
        printf("  - 5 multiply 3\n");
        printf("  - Multiply 5 and 3\n\n");
    }
    if (strstr(query_lower, "greater") || strstr(query_lower, "compare") || strstr(query_lower, ">")) {
        printf("Comparison - Greater Than:\n");
        printf("  - Which is greater 10 and 7\n");
        printf("  - 10 greater 7\n");
        printf("  - x greater y\n\n");
    }
    if (strstr(query_lower, "variable") || strstr(query_lower, "let") || strstr(query_lower, "=")) {
        printf("Variable Assignment:\n");
        printf("  - Let X = 5.\n");
        printf("  - x equals 5\n");
        printf("  - x = 5\n\n");
    }
    if (strstr(query_lower, "tallest") || strstr(query_lower, "reasoning") || strstr(query_lower, "taller")) {
        printf("Reasoning Problems:\n");
        printf("  - A is taller than B. B is taller than C. Who is the tallest?\n");
        printf("  - VARIABLE IS TALLEST THAN VARIABLE\n\n");
    }
    if (strstr(query_lower, "calculate") || strstr(query_lower, "compute")) {
        printf("Calculate Expressions:\n");
        printf("  - Calculate X + Y * 2.\n");
        printf("  - Calculate 5 + 3 * 2\n");
        printf("  - CALCULATE expression\n\n");
    }
    
    printf("==========================================\n\n");
}

void show_all_examples() {
    printf("\n==========================================\n");
    printf("AMCI - Available Commands & Examples\n");
    printf("==========================================\n\n");
    
    printf("1. GREETINGS:\n");
    printf("   - Hello\n");
    printf("   - Hi\n");
    printf("   - Hey\n\n");
    
    printf("2. ARITHMETIC OPERATIONS:\n");
    printf("   Simple: 5 sum 99, 10 plus 5, 5 multiply 3\n");
    printf("   Natural: Find sum 5 and 3, Calculate 8 times 2\n");
    printf("   Expressions: Calculate X + Y * 2\n\n");
    
    printf("3. VARIABLE ASSIGNMENT:\n");
    printf("   - x equals 5 (or x = 5)\n");
    printf("   - Let X = 5.\n");
    printf("   - Variables persist across commands\n\n");
    
    printf("4. COMPARISONS:\n");
    printf("   - 10 greater 7\n");
    printf("   - Which is greater 10 and 7\n");
    printf("   - x greater y\n");
    printf("   - If A = 5 and B = 8, which is greater?\n\n");
    
    printf("5. REASONING PROBLEMS:\n");
    printf("   - A is taller than B. B is taller than C. Who is the tallest?\n");
    printf("   - VARIABLE IS TALLEST THAN VARIABLE\n\n");
    
    printf("6. SEARCH/HELP:\n");
    printf("   - Search (shows all examples)\n");
    printf("   - Help (shows all examples)\n");
    printf("   - Search sum (shows sum examples)\n");
    printf("   - Search multiply (shows multiply examples)\n\n");
    
    printf("7. EXIT:\n");
    printf("   - Bye\n");
    printf("   - Goodbye\n");
    printf("   - Exit\n\n");
    
    printf("==========================================\n");
    printf("Tip: Use 'Search <keyword>' to find specific examples\n");
    printf("==========================================\n\n");
}

int main(int argc, char* argv[]) {
    // Initialize symbol table
    for (int i = 0; i < 26; i++) {
        symbol_table[i].name = '\0';
        symbol_table[i].value = 0;
    }
    
    // Set up signal handler for Ctrl+C
    signal(SIGINT, signal_handler);
    
    // Set line buffering for stdout to ensure output appears after Enter
    setvbuf(stdout, NULL, _IOLBF, 0);
    setvbuf(stdin, NULL, _IOLBF, 0);
    
    if (argc > 1) {
        // File mode - process file and exit
        FILE* file = fopen(argv[1], "r");
        if (file) {
            yyin = file;
            interactive_mode = 0;
        } else {
            fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyparse();
        fclose(yyin);
    } else {
        // Interactive mode - continuous conversation
        interactive_mode = 1;
        printf("==========================================\n");
        printf("AMCI - Advanced Mini Chatbot Interpreter\n");
        printf("==========================================\n");
        printf("Enter problem statements (Press Ctrl+C to exit):\n");
        printf("Examples:\n");
        printf("  - Hello\n");
        printf("  - Find sum 5 and 3\n");
        printf("  - Calculate 8 times 2\n");
        printf("  - Let X = 5.\n");
        printf("  - Calculate X + Y * 2.\n");
        printf("  - Search (to see all commands)\n");
        printf("==========================================\n");
        printf("Note: Conversation will continue until Ctrl+C\n");
        printf("==========================================\n\n");
        
        // Continuous loop for conversation
        while (!should_exit) {
            yyin = stdin;
            
            // Show prompt before input
            printf("> ");
            fflush(stdout);
            
            // Parse one statement at a time (waits for Enter)
            int result = yyparse();
            
            // Flush output after parsing to ensure results are shown
            fflush(stdout);
            
            // If parse fails or EOF, continue
            if (result != 0 && !feof(stdin)) {
                // Clear input buffer
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
            
            // Check for EOF (Ctrl+D)
            if (feof(stdin)) {
                printf("\nEOF detected. Exiting...\n");
                break;
            }
            
            // Result shown, loop continues and shows prompt again
        }
    }
    
    return 0;
}
