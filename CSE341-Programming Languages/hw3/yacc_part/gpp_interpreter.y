

%{
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









%}




%union
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

};






%token KW_NIL

%token KW_WHILE

%token KW_IF

%token KW_EXIT

%token KW_LOAD

%token KW_DISP

%token <boolVal> KW_TRUE

%token <boolVal> KW_FALSE

%token DEFV

%token DEFF

%token COMMENT

%token <val> VALUEF

%token <val> ID



%token OP_COMMA

%token CP

%token OP

%token OP_MULT

%token OP_DIV

%token OP_MINUS

%token OP_PLUS

%token OP_AND

%token OP_OR

%token OP_NOT

%token OP_EQ

%token OP_GT

%token OP_SET


%type <val> start

%type <val> input

%type <val> exp

%type <val> explist

%type <val> function

%type <val> asg

%type <val> fcall

%type <boolVal> expb


%%





start : input { return 1; }



input : exp { $$ = $1;}
	   | explist { $$ = $1; }
	   | function { $$ = $1; }
	   | fcall








exp :   OP OP_PLUS exp exp CP {$$ = addFraction( $3 , $4 );printf("\n\nexp parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString($$));}
	   |OP OP_MINUS exp exp CP {$$ = subtractFraction( $3 , $4 );printf("\n\nexp parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString($$));}
	   |OP OP_MULT exp exp CP {$$ = multFraction( $3 , $4 );printf("\n\nexp parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString($$));}
	   |OP OP_DIV exp exp CP {$$ = divFraction( $3 , $4 );printf("\n\nexp parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString($$));}
	   | ID { 
				if(hasIdDeclaredBefore(yylval.keepStringOfTheCurrentToken.idName) == 1)
				{
					$$ = getValueOfId(yylval.keepStringOfTheCurrentToken.idName);
				}
				else
				{
					printf("\nId \"%s\" has not declared...\n",yylval.keepStringOfTheCurrentToken.idName);
					$$ = stringToFraction("0f1");
				}
	   		}

	   | VALUEF  { $$ = stringToFraction(yylval.keepStringOfTheCurrentToken.fractionStr);}
	   |fcall {$$ = $1;}
	   | asg { $$ = $1; }
	   |OP KW_IF expb explist explist CP { 
													if( $3 == 1 )
													{
														$$ = $4;
													}
													else
													{
														$$ = $5;
													}	
											   }



	   |OP KW_WHILE expb explist CP
	   {
		   int loopCounter;

	   }




	   |OP DEFV ID exp CP {
									$$ = $4;
									if( hasIdDeclaredBefore(yylval.keepStringOfTheCurrentToken.idName) == 0 )
									{
										addNewId(yylval.keepStringOfTheCurrentToken.idName , $4.intPart , $4.fractionPart);
										printf("\nID \"%s\" has not been declared before , assigned with value %s\n\n",yylval.keepStringOfTheCurrentToken.idName,yylval.keepStringOfTheCurrentToken.fractionStr);
									}
									else
									{
										printf("\n\nError,ID \"%s\" has been declared before\n\n",yylval.keepStringOfTheCurrentToken.idName);
									}
	   							}









expb :  OP OP_EQ exp exp CP { $$ = isFracEqual($3,$4); printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",$$);}
	   |OP OP_GT exp exp CP { $$ = isFracGreater($3,$4); printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",$$);}
	   |KW_TRUE { $$ = 1; printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",$$);}
	   |KW_FALSE { $$ = 0; printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",$$);}
	   |OP OP_AND expb expb CP { $$ = $3 && $4; printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",$$);}
	   |OP OP_OR expb expb CP { $$ = $3 || $4; printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",$$);}
	   |OP OP_NOT expb CP { $$ = !$3; printf("\n\nExpb parsed...\nSyntax ok.\nResult : %d\n\n",$$);}


explist : OP exp explist CP { $$ = $2; printf("\n\nExplist parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString($$));}
		  |  exp  { $$ = $1; printf("\n\nExplist parsed...\nSyntax ok.\nResult : %s\n\n",fractionToString($$));}

asg : OP OP_SET ID exp CP {
									assignFractionToId(yylval.keepStringOfTheCurrentToken.idName , $4);
									$$ = $4;
									$3 = $4;
								}

function :  OP DEFF ID OP CP exp CP{ 
													$$ = $6; addFunctionIfItsPossible(yylval.keepStringOfTheCurrentToken.tokenStringKeeper); 
													functionResultKeeper = $6;
													if( isFunctionCall == 1 )
													{
														char* result = fractionToString( functionResultKeeper );
														printf("\nresult = %s \n",result);
														free(result);
														isFunctionCall = 0;
													}
											    }
		   |OP DEFF ID OP ID CP exp CP{
													 $$ = $7; addFunctionIfItsPossible(yylval.keepStringOfTheCurrentToken.tokenStringKeeper);
													 functionResultKeeper = $7;
													 if( isFunctionCall == 1 )
													 {
														char* result = fractionToString( functionResultKeeper );
														printf("\nresult = %s \n",result);
														free(result);
														isFunctionCall = 0;
													 }
		   										  }
		   |OP DEFF ID OP ID ID CP exp CP{ 
														$$ = $8; addFunctionIfItsPossible(yylval.keepStringOfTheCurrentToken.tokenStringKeeper);
														functionResultKeeper = $8;
														if( isFunctionCall == 1 )
														{
															char* result = fractionToString( functionResultKeeper );
															printf("\nresult = %s \n",result);
															free(result);
															isFunctionCall = 0;
														}
		   											 }
		   |OP DEFF ID OP ID ID ID CP exp CP{
														 $$ = $9; addFunctionIfItsPossible(yylval.keepStringOfTheCurrentToken.tokenStringKeeper);
														 functionResultKeeper = $9;
														 if( isFunctionCall == 1 )
														 {
															char* result = fractionToString( functionResultKeeper );
															printf("\nresult = %s \n",result);
															free(result);
															isFunctionCall = 0;
														 }
		   												}



fcall : OP ID CP { $$ = stringToFraction("0f1"); callFunctionTypeOne(); }
	   |OP ID exp CP { $$ = $3; callFunctionTypeTwo("id1");}
	   |OP ID exp exp CP { $$ = $4; callFunctionTypeThree("id1","id2");}
	   |OP ID exp exp exp CP { $$ = $5; callFunctionTypeFour("id1","id2","id3");}




%%





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
