/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_NIL = 258,
     KW_WHILE = 259,
     KW_IF = 260,
     KW_EXIT = 261,
     KW_LOAD = 262,
     KW_DISP = 263,
     KW_TRUE = 264,
     KW_FALSE = 265,
     DEFV = 266,
     DEFF = 267,
     COMMENT = 268,
     VALUEF = 269,
     ID = 270,
     OP_COMMA = 271,
     CP = 272,
     OP = 273,
     OP_MULT = 274,
     OP_DIV = 275,
     OP_MINUS = 276,
     OP_PLUS = 277,
     OP_AND = 278,
     OP_OR = 279,
     OP_NOT = 280,
     OP_EQ = 281,
     OP_GT = 282,
     OP_SET = 283
   };
#endif
/* Tokens.  */
#define KW_NIL 258
#define KW_WHILE 259
#define KW_IF 260
#define KW_EXIT 261
#define KW_LOAD 262
#define KW_DISP 263
#define KW_TRUE 264
#define KW_FALSE 265
#define DEFV 266
#define DEFF 267
#define COMMENT 268
#define VALUEF 269
#define ID 270
#define OP_COMMA 271
#define CP 272
#define OP 273
#define OP_MULT 274
#define OP_DIV 275
#define OP_MINUS 276
#define OP_PLUS 277
#define OP_AND 278
#define OP_OR 279
#define OP_NOT 280
#define OP_EQ 281
#define OP_GT 282
#define OP_SET 283




/* Copy the first part of user declarations.  */
#line 3 "gpp_interpreter.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "y.tab.h"




	extern FILE *yyin;

	int yylex();

	void yyerror(const char* message) 
	{ fprintf(stderr, "%s\n", message);}



	struct fraction stringToFraction( char* str );
	struct fraction simplifyFraction(struct fraction frac);
	struct fraction addFraction(struct fraction a , struct fraction b);
	struct fraction subtractFraction(struct fraction a , struct fraction b);
	struct fraction multFraction(struct fraction a , struct fraction b);
	struct fraction divFraction(struct fraction a , struct fraction b);
	int isFracGreater( struct fraction a , struct fraction b );
	int isFracEqual( struct fraction a , struct fraction b );
	int hasIdDeclaredBefore( char* id );
	void assignFractionToId(char* id , struct fraction frac);
	char* getFunctionIdFromDEFFexpressionString( const char* functionString );
	int doesGivenStringContainAfunction( const char *string );
	struct fraction callFunctionTypeOne();
	struct fraction callFunctionTypeTwo();
	struct fraction callFunctionTypeThree();
	struct fraction callFunctionTypeFour();
	char* fractionToString( const struct fraction fr);
	struct fraction getValueOfId(char* id);
	void replaceString(char *mainStr , char* oldStr , char* newStr);
	void addFunctionIfItsPossible( char* expressionString );
	void addNewId(char* id , int intValue , int fracValue);

	struct fraction functionResultKeeper;
	int isFunctionCall = 0;




	//Keeps an id and it's value
	typedef struct ID_value_pair_keeper
	{
		int integerValue;
		int fractionValue;
		char id[100];
	}id_val_pair;


	id_val_pair id_val_pair_keeper[1000];    //Keeps id's and their values
	int id_val_pair_keeper_index_counter = 0;	//Tracks end index of "id_val_pair_keeper"







	//Keeps a function and it's name
	typedef struct FunctionKeeper
	{
		char* functionName;
		char* functionBody;

	}funcKeep;

	void setFunctionStructFromGivenString( funcKeep* func  , char* newString );
	void setFunctionName( funcKeep func );




	funcKeep FunctionKeeperArray[1000];
	int FunctionKeeperArray_counter = 0;











/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 99 "gpp_interpreter.y"
{
	struct fraction
	{
		int intPart;
		int fractionPart;
	} val;

	int boolVal;   //Used to specify the type of the "KW_TRUE" and "KW_FALSE" tokens

	struct keepStringOfTheCurrentToken
	{
		char idName[200];	//Keeps last id name ,updated from lexer
		char fractionStr[200];    //Keeps last fraction string
		char tokenStringKeeper[10000];	//For every time,lexer appends string of current token,used to keep function body

	}keepStringOfTheCurrentToken;

}
/* Line 193 of yacc.c.  */
#line 263 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 276 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  35
/* YYNRULES -- Number of states.  */
#define YYNSTATES  101

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    19,    25,
      31,    37,    39,    41,    43,    45,    52,    58,    64,    70,
      76,    78,    80,    86,    92,    97,   102,   104,   110,   118,
     127,   137,   148,   152,   157,   163
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      30,     0,    -1,    31,    -1,    32,    -1,    34,    -1,    36,
      -1,    37,    -1,    18,    22,    32,    32,    17,    -1,    18,
      21,    32,    32,    17,    -1,    18,    19,    32,    32,    17,
      -1,    18,    20,    32,    32,    17,    -1,    15,    -1,    14,
      -1,    37,    -1,    35,    -1,    18,     5,    33,    34,    34,
      17,    -1,    18,     4,    33,    34,    17,    -1,    18,    11,
      15,    32,    17,    -1,    18,    26,    32,    32,    17,    -1,
      18,    27,    32,    32,    17,    -1,     9,    -1,    10,    -1,
      18,    23,    33,    33,    17,    -1,    18,    24,    33,    33,
      17,    -1,    18,    25,    33,    17,    -1,    18,    32,    34,
      17,    -1,    32,    -1,    18,    28,    15,    32,    17,    -1,
      18,    12,    15,    18,    17,    32,    17,    -1,    18,    12,
      15,    18,    15,    17,    32,    17,    -1,    18,    12,    15,
      18,    15,    15,    17,    32,    17,    -1,    18,    12,    15,
      18,    15,    15,    15,    17,    32,    17,    -1,    18,    15,
      17,    -1,    18,    15,    32,    17,    -1,    18,    15,    32,
      32,    17,    -1,    18,    15,    32,    32,    32,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   201,   201,   205,   206,   207,   208,   217,   218,   219,
     220,   221,   233,   234,   235,   236,   249,   258,   279,   280,
     281,   282,   283,   284,   285,   288,   289,   291,   297,   308,
     319,   330,   344,   345,   346,   347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_NIL", "KW_WHILE", "KW_IF", "KW_EXIT",
  "KW_LOAD", "KW_DISP", "KW_TRUE", "KW_FALSE", "DEFV", "DEFF", "COMMENT",
  "VALUEF", "ID", "OP_COMMA", "CP", "OP", "OP_MULT", "OP_DIV", "OP_MINUS",
  "OP_PLUS", "OP_AND", "OP_OR", "OP_NOT", "OP_EQ", "OP_GT", "OP_SET",
  "$accept", "start", "input", "exp", "expb", "explist", "asg", "function",
  "fcall", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    31,    31,    31,    31,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    33,    33,
      33,    33,    33,    33,    33,    34,    34,    35,    36,    36,
      36,    36,    37,    37,    37,    37
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     5,     5,     5,
       5,     1,     1,     1,     1,     6,     5,     5,     5,     5,
       1,     1,     5,     5,     4,     4,     1,     5,     7,     8,
       9,    10,     3,     4,     5,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    11,     0,     0,     2,     3,     4,    14,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     1,    20,    21,     0,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    16,     0,    17,     0,     0,
      34,     0,     9,    10,     8,     7,    27,     0,     0,    24,
       0,     0,    15,     0,     0,     0,    35,    22,    23,    18,
      19,     0,     0,     0,    28,     0,     0,    29,     0,    30,
      31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,    41,    28,     7,     8,     9,    23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -22
static const yytype_int8 yypact[] =
{
      42,   -22,   -22,    61,     2,   -22,   -22,   -22,   -22,   -22,
     -22,    -5,    -5,    -9,     1,    34,    94,    76,    76,    76,
      76,     6,    93,   -22,   -22,   -22,   -22,    -1,    93,    93,
      76,    13,   -22,    53,    34,    76,    76,    76,    76,    76,
      82,   -22,    15,    -5,    -5,    -5,    76,    76,    27,    93,
      28,    -6,   -22,   103,    33,    37,    38,    44,    45,   -22,
      -5,    -5,    57,    76,    76,   -22,    60,   -22,    -3,    76,
     -22,    68,   -22,   -22,   -22,   -22,   -22,    71,    89,   -22,
      95,   102,   -22,    12,    76,   106,   -22,   -22,   -22,   -22,
     -22,   107,    76,   108,   -22,    76,   109,   -22,   110,   -22,
     -22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,   -22,   -22,     0,    -2,   -21,   -22,   -22,    78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       6,    42,    24,    22,    25,    26,    30,    48,    49,    68,
      29,    69,    83,    27,    84,    33,    31,    35,    36,    37,
      38,    39,    43,    44,    45,    46,    47,    91,    66,    92,
      50,    51,    59,    53,    33,    54,    55,    56,    57,    58,
      22,    60,    61,    62,    65,    67,    63,    64,     1,     2,
      72,    32,    16,    71,    73,    74,     1,     2,    77,    78,
       3,    75,    76,    80,    81,    11,    12,     1,     2,    85,
      52,    16,    13,    14,    79,     1,    15,    82,    10,    16,
      17,    18,    19,    20,    93,    86,    11,    12,    87,    21,
       1,     2,    96,    13,    16,    98,     1,    15,    11,    12,
      16,    17,    18,    19,    20,    13,    88,     1,     2,    34,
      21,    40,    89,    17,    18,    19,    20,     1,     2,    90,
      70,    16,    21,    94,    95,    97,    99,   100
};

static const yytype_uint8 yycheck[] =
{
       0,    22,     0,     3,     9,    10,    15,    28,    29,    15,
      12,    17,    15,    18,    17,    15,    15,    17,    18,    19,
      20,    15,    23,    24,    25,    26,    27,    15,    49,    17,
      30,    18,    17,    33,    34,    35,    36,    37,    38,    39,
      40,    43,    44,    45,    17,    17,    46,    47,    14,    15,
      17,    17,    18,    53,    17,    17,    14,    15,    60,    61,
      18,    17,    17,    63,    64,     4,     5,    14,    15,    69,
      17,    18,    11,    12,    17,    14,    15,    17,     0,    18,
      19,    20,    21,    22,    84,    17,     4,     5,    17,    28,
      14,    15,    92,    11,    18,    95,    14,    15,     4,     5,
      18,    19,    20,    21,    22,    11,    17,    14,    15,    15,
      28,    18,    17,    19,    20,    21,    22,    14,    15,    17,
      17,    18,    28,    17,    17,    17,    17,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    15,    18,    30,    31,    32,    34,    35,    36,
      37,     4,     5,    11,    12,    15,    18,    19,    20,    21,
      22,    28,    32,    37,     0,     9,    10,    18,    33,    33,
      15,    15,    17,    32,    15,    32,    32,    32,    32,    15,
      18,    32,    34,    23,    24,    25,    26,    27,    34,    34,
      32,    18,    17,    32,    32,    32,    32,    32,    32,    17,
      33,    33,    33,    32,    32,    17,    34,    17,    15,    17,
      17,    32,    17,    17,    17,    17,    17,    33,    33,    17,
      32,    32,    17,    15,    17,    32,    17,    17,    17,    17,
      17,    15,    17,    32,    17,    17,    32,    17,    32,    17,
      17
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 201 "gpp_interpreter.y"
    { return 1; }
    break;

  case 3:
#line 205 "gpp_interpreter.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val);}
    break;

  case 4:
#line 206 "gpp_interpreter.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 5:
#line 207 "gpp_interpreter.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 7:
#line 217 "gpp_interpreter.y"
    {(yyval.val) = addFraction( (yyvsp[(3) - (5)].val) , (yyvsp[(4) - (5)].val) );printf("\n\nexp parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString((yyval.val)));}
    break;

  case 8:
#line 218 "gpp_interpreter.y"
    {(yyval.val) = subtractFraction( (yyvsp[(3) - (5)].val) , (yyvsp[(4) - (5)].val) );printf("\n\nexp parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString((yyval.val)));}
    break;

  case 9:
#line 219 "gpp_interpreter.y"
    {(yyval.val) = multFraction( (yyvsp[(3) - (5)].val) , (yyvsp[(4) - (5)].val) );printf("\n\nexp parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString((yyval.val)));}
    break;

  case 10:
#line 220 "gpp_interpreter.y"
    {(yyval.val) = divFraction( (yyvsp[(3) - (5)].val) , (yyvsp[(4) - (5)].val) );printf("\n\nexp parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString((yyval.val)));}
    break;

  case 11:
#line 221 "gpp_interpreter.y"
    { 
				if(hasIdDeclaredBefore(yylval.keepStringOfTheCurrentToken.idName) == 1)
				{
					(yyval.val) = getValueOfId(yylval.keepStringOfTheCurrentToken.idName);
				}
				else
				{
					printf("\nId \"%s\" has not declared...\n",yylval.keepStringOfTheCurrentToken.idName);
					(yyval.val) = stringToFraction("0f1");
				}
	   		}
    break;

  case 12:
#line 233 "gpp_interpreter.y"
    { (yyval.val) = stringToFraction(yylval.keepStringOfTheCurrentToken.fractionStr);}
    break;

  case 13:
#line 234 "gpp_interpreter.y"
    {(yyval.val) = (yyvsp[(1) - (1)].val);}
    break;

  case 14:
#line 235 "gpp_interpreter.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 15:
#line 236 "gpp_interpreter.y"
    { 
													if( (yyvsp[(3) - (6)].boolVal) == 1 )
													{
														(yyval.val) = (yyvsp[(4) - (6)].val);
													}
													else
													{
														(yyval.val) = (yyvsp[(5) - (6)].val);
													}	
											   }
    break;

  case 16:
#line 250 "gpp_interpreter.y"
    {
		   int loopCounter;

	   }
    break;

  case 17:
#line 258 "gpp_interpreter.y"
    {
									(yyval.val) = (yyvsp[(4) - (5)].val);
									if( hasIdDeclaredBefore(yylval.keepStringOfTheCurrentToken.idName) == 0 )
									{
										addNewId(yylval.keepStringOfTheCurrentToken.idName , (yyvsp[(4) - (5)].val).intPart , (yyvsp[(4) - (5)].val).fractionPart);
										printf("\nID \"%s\" has not been declared before , assigned with value %s\n\n",yylval.keepStringOfTheCurrentToken.idName,yylval.keepStringOfTheCurrentToken.fractionStr);
									}
									else
									{
										printf("\n\nError,ID \"%s\" has been declared before\n\n",yylval.keepStringOfTheCurrentToken.idName);
									}
	   							}
    break;

  case 18:
#line 279 "gpp_interpreter.y"
    { (yyval.boolVal) = isFracEqual((yyvsp[(3) - (5)].val),(yyvsp[(4) - (5)].val)); printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",(yyval.boolVal));}
    break;

  case 19:
#line 280 "gpp_interpreter.y"
    { (yyval.boolVal) = isFracGreater((yyvsp[(3) - (5)].val),(yyvsp[(4) - (5)].val)); printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",(yyval.boolVal));}
    break;

  case 20:
#line 281 "gpp_interpreter.y"
    { (yyval.boolVal) = 1; printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",(yyval.boolVal));}
    break;

  case 21:
#line 282 "gpp_interpreter.y"
    { (yyval.boolVal) = 0; printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",(yyval.boolVal));}
    break;

  case 22:
#line 283 "gpp_interpreter.y"
    { (yyval.boolVal) = (yyvsp[(3) - (5)].boolVal) && (yyvsp[(4) - (5)].boolVal); printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",(yyval.boolVal));}
    break;

  case 23:
#line 284 "gpp_interpreter.y"
    { (yyval.boolVal) = (yyvsp[(3) - (5)].boolVal) || (yyvsp[(4) - (5)].boolVal); printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",(yyval.boolVal));}
    break;

  case 24:
#line 285 "gpp_interpreter.y"
    { (yyval.boolVal) = !(yyvsp[(3) - (4)].boolVal); printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",(yyval.boolVal));}
    break;

  case 25:
#line 288 "gpp_interpreter.y"
    { (yyval.val) = (yyvsp[(2) - (4)].val); printf("\n\nExplist parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString((yyval.val)));}
    break;

  case 26:
#line 289 "gpp_interpreter.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); printf("\n\nExplist parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString((yyval.val)));}
    break;

  case 27:
#line 291 "gpp_interpreter.y"
    {
									assignFractionToId(yylval.keepStringOfTheCurrentToken.idName , (yyvsp[(4) - (5)].val));
									(yyval.val) = (yyvsp[(4) - (5)].val);
									(yyvsp[(3) - (5)].val) = (yyvsp[(4) - (5)].val);
								}
    break;

  case 28:
#line 297 "gpp_interpreter.y"
    { 
													(yyval.val) = (yyvsp[(6) - (7)].val); addFunctionIfItsPossible(yylval.keepStringOfTheCurrentToken.tokenStringKeeper); 
													functionResultKeeper = (yyvsp[(6) - (7)].val);
													if( isFunctionCall == 1 )
													{
														char* result = fractionToString( functionResultKeeper );
														printf("\nresult = %s \n",result);
														free(result);
														isFunctionCall = 0;
													}
											    }
    break;

  case 29:
#line 308 "gpp_interpreter.y"
    {
													 (yyval.val) = (yyvsp[(7) - (8)].val); addFunctionIfItsPossible(yylval.keepStringOfTheCurrentToken.tokenStringKeeper);
													 functionResultKeeper = (yyvsp[(7) - (8)].val);
													 if( isFunctionCall == 1 )
													 {
														char* result = fractionToString( functionResultKeeper );
														printf("\nresult = %s \n",result);
														free(result);
														isFunctionCall = 0;
													 }
		   										  }
    break;

  case 30:
#line 319 "gpp_interpreter.y"
    { 
														(yyval.val) = (yyvsp[(8) - (9)].val); addFunctionIfItsPossible(yylval.keepStringOfTheCurrentToken.tokenStringKeeper);
														functionResultKeeper = (yyvsp[(8) - (9)].val);
														if( isFunctionCall == 1 )
														{
															char* result = fractionToString( functionResultKeeper );
															printf("\nresult = %s \n",result);
															free(result);
															isFunctionCall = 0;
														}
		   											 }
    break;

  case 31:
#line 330 "gpp_interpreter.y"
    {
														 (yyval.val) = (yyvsp[(9) - (10)].val); addFunctionIfItsPossible(yylval.keepStringOfTheCurrentToken.tokenStringKeeper);
														 functionResultKeeper = (yyvsp[(9) - (10)].val);
														 if( isFunctionCall == 1 )
														 {
															char* result = fractionToString( functionResultKeeper );
															printf("\nresult = %s \n",result);
															free(result);
															isFunctionCall = 0;
														 }
		   												}
    break;

  case 32:
#line 344 "gpp_interpreter.y"
    { (yyval.val) = stringToFraction("0f1"); callFunctionTypeOne(); }
    break;

  case 33:
#line 345 "gpp_interpreter.y"
    { (yyval.val) = (yyvsp[(3) - (4)].val); callFunctionTypeTwo("id1");}
    break;

  case 34:
#line 346 "gpp_interpreter.y"
    { (yyval.val) = (yyvsp[(4) - (5)].val); callFunctionTypeThree("id1","id2");}
    break;

  case 35:
#line 347 "gpp_interpreter.y"
    { (yyval.val) = (yyvsp[(5) - (6)].val); callFunctionTypeFour("id1","id2","id3");}
    break;


/* Line 1267 of yacc.c.  */
#line 1788 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 353 "gpp_interpreter.y"






int isFracGreater( struct fraction a , struct fraction b )
{
	int result = 0;
	if(a.intPart > b.intPart)
	{
		result = 1;
	}
	else if( (a.intPart == b.intPart) && (a.fractionPart > b.fractionPart) )
	{
		result = 1;
	}


	return result;
}


int isFracEqual( struct fraction a , struct fraction b )
{
	int result = 0;
	if(a.intPart == b.intPart)
	{
		result = 1;
	}
	else if( a.fractionPart == b.fractionPart )
	{
		result = 1;
	}


	return result;
}




struct fraction simplifyFraction(struct fraction frac)
{
	struct fraction result = frac;

	int greaterPart = 0;

	frac.intPart > frac.fractionPart ? (greaterPart = frac.intPart) : (greaterPart = frac.fractionPart);

	for(int i=2 ; i<=greaterPart ; i++)
	{
		if( (result.intPart % i == 0) && (result.fractionPart % i == 0) )
		{
			result.intPart /= i;
			result.fractionPart /= i;
			i--;
		}
	}


	return result;
}






//______________________________Aritmetic operations for fraction structs below

struct fraction addFraction(struct fraction a , struct fraction b)
{
	struct fraction sum;

	const int aFracPartKeeper = a.fractionPart;
	const int bFracPartKeeper = b.fractionPart;

	int aFrac = a.fractionPart;
	int bFrac = b.fractionPart;
	int aInt = a.intPart;
	int bInt = b.intPart;


	aFrac *= bFracPartKeeper;
	aInt *= bFracPartKeeper;

	bFrac *= aFracPartKeeper;
	bInt *= aFracPartKeeper;


	sum.intPart = aInt + bInt;
	sum.fractionPart = bFrac;

	return simplifyFraction(sum);

}

struct fraction subtractFraction(struct fraction a , struct fraction b)
{
	struct fraction result;

	struct fraction bNegative;

	bNegative.intPart = -b.intPart;
	bNegative.fractionPart = b.fractionPart;

	result = addFraction(a,bNegative);

	return simplifyFraction(result);

}

struct fraction multFraction(struct fraction a , struct fraction b)
{
	struct fraction result;

	result.intPart = a.intPart * b.intPart;
	result.fractionPart = a.fractionPart * b.fractionPart;

	return simplifyFraction(result);

}




struct fraction divFraction(struct fraction a , struct fraction b)
{
	struct fraction result;

	result.intPart = a.intPart * b.fractionPart;
	result.fractionPart = a.fractionPart * b.intPart;

	return simplifyFraction(result);

}


//______________________________Aritmetic operations for fraction structs above









//Takes an string and returns an fraction struct
struct fraction stringToFraction( char* str )
{
	struct fraction result;
	int intPart = 0;
	int fractionPart = 0;

	int isReadingIntPart = 1;

	for(int i=0 ; i < strlen(str) ; i++ )
	{
		if(str[i] == 'f')
		{
			isReadingIntPart = 0;
		}

		else if( str[i]>= '0' && str[i]<= '9' )
		{
			if( isReadingIntPart )
			{
				intPart *= 10;
				int temp = str[i] - '0';
				intPart += temp;
			}
			else
			{
				fractionPart *= 10;
				int temp = str[i] - '0';
				fractionPart += temp;
			}
		}
	}


	result.intPart = intPart;
	result.fractionPart = fractionPart;

	return simplifyFraction(result);

}



//takes an fraction struct and returns string value(Ex. 3f5 ...)
char* fractionToString( const struct fraction fr)
{
	char* result = (char*) malloc( 200 *  sizeof(char) );

	char intPartStr[100];
	char fractionPartStr[100];

	sprintf( intPartStr, "%d", fr.intPart );
	sprintf( fractionPartStr, "%d", fr.fractionPart);

	strcat( result , intPartStr );
	strcat( result , "f" );
	strcat( result , fractionPartStr );

	return result;
}




//Saves new id with given properties
void addNewId(char* id , int intValue , int fracValue)
{
	id_val_pair newId;
	newId.integerValue = intValue;
	newId.fractionValue = fracValue;
	
	const int idLength = strlen(id);

	for(int i=0 ; i<idLength ; i++)
	{
		newId.id[i] = id[i];
	}
	newId.id[idLength] = '\0';

	id_val_pair_keeper[id_val_pair_keeper_index_counter] = newId;

	id_val_pair_keeper_index_counter++;
	
}






//Checks if an id with given name has been declared before
int hasIdDeclaredBefore( char* id )
{
	int result = 0;

	const int id_val_pair_keeper_size = 1000;

	for( int i=0 ; i<id_val_pair_keeper_size ; i++ )
	{
		if( strcmp( id , id_val_pair_keeper[i].id ) == 0 )
		{
			result = 1;
			break;
		}
	}

	return result;
}


//Finds id with given name and changes it's saved value
void assignFractionToId(char* id , struct fraction frac)
{

	int temp = 0;

	for(int i=0 ; i<id_val_pair_keeper_index_counter ; i++ )
	{
		if( strcmp(id_val_pair_keeper[i].id , id) == 0 )
		{
			printf("\n\nOld value of %s is %df%d",id_val_pair_keeper[i].id , id_val_pair_keeper[i].integerValue, id_val_pair_keeper[i].fractionValue );

			id_val_pair_keeper[i].integerValue = frac.intPart;
			id_val_pair_keeper[i].fractionValue = frac.fractionPart;
			temp = i;
			break;
		}
	}
	printf("\n\nNew value of %s is %df%d\n",id_val_pair_keeper[temp].id , id_val_pair_keeper[temp].integerValue, id_val_pair_keeper[temp].fractionValue );

}



//All expressions are kept in "tokenStringKeeper" which is in union
//All tokens gets read and corresponding strings for them gets appended to this string
//This function checks if given expression contains a function or not
//Returns 1 for true,0 for false
int doesGivenStringContainAfunction( const char *string )
{
	//whitespaces and newlines are set automatically so,it can be easily checked if given string
	//is below the minimum possible length

	if( strlen(string) < 12 )
	{
		return 0;
	}

	//checks for "deff" keyword
	else if( string[2] != 'd' || string[3] != 'e' ||string[4] != 'f' || string[5] != 'f' )
	{
		return 0;
	}

	return 1;

} 



//Everytime a token is read for an expression,"tokenStringKeeper" gets updated by appending new token's string
//This function checks if expression is completely read and clears that string for new expression
void clearStringThatKeepsTokenStrings( char *string )
{
	int numOP = 1;
	int numCP = 0;

	const int expressionStringLength = strlen(string);

	for( int i=1 ; i < expressionStringLength ; i++ )
	{
		if( string[i] == '(' )
		{
			numOP++;
		}
		else if( string[i] == ')' )
		{
			numCP++;
		}
	}


	if( numOP == numCP )
	{
		strcpy(string,"");
	}

}










//This function gets string that contains whole expression of function and returns the id of the function
char* getFunctionIdFromDEFFexpressionString( const char* functionString )
{

	char* result = (char*) malloc( 200 *  sizeof(char) );
	result[0] = '\0';


	int indexOfTheIDWithinFunctionString = 7;	


	while( functionString[ indexOfTheIDWithinFunctionString ] != ' ' )
	{

		char currentCharOfId = functionString[ indexOfTheIDWithinFunctionString ];

		result[ indexOfTheIDWithinFunctionString - 7 ] = currentCharOfId;

		result[ indexOfTheIDWithinFunctionString - 6 ] = '\0';

		indexOfTheIDWithinFunctionString++;
	}

	return result;

}



//Takes input name and searches saved functions
//Returns index of this function,returns -1 if not found
int getIndexOfCorrespondingFunction( const char* functionName )
{
	int result = -1;

	for( int i=0 ; i<FunctionKeeperArray_counter ; i++)
	{
		if( strcmp( FunctionKeeperArray[i].functionName , functionName ) == 0 )
		{
			result = i;
			break;
		}
	}

	return result;
}





//Gets string from fcall expression
//Ex:
//	For "( deffun foo() ...."
//
// returns "foo"
char* getFunctionIdFromFCALLexpressionString( const char* functionString )
{

	char* result = (char*) malloc( 200 *  sizeof(char) );
	result[0] = '\0';


	int indexOfTheIDWithinFunctionString = 2;	


	while( functionString[ indexOfTheIDWithinFunctionString ] != ' ' )
	{

		char currentCharOfId = functionString[ indexOfTheIDWithinFunctionString ];

		result[ indexOfTheIDWithinFunctionString - 2 ] = currentCharOfId;

		result[ indexOfTheIDWithinFunctionString - 1 ] = '\0';

		indexOfTheIDWithinFunctionString++;
	}

	return result;

}




//returns value of an id that has been declared before
struct fraction getValueOfId(char* id)
{
	struct fraction frac;

	for(int i=0 ; i<id_val_pair_keeper_index_counter ; i++ )
	{
		if( strcmp(id_val_pair_keeper[i].id , id) == 0 )
		{
			frac.intPart = id_val_pair_keeper[i].integerValue;
			frac.fractionPart = id_val_pair_keeper[i].fractionValue;
			break;
		}
	}	
	return frac;
}







//
//For function calls , these functions gets function body of asked function
// writes the body of in a file
//and then applies tokenization and parsing proccess for that file to read saved function body
//






struct fraction callFunctionTypeOne()
{
	char id[200];
	strcpy( id , getFunctionIdFromFCALLexpressionString(yylval.keepStringOfTheCurrentToken.tokenStringKeeper) );
	printf("\nfcall id ->%s\n",id);

	for(int i=0 ; i<FunctionKeeperArray_counter ;i++)
	{
		if( strcmp( id , FunctionKeeperArray[ i ].functionName ) == 0 )
		{
			isFunctionCall = 1;
			FILE* f = fopen("temp","w");
			fputs( FunctionKeeperArray[ i ].functionBody, f );
			fclose(f);
			fopen("temp","r");
			yyin = f;
			yyparse();
			fclose(f);
			yyin = stdin;
			clearStringThatKeepsTokenStrings(yylval.keepStringOfTheCurrentToken.tokenStringKeeper);
			remove("temp");
			break;
		}
	}




	struct fraction f;
	return f;
}




struct fraction callFunctionTypeTwo( struct fraction paramOne )
{
	char id[200];
	strcpy( id , getFunctionIdFromFCALLexpressionString(yylval.keepStringOfTheCurrentToken.tokenStringKeeper) );
	printf("\nfcall id ->%s\n",id);

	for(int i=0 ; i<FunctionKeeperArray_counter ;i++)
	{
		if( strcmp( id , FunctionKeeperArray[ i ].functionName ) == 0 )
		{
			isFunctionCall = 1;
			FILE* f = fopen("temp","w");
			char functionBodyRewritten[10000];
			functionBodyRewritten[0] = '\0';



			int countSpaces;
			char paramOneId[200]; paramOneId[0] = '\0';
			for( int j=0 ; j<strlen(FunctionKeeperArray[ i ].functionBody) ; i++ )
			{
				if( FunctionKeeperArray[ i ].functionBody[j] == ' ' )
				{
					countSpaces++;
				}

				if( countSpaces == 2 )
				{
					char t[2];
					t[0] = FunctionKeeperArray[ i ].functionBody[j];
					t[1] = '\0';
					strcat( paramOneId , t );
				}
					char t[2];
					t[0] = ' ';
					t[1] = '\0';
					strcat( paramOneId , t );

			}

			replaceString( functionBodyRewritten , fractionToString(paramOne) , paramOneId );




			fputs( FunctionKeeperArray[ i ].functionBody, f );
			fclose(f);
			fopen("temp","r");
			yyin = f;
			yyparse();
			fclose(f);
			yyin = stdin;
			clearStringThatKeepsTokenStrings(yylval.keepStringOfTheCurrentToken.tokenStringKeeper);
			remove("temp");
			break;
		}
	}

	struct fraction f;
	return f;
}

struct fraction callFunctionTypeThree()
{
	char id[200];
	strcpy( id , getFunctionIdFromFCALLexpressionString(yylval.keepStringOfTheCurrentToken.tokenStringKeeper) );


	struct fraction f;
	return f;
}

struct fraction callFunctionTypeFour()
{
	char id[200];
	strcpy( id , getFunctionIdFromFCALLexpressionString(yylval.keepStringOfTheCurrentToken.tokenStringKeeper) );


	struct fraction f;
	return f;
}









//_______Useless for now________
//Was going to be used when if user entered an expression like (+ 1f1 2f1) as parameter of function,function were going to be found 
//and all substrings that is id of that parameter were going to be replaced with (+ 1f1 2f1) by  this function
void replaceString(char *mainStr , char* oldStr , char* newStr)
{
	char temp[10000];
	temp[0] = '\0';
	if (true)
	{

		for( int i=0 ; i<(strlen(mainStr)) ; i++ )
		{
			int hasSubStrFound = 1;

			for( int x=i ; x<(i+strlen(oldStr)) ; x++ )
			{
				if( mainStr[x] != oldStr[x-i] )
				{
					hasSubStrFound = 0;
					break;
				}
			}

			if( hasSubStrFound == 1 )
			{
				strcat( temp , newStr );
				i += strlen(oldStr)-1;
			}
			else
			{
				char t[2];
				t[0] = mainStr[i];
				t[1] = '\0';
				strcat( temp , t );
				hasSubStrFound = 1;
			}


		}

	}
	printf("%s",temp);
}





void setFunctionStructFromGivenString( funcKeep* func  , char* newString )
{

		const int idLength = strlen(newString)+1;

		const int wholeFunctionStringLength = strlen( getFunctionIdFromDEFFexpressionString( newString ) )+1;

		func->functionBody = (char*) malloc( idLength *  sizeof(char) );

		func->functionName = (char*) malloc( wholeFunctionStringLength * sizeof(char) );

		strcpy( func -> functionBody , newString );

		strcpy( func -> functionName , getFunctionIdFromDEFFexpressionString( newString ) );
}




	void addFunctionIfItsPossible( char* expressionString )
	{

		if( doesGivenStringContainAfunction( expressionString ) == 1 )
		{


			funcKeep newFunc;

			setFunctionStructFromGivenString( &newFunc , expressionString );

			FunctionKeeperArray[ FunctionKeeperArray_counter ] = newFunc;

			FunctionKeeperArray_counter++;

		}
	}

	//function body contains whole function but functionName needs to be taken and saved explicitly to functionName
	void setFunctionName( funcKeep func )
	{
		const char* fbody = func.functionBody;
		char *copyOfFuncBody;
		printf("%s",copyOfFuncBody);
	}





int main() {




    while(1)
	{	
		printf("-->");

		clearStringThatKeepsTokenStrings( yylval.keepStringOfTheCurrentToken.tokenStringKeeper );
		yyparse();


	}
}

