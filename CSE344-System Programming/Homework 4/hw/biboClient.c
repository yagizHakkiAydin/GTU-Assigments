#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>
#include "connectionelements.h"
#include "tokenizationoperations.h"










int checkClientProgramArguments( int args , char** argv );


void handleClientComment( char *comment );
void printHelpComment(const char* comment );
void connectServer();




void handleCtrlC(int signal)
{
    printf("Kill signal for client detected. Exiting...\n");
    strcpy(CLIENT_TO_SERVER_BUFFER,"killClient");
    close(serverFifoFileDescriptor);
    close(clientFifoFileDescriptor);
    unlink(CLIENT_FIFO_PATH);
    exit(0);  // Terminate the program
}







int main(int args,char** argv)
{
    
    signal(SIGINT, handleCtrlC);

    checkClientProgramArguments(args,argv);

    generateClientFifo( getpid() );
    openClientFifo( getpid() );



    //Gets client working directory to send server later
    if ( getcwd( CLIENT_WORKING_DIRECTORY , 500 ) == NULL )
    {
        perror("Client could not detect current path...\n");
        exit(1);
    }


    //Opens server fifo to connect only main process of the server and connects it;
    openServerFifo( atoi(argv[2]) );


    connectServer();


    char comment[200] = "";
    usleep(10000);
    while(1)
    {


        ssize_t bytesRead = read( clientFifoFileDescriptor , SERVER_TO_CLIENT_BUFFER , BUFFER_SIZE );
        if( bytesRead > 0 )  //Getting request
        {
            char** tokenizedResponse = tokenizeGivenCommand( SERVER_TO_CLIENT_BUFFER );

            if( tokenizedResponse != NULL )
            {
	            if( strcmp( tokenizedResponse[0] , "ForkedServerPID:" ) == 0)
	            {
	                openServerFifo( atoi( tokenizedResponse[1] ) );
	            }
	            else
	            {
	                printf("%s\n",SERVER_TO_CLIENT_BUFFER);
	                fflush(stdout);
	            }
            }


            free( tokenizedResponse );
        }
        else
        {
            printf("\nEnter comment : ");
            fflush(stdout);
            fgets(comment, 200, stdin);
            handleClientComment( comment );
            usleep(1000);
        }

    }





    return 0;
}












int checkClientProgramArguments( int args , char** argv )
{

    //Checking number of arguments
    if( args != 3 )
    {
        perror("Invalid number of arguments...\n");
        return 0;
    }


    const char* arg1 = argv[0];
    const char* arg2 = argv[1];  //
    const char* arg3 = argv[2];   //

   
    if( strcmp( arg1 , "./biboClient" ) != 0 )
    {
        perror("Invalid argument3...\n");
        return 0;
    }





    if( ( strcmp( arg2 , "connect" ) != 0 ) && ( strcmp( arg2 , "Connect" ) != 0 ) && ( strcmp( arg2 , "CONNECT" ) != 0 ))
    {
        perror("Invalid argument2...\n");
        return 0;
    }



    const int lengthOfPIDString = strlen( arg3 );

    for( int i = 0 ; i < lengthOfPIDString ; i++ )
    {
        if( (arg3[i] > '9') || (arg3[i] < '0') )
        {
            perror("Invalid PID...\n");
            return 0;
        }
    }

    return 1;  //If all arguments are correct
}









//sends request to server by tokenizing user input
void handleClientComment( char *comment )
{

    char** commentTokens = tokenizeGivenCommand( comment );
    char request[1024] = "";

    if( strcmp( commentTokens[0] , "help" ) == 0 )
    {
        printHelpComment( commentTokens[1] );
    }

    else if( strcmp( commentTokens[0] , "list") == 0 )
    {
        strcpy( request , "list" );
    }

    else if( strcmp( commentTokens[0] , "download") == 0 )
    {
        strcpy( request ,"download ");
        strcat( request , commentTokens[1] );
    }   
    else if( strcmp( commentTokens[0] , "upload") == 0 )
    {
        strcpy(request , "upload " );
        strcat( request , commentTokens[1] );
    }
    else if( strcmp( commentTokens[0] , "killServer") == 0 )
    {
        strcpy( request ,"kill" );

    }


    else if( strcmp( commentTokens[0] , "quit") == 0 )
    {
        strcpy( request , "quit" );
        writeToServerFifo();
        close(serverFifoFileDescriptor);
        close(clientFifoFileDescriptor);
        unlink(CLIENT_FIFO_PATH);
        exit(0);
    } 
    else if(  strcmp( commentTokens[0] , "readF") == 0 )
    {
         strcpy( request , commentTokens[0]);
         strcat( request , " " );
         strcat( request , commentTokens[1] );
         strcat( request , " " );
         strcat( request , commentTokens[2] );    
    }
    else
    {
    	free(commentTokens);
    }

    strcpy( CLIENT_TO_SERVER_BUFFER , request );
    writeToServerFifo();

}



//Help comment,does not need server to run
void printHelpComment(const char* comment)
{
        if( comment == NULL )
        {
            printf("\n    Available comments are : help, list, readF, writeT, upload, download, quit, killServer\n");

        }
        else if( strcmp( comment , "list" ) == 0 )
        {
            printf("\n    Prints list of all files available in server directory.\n");  
        }
        else if( strcmp( comment , "readF" ) == 0 )
        {
            printf("\n    readF <file> <line #>\n");  
            printf("        display the #th line of the <file>, returns with an\n");
            printf("        error if <file> does not exists\n");
        }
        else if( strcmp( comment , "writeT" ) == 0 )
        {
            printf("\n    writeT <file> <line #> <string>\n");  
            printf("        Writes <string> to #th line of the <file>\n");
            printf("        if <file> does not exists,creates file and writes end of it.\n");
            printf("        if #th line does not exists, writes end of file.\n");
        }
        else if( strcmp( comment , "upload" ) == 0 )
        {
            printf("\n    Uploads <file> to server.\n");  
        }
        else if( strcmp( comment , "download" ) == 0 )
        {
            printf("\n    Downloads <file> from server.\n");  
        }
        else if( strcmp( comment , "quit" ) == 0 )
        {
            printf("\n    Sends write request to Server side log file and quits.\n");  
        }
        else if( strcmp( comment , "killServer" ) == 0 )
        {
            printf("\n    Sends a kill request to the Server.\n");  
        }
        else
        {
            printf("\n    Invalid help comment...\n");
        }
}







//Write specific command to make server connect to that client ; comment in format "Connect <server id> <server path>"
//After this,server forks itself and then sends another specific response to make this client connect server's child process
void connectServer()
{   char pidOfClientStr[20];
    sprintf(pidOfClientStr, "%d", getpid());
    strcpy( CLIENT_TO_SERVER_BUFFER , "Connect " );
    strcat( CLIENT_TO_SERVER_BUFFER , pidOfClientStr );
    strcat( CLIENT_TO_SERVER_BUFFER , " " );
    strcat( CLIENT_TO_SERVER_BUFFER , CLIENT_WORKING_DIRECTORY );
    writeToServerFifo(  );
    usleep(10000);
}




