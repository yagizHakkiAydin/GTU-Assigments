#ifndef CONNECTIONELEMENTS_H
#define CONNECTIONELEMENTS_H




#define BUFFER_SIZE 1024

char SERVER_TO_CLIENT_BUFFER[ BUFFER_SIZE ] = "";
char CLIENT_TO_SERVER_BUFFER[ BUFFER_SIZE ] = "";


char SERVER_FIFO_PATH[300] = "/tmp/serverfifo_";	//Initialized by server , client will take it's name from server and conenct to the server fifo to connect
char CLIENT_FIFO_PATH[300] = "/tmp/clientfifo_";	//Initialized by client , server will take it's name from client and connect to the client fifo to connect



int serverFifoFileDescriptor = -1;
int clientFifoFileDescriptor = -1;




char SERVER_WORKING_DIRECTORY[300] = "";	//Keeps where server works,entered by user when starting servee
char CLIENT_WORKING_DIRECTORY[300] = "";	//Keeps where client work,defaultly set where client application performs







void openServerFifo( int pidOfServer )
{
    char pidOfServerString[20] = "";    //Converted from int to string
    sprintf( pidOfServerString , "%d" , pidOfServer );

    strcpy(SERVER_FIFO_PATH,"/tmp/serverfifo_");
    strcat(SERVER_FIFO_PATH,pidOfServerString);
    strcat(SERVER_FIFO_PATH,".fifo");

    serverFifoFileDescriptor = open( SERVER_FIFO_PATH , O_RDWR | O_NONBLOCK  );

    if( serverFifoFileDescriptor == -1 )
    {
        perror("Fifo for requests to server could not opened.Fifo might not be created by server correctly.Terminating...\n" );
        exit(1);
    }

}





void generateServerFifo( int pidOfServer )
{   
	char pidOfServerString[20] = "";    //Converted from int to string
    sprintf( pidOfServerString , "%d" , pidOfServer );

    strcpy(SERVER_FIFO_PATH,"/tmp/serverfifo_");
    strcat(SERVER_FIFO_PATH,pidOfServerString);
    strcat(SERVER_FIFO_PATH,".fifo");

    if( mkfifo( SERVER_FIFO_PATH , S_IRUSR | S_IWUSR | S_IWGRP ) == -1 && errno != EEXIST )
    {
        perror("Cannot generate server fifo to get requests,terminating...\n");
        exit(1);
    }
}



void openClientFifo( int pidOfClient )
{
    char pidOfClientString[20] = "";    //Converted from int to string
    sprintf( pidOfClientString , "%d" , pidOfClient );

    strcpy(CLIENT_FIFO_PATH,"/tmp/clientfifo_");
    strcat(CLIENT_FIFO_PATH,pidOfClientString);
    strcat(CLIENT_FIFO_PATH,".fifo");

    clientFifoFileDescriptor = open( CLIENT_FIFO_PATH , O_RDWR | O_NONBLOCK  );

    if( clientFifoFileDescriptor == -1 )
    {
        perror("Fifo for requests to server could not opened.Fifo might not be created by server correctly.Terminating...\n" );
        exit(1);
    }

}





void generateClientFifo( int pidOfClient )
{   
	char pidOfClientString[20] = "";    //Converted from int to string
    sprintf( pidOfClientString , "%d" , pidOfClient );

    strcpy(CLIENT_FIFO_PATH,"/tmp/clientfifo_");
    strcat(CLIENT_FIFO_PATH,pidOfClientString);
    strcat(CLIENT_FIFO_PATH,".fifo");

    if( mkfifo( CLIENT_FIFO_PATH , S_IRUSR | S_IWUSR | S_IWGRP ) == -1 && errno != EEXIST )
    {
        perror("Cannot generate client fifo to get requests,terminating...\n");
        exit(1);
    }
}



void writeToClientFifo( )
{

    ssize_t bytesWritten = write( clientFifoFileDescriptor , SERVER_TO_CLIENT_BUFFER , BUFFER_SIZE );
    if( bytesWritten == -1 )
    {
        perror("Response from server could not written to the fifo...\n");
        exit(1);
    }
}





void writeToServerFifo(  )
{



    ssize_t bytesWritten = write( serverFifoFileDescriptor , CLIENT_TO_SERVER_BUFFER , BUFFER_SIZE );
    if( bytesWritten == -1 )
    {
        perror("Request from server could not written to the fifo...\n");
        exit(1);
    }
}






#endif