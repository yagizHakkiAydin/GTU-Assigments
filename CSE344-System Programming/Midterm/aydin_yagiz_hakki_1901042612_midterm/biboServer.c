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


int forkFlag = 1;


const int BUFFER_SIZE = 1024;
char buffer[BUFFER_SIZE];




int logFileFD = -1;




int MAX_NUM_OF_CLIENTS = 0;
int* clients = NULL;
int clientFifo = -1;
int clientPID = -1;
int serverFifo = -1;



char SERVER_FIFO_PATH[500] = "/tmp/serverfifo_";
char clientFifoPath[100] = "/tmp/clientfifo_";
char serverPath[500] = "";
char clientPath[500] = "";
char request[500] = "";


int NUM_OF_CONNECTED_CLIENTS = 0;



void checkServerProgramArguments( int args , char** argv );
void continueRunInDirectory( char* pathName );
void handleRequest(char* request);
void copyFile(char* fileName , char* sourceDirectory , char* destDirectory );
void setServerFifoPath(int pid);
void readLine( char* fileName , int lineNum );
void addClient( char* pidOfClient , char* pathOfClient);


sem_t* semaphore = NULL;



void handleCtrlC(int signal)
{
    printf("Kill signal for client detected. Exiting...\n");
    strcpy(buffer,"killClient");
    close(serverFifo);
    close(clientFifo);
    close(logFileFD);
    exit(0);
}




int main( int args , char** argv )
{

    signal(SIGINT, handleCtrlC);

    checkServerProgramArguments(args,argv);  //Checks correctness of commands


    printf("Server started PID %d\n",getpid());  //Prints the message that shows server has started
    fflush(stdout);


    strcpy(serverPath,argv[1]);          //Sets server's running directory and
    continueRunInDirectory( argv[1] );  //stores it for coming actions





    char serverPIDStr[20];
    sprintf(serverPIDStr, "%d", getpid());

    logFileFD = open( strcat(serverPIDStr,".log") , O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR );
    if( logFileFD == -1 )
    {
        perror("Cannot create log file...\n");
        exit(1);
    }


    MAX_NUM_OF_CLIENTS = atoi( argv[2] );   //Sets maximum number of clients



    semaphore = sem_open("/tmp/", O_CREAT, 0644, 1);
    if (semaphore == SEM_FAILED) {
        perror("Error creating semaphore...\n");
        exit(1);
    }








    umask(0);
    setServerFifoPath(getpid());   //Creates the fifo to get request from client
    if( mkfifo( SERVER_FIFO_PATH , S_IRUSR | S_IWUSR | S_IWGRP ) == -1 && errno != EEXIST )
    {
        perror("mkfifo error");
    }
    serverFifo = open( SERVER_FIFO_PATH , O_RDONLY  |  O_NONBLOCK );








    strcpy(buffer,"");
    while(1)
    {
        
        ssize_t bytesRead = read( serverFifo , buffer , BUFFER_SIZE );

        if( bytesRead > 0 )  //Getting request
        {
            handleRequest( buffer );
        }

    }





}















void checkServerProgramArguments( int args , char** argv )
{

    //Checking number of arguments
    if( args != 3 )
    {
        perror("Invalid number of arguments...\n");
        exit(1);
    }


    const char* arg2 = argv[1];  //
    const char* arg3 = argv[2];   //

   




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
void handleRequest(char* request)
{
    char copyOfRequest[200];

    strcpy(copyOfRequest,request);
    if( strcmp(strtok(copyOfRequest, " \n"),"Connect") == 0)
    {
        strcpy(copyOfRequest,strtok(0," \n"));
        addClient( copyOfRequest ,strtok(0," \n"));
        char listMessage[100];
        sprintf( listMessage,"%d",clientPID );
        strcat(listMessage," PID client made list request...\n");
        if( write(logFileFD, listMessage, 100) == -1 )
        {
            perror("Cannot write list request to log file...\n");
        }

    }
    if( forkFlag == 0 )  //perform if it is forked server process
    {
        strcpy(copyOfRequest,request);
        if( strcmp(strtok(copyOfRequest, " \n"),"list") == 0 )
        {
    
            DIR *d;
            struct dirent *dir;
            d = opendir(".");
            char fileList[10000] = "";
            if(d != 0)
            {
                while(1)
                {
                    dir = readdir(d);
                    if(dir == NULL)
                    {
                        break;
                    }
                    strcat( fileList , dir->d_name );
                    strcat( fileList , "\n" );
                }
                fflush(stdout);
                int bytesWrite = write( clientFifo , fileList , 10000 );
                if( bytesWrite == -1 )
                {
                    //printf("Can't respond to     %s...\n"," ");
                    fflush(stdout);
                    return;         
                }
                char listMessage[100];
                sprintf( listMessage,"%d",clientPID );
                strcat(listMessage," PID client made list request...\n");
                if( write(logFileFD, listMessage, 100) == -1 )
                {
                    perror("Cannot write list request to log file...\n");
                }
                closedir(d);
            }
        }
        strcpy(copyOfRequest,request);
        if( strcmp(strtok(copyOfRequest, " \n"),"download") == 0 ) 
        {

            strcpy(copyOfRequest,strtok(0, " \n"));  //extract filename

            //Write to log file

            char downloadMessage[100];
            sprintf( downloadMessage,"%d",clientPID );
            strcat(downloadMessage," PID client made download operation\n");
            if( write(logFileFD, downloadMessage, 100) == -1 )
            {
                perror("Cannot write download message to log file...\n");
            }
            printf("sp ------ %s\n",serverPath);
            copyFile( copyOfRequest , serverPath , clientPath );
        }
        strcpy(copyOfRequest,request);
        if( strcmp(strtok(copyOfRequest, " \n"),"upload") == 0 )
        {
            strcpy(copyOfRequest,strtok(0, " \n"));  //extract filename

            //Write to log file

            char uploadMessage[100] = "Upload operation : ";
            sprintf( uploadMessage,"%d",clientPID );
            strcat(uploadMessage," PID client made upload operation\n");
            if( write(logFileFD, uploadMessage, 100) == -1 )
            {
                perror("Cannot write upload message to log file...\n");
            }
            copyFile( copyOfRequest  , clientPath , serverPath );
        }
        strcpy(copyOfRequest,request);
        if( strcmp(strtok(copyOfRequest, " \n"),"kill") == 0 )
        {
            char killMessage[100] = "Server Killed by client\n";
            if( write(logFileFD, killMessage, 100) == -1 )
            {
                perror("Cannot write lill message to log file...\n");
            }
            printf("Server Killed by client\n");
            close(serverFifo);
            close(clientFifo);
            close(logFileFD);
            exit(0);
            fflush(stdout);
            exit(0);
        }
        strcpy(copyOfRequest,request);
        if( strcmp(strtok(copyOfRequest, " \n"),"readF") == 0 )
        {
            char* token;
            token = strtok( 0 , " \n");
            readLine( token , atoi(strtok( 0 , " \n")) );  //send line to client
            char downloadMessage[100];
            sprintf( downloadMessage,"%d",clientPID );
            strcat(downloadMessage," PID client made download operation\n");
            if( write(logFileFD, downloadMessage, 100) == -1 )
            {
                perror("Cannot write download/upload message to log file...\n");
            }
        }
        strcpy(copyOfRequest,request);
        if( strcmp(strtok(copyOfRequest, " \n"),"killClient") == 0 )
        {
            printf("Client PID %d left...\n",clientPID);

        }
        if( strcmp(strtok(copyOfRequest, " \n") , "quit" ) == 0)
        {
            printf( "Client with PID %d quits..." , clientPID );
            fflush(stdout);
        }
    }
}




//43242 /tmp/clientDir
void addClient( char* pidOfClient , char* pathOfClient)
{
    forkFlag = fork();
    if( forkFlag == 0)
    {
        clientPID = atoi(pidOfClient);
        strcpy(clientFifoPath,"/tmp/clientfifo_");
        strcat( clientFifoPath , pidOfClient );
        strcat( clientFifoPath , ".fifo" );

        strcpy(clientPath,pathOfClient);

        clientFifo = open( clientFifoPath , O_RDWR | O_NONBLOCK );
        if( clientFifo == -1 )
        {
            fprintf(stderr, "Fifo for client with fifo : %s , could not opened...\n",clientFifoPath);
            exit(1);
        }
        else
        {
            printf("Client PID %s connected as \"client01\"\n",pidOfClient);
            fflush(stdout);
        }



        setServerFifoPath( getpid() );
        char commandToClientForNewServerFifo[400];
        strcpy( commandToClientForNewServerFifo , "ServerForkedWithFifo: " );
        strcat( commandToClientForNewServerFifo , SERVER_FIFO_PATH );



        if( mkfifo( SERVER_FIFO_PATH , S_IRUSR | S_IWUSR | S_IWGRP ) == -1 && errno != EEXIST )
        {
            perror("mkfifo error");
        }
        serverFifo = open( SERVER_FIFO_PATH , O_RDONLY  |  O_NONBLOCK );
        if( serverFifo == -1 )
        {
            perror("serverFifo open error\n");
            exit(1);
        }

        int bytesWrite = write( clientFifo , commandToClientForNewServerFifo , 400 );
        if( bytesWrite == -1 )
        {
            perror("After fork,server fifo could not created...");
            exit(1);
        }


    }

}





void copyFile( char* fileName , char* sourceDirectory , char* destDirectory )
{
    char sourceFilePath[50];
    char destFilePath[50];

    strcpy(sourceFilePath,sourceDirectory);
    strcat(sourceFilePath,"/");
    strcat(sourceFilePath,fileName);

    printf("s---> %s\n",sourceFilePath);
    fflush(stdout);

    strcpy(destFilePath,destDirectory);
    strcat(destFilePath,"/");
    strcat(destFilePath,fileName);
    printf("d---> %s\n",destFilePath);
    fflush(stdout);


    umask(0);
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




        if (sem_wait(semaphore) == -1)
        {
            perror("Semaphore can't lock...\n");
            sem_close(semaphore);
            exit(1);
        }

        int bytesWrite = write( destinationFd , fileTransferBuffer , bytesRead );
        if( bytesWrite == -1 )
        {
            perror("Can't write file 1 %d...\n");
            return;         
        }


        if (sem_post(semaphore) == -1)
        {
            perror("Semaphore can't unlock...\n");
            sem_close(semaphore);
            exit(1);
        }

    // Close and unlink the semaphore
    sem_close(semaphore);

        totalBytesTransfered += bytesWrite;
    }


    char bytesTransferedMessage[100] = "";
    sprintf( bytesTransferedMessage, "%ld", totalBytesTransfered);
    strcat( bytesTransferedMessage , " bytes transfered...\n" );

    printf("%s",bytesTransferedMessage);
    fflush(stdout);


    if( write(clientFifo, bytesTransferedMessage, 100) == -1 )
    {
        perror("Cannot send response message to the client...\n");
    }







    if (chmod(destFilePath, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH) == -1)
    {
        perror("Can't set file permissions...\n");
        return;
    }

    close(sourceFd);
    close(destinationFd);


}






void readLine( char* fileName , int lineNum )
{

    char filePath[2000] = "";
    strcat( filePath , serverPath );
    strcat( filePath , "/" );
    strcat( filePath , fileName );
    FILE* file = fopen( filePath , "r" );

    if( file == NULL )
    {
        //___________________Error condition
        strcpy( buffer , "Can't open file,file not exist\n" );
        int bytesWrite = write( clientFifo , buffer , BUFFER_SIZE );
        if( bytesWrite == -1 )
        {
            printf("Can't write file 3     %s...\n"," ");
            fflush(stdout);        
        }
        return;
    }


    char line[1000];
    int countLine = 0;
    while (fgets( line , 1000 , file ) != NULL )
    {
        countLine++;
        if( countLine == lineNum )
        {
            printf("line> %s\n",line);
            int bytesWrite = write( clientFifo , line , 1000 );
            if( bytesWrite == -1 )
            {
                printf("Can't write file 3     %s...\n"," ");
                fflush(stdout);        
            }
            return;
        }
    }

    if( countLine < lineNum)
    {
        while (fgets( line , 1000 , file ) != NULL )
        {
            printf("line> %s\n",line);
            int bytesWrite = write( clientFifo , line , 1000 );
            if( bytesWrite == -1 )
            {
                printf("Can't write file 3     %s...\n"," ");
                fflush(stdout);
                return;         
            }
        }     
    }

    fclose( file );
}





void setServerFifoPath( int pid )
{
    char pidOfServerStr[20];
    sprintf(pidOfServerStr, "%d", pid);
    strcpy(SERVER_FIFO_PATH,"/tmp/serverfifo_");
    strcat(SERVER_FIFO_PATH,pidOfServerStr);
    strcat(SERVER_FIFO_PATH,".fifo");
}











