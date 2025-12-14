/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

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


#line 124 "grammar.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "grammar.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_GREETING = 3,                   /* GREETING  */
  YYSYMBOL_FAREWELL = 4,                   /* FAREWELL  */
  YYSYMBOL_SEARCH = 5,                     /* SEARCH  */
  YYSYMBOL_LET = 6,                        /* LET  */
  YYSYMBOL_CALCULATE = 7,                  /* CALCULATE  */
  YYSYMBOL_FIND = 8,                       /* FIND  */
  YYSYMBOL_SUM = 9,                        /* SUM  */
  YYSYMBOL_DIFFERENCE = 10,                /* DIFFERENCE  */
  YYSYMBOL_MULTIPLY = 11,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 12,                    /* DIVIDE  */
  YYSYMBOL_OF = 13,                        /* OF  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_WHICH = 16,                     /* WHICH  */
  YYSYMBOL_WHO = 17,                       /* WHO  */
  YYSYMBOL_IS = 18,                        /* IS  */
  YYSYMBOL_THE = 19,                       /* THE  */
  YYSYMBOL_THAN = 20,                      /* THAN  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_EQUALS = 22,                    /* EQUALS  */
  YYSYMBOL_GREATER = 23,                   /* GREATER  */
  YYSYMBOL_SMALLER = 24,                   /* SMALLER  */
  YYSYMBOL_TALLEST = 25,                   /* TALLEST  */
  YYSYMBOL_YOUNGEST = 26,                  /* YOUNGEST  */
  YYSYMBOL_VARIABLE = 27,                  /* VARIABLE  */
  YYSYMBOL_NUMBER = 28,                    /* NUMBER  */
  YYSYMBOL_PLUS = 29,                      /* PLUS  */
  YYSYMBOL_MINUS = 30,                     /* MINUS  */
  YYSYMBOL_MULT = 31,                      /* MULT  */
  YYSYMBOL_DIV = 32,                       /* DIV  */
  YYSYMBOL_TIMES = 33,                     /* TIMES  */
  YYSYMBOL_LPAREN = 34,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 35,                    /* RPAREN  */
  YYSYMBOL_PERIOD = 36,                    /* PERIOD  */
  YYSYMBOL_QUESTION = 37,                  /* QUESTION  */
  YYSYMBOL_COMMA = 38,                     /* COMMA  */
  YYSYMBOL_NEWLINE = 39,                   /* NEWLINE  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_input = 41,                     /* input  */
  YYSYMBOL_statement = 42,                 /* statement  */
  YYSYMBOL_greeting_stmt = 43,             /* greeting_stmt  */
  YYSYMBOL_farewell_stmt = 44,             /* farewell_stmt  */
  YYSYMBOL_search_stmt = 45,               /* search_stmt  */
  YYSYMBOL_assignment_stmt = 46,           /* assignment_stmt  */
  YYSYMBOL_arithmetic_stmt = 47,           /* arithmetic_stmt  */
  YYSYMBOL_comparison_stmt = 48,           /* comparison_stmt  */
  YYSYMBOL_reasoning_stmt = 49,            /* reasoning_stmt  */
  YYSYMBOL_expression = 50                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    68,    69,    70,    74,    75,    76,    77,
      78,    79,    80,    84,    92,   103,   106,   109,   112,   115,
     120,   125,   128,   131,   137,   141,   146,   150,   154,   159,
     167,   170,   173,   177,   181,   192,   196,   200,   205,   210,
     222,   232,   242,   246,   250,   253,   257,   261,   265,   273,
     284,   295,   304,   316,   323,   335,   344,   353,   365,   372,
     384,   391,   398,   405,   412,   424,   439,   442,   445,   448,
     451,   454,   460,   461,   470,   474,   483,   487,   491
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "GREETING", "FAREWELL",
  "SEARCH", "LET", "CALCULATE", "FIND", "SUM", "DIFFERENCE", "MULTIPLY",
  "DIVIDE", "OF", "AND", "OR", "WHICH", "WHO", "IS", "THE", "THAN", "IF",
  "EQUALS", "GREATER", "SMALLER", "TALLEST", "YOUNGEST", "VARIABLE",
  "NUMBER", "PLUS", "MINUS", "MULT", "DIV", "TIMES", "LPAREN", "RPAREN",
  "PERIOD", "QUESTION", "COMMA", "NEWLINE", "$accept", "input",
  "statement", "greeting_stmt", "farewell_stmt", "search_stmt",
  "assignment_stmt", "arithmetic_stmt", "comparison_stmt",
  "reasoning_stmt", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      37,   -34,   -34,    63,   -26,    29,    -6,    -8,   -15,    19,
      24,    71,    38,    11,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
      51,   -34,    48,    32,    46,    -7,   -20,    65,    10,    70,
      58,     0,    74,    60,   110,     8,   111,   112,   113,   114,
     -18,   -16,    27,   115,   116,   -34,   -34,    82,   118,   -34,
      91,    32,    32,    32,    32,   -34,    56,   124,   131,   133,
     120,    90,    97,   121,   -34,   130,   132,   134,    67,    75,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   123,   -34,
     125,   -34,   -34,   -34,   -34,   -34,   122,    83,   -34,   -34,
      96,    96,   -34,   -34,   141,   142,   129,   102,   104,   -34,
     145,   146,   147,   148,   149,   137,   138,   139,   -34,   -34,
     -34,   -34,   -34,   -34,   140,   143,   -34,   -34,   -34,   -34,
     -34,   150,   144,   151,   152,   154,   -34,   153,   155,   -34,
     -34,   -34,   -34,   -34,   -34,   157,   156,   158,   159,   164,
     166,   135,   161,   162,   160,   170,   172,   175,   167,   168,
     173,   163,   165,   169,   117,   119,   -34,   179,   180,   182,
     184,   185,   186,   188,   189,   178,   187,   183,   190,   174,
     176,   177,   181,   -34,   -34,   -34,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     6,     7,     8,     9,    10,
      11,    12,    23,    21,    16,    17,    18,    22,    19,    20,
       0,    73,    72,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     3,     0,     0,    72,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,    26,    28,
      64,    65,    50,    52,    42,    46,    48,    45,     0,    60,
       0,    62,    51,    43,    47,    36,    72,     0,    35,    78,
      76,    77,    74,    75,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    29,
      61,    63,    24,    25,     0,     0,    32,    39,    41,    40,
      38,     0,     0,     0,     0,     0,    57,     0,     0,    34,
      33,    54,    53,    59,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      68,     0,     0,    67,    66,    71,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -34,   -34,   197,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
     -33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    30,    88,    35,    90,    36,    66,    68,    69,    79,
      89,    55,    91,    37,     1,     2,     3,     4,     5,     6,
       7,    67,     8,    75,    97,    76,    77,     9,   100,   101,
     102,   103,    10,    71,    72,    82,    83,    38,    11,    12,
       1,     2,     3,     4,     5,     6,     7,    46,     8,    47,
      48,    39,    49,     9,    92,    93,    31,    32,    10,    31,
      59,    50,    51,    33,    11,    12,    33,    52,    53,    22,
      23,    54,    24,    57,    25,    61,    62,    63,    64,    70,
      40,    58,    65,   104,   105,    74,    26,    80,    27,    41,
      28,    29,    73,    42,    43,    44,   -72,   -72,   -72,   -72,
      45,    31,    78,   118,    61,    62,    63,    64,    33,    31,
      96,   119,    61,    62,    63,    64,    33,   110,   111,   123,
      61,    62,    63,    64,   112,   113,    99,    63,    64,   127,
     128,   129,   130,   167,   168,   169,   170,    81,   106,    84,
      85,    86,    87,    94,    95,   107,    98,   108,   109,   114,
     115,   120,   116,   121,   117,   124,   125,   126,   122,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,   140,   142,   154,     0,     0,   157,   141,   143,   148,
     144,   145,   152,   149,   153,   150,   155,   151,   156,   146,
     158,   147,   159,   160,   161,   162,   163,   171,   172,   164,
     173,   165,   174,   179,   175,   176,   166,   177,   178,   181,
      56,   183,   180,   184,   185,     0,   182,     0,   186
};

static const yytype_int8 yycheck[] =
{
      33,    27,    20,     9,    20,    13,    13,    27,    28,    42,
      28,     0,    28,    28,     3,     4,     5,     6,     7,     8,
       9,    28,    11,    23,    57,    25,    26,    16,    61,    62,
      63,    64,    21,    23,    24,    27,    28,    18,    27,    28,
       3,     4,     5,     6,     7,     8,     9,     9,    11,    11,
      12,    27,    14,    16,    27,    28,    27,    28,    21,    27,
      28,    23,    24,    34,    27,    28,    34,    29,    30,     6,
       7,    33,     9,    22,    11,    29,    30,    31,    32,    14,
       9,    33,    36,    27,    28,    27,    23,    27,    25,    18,
      27,    28,    22,    22,    23,    24,    29,    30,    31,    32,
      29,    27,    28,    36,    29,    30,    31,    32,    34,    27,
      28,    36,    29,    30,    31,    32,    34,    27,    28,    36,
      29,    30,    31,    32,    27,    28,    35,    31,    32,    27,
      28,    27,    28,    16,    17,    16,    17,    27,    14,    28,
      28,    28,    28,    28,    28,    14,    28,    14,    28,    28,
      20,    28,    20,    28,    20,    14,    14,    28,    36,    14,
      14,    14,    14,    14,    27,    27,    27,    27,    -1,    -1,
      -1,    28,    28,    38,    -1,    -1,    16,    27,    27,    22,
      28,    27,    18,    27,    18,    27,    25,    28,    26,    36,
      20,    36,    20,    18,    27,    27,    23,    18,    18,    36,
      18,    36,    18,    25,    19,    19,    37,    19,    19,    26,
      13,    37,    25,    37,    37,    -1,    26,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    11,    16,
      21,    27,    28,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     6,     7,     9,    11,    23,    25,    27,    28,
      27,    27,    28,    34,    50,     9,    13,    28,    18,    27,
       9,    18,    22,    23,    24,    29,     9,    11,    12,    14,
      23,    24,    29,    30,    33,     0,    42,    22,    33,    28,
      50,    29,    30,    31,    32,    36,    13,    28,    27,    28,
      14,    23,    24,    22,    27,    23,    25,    26,    28,    50,
      27,    27,    27,    28,    28,    28,    28,    28,    20,    28,
      20,    28,    27,    28,    28,    28,    28,    50,    28,    35,
      50,    50,    50,    50,    27,    28,    14,    14,    14,    28,
      27,    28,    27,    28,    28,    20,    20,    20,    36,    36,
      28,    28,    36,    36,    14,    14,    28,    27,    28,    27,
      28,    14,    14,    14,    14,    14,    27,    27,    27,    27,
      28,    27,    28,    27,    28,    27,    36,    36,    22,    27,
      27,    28,    18,    18,    38,    25,    26,    16,    20,    20,
      18,    27,    27,    23,    36,    36,    37,    16,    17,    16,
      17,    18,    18,    18,    18,    19,    19,    19,    19,    25,
      25,    26,    26,    37,    37,    37,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    41,    41,    42,    42,    42,    42,
      42,    42,    42,    43,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    46,    46,    46,    46,    46,    46,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    49,    49,    49,    49,
      49,    49,    50,    50,    50,    50,    50,    50,    50
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     5,     5,     3,     4,     3,     4,
       3,     2,     5,     6,     6,     4,     3,     4,     5,     5,
       5,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     6,     6,    13,    12,     5,     6,     6,
       3,     4,     3,     4,     3,     3,    17,    17,    16,    16,
      17,    17,     1,     1,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 13: /* greeting_stmt: GREETING  */
#line 84 "grammar.y"
             {
        printf("Hi! I can solve arithmetic, logical, and reasoning problems.\n");
        printf("Type 'Search' or 'Help' to see all available commands and examples.\n");
        fflush(stdout);
    }
#line 1281 "grammar.tab.c"
    break;

  case 14: /* farewell_stmt: FAREWELL  */
#line 92 "grammar.y"
             {
        if (interactive_mode) {
            printf("Goodbye! (Type 'Hello' to continue or Ctrl+C to exit)\n");
        } else {
            printf("Goodbye!\n");
            exit(0);
        }
    }
#line 1294 "grammar.tab.c"
    break;

  case 15: /* search_stmt: SEARCH  */
#line 103 "grammar.y"
           {
        show_all_examples();
    }
#line 1302 "grammar.tab.c"
    break;

  case 16: /* search_stmt: SEARCH SUM  */
#line 106 "grammar.y"
                 {
        show_search_results("sum");
    }
#line 1310 "grammar.tab.c"
    break;

  case 17: /* search_stmt: SEARCH MULTIPLY  */
#line 109 "grammar.y"
                      {
        show_search_results("multiply");
    }
#line 1318 "grammar.tab.c"
    break;

  case 18: /* search_stmt: SEARCH GREATER  */
#line 112 "grammar.y"
                     {
        show_search_results("greater");
    }
#line 1326 "grammar.tab.c"
    break;

  case 19: /* search_stmt: SEARCH VARIABLE  */
#line 115 "grammar.y"
                      {
        char query = yyvsp[0];
        char query_str[2] = {query, '\0'};
        show_search_results(query_str);
    }
#line 1336 "grammar.tab.c"
    break;

  case 20: /* search_stmt: SEARCH NUMBER  */
#line 120 "grammar.y"
                    {
        char query_str[20];
        sprintf(query_str, "%d", yyvsp[0]);
        show_search_results(query_str);
    }
#line 1346 "grammar.tab.c"
    break;

  case 21: /* search_stmt: SEARCH CALCULATE  */
#line 125 "grammar.y"
                       {
        show_search_results("calculate");
    }
#line 1354 "grammar.tab.c"
    break;

  case 22: /* search_stmt: SEARCH TALLEST  */
#line 128 "grammar.y"
                     {
        show_search_results("tallest");
    }
#line 1362 "grammar.tab.c"
    break;

  case 23: /* search_stmt: SEARCH LET  */
#line 131 "grammar.y"
                 {
        show_search_results("variable");
    }
#line 1370 "grammar.tab.c"
    break;

  case 24: /* assignment_stmt: LET VARIABLE EQUALS NUMBER PERIOD  */
#line 137 "grammar.y"
                                      {
        set_symbol(yyvsp[-3], yyvsp[-1]);
        printf("Variable %c = %d\n", yyvsp[-3], yyvsp[-1]);
    }
#line 1379 "grammar.tab.c"
    break;

  case 25: /* assignment_stmt: LET VARIABLE EQUALS expression PERIOD  */
#line 141 "grammar.y"
                                            {
        int val = yyvsp[-1];
        set_symbol(yyvsp[-3], val);
        printf("Variable %c = %d\n", yyvsp[-3], val);
    }
#line 1389 "grammar.tab.c"
    break;

  case 26: /* assignment_stmt: VARIABLE EQUALS NUMBER  */
#line 146 "grammar.y"
                             {
        set_symbol(yyvsp[-2], yyvsp[0]);
        printf("Variable %c = %d\n", yyvsp[-2], yyvsp[0]);
    }
#line 1398 "grammar.tab.c"
    break;

  case 27: /* assignment_stmt: VARIABLE EQUALS NUMBER PERIOD  */
#line 150 "grammar.y"
                                    {
        set_symbol(yyvsp[-3], yyvsp[-1]);
        printf("Variable %c = %d\n", yyvsp[-3], yyvsp[-1]);
    }
#line 1407 "grammar.tab.c"
    break;

  case 28: /* assignment_stmt: VARIABLE EQUALS expression  */
#line 154 "grammar.y"
                                 {
        int val = yyvsp[0];
        set_symbol(yyvsp[-2], val);
        printf("Variable %c = %d\n", yyvsp[-2], val);
    }
#line 1417 "grammar.tab.c"
    break;

  case 29: /* assignment_stmt: VARIABLE EQUALS expression PERIOD  */
#line 159 "grammar.y"
                                        {
        int val = yyvsp[-1];
        set_symbol(yyvsp[-3], val);
        printf("Variable %c = %d\n", yyvsp[-3], val);
    }
#line 1427 "grammar.tab.c"
    break;

  case 30: /* arithmetic_stmt: CALCULATE expression PERIOD  */
#line 167 "grammar.y"
                                {
        printf("Result = %d\n", yyvsp[-1]);
    }
#line 1435 "grammar.tab.c"
    break;

  case 31: /* arithmetic_stmt: CALCULATE expression  */
#line 170 "grammar.y"
                           {
        printf("Result = %d\n", yyvsp[0]);
    }
#line 1443 "grammar.tab.c"
    break;

  case 32: /* arithmetic_stmt: FIND SUM NUMBER AND NUMBER  */
#line 173 "grammar.y"
                                 {
        int result = yyvsp[-2] + yyvsp[0];
        printf("Result = %d\n", result);
    }
#line 1452 "grammar.tab.c"
    break;

  case 33: /* arithmetic_stmt: FIND SUM OF NUMBER AND NUMBER  */
#line 177 "grammar.y"
                                    {
        int result = yyvsp[-2] + yyvsp[0];
        printf("Result = %d\n", result);
    }
#line 1461 "grammar.tab.c"
    break;

  case 34: /* arithmetic_stmt: FIND SUM OF VARIABLE AND VARIABLE  */
#line 181 "grammar.y"
                                        {
        int val1 = get_symbol(yyvsp[-2]);
        int val2 = get_symbol(yyvsp[0]);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? yyvsp[-2] : yyvsp[0], (val2 == -9999) ? yyvsp[0] : yyvsp[-2]);
        } else {
            int result = val1 + val2;
            printf("Result = %d\n", result);
        }
    }
#line 1477 "grammar.tab.c"
    break;

  case 35: /* arithmetic_stmt: CALCULATE NUMBER TIMES NUMBER  */
#line 192 "grammar.y"
                                    {
        int result = yyvsp[-2] * yyvsp[0];
        printf("Result = %d\n", result);
    }
#line 1486 "grammar.tab.c"
    break;

  case 36: /* arithmetic_stmt: NUMBER TIMES NUMBER  */
#line 196 "grammar.y"
                          {
        int result = yyvsp[-2] * yyvsp[0];
        printf("Result = %d\n", result);
    }
#line 1495 "grammar.tab.c"
    break;

  case 37: /* arithmetic_stmt: MULTIPLY NUMBER AND NUMBER  */
#line 200 "grammar.y"
                                 {
        int result = yyvsp[-2] * yyvsp[0];
        printf("Step 1: Multiply %d * %d = %d\n", yyvsp[-2], yyvsp[0], result);
        printf("Result = %d\n", result);
    }
#line 1505 "grammar.tab.c"
    break;

  case 38: /* arithmetic_stmt: SUM OF NUMBER AND NUMBER  */
#line 205 "grammar.y"
                               {
        int result = yyvsp[-2] + yyvsp[0];
        printf("Step 1: Add %d + %d = %d\n", yyvsp[-2], yyvsp[0], result);
        printf("Result = %d\n", result);
    }
#line 1515 "grammar.tab.c"
    break;

  case 39: /* arithmetic_stmt: SUM OF VARIABLE AND VARIABLE  */
#line 210 "grammar.y"
                                   {
        int val1 = get_symbol(yyvsp[-2]);
        int val2 = get_symbol(yyvsp[0]);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? yyvsp[-2] : yyvsp[0], (val2 == -9999) ? yyvsp[0] : yyvsp[-2]);
        } else {
            int result = val1 + val2;
            printf("Step 1: Add %c (%d) + %c (%d) = %d\n", yyvsp[-2], val1, yyvsp[0], val2, result);
            printf("Result = %d\n", result);
        }
    }
#line 1532 "grammar.tab.c"
    break;

  case 40: /* arithmetic_stmt: SUM OF NUMBER AND VARIABLE  */
#line 222 "grammar.y"
                                 {
        int val2 = get_symbol(yyvsp[0]);
        if (val2 == -9999) {
            printf("Error: Undefined variable %c.\n", yyvsp[0]);
        } else {
            int result = yyvsp[-2] + val2;
            printf("Step 1: Add %d + %c (%d) = %d\n", yyvsp[-2], yyvsp[0], val2, result);
            printf("Result = %d\n", result);
        }
    }
#line 1547 "grammar.tab.c"
    break;

  case 41: /* arithmetic_stmt: SUM OF VARIABLE AND NUMBER  */
#line 232 "grammar.y"
                                 {
        int val1 = get_symbol(yyvsp[-2]);
        if (val1 == -9999) {
            printf("Error: Undefined variable %c.\n", yyvsp[-2]);
        } else {
            int result = val1 + yyvsp[0];
            printf("Step 1: Add %c (%d) + %d = %d\n", yyvsp[-2], val1, yyvsp[0], result);
            printf("Result = %d\n", result);
        }
    }
#line 1562 "grammar.tab.c"
    break;

  case 42: /* arithmetic_stmt: NUMBER SUM NUMBER  */
#line 242 "grammar.y"
                        {
        int result = yyvsp[-2] + yyvsp[0];
        printf("Result = %d\n", result);
    }
#line 1571 "grammar.tab.c"
    break;

  case 43: /* arithmetic_stmt: NUMBER PLUS NUMBER  */
#line 246 "grammar.y"
                         {
        int result = yyvsp[-2] + yyvsp[0];
        printf("Result = %d\n", result);
    }
#line 1580 "grammar.tab.c"
    break;

  case 44: /* arithmetic_stmt: NUMBER SUM NUMBER  */
#line 250 "grammar.y"
                        {
        // Already handled above, but keeping for clarity
    }
#line 1588 "grammar.tab.c"
    break;

  case 45: /* arithmetic_stmt: NUMBER AND NUMBER  */
#line 253 "grammar.y"
                        {
        int result = yyvsp[-2] + yyvsp[0];
        printf("Result = %d\n", result);
    }
#line 1597 "grammar.tab.c"
    break;

  case 46: /* arithmetic_stmt: NUMBER MULTIPLY NUMBER  */
#line 257 "grammar.y"
                             {
        int result = yyvsp[-2] * yyvsp[0];
        printf("Result = %d\n", result);
    }
#line 1606 "grammar.tab.c"
    break;

  case 47: /* arithmetic_stmt: NUMBER MINUS NUMBER  */
#line 261 "grammar.y"
                          {
        int result = yyvsp[-2] - yyvsp[0];
        printf("Result = %d\n", result);
    }
#line 1615 "grammar.tab.c"
    break;

  case 48: /* arithmetic_stmt: NUMBER DIVIDE NUMBER  */
#line 265 "grammar.y"
                           {
        if (yyvsp[0] == 0) {
            printf("Error: Division by zero.\n");
        } else {
            int result = yyvsp[-2] / yyvsp[0];
            printf("Result = %d\n", result);
        }
    }
#line 1628 "grammar.tab.c"
    break;

  case 49: /* arithmetic_stmt: VARIABLE SUM VARIABLE  */
#line 273 "grammar.y"
                            {
        int val1 = get_symbol(yyvsp[-2]);
        int val2 = get_symbol(yyvsp[0]);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? yyvsp[-2] : yyvsp[0], (val2 == -9999) ? yyvsp[0] : yyvsp[-2]);
        } else {
            int result = val1 + val2;
            printf("Result = %d\n", result);
        }
    }
#line 1644 "grammar.tab.c"
    break;

  case 50: /* arithmetic_stmt: VARIABLE PLUS VARIABLE  */
#line 284 "grammar.y"
                             {
        int val1 = get_symbol(yyvsp[-2]);
        int val2 = get_symbol(yyvsp[0]);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? yyvsp[-2] : yyvsp[0], (val2 == -9999) ? yyvsp[0] : yyvsp[-2]);
        } else {
            int result = val1 + val2;
            printf("Result = %d\n", result);
        }
    }
#line 1660 "grammar.tab.c"
    break;

  case 51: /* arithmetic_stmt: NUMBER PLUS VARIABLE  */
#line 295 "grammar.y"
                           {
        int val2 = get_symbol(yyvsp[0]);
        if (val2 == -9999) {
            printf("Error: Undefined variable %c.\n", yyvsp[0]);
        } else {
            int result = yyvsp[-2] + val2;
            printf("Result = %d\n", result);
        }
    }
#line 1674 "grammar.tab.c"
    break;

  case 52: /* arithmetic_stmt: VARIABLE PLUS NUMBER  */
#line 304 "grammar.y"
                           {
        int val1 = get_symbol(yyvsp[-2]);
        if (val1 == -9999) {
            printf("Error: Undefined variable %c.\n", yyvsp[-2]);
        } else {
            int result = val1 + yyvsp[0];
            printf("Result = %d\n", result);
        }
    }
#line 1688 "grammar.tab.c"
    break;

  case 53: /* comparison_stmt: WHICH IS GREATER NUMBER AND NUMBER  */
#line 316 "grammar.y"
                                       {
        if (yyvsp[-2] > yyvsp[0]) {
            printf("Greater = %d\n", yyvsp[-2]);
        } else {
            printf("Greater = %d\n", yyvsp[0]);
        }
    }
#line 1700 "grammar.tab.c"
    break;

  case 54: /* comparison_stmt: WHICH IS GREATER VARIABLE AND VARIABLE  */
#line 323 "grammar.y"
                                             {
        int val1 = get_symbol(yyvsp[-2]);
        int val2 = get_symbol(yyvsp[0]);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? yyvsp[-2] : yyvsp[0], (val2 == -9999) ? yyvsp[0] : yyvsp[-2]);
        } else if (val1 > val2) {
            printf("%c is greater.\n", yyvsp[-2]);
        } else {
            printf("%c is greater.\n", yyvsp[0]);
        }
    }
#line 1717 "grammar.tab.c"
    break;

  case 55: /* comparison_stmt: IF VARIABLE EQUALS NUMBER AND VARIABLE EQUALS NUMBER COMMA WHICH IS GREATER QUESTION  */
#line 335 "grammar.y"
                                                                                           {
        set_symbol(yyvsp[-11], yyvsp[-9]);
        set_symbol(yyvsp[-7], yyvsp[-5]);
        if (yyvsp[-9] > yyvsp[-5]) {
            printf("%c is greater.\n", yyvsp[-11]);
        } else {
            printf("%c is greater.\n", yyvsp[-7]);
        }
    }
#line 1731 "grammar.tab.c"
    break;

  case 56: /* comparison_stmt: IF VARIABLE EQUALS NUMBER AND VARIABLE EQUALS NUMBER COMMA WHICH IS GREATER  */
#line 344 "grammar.y"
                                                                                  {
        set_symbol(yyvsp[-10], yyvsp[-8]);
        set_symbol(yyvsp[-6], yyvsp[-4]);
        if (yyvsp[-8] > yyvsp[-4]) {
            printf("%c is greater.\n", yyvsp[-10]);
        } else {
            printf("%c is greater.\n", yyvsp[-6]);
        }
    }
#line 1745 "grammar.tab.c"
    break;

  case 57: /* comparison_stmt: VARIABLE IS GREATER THAN VARIABLE  */
#line 353 "grammar.y"
                                        {
        int val1 = get_symbol(yyvsp[-4]);
        int val2 = get_symbol(yyvsp[0]);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? yyvsp[-4] : yyvsp[0], (val2 == -9999) ? yyvsp[0] : yyvsp[-4]);
        } else if (val1 > val2) {
            printf("%c is greater than %c.\n", yyvsp[-4], yyvsp[0]);
        } else {
            printf("%c is not greater than %c.\n", yyvsp[-4], yyvsp[0]);
        }
    }
#line 1762 "grammar.tab.c"
    break;

  case 58: /* comparison_stmt: WHICH IS SMALLER NUMBER AND NUMBER  */
#line 365 "grammar.y"
                                         {
        if (yyvsp[-2] < yyvsp[0]) {
            printf("Smaller = %d\n", yyvsp[-2]);
        } else {
            printf("Smaller = %d\n", yyvsp[0]);
        }
    }
#line 1774 "grammar.tab.c"
    break;

  case 59: /* comparison_stmt: WHICH IS SMALLER VARIABLE AND VARIABLE  */
#line 372 "grammar.y"
                                             {
        int val1 = get_symbol(yyvsp[-2]);
        int val2 = get_symbol(yyvsp[0]);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? yyvsp[-2] : yyvsp[0], (val2 == -9999) ? yyvsp[0] : yyvsp[-2]);
        } else if (val1 < val2) {
            printf("%c is smaller.\n", yyvsp[-2]);
        } else {
            printf("%c is smaller.\n", yyvsp[0]);
        }
    }
#line 1791 "grammar.tab.c"
    break;

  case 60: /* comparison_stmt: NUMBER GREATER NUMBER  */
#line 384 "grammar.y"
                            {
        if (yyvsp[-2] > yyvsp[0]) {
            printf("%d is greater than %d\n", yyvsp[-2], yyvsp[0]);
        } else {
            printf("%d is not greater than %d\n", yyvsp[-2], yyvsp[0]);
        }
    }
#line 1803 "grammar.tab.c"
    break;

  case 61: /* comparison_stmt: NUMBER GREATER THAN NUMBER  */
#line 391 "grammar.y"
                                 {
        if (yyvsp[-3] > yyvsp[0]) {
            printf("%d is greater than %d\n", yyvsp[-3], yyvsp[0]);
        } else {
            printf("%d is not greater than %d\n", yyvsp[-3], yyvsp[0]);
        }
    }
#line 1815 "grammar.tab.c"
    break;

  case 62: /* comparison_stmt: NUMBER SMALLER NUMBER  */
#line 398 "grammar.y"
                            {
        if (yyvsp[-2] < yyvsp[0]) {
            printf("%d is smaller than %d\n", yyvsp[-2], yyvsp[0]);
        } else {
            printf("%d is not smaller than %d\n", yyvsp[-2], yyvsp[0]);
        }
    }
#line 1827 "grammar.tab.c"
    break;

  case 63: /* comparison_stmt: NUMBER SMALLER THAN NUMBER  */
#line 405 "grammar.y"
                                 {
        if (yyvsp[-3] < yyvsp[0]) {
            printf("%d is smaller than %d\n", yyvsp[-3], yyvsp[0]);
        } else {
            printf("%d is not smaller than %d\n", yyvsp[-3], yyvsp[0]);
        }
    }
#line 1839 "grammar.tab.c"
    break;

  case 64: /* comparison_stmt: VARIABLE GREATER VARIABLE  */
#line 412 "grammar.y"
                                {
        int val1 = get_symbol(yyvsp[-2]);
        int val2 = get_symbol(yyvsp[0]);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? yyvsp[-2] : yyvsp[0], (val2 == -9999) ? yyvsp[0] : yyvsp[-2]);
        } else if (val1 > val2) {
            printf("%c is greater than %c\n", yyvsp[-2], yyvsp[0]);
        } else {
            printf("%c is not greater than %c\n", yyvsp[-2], yyvsp[0]);
        }
    }
#line 1856 "grammar.tab.c"
    break;

  case 65: /* comparison_stmt: VARIABLE SMALLER VARIABLE  */
#line 424 "grammar.y"
                                {
        int val1 = get_symbol(yyvsp[-2]);
        int val2 = get_symbol(yyvsp[0]);
        if (val1 == -9999 || val2 == -9999) {
            printf("Error: Undefined variable %c or %c.\n", 
                   (val1 == -9999) ? yyvsp[-2] : yyvsp[0], (val2 == -9999) ? yyvsp[0] : yyvsp[-2]);
        } else if (val1 < val2) {
            printf("%c is smaller than %c\n", yyvsp[-2], yyvsp[0]);
        } else {
            printf("%c is not smaller than %c\n", yyvsp[-2], yyvsp[0]);
        }
    }
#line 1873 "grammar.tab.c"
    break;

  case 66: /* reasoning_stmt: VARIABLE IS TALLEST THAN VARIABLE PERIOD VARIABLE IS TALLEST THAN VARIABLE PERIOD WHO IS THE TALLEST QUESTION  */
#line 439 "grammar.y"
                                                                                                                  {
        printf("%c is the tallest.\n", yyvsp[-16]);
    }
#line 1881 "grammar.tab.c"
    break;

  case 67: /* reasoning_stmt: VARIABLE IS TALLEST THAN VARIABLE PERIOD VARIABLE IS TALLEST THAN VARIABLE PERIOD WHICH IS THE TALLEST QUESTION  */
#line 442 "grammar.y"
                                                                                                                      {
        printf("%c is the tallest.\n", yyvsp[-16]);
    }
#line 1889 "grammar.tab.c"
    break;

  case 68: /* reasoning_stmt: VARIABLE IS TALLEST THAN VARIABLE PERIOD VARIABLE IS TALLEST THAN VARIABLE PERIOD WHO IS THE TALLEST  */
#line 445 "grammar.y"
                                                                                                           {
        printf("%c is the tallest.\n", yyvsp[-15]);
    }
#line 1897 "grammar.tab.c"
    break;

  case 69: /* reasoning_stmt: VARIABLE IS TALLEST THAN VARIABLE PERIOD VARIABLE IS TALLEST THAN VARIABLE PERIOD WHICH IS THE TALLEST  */
#line 448 "grammar.y"
                                                                                                             {
        printf("%c is the tallest.\n", yyvsp[-15]);
    }
#line 1905 "grammar.tab.c"
    break;

  case 70: /* reasoning_stmt: VARIABLE IS YOUNGEST THAN VARIABLE PERIOD VARIABLE IS YOUNGEST THAN VARIABLE PERIOD WHO IS THE YOUNGEST QUESTION  */
#line 451 "grammar.y"
                                                                                                                       {
        printf("%c is the youngest.\n", yyvsp[-16]);
    }
#line 1913 "grammar.tab.c"
    break;

  case 71: /* reasoning_stmt: VARIABLE IS YOUNGEST THAN VARIABLE PERIOD VARIABLE IS YOUNGEST THAN VARIABLE PERIOD WHICH IS THE YOUNGEST QUESTION  */
#line 454 "grammar.y"
                                                                                                                         {
        printf("%c is the youngest.\n", yyvsp[-16]);
    }
#line 1921 "grammar.tab.c"
    break;

  case 72: /* expression: NUMBER  */
#line 460 "grammar.y"
           { yyval = yyvsp[0]; }
#line 1927 "grammar.tab.c"
    break;

  case 73: /* expression: VARIABLE  */
#line 461 "grammar.y"
               { 
        int val = get_symbol(yyvsp[0]);
        if (val == -9999) {
            printf("Error: Undefined variable %c.\n", yyvsp[0]);
            yyval = 0;
        } else {
            yyval = val;
        }
    }
#line 1941 "grammar.tab.c"
    break;

  case 74: /* expression: expression MULT expression  */
#line 470 "grammar.y"
                                 { 
        yyval = evaluate_arithmetic(yyvsp[-2], '*', yyvsp[0]);
        printf("Step: %d * %d = %d\n", yyvsp[-2], yyvsp[0], yyval);
    }
#line 1950 "grammar.tab.c"
    break;

  case 75: /* expression: expression DIV expression  */
#line 474 "grammar.y"
                                { 
        if (yyvsp[0] == 0) {
            printf("Error: Division by zero.\n");
            yyval = 0;
        } else {
            yyval = evaluate_arithmetic(yyvsp[-2], '/', yyvsp[0]);
            printf("Step: %d / %d = %d\n", yyvsp[-2], yyvsp[0], yyval);
        }
    }
#line 1964 "grammar.tab.c"
    break;

  case 76: /* expression: expression PLUS expression  */
#line 483 "grammar.y"
                                 { 
        yyval = evaluate_arithmetic(yyvsp[-2], '+', yyvsp[0]);
        printf("Step: %d + %d = %d\n", yyvsp[-2], yyvsp[0], yyval);
    }
#line 1973 "grammar.tab.c"
    break;

  case 77: /* expression: expression MINUS expression  */
#line 487 "grammar.y"
                                  { 
        yyval = evaluate_arithmetic(yyvsp[-2], '-', yyvsp[0]);
        printf("Step: %d - %d = %d\n", yyvsp[-2], yyvsp[0], yyval);
    }
#line 1982 "grammar.tab.c"
    break;

  case 78: /* expression: LPAREN expression RPAREN  */
#line 491 "grammar.y"
                               { yyval = yyvsp[-1]; }
#line 1988 "grammar.tab.c"
    break;


#line 1992 "grammar.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 494 "grammar.y"


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
