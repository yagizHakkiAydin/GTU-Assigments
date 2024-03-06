#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "tokenizationoperations.h"






void checkCommandLineArguments( int argc , char** argv );
void setClientSocketAddress( struct sockaddr_in* clientSocketAddress , char* serverIP , int portNumber );



int main(int argc, char** argv)
{


	checkCommandLineArguments( argc , argv );

    int portNumber = atoi(argv[2]);

    int clientSocket = socket( AF_INET , SOCK_STREAM , 0 );
    if (clientSocket == -1)
    {
        perror("Client failed to create socket...\n");
        exit(1);
    }





    struct sockaddr_in clientSocketAddress;


    if( argc == 3 )
	{
		setClientSocketAddress( &clientSocketAddress , NULL , portNumber );
	}
	else if( argc == 4 )
	{
		char* serverIP = argv[3];
		        	printf("->serverIP    %s\n",serverIP);
        	fflush(stdout);
		setClientSocketAddress( &clientSocketAddress , serverIP , portNumber );

	}










    if (connect(clientSocket, (struct sockaddr*)&clientSocketAddress, sizeof(clientSocketAddress)) == -1) {
        perror("Failed to connect to the server");
        exit(1);
    }

    printf("Connected to the server\n");

    char message[1024];
    int isExit = 0;

    while (!isExit)
    {
        printf("Enter a message (or type \"exit\" to quit): ");
        fgets(message, 1024, stdin);
        message[strcspn(message, "\n")] = '\0';

        // Send message to the server
        if (send(clientSocket, message, strlen(message), 0) == -1)
        {
            perror("Message sending failed");
            exit(1);
        }
        else
        {
        	printf("->%s  -- send",message);
        	fflush(stdout);
        }

        if (strcmp(message, "exit") == 0) {
            isExit = 1;
        }
    }

    // Close the client socket
    close(clientSocket);

    printf("Connection closed\n");
    fflush(stdout);

    return 0;
}






void checkCommandLineArguments( int argc , char** argv )
{
    if ( (argc != 3) && (argc != 4) )
    {
        fprintf(stderr, "Invalid number of command-line arguments.\nExpected 2 arguments for local host as : <directory> <portNumber>\nExpected 3 arguments for not local host as : <directory> <portNumber> <server IP>\n");
        exit(1); // Terminate the program with an error code
    }


}









void setClientSocketAddress( struct sockaddr_in* clientSocketAddress, char* serverIP , int portNumber )
{
	clientSocketAddress->sin_family = AF_INET;
	clientSocketAddress->sin_port = htons(portNumber);

	if( serverIP == NULL )
	{
		clientSocketAddress->sin_addr.s_addr = INADDR_ANY;
	}
	else if ( inet_pton(AF_INET, serverIP, &(clientSocketAddress->sin_addr)) <= 0 )
    {
        perror("Invalid server IP address");
        exit(1);
    }
}





















