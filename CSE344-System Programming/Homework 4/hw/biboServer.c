#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <semaphore.h>
#include "connectionelements.h"
#include "tokenizationoperations.h"
#include <pthread.h>




pthread_mutex_t mutex;
pthread_t* threads;
int threadsIndex = -1;


int logFileFD = -1;




int MAX_NUM_OF_CLIENTS = 0;
int clientPID = -1;







void checkServerProgramArguments( int args , char** argv );
void continueRunInDirectory( char* pathName );
void* handleRequest(void* arg);
void copyFile(char* fileName , char* sourceDirectory , char* destDirectory );
void readLine( char* fileName , int lineNum );
void addClient( char* pidOfClient , char* pathOfClient);
void openLogFile();
void sendListOfFilesToClient();
void initializeThreads( int numOfThreads );
void runInNewThread();









//Frees thread array
//unlinks fifos
void handleCtrlC(int signal)
{
    printf("Kill signal for client detected. Exiting...\n");
    strcpy( SERVER_TO_CLIENT_BUFFER , "killClient" );
    close(serverFifoFileDescriptor);
    close(clientFifoFileDescriptor);
    unlink(SERVER_FIFO_PATH);
    unlink(CLIENT_FIFO_PATH);
    close(logFileFD);
    free(threads);
    exit(0);
}




int main( int args , char** argv )
{

    signal(SIGINT, handleCtrlC);

    checkServerProgramArguments(args,argv);  //Checks correctness of commands


    printf("Server started PID %d\n",getpid());  //Prints the message that shows server has started
    fflush(stdout);


    strcpy(SERVER_WORKING_DIRECTORY,argv[1]);          //Sets server's running directory and
    continueRunInDirectory( argv[1] );  //stores it for coming actions


    openLogFile();

    MAX_NUM_OF_CLIENTS = atoi( argv[2] );   //Sets maximum number of clients



    initializeThreads( MAX_NUM_OF_CLIENTS );




    umask(0);
    generateServerFifo( getpid() );
    openServerFifo( getpid() );







    while(1)
    {

        
        ssize_t bytesRead = read( serverFifoFileDescriptor, CLIENT_TO_SERVER_BUFFER , BUFFER_SIZE );

        if( bytesRead > 0 )  //Getting request and executing it at available thread
        {
            char **tokenizedRequest = tokenizeGivenCommand(CLIENT_TO_SERVER_BUFFER);
            if( strcmp( tokenizedRequest[0] ,"Connect") == 0)
            {
                addClient( tokenizedRequest[1] , tokenizedRequest[2] );
                usleep(1000);
            }
            else
            {
                runInNewThread();
                threadsIndex--; //After execution,sets threadsIndex to track num of threads
            }
            free(tokenizedRequest);

        }

    }





}














//Checks validity of arguments
void checkServerProgramArguments( int args , char** argv )
{

    //Checking number of arguments
    if( args != 3 )
    {
        perror("Invalid number of arguments...\n");
        exit(1);
    }


    const char* arg2 = argv[1];  
    const char* arg3 = argv[2];  

   

    if( argv[1][0] != '/' )
    {
        perror("Invalid path name...\n");
        exit(1);
    }

    const int lengthOfPIDString = strlen( arg3 );

    for( int i = 0 ; i < lengthOfPIDString ; i++ )
    {
        if( (arg3[i] > '9') || (arg3[i] < '0') )
        {
            perror("Invalid number of max clients...\n");
            exit(1);
        }
    }

}






void continueRunInDirectory( char* pathName )
{



    char* dynamicPathName = malloc( sizeof(char) * strlen(pathName) + 1 );
    dynamicPathName[0] = '\0';


    for( int i = 0 ; i < strlen(pathName) ; i++ )
    {
        dynamicPathName[ i + 1 ] = '\0';
        dynamicPathName[i] = pathName[i];

        if(pathName[i] == '/')
        {
            if( mkdir( dynamicPathName , (S_IRWXU | S_IRWXG | S_IRWXO) ) != 0 )
            {
                if( errno == EACCES )
                {
                    fprintf( stderr , "Access denied to path \"%s\",terminating..." , dynamicPathName );
                    exit(1);
                }
            }
        }


    }


    if( mkdir( pathName , (S_IRWXU | S_IRWXG | S_IRWXO) ) != 0 )
    {

        if( errno == EACCES)
        {
            fprintf( stderr , "Access denied to path \"%s\",terminating..." , dynamicPathName );
            exit(1);
        }

    }





    if( chdir( pathName ) != 0 )
    {
        fprintf(stderr, "The path \"%s\" is accesible but server cannot start in there...\n",pathName );
        exit(1);
    }

    free( dynamicPathName );



}




//Get request from server and handle it by tokenizing
void* handleRequest(void* arg)
{
    


    char request[BUFFER_SIZE] = "";
    strcpy(request,CLIENT_TO_SERVER_BUFFER);



    char** tokenizedRequest = tokenizeGivenCommand( request );


        if( strcmp( tokenizedRequest[0] , "list" ) == 0 )
        {

            sendListOfFilesToClient();
        }
        if( strcmp( tokenizedRequest[0] ,"download") == 0 ) 
        {

            char downloadMessage[100];
            sprintf( downloadMessage,"%d",clientPID );
            strcat(downloadMessage," PID client made download operation\n");
            if( write(logFileFD, downloadMessage, 100) == -1 )
            {
                perror("Cannot write download message to log file...\n");
            }
            copyFile( tokenizedRequest[1] , SERVER_WORKING_DIRECTORY , CLIENT_WORKING_DIRECTORY );
        }
        if( strcmp( tokenizedRequest[0],"upload") == 0 )
        {
            char uploadMessage[100] = "Upload operation : ";
            sprintf( uploadMessage,"%d",clientPID );
            strcat(uploadMessage," PID client made upload operation\n");
            if( write(logFileFD, uploadMessage, 100) == -1 )
            {
                perror("Cannot write upload message to log file...\n");
            }
            copyFile( tokenizedRequest[1]  , CLIENT_WORKING_DIRECTORY , SERVER_WORKING_DIRECTORY );
        }
        if( strcmp( tokenizedRequest[0] , "kill") == 0 )
        {
            char killMessage[100] = "Server Killed by client\n";
            if( write(logFileFD, killMessage, 100) == -1 )
            {
                perror("Cannot write lill message to log file...\n");
            }
            close(serverFifoFileDescriptor);
            close(clientFifoFileDescriptor);
            unlink(SERVER_FIFO_PATH);
            unlink(CLIENT_FIFO_PATH);
            close(logFileFD);
            free(threads);
            exit(0);
        }
        if( strcmp( tokenizedRequest[0] , "readF") == 0 )
        {

            readLine( tokenizedRequest[1] , atoi(tokenizedRequest[2] ) );  //send line to client
            char downloadMessage[100];
            sprintf( downloadMessage,"%d",clientPID );
            strcat(downloadMessage," PID client made download operation\n");
            if( write(logFileFD, downloadMessage, 100) == -1 )
            {
                perror("Cannot write download/upload message to log file...\n");
            }
        }
        if( strcmp( tokenizedRequest[0] , "killClient") == 0 )
        {
            printf("Client PID %d left...\n",clientPID);

        }
        if( strcmp( tokenizedRequest[0] , "quit" ) == 0)
        {
            printf( "Client with PID %d quits..." , clientPID );
            fflush(stdout);
        }

    pthread_exit(NULL);
}




//This function forks main server process
//Then creates a new fifo to get requests from server
//Also opens a fifo to send response to the client
//Sends the information to client ; with this info,client gets able to open that fifo and be able to send request to new created server process
void addClient( char* pidOfClient , char* pathOfClient )
{
    if( fork() == 0 )
    {
        strcpy(CLIENT_WORKING_DIRECTORY,pathOfClient);
        clientPID = atoi(pidOfClient);
        openClientFifo( clientPID );
        printf("Client PID %s connected as \"client01\" with fifo -> %d to pid %d server\n",pidOfClient,clientFifoFileDescriptor,getpid());
        fflush(stdout);



        generateServerFifo( getpid() );     //For new child process,new fifo to get request is created
        openServerFifo( getpid() );     //That new fifo is opened


        char pidOfNewForkedServer[20];
        sprintf( pidOfNewForkedServer , "%d" , getpid() );
        strcpy( SERVER_TO_CLIENT_BUFFER, "  ForkedServerPID: " );
        strcat( SERVER_TO_CLIENT_BUFFER, pidOfNewForkedServer );
        strcat( SERVER_TO_CLIENT_BUFFER, " " );
        writeToClientFifo();

    }

}




//This fonction handled download and upload comments by copying file from a directory to another
void copyFile( char* fileName , char* sourceDirectory , char* destDirectory )
{
    char sourceFilePath[50];
    char destFilePath[50];


    //Setting file dest and source file paths
    strcpy(sourceFilePath,sourceDirectory);
    strcat(sourceFilePath,"/");
    strcat(sourceFilePath,fileName);

    strcpy(destFilePath,destDirectory);
    strcat(destFilePath,"/");
    strcat(destFilePath,fileName);

    umask(0);





    //Opening destination and source files
    int sourceFd = open( sourceFilePath , O_RDONLY );
    if( sourceFd == -1 )
    {
        fprintf(stderr,"Can't open file \"%s\"...\n",sourceFilePath );
        return;
    }

    int destinationFd = open( destFilePath , O_CREAT | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH| O_WRONLY );
    if( destinationFd == -1 )
    {
        fprintf(stderr, "Can't open/create file \"%s\"...\n",destFilePath );
        return;
    }




    char fileTransferBuffer[8192];
    long totalBytesTransfered = 0;
    while(1)
    {
        int bytesRead = read( sourceFd , fileTransferBuffer , 8192 );
        if( bytesRead == 0 )
        {
            break;
        }
        else if( bytesRead == -1 )
        {
            perror("Can't get file...\n");
            return;
        }

        int bytesWrite = write( destinationFd , fileTransferBuffer , bytesRead );
        if( bytesWrite == -1 )
        {
            perror("Can't write file 1 %d...\n");
            return;         
        }

        totalBytesTransfered += bytesWrite;
    }


    char bytesTransferedMessage[100] = "";
    sprintf( bytesTransferedMessage, "%ld", totalBytesTransfered);
    strcat( bytesTransferedMessage , " bytes transfered...\n" );

    strcpy( CLIENT_TO_SERVER_BUFFER , bytesTransferedMessage );
    writeToClientFifo();



    if (chmod(destFilePath, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH) == -1)
    {
        perror("Can't set file permissions...\n");
        return;
    }

    close(sourceFd);
    close(destinationFd);


}





//This function reads the line with given number from file and sends to the server,if given line does not exits;sends entire file
void readLine( char* fileName , int lineNum )
{


    char filePath[2000] = "";
    strcat( filePath , SERVER_WORKING_DIRECTORY );
    strcat( filePath , "/" );
    strcat( filePath , fileName );
    FILE* file = fopen( filePath , "r" );

    if( file == NULL )
    {
        strcpy( SERVER_TO_CLIENT_BUFFER , "Can't open file,file not exist\n" );
        writeToClientFifo();
        return;
    }

    char allFile[100000] = "";
    char line[ BUFFER_SIZE ];
    int countLine = 0;
    while (fgets( line , BUFFER_SIZE , file ) != NULL )
    {
        fflush(stdout);
        strcat( allFile , line );
        countLine++;
        if( countLine == lineNum )
        {
            strcpy( SERVER_TO_CLIENT_BUFFER , line );
            if( strcmp(SERVER_TO_CLIENT_BUFFER,"\n") != 0 )
            {
                writeToClientFifo();
            }
            return;
        }
    }

        int bytesWrite = write( clientFifoFileDescriptor , allFile , (strlen( allFile ) % 100000));

        if( bytesWrite == -1 )
        {
            printf("Can't write file 3     %s...\n"," ");
            fflush(stdout);
            return;         
        }  
    

    fclose( file );
}







void openLogFile()
{
    char serverPIDStr[20];
    sprintf(serverPIDStr, "%d", getpid());

    logFileFD = open( strcat(serverPIDStr,".log") , O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR );
    if( logFileFD == -1 )
    {
        perror("Cannot create log file...\n");
        exit(1);
    }
}









void sendListOfFilesToClient()
{
    char allNames[10000] = "";
    int lengthOfConcatenatedNames = 0;
            DIR *d;
            struct dirent *dir;
            d = opendir(".");
            if(d != 0)
            {
                while(1)
                {
                    dir = readdir(d);
                    if(dir == NULL)
                    {
                        break;
                    }
                    strcat( allNames , dir->d_name );
                    strcat( allNames , "\n" );
                    lengthOfConcatenatedNames += strlen( dir->d_name + 1 );
                }

                



                char listMessage[100];
                sprintf( listMessage,"%d",clientPID );
                strcat(listMessage," PID client made list request...\n");
                if( write(logFileFD, listMessage, 100) == -1 )
                {
                    perror("Cannot write list request to log file...\n");
                }
                closedir(d);
                ssize_t bytesWritten = write( clientFifoFileDescriptor , allNames , 10000 );
                if( bytesWritten == -1 )
                {
                    perror("Response from server could not written to the fifo...\n");
                    exit(1);
                }
                usleep(10000);

            }
}







void initializeThreads( int numOfThreads )
{
    threads = malloc( sizeof(pthread_t) * (numOfThreads + 1) );
    pthread_mutex_init(&mutex, NULL);
    for( int i=0 ; i<numOfThreads ; i++ )
    {
         threads[i] = NULL;
    }
}


void runInNewThread()
{

    pthread_mutex_lock(&mutex);
    threadsIndex++;
    if( threadsIndex < 0 )
    {
        perror("Error with process in new thread...\n");
        exit(1);
    }
    else if( threadsIndex == MAX_NUM_OF_CLIENTS )
    {
        perror("All threads busy...\n");
    }
    else
    {
        pthread_create( &threads[threadsIndex] , NULL , handleRequest , (void *)&threads[threadsIndex] );
    }
    pthread_mutex_unlock(&mutex);
}

















