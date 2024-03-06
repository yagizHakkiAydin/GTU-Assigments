#ifndef THREADOPERATIONS_H
#define THREADOPERATIONS_H


#include <stdlib.h>
#include <pthread.h>





void* handleClient(void* arg);
void handleRequest( char* request );


struct threadPool
{
	pthread_t thread;
	int isAvailable;
	int clientAcceptSocket;
}threadPool;


struct threadPool* _threadPool;	//This keeps thread pool


int threadPoolSize;	//Size of the treadpool



//Creates thread pool and initializes it as empty
void createThreadPool( int poolSize )
{

	threadPoolSize = poolSize;
	_threadPool = malloc( sizeof( struct threadPool ) * poolSize );


	if( _threadPool == NULL )
	{
		perror("Thread pool could not be allocated properly...\n");
		exit(1);
	}


	for( int i=0 ; i<poolSize ; i++ )
	{
		_threadPool[i].isAvailable = 0;
		_threadPool[i].clientAcceptSocket = -1;
	}


}






int addClient( int clientAcceptSocket )
{
	for( int i=0 ; i<threadPoolSize ; i++ )
	{

		if( _threadPool[i].isAvailable == 0 )
		{
			_threadPool[i].clientAcceptSocket = clientAcceptSocket;
			if (pthread_create( &_threadPool[i].thread , NULL , handleClient , (void*)&_threadPool[i].clientAcceptSocket) != 0)
			{
				perror("Failed to create thread");
				return 0;
			}


			return 1;
		}
	}



	return 0;
}








void* handleClient(void* arg)
{
	printf("lelelelele\n");
    int* clientSocket = NULL;
    clientSocket = (int*)(arg);

    char buffer[1024] = "";

    while (1)
    {
    	//recieving from the client
        int bytesRead = recv( *clientSocket , buffer , 1024 , 0);
        if (bytesRead == -1)
        {
            perror("Error while receiving message from the client");
            exit(1);
        }


        handleRequest( buffer );
        // Process the received message as needed

        // ...

        // If necessary, send a response to the client
        // send(clientSocket, response, strlen(response), 0);
    }

    pthread_exit(NULL);
}





void releaseThread( int index )
{
	if (index >= 0 && index < threadPoolSize)
	{
		pthread_cancel(_threadPool[index].thread);
		_threadPool[index].isAvailable = 0;
		_threadPool[index].clientAcceptSocket = -1;
	}
}










void handleRequest( char* request )
{
	int tokenNumber = howManyTokensGivenCommandHas( request );
	char** tokenizedRequest = tokenizeGivenCommand( request );

	char requestType[100] = "";
	strcpy( requestType , tokenizedRequest[0] );

	char clientIPAdress[100] = "";
	strcpy( clientIPAdress , tokenizedRequest[1] );

	char clientIPDirectory[100] = "";
	strcpy( clientIPDirectory , tokenizedRequest[2] );



	if( howManyTokensGivenCommandHas < 2 )
	{
		return;
	}



	printf("Request");
	fflush( stdout );

	for( int i = 0 ; i < tokenNumber ; i++ )
	{
		free(tokenizedRequest[i]);  // Free each row
	}
    free(tokenizedRequest);  // Free the array itself
}





#endif