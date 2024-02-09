

%{
#include <string.h>
#include "keyworddefinitions.h"
#include "operatordefinitions.h"
#include "otherdefinitions.h"

int isQuoteOpened = 0;

char tokenString[100];

%}





ID [a-zA-Z_][a-zA-Z_0-9]*


INCORRECTID {DIGIT}{ID}







DIGIT [0-9]

INTEGER [1-9]{DIGIT}*|0+

NOTINTEGER 0+[1-9]+

FRACTION {INTEGER}"f"{INTEGER}

NOTFRACTION {INTEGER}"f"^{INTEGER}

NEWLINE "\n"


STRING "\"".*"\""

NOTSTRING "\"".*



DBLMULT "*"{}"*"
MULT "*"

COMMENT ":;".*


EXIT "(exit)"



%%



YYEOF {return(0);}

"\n" {/*Ignore newlines*/}


" " {/*Ignore whitespaces*/}


"and" {
		if(isQuoteOpened == 0)
		{
			printf("and: KW_AND\n");
		}
	}


"or" {
	if(isQuoteOpened == 0)
		{
			printf("or: KW_OR\n");
		}
	}


"not" {
	if(isQuoteOpened == 0)
		printf("not: KW_NOT\n");
	}


"equal" {
	if(isQuoteOpened == 0)
		printf("equal: KW_EQUAL\n");
	}



"less" {
	if(isQuoteOpened == 0)
		printf("less: KW_LESS\n");
	}




"nil" {
	if(isQuoteOpened == 0)
		printf("nil: KW_NIL\n");
	}



"list" {
	if(isQuoteOpened == 0)
		printf("list: KW_LIST\n");
	}



"append" {
	if(isQuoteOpened == 0)
		printf("append: KW_APPEND\n");
	}


"if" {
	if(isQuoteOpened == 0)
		printf("if: KW_IF\n");
	}


"concat" {
	if(isQuoteOpened == 0)
		printf("concat: KW_CONCAT\n");
	}



"set" {
	if(isQuoteOpened == 0)
		printf("set: KW_SET\n");
	}



"deffun" {
	if(isQuoteOpened == 0)
		printf("deffun: KW_DEFFUN\n");
	}




"for" {
	if(isQuoteOpened == 0)
		printf("for: KW_FOR\n");
	}





"exit" {
	if(isQuoteOpened == 0)
		printf("exit: KW_EXIT\n");
	}




"load" {
	if(isQuoteOpened == 0)
		printf("load: KW_LOAD\n");
	}



"disp" {
	if(isQuoteOpened == 0)
		printf("disp: KW_DISP\n");
	}



"true" {
	if(isQuoteOpened == 0)
		printf("true: KW_TRUE\n");
	}



"false" {
	if(isQuoteOpened == 0)
		printf("false: KW_FALSE\n");
	}




"+" {
	if(isQuoteOpened == 0)
		printf("+: OP_PLUS\n");
	}


"," {
	if(isQuoteOpened == 0)
		printf(",: OP_COMMA\n");
	}


"-" {
	if(isQuoteOpened == 0)
		printf("-: OP_MINUS\n");
	}

"/" {
	if(isQuoteOpened == 0)
		printf("/: OP_DIV\n");
	}

"*" {
	if(isQuoteOpened == 0)
		printf("*: OP_MULT\n");
	}



"(" {
	if(isQuoteOpened == 0)
		printf("(: OP_OP\n");
	}

")" {
	if(isQuoteOpened == 0)
		printf("): OP_CP\n");
	}


"**" {
	if(isQuoteOpened == 0)
		printf("**: OP_DBLMULT\n");
	}

";;".* {
	if(isQuoteOpened == 0)
		printf(";;: COMMENT\n");
	}







{STRING} {

			const int x = strlen(yytext)-2;

			char stringWithoutQuotes[x];

			for( int i=1 ; i <= x ; i++ )
			{
				stringWithoutQuotes[i-1] = yytext[i];
			}

			stringWithoutQuotes[x] = '\0';

			printf("\": OP_OC\n");
			printf("%s: VALUESTR\n" , stringWithoutQuotes);
			printf("\": OP_CC\n");
}


{NOTSTRING} {
	printf("%s is not a valid token\n",yytext);
}




{NOTINTEGER} {
	if(isQuoteOpened == 0)
		printf("%s is not a valid token\n",yytext);
		exit(1);
	}

{INTEGER} {
	if(isQuoteOpened == 0)
		printf("%s: VALUEI\n",yytext);
	}



{NOTFRACTION} {
	if(isQuoteOpened == 0)
		printf("%s is not a valid token\n",yytext);
		exit(1);
}


{FRACTION} {
	if(isQuoteOpened == 0)
		printf("%s: VALUEF\n",yytext);
	}






{ID} {
	if(isQuoteOpened == 0)
		printf("%s: IDENTIFIER\n",yytext);
	}


{COMMENT} {
	if(isQuoteOpened == 0)
		printf("%s: COMMENT\n",yytext);
	}




<<EOF>> {
		return(0);
	}


{EXIT} {
	if(isQuoteOpened == 0)
		{
			printf("Bye.");
			exit(1);
		}

	}



. {
	if(isQuoteOpened == 0)
		printf("%s is not a valid token\n",yytext);
		exit(1);
	}



%%











int yywrap(){}

int main(int args , char** argv)
{

	printf("\e[1;1H\e[2J");  //Clear screen

	switch(args)
	{
		case 2:
			if( strlen(argv[1]) < 5 )
			{
				printf("Invalid extension of source file...\n");
				return 1;
			}

			else
			{
				int fileNameLastIndex = strlen(argv[1]) - 1;


				if( (argv[1][fileNameLastIndex] != 'p') || (argv[1][fileNameLastIndex-1] != 'p') || (argv[1][fileNameLastIndex-2] != 'g') || (argv[1][fileNameLastIndex-3] != '.') )
				{
					printf("Invalid extension of source file...\n");
					return 1;
				}
				else
				{
					yyin = fopen( argv[1] , "r" );
					if( yyin == NULL )
					{
						printf("File read error...\n");
						return 1;
					}
				}
			}
		case 1:
			yylex();
			break;
		default:
			printf("Invalid Argument...\n");
	}


  
	return 0;
}






