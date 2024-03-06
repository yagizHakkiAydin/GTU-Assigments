#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>






int fileDescriptorForLogFile = 0;  //This keeps file descriptor for log file,when shell starts,a new log file opened everytime



void redirect( char* command ); //This function makes redirecting if a command is redirecting command



void runCommands(char* commandLine); //This function takes command line that includes commands those are seperated
									//"|" pipe symbol and runs them with pipes,detailed explaination is at implementation


char** tokenizeCommandLine( char* commandLine );  //Takes command line and returns commands seperated with pipe symbol

char** tokenizeSingleCommand( const char* command );  //Takes a single command and tokenizes it

int checkIfCommandIsRedirection( const char* command );  //Checks if given command is redirection command

int createLogFile(); // Opens log file with the name corresponding to time stamp

void getTimeStr( char* timeStr ); //Sets timeStr to currant time with human readable time format

void writeToLogFile(int fd , int pid , char* command );  //Writes given command with given pid to the file at fd





void handleSGKILL()
{
	printf("Execution terminated by \"SGKILL\"...\n");
	close( fileDescriptorForLogFile );
	exit(1);
}










int main( int argc , char** argv )
{

	createLogFile();

	struct sigaction sigAct;
    sigAct.sa_handler = handleSGKILL;

    sigaction( SIGINT , &sigAct , NULL );


	while(1)
	{

		char line[4000];
		printf("\n->");
		fgets(line, sizeof(line), stdin);

		line[ strlen(line) - 1 ] = '\0';


		if( strcmp( line , ":q" ) == 0 )
		{
			printf("Execution terminated by \":q\" command...\n");
			close( fileDescriptorForLogFile );
			exit(0);
		}

		runCommands(line);

	}

	return 0;
}









void runCommands(char* commandLine)
{

	//This array contains commands at commands[i] for each i'th index.At the end of commands,it is marked with NULL
	char** commands = tokenizeCommandLine(commandLine);

	int pipeFileDescriptors[2]; //Pipe file descriptors

	int prev_pipe_read = STDIN_FILENO; //Read end of previous pipe



	for (int i = 0; commands[i] != NULL; i++)
	{

		if ( pipe( pipeFileDescriptors ) == -1 ) //Creates pipe and makes error check
		{
			perror("Error with \"pipe\"...\n");
			return;
		}

		int pid = fork(); //Creates a child process for next command


		if ( pid == -1 ) //Checks if there is any error for fork
		{
			perror("Error during fork...\n");
			exit(1);
		}
		else if ( pid == 0 ) //Checks if current process child process
		{
			//Checking if we are in first command because we assigned "STDIN_FILENO" to "prev_pipe_read"
			if ( prev_pipe_read != STDIN_FILENO )
			{
				//Connects previous process's output to child process's input and makes error check
				if ( dup2( prev_pipe_read , STDIN_FILENO ) == -1 )
				{
					perror("Error with \"dup2\"...\n");
					exit(1);
				}
				close( prev_pipe_read );
			}

			if( commands[i+1] != NULL )
			{
				// Connects output of the corresponding process to end of the pipe
				if( dup2( pipeFileDescriptors[1] , STDOUT_FILENO ) == -1)
				{
					perror("Error with \"dup2\"...\n");
					exit(1);
				}
			}



			close( pipeFileDescriptors[0] );
			close( pipeFileDescriptors[1] );





			if( checkIfCommandIsRedirection(commands[i]) )
			{
				redirect(commands[i]);
			}
			else
			{
				execl("/bin/sh", "sh", "-c", commands[i], NULL);
			}



			//If execl performed correctly,this part should not be executed
			fprintf(stderr, "Command \"%s\" could not be executed with \"execl\", terminating...\n", commands[i]);
			exit(1);


		}
		else // Proccess id is not 0 , so this is the parent process
		{
			close(pipeFileDescriptors[1]); // close write end of current pipe

			if( prev_pipe_read != STDIN_FILENO )
			{
				close(prev_pipe_read); // close read end of previous pipe
			}
			prev_pipe_read = pipeFileDescriptors[0]; //Keep read end of current pipe for the next process


			writeToLogFile( fileDescriptorForLogFile , pid , commands[i] );

			int status;
			wait(&status);
		}
	}
}






/*
	Takes a single command and checks if it is an redirection command
	if it is ; returns 1
	else ; returns 0
*/
int checkIfCommandIsRedirection( const char* command )
{
	//At every i'th index of tokenizedCommand , there exists an token of given command
	char** tokenizedCommand = tokenizeSingleCommand( command );


	int i = 0;  //Index for traversing tokens of commands

	//Checks all tokens of command
	while( tokenizedCommand[i] != NULL )
	{


		//Checks for redirection symbols , if symbol is found ; then it frees the memory for tokenizedCommand and returns 1.
		if( (strcmp(tokenizedCommand[i],"<") == 0) || (strcmp(tokenizedCommand[i],">") == 0) )
		{
			free(tokenizedCommand);
			return 1;
		}
		i++;
	}



	free(tokenizedCommand);  //These lines are executed if any redirection symbol are found
	return 0;			    //memory for tokenizedCommand is freed and 0 is returned as result
}







void redirect( char* command )
{
	char** tokenizedCommand = tokenizeSingleCommand( command );

	char* commandPartOfRedirection = "";

	int indexOfRedirectionSymbol = 0;


	if( checkIfCommandIsRedirection(command) == 0 )
	{	
		perror("Command is not redirection command for redirect function\n");
		exit(1);
	}
	else
	{
		while( tokenizedCommand[indexOfRedirectionSymbol] != NULL )
		{
			if( ( strcmp(tokenizedCommand[indexOfRedirectionSymbol],"<") == 0 ) || ( strcmp(tokenizedCommand[indexOfRedirectionSymbol],">") == 0 ) )
			{
				break;
			}
			indexOfRedirectionSymbol++;
		}
	}
	commandPartOfRedirection = malloc( strlen( command ) * sizeof(char) );
	for( int i=0 ; i<indexOfRedirectionSymbol ; i++ )
	{
		commandPartOfRedirection = strcat(commandPartOfRedirection,tokenizedCommand[i]);
		commandPartOfRedirection = strcat(commandPartOfRedirection," ");
	}



	int fileDescriptorForRedirecting = open( tokenizedCommand[ indexOfRedirectionSymbol + 1 ] , O_RDWR | O_CREAT , 0644 );

	if( fileDescriptorForRedirecting == -1 )
	{
		perror("Error with opening file\n");
		exit(1);
	}


	if( strcmp( tokenizedCommand[ indexOfRedirectionSymbol ] , ">" ) == 0 )
	{
		if( dup2( fileDescriptorForRedirecting , STDOUT_FILENO ) == -1 )
		{
			perror("Error with dup2\n");
			exit(1);
		}

		close( fileDescriptorForRedirecting );

		free( tokenizedCommand );

		execl( "/bin/sh" , "sh" , "-c" , commandPartOfRedirection , NULL );
	}
	else if( strcmp(tokenizedCommand[ indexOfRedirectionSymbol ] , "<" ) == 0 )
	{
		if( dup2( fileDescriptorForRedirecting , STDIN_FILENO ) == -1 )
		{
			perror("Error with dup2\n");
			exit(1);
		}
		close( fileDescriptorForRedirecting );

		free( tokenizedCommand );

		execl( "/bin/sh" , "sh" , "-c" , commandPartOfRedirection , NULL );
	}



}













char** tokenizeCommandLine( char* commandLine )
{

	if( commandLine == NULL )
	{
		return NULL;
	}


	char* commandLineCopy = strdup(commandLine);

	char** result = malloc( sizeof(char*) * strlen(commandLine) );


	char *temp = strtok( commandLineCopy , "|" );


	int i = 0;
	while( temp != NULL )
	{
		result[i] = malloc( sizeof(char)* strlen(temp) );
		strcpy( result[i] , temp );
		result[ i + 1 ] = NULL;
		i++;
		temp = strtok( NULL , "|" );
	}



	return result;

}


char** tokenizeSingleCommand( const char* command )
{

	if( command == NULL )
	{
		return NULL;
	}


	char* commandCopy = strdup(command);

	char** result = malloc( sizeof(char*) * strlen(command) );


	char *temp = strtok( commandCopy , " " );


	int i = 0;
	while( temp != NULL )
	{
		result[i] = malloc( sizeof(char)* strlen(temp) );
		strcpy( result[i] , temp );
		i++;
		temp = strtok( NULL , " " );
	}

	result[ i ] = NULL;

	result[ i-1 ][ strlen( result[ i-1 ] ) ] = '\0';


	return result;

}



int createLogFile()
{

	char timeStr[50];

	getTimeStr( timeStr );

	fileDescriptorForLogFile = open( strcat(timeStr,".txt") , O_RDWR | O_CREAT | O_APPEND , 0644 );

	if( fileDescriptorForLogFile == -1 )
	{
		perror("Log file could not created\n");
		fprintf(stderr, "%s\n", timeStr);
	}

	return fileDescriptorForLogFile;
}


void getTimeStr( char* timeStr )
{

  time_t currentTime = time( NULL );

  struct tm *timeStruct = localtime( &currentTime );

  strftime( timeStr , 50 , "%Y-%m-%d&&%H:%M:%S" , timeStruct );

}



void writeToLogFile(int fd , int pid , char* command )
{

	char logFileLine[1000];
	logFileLine[0] = '\0';

	char pidStr[100] = "";

	sprintf( pidStr , "%d" , pid );

	sprintf(logFileLine, "PID -> %d   |   COMMAND -> %s \n", pid, command);


	if(  write( fd , logFileLine , strlen(logFileLine) ) == -1 )
	{
		perror("Error for writing to log file\n");
	}
}









//execl("/bin/sh", "sh", "-c", commands[i], NULL);











