#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>





const int BUFFER_SIZE = 1024;
char buffer[BUFFER_SIZE] = "";
char BUFFER[BUFFER_SIZE] = "";





char SERVER_FIFO_PATH[500] = "/tmp/serverfifo_";
char CLIENT_PATH[500] = "";
int clientFifo = -1;
int serverFifo = -1;








int checkClientProgramArguments( int args , char** argv );


void handleClientComment( char *comment );
void printHelpComment(const char* comment );
void readF(const char* comment);
void connectServer(char* serverPID);
void setServerFifoPath( char* pidOfServer );




void handleCtrlC(int signal)
{
    printf("Kill signal for client detected. Exiting...\n");
    strcpy(buffer,"killClient");
    close(serverFifo);
    close(clientFifo);
    exit(0);
    exit(0);  // Terminate the program
}







int main(int args,char** argv)
{
    
    signal(SIGINT, handleCtrlC);
    umask(0);
    char pidStr[20];
    sprintf(pidStr, "%d", getpid());


    if ( getcwd( CLIENT_PATH , 500 ) == NULL )
    {
        perror("Client could not detect current path...\n");
        exit(1);
    }




    //------------------------------------------------------Server fifo is opened,client path and pid sent to server via serverfifo
    umask(0);
    setServerFifoPath( argv[2] );
    serverFifo = open( SERVER_FIFO_PATH , O_WRONLY  );;
    if( serverFifo == -1 )
    {
        fprintf(stderr, "Client cannot open serverFifo...fifo ->%s\n",SERVER_FIFO_PATH );
        exit(1);
    }


    //connect 31231231 /clientpath
    strcpy(buffer,"Connect ");
    strcat(buffer,pidStr);
    strcat(buffer," ");
    strcat(buffer,CLIENT_PATH);


    connectServer(NULL);
    usleep(1000);


    ssize_t bytesWritten = write(serverFifo, buffer, BUFFER_SIZE);
    if(bytesWritten == -1)
    {
        perror("Error writing to FIFO");
        exit(1);
    }

    usleep(1000);

    //------------------------------------------------------




    char comment[200] = "";

    while(1)
    {



        char response[10000] = "";
        ssize_t bytesRead = read( clientFifo , response , 10000 );
        if( bytesRead > 0 )  //Getting request
        {
            char responseCopy[10000];
            strcpy( responseCopy , response );
            if( strcmp( strtok( responseCopy , " \n"),"ServerForkedWithFifo:") == 0)
            {
                char* token;
                token = strtok( 0 , " \n");
                strcpy(SERVER_FIFO_PATH , token );
                serverFifo = open( SERVER_FIFO_PATH , O_WRONLY  );
                if( serverFifo == -1 )
                {
                    fprintf(stderr, "Client cannot open serverFifo   \n" );
                    exit(1);
                }
            }
            else
            {
                printf("%s",response);
                fflush(stdout);
            }
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










void handleClientComment( char *comment )
{


    char commentFirstToken[50];
    strcpy(commentFirstToken,strtok(comment, " \n"));


    if( strcmp( commentFirstToken , "help") == 0 )
    {
        comment = strtok(0, " \n");

        printHelpComment( comment );

    }

    else if( strcmp( commentFirstToken , "list") == 0 )
    {
        strcpy(buffer,"list");
        ssize_t bytesWritten = write(serverFifo, buffer, BUFFER_SIZE);
        usleep(10000);
        if(bytesWritten == -1)
        {
            perror("Error writing to FIFO");
            exit(1);
        }
    }

    else if( strcmp( commentFirstToken , "download") == 0 )
    {
        comment = strtok(0, " \n");
        strcpy(buffer,"download ");
        strcat(buffer , comment);

        ssize_t bytesWritten = write(serverFifo, buffer, BUFFER_SIZE);
        if(bytesWritten == -1)
        {
            perror("Error writing to FIFO");
            exit(1);
        }
    }   
    else if( strcmp( commentFirstToken , "upload") == 0 )
    {
        comment = strtok(0, " \n");
        strcpy(buffer,"upload ");
        strcat(buffer , comment);

        ssize_t bytesWritten = write(serverFifo, buffer, BUFFER_SIZE);
        if(bytesWritten == -1)
        {
            perror("Error writing to FIFO");
            exit(1);
        }
    }
    else if( strcmp( commentFirstToken , "killServer") == 0 )
    {
        strcpy(buffer,"kill");

        ssize_t bytesWritten = write(serverFifo, buffer, BUFFER_SIZE);
        if(bytesWritten == -1)
        {
            perror("Error writing to FIFO");
            exit(1);
        }
    }
    else if( strcmp( commentFirstToken , "quit") == 0 )
    {
        strcpy(buffer,"quit");

        ssize_t bytesWritten = write(serverFifo, buffer, BUFFER_SIZE);
        if(bytesWritten == -1)
        {
            perror("Error writing to FIFO");
            exit(1);
        }
        close(serverFifo);
        close(clientFifo);
        exit(0);
    } 
    else if(  strcmp( comment , "readF") == 0 )
    {
         strcpy(buffer,comment);
         strcat( buffer , " " );
         strcat( buffer , strtok(0, " \n") );
         strcat( buffer , " " );
         strcat( buffer , strtok(0, " \n") );

        ssize_t bytesWritten = write(serverFifo, buffer, BUFFER_SIZE);
        if(bytesWritten == -1)
        {
            perror("Error writing to FIFO");
            exit(1);
        }      
    }

}




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




void readF(const char* comment)
{
    char fileName[200];
    char lineNumber[200];

    strcpy(fileName,strtok(0, " \n"));
    strcpy(lineNumber,strtok(0, " \n"));
        printf("\ncomment entered : readF\n");
        printf("\nfile name %s=\n",fileName);
        printf("\nline = %s\n",lineNumber);
}






void connectServer( char* serverPID )
{

    char clientFifoPath[100] = "/tmp/clientfifo_";
    char pidStr[20];
    sprintf(pidStr, "%d", getpid());
    strcat( clientFifoPath , pidStr );
    strcat( clientFifoPath , ".fifo" );


    if( mkfifo( clientFifoPath, S_IRUSR | S_IWUSR | S_IWGRP ) == -1 && errno != EEXIST )
    {
        perror("mkfifo error");
        exit(1);
    }



    clientFifo = open( clientFifoPath, O_RDONLY | O_NONBLOCK  );

    if( clientFifo == -1 )
    {
        perror("clientFifo open error");
    }


}


void setServerFifoPath( char* pidOfServer )
{
    strcpy(SERVER_FIFO_PATH,"/tmp/serverfifo_");
    strcat(SERVER_FIFO_PATH,pidOfServer);
    strcat(SERVER_FIFO_PATH,".fifo");
}





