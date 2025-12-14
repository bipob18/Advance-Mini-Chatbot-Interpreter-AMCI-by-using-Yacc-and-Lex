%{
/*
 * AMCI Lexical Analyzer (scanner.l)
 * 
 * This file defines the lexical rules for tokenizing input.
 * It recognizes keywords, operators, variables, and numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "grammar.tab.h"

extern int yylval;
extern char* yytext;

int line_num = 1;
%}

%option noyywrap
%option case-insensitive

%%

"hello"|"hi"|"hey"                    { return GREETING; }
"bye"|"goodbye"|"exit"                { return FAREWELL; }
"search"|"help"|"show"|"examples"      { return SEARCH; }

"let"                                  { return LET; }
"calculate"|"compute"                  { return CALCULATE; }
"find"                                  { return FIND; }
"sum"|"add"|"plus"|"addition"          { return SUM; }
"difference"|"subtract"|"minus"        { return DIFFERENCE; }
"multiply"|"product"                   { return MULTIPLY; }
"times"                                 { return TIMES; }
"divide"|"division"                    { return DIVIDE; }
"of"                                   { return OF; }
"and"                                  { return AND; }
"or"                                   { return OR; }
"which"|"who"                          { return WHICH; }
"is"|"are"                             { return IS; }
"greater"|"larger"|"bigger"            { return GREATER; }
"smaller"|"less"|"shorter"             { return SMALLER; }
"tallest"|"taller"                     { return TALLEST; }
"youngest"|"younger"                   { return YOUNGEST; }
"the"                                  { return THE; }
"than"                                 { return THAN; }
"if"                                   { return IF; }
"equals"|"equal"|"="                   { return EQUALS; }

[A-Za-z]                               { yylval = toupper(yytext[0]); return VARIABLE; }
[0-9]+                                 { yylval = atoi(yytext); return NUMBER; }
[0-9]+\.[0-9]+                         { yylval = (int)(atof(yytext) * 1000); return NUMBER; }

"+"                                    { return PLUS; }
"-"                                    { return MINUS; }
"*"                                    { return MULT; }
"/"                                    { return DIV; }
"("                                    { return LPAREN; }
")"                                    { return RPAREN; }
"."                                    { return PERIOD; }
"?"                                    { return QUESTION; }
","                                    { return COMMA; }

[ \t]+                                 { /* ignore whitespace */ }
\n                                     { line_num++; return NEWLINE; }
.                                      { return yytext[0]; }

%%
