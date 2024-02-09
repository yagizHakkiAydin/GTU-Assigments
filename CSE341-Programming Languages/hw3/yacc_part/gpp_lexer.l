

%option noinput nounput


%{
	
	#include <stdio.h>
	#include "y.tab.h"



	void setTokenString()
	{
		char temp[200];

		const int yytextLen = strlen(yytext);

		for(int i=0 ; i<yytextLen ; i++)
		{
			temp[i] = yytext[i];
		}
		temp[yytextLen] = ' ';	
		temp[yytextLen+1] = '\0';	

		strcat(yylval.keepStringOfTheCurrentToken.tokenStringKeeper,temp);

	}

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
			setTokenString();
			return OP_AND;
		
	}


"or" {
			setTokenString();
			return OP_OR;	
	}


"not" {
		setTokenString();
		return OP_NOT;
	}


"eq" {
		setTokenString();
		return OP_EQ;
	}



"gt" {
		setTokenString();
		return OP_GT;
	}




"nil" {
		setTokenString();
		return KW_NIL;
	}



"defvar" {
		setTokenString();
		return DEFV;
	}



"deff" {
		setTokenString();
		return DEFF;
	}

"while" {
		setTokenString();
		return KW_WHILE;
	}



"if" {
		setTokenString();
		return KW_IF;
	}

"exit" {
		setTokenString();
		return KW_EXIT;
	}



"load" {
		setTokenString();
		return KW_LOAD;
	}



"disp" {
		setTokenString();
		return KW_DISP;
	}



"true" {
		setTokenString();
		return KW_TRUE;
	}



"false" {
		setTokenString();
		return KW_FALSE;
	}












"+" {
		setTokenString();
		return OP_PLUS;
	}


"," {
		setTokenString();
		return OP_COMMA;
	}


"-" {
		setTokenString();
		return OP_MINUS;
	}

"/" {
		setTokenString();
		return OP_DIV;
	}

"*" {
		setTokenString();
		return OP_MULT;
	}



"(" {
		setTokenString();
		return OP;
	}

")" {
		setTokenString();
		return CP;
	}

"set" {
		setTokenString();
		return OP_SET;
	}


";;".* {
		setTokenString();
		return COMMENT;
	}











{FRACTION} {
		const int yytextLen = strlen(yytext);

		for(int i=0 ; i<yytextLen ; i++)
		{
			yylval.keepStringOfTheCurrentToken.fractionStr[i] = yytext[i];
		}
		yylval.keepStringOfTheCurrentToken.fractionStr[yytextLen] = '\0';

		setTokenString();
	
		return VALUEF;
	}






{ID} {
		const int yytextLen = strlen(yytext);

		for(int i=0 ; i<yytextLen ; i++)
		{
			yylval.keepStringOfTheCurrentToken.idName[i] = yytext[i];
		}
		yylval.keepStringOfTheCurrentToken.idName[yytextLen] = '\0';

		setTokenString();

		return ID;
	}


{COMMENT} {

		return COMMENT;
	}




<<EOF>> {
		return 0;
	}




. {
	
		exit(1);
	}



%%











int yywrap(){}







