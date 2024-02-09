/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 124 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

