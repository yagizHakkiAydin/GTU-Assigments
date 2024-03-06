#ifndef ARGUMENTCORRECTNESSCHECK_H
#define ARGUMENTCORRECTNESSCHECK_H



#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>




int isGivenStringPositiveInteger( const char* integer )
{

	const int numOfStrElements = strlen( integer );


	//Checking all elements of string,if there is a bad character ; returns 0
	for( int i=0 ; i<numOfStrElements ; i++ )
	{
		const char digit = integer[i];
		if( (digit > '9') || (digit < '0')  )
		{
			return 0;
		}
	}

	//If all elements of string are checked and passed the condition
	return 1;
}






int doesGivenDirectoryExist( const char* directory )
{

	DIR* dir = opendir( directory );
	if (dir)
	{
		closedir(dir);
		return 1;
	}
	else
	{
	    return 0;
	}
}







//   ./main <buffer size> <num of customers> <source directory> <destination directory>
void checkArgumentsOfMainProgram( int args , char** argv )
{
	if( args != 5 )	//Check number of arguments
	{
		perror("Invalid number of arguments...\n");
		exit(1);
	}
	else if( isGivenStringPositiveInteger(argv[1]) == 0 )	//Check correctness of buffer size 
	{
		perror("Invalid buffer size...\n");
		exit(1);		
	}
	else if( isGivenStringPositiveInteger(argv[2]) == 0 )	//Check correctness of buffer size 
	{
		perror("Invalid number of customers...\n");
		exit(1);
	}
	else if( doesGivenDirectoryExist(argv[3]) == 0 )	//Check if source directory exist
	{
		perror("Invalid source directory...\n");
		exit(1);
	}
}












#endif