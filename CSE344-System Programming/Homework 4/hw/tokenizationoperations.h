#ifndef TOKENIZATIONOPERATIONS_H
#define TOKENIZATIONOPERATIONS_H

#include <string.h>
#include <stdlib.h>







char** tokenizeGivenCommand( char* commandString );    //
int howManyTokensGivenCommandHas( char* commandString );   //




char** tokenizeGivenCommand(char* commandString)
{
	
    if (commandString == NULL || *commandString == '\0')
    {
        return NULL; // Handle empty or NULL command string
    }

    char** tokens = NULL;
    char commandStringCopyToGenerateTokens[1000];
    strcpy(commandStringCopyToGenerateTokens, commandString);

    int numberOfTokens = howManyTokensGivenCommandHas(commandStringCopyToGenerateTokens);

    char* tempTokenKeeper = strtok(commandStringCopyToGenerateTokens, " \n");

    tokens = malloc(sizeof(char*) * (numberOfTokens + 1)); // +1 for the NULL terminator

    if (tokens == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < numberOfTokens; i++)
    {
        tokens[i] = malloc(sizeof(char) * (strlen(tempTokenKeeper) + 1));

        if (tokens[i] == NULL)
        {
            return NULL;
        }

        strcpy(tokens[i], tempTokenKeeper);
        tempTokenKeeper = strtok(NULL, " \n");
    }

    tokens[numberOfTokens] = NULL;

    return tokens;
}





int howManyTokensGivenCommandHas( char* commandString)
{
	char commandStringCopyToCountTokens[ 1000 ];
	strcpy( commandStringCopyToCountTokens , commandString );

    int count = 0;
    char* temp = strtok( commandStringCopyToCountTokens , " \n" );

    while ( temp != NULL )
    {
        count++;
        temp = strtok( NULL , " \n" );
    }

    return count;
}





#endif