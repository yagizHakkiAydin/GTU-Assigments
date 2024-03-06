#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <unistd.h>
#include "tokenizationoperations.h"
#include "threadoperations.h"



//This function checks if user entered a correct form of command,if not;then it terminates whole program
//Correct format is ./BibakBOXServer <directory> <threadPoolSize> <portnumber>
void checkCommandLineArguments( int argc , char** argv );
void setServerSocketAddress( struct sockaddr_in* serverSocketAddress , int portNumber );






int main( int argc , char** argv )
{

	checkCommandLineArguments( argc , argv );	//Checking command line arguments


    char* directory = argv[1];
    int threadPoolSize = atoi(argv[2]);
    int portNumber = atoi(argv[3]);

	struct sockaddr_in serverSocketAddress;

	setServerSocketAddress( &serverSocketAddress , portNumber );


/*
	int i=0;
	while(1)
	{

		sleep(1);
	}
*/





	int serverSocket = socket( AF_INET , SOCK_STREAM , 0 );

	if( serverSocket == -1 )
	{
		perror("Server failed to create socket...\n");
		exit(1);
	}





	printf("%d",serverSocket);
	fflush(stdout);
	if( bind( serverSocket , &(serverSocketAddress) , sizeof( serverSocketAddress ) ) == -1 )
	{
		perror("Server failed to bind socket,you might want to start the server with a port number above 1024 if you have not tried yet...\n");
		exit(1);
	}

	if ( listen( serverSocket , threadPoolSize ) == -1 )
	{
		perror("Server failed to listen for connections...\n");
		exit(1);
	}





	createThreadPool( threadPoolSize );
	while (1)
    {



        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);
        if (clientSocket == -1) {
            perror("Server failed to accept client connection");
            exit(1);
        }
        addClient( clientSocket );

        printf("Client connected\n");

        sleep(1);
    }




	return 0;
}








void setServerSocketAddress(struct sockaddr_in* serverSocketAddress, int portNumber)
{
    struct ifaddrs** ifaddr;	//list of IP addresses associated with all network interfaces available on the system
    struct ifaddrs* ifa;	//Used to traverse ifaddrs structs within all network interfaces
    char* ipAddress = NULL;		//Keeps the available IP address

    if ( getifaddrs(ifaddr) == -1 )
    {
        perror("Fail when trying to obtain network interface information...\n");
        exit(1);
    }


    //This loop is used to traverse within all network interfaces available on the system.
    //ifa is initialized with the first entry of ifaddr and this first entry is also first node of the linked list
    for( ifa = *(ifaddr) ; ifa != NULL ; ifa = ifa->ifa_next )
    {
		if (ifa->ifa_addr == NULL || !( ifa->ifa_flags && IFF_UP ) )
		{
			continue;	//If interface is not available or it is not up
		}

		//Check if corresponding interface's address is IPV4
		if( ifa->ifa_addr->sa_family == AF_INET )
		{
			struct sockaddr_in* sa = (struct sockaddr_in*)ifa->ifa_addr;
			if( sa->sin_addr.s_addr != htonl(INADDR_LOOPBACK) )
			{
				ipAddress = inet_ntoa(sa->sin_addr);
				break;
			}
		}
	}

	freeifaddrs(*(ifaddr));

    if (ipAddress == NULL)
    {
        perror("Failed to obtain an available IP address");
        exit(1);
    }

    if (inet_pton(AF_INET, ipAddress, &(serverSocketAddress->sin_addr)) <= 0)
    {
        perror("Failed to convert IP address to binary format");
        exit(1);
    }

    serverSocketAddress->sin_family = AF_INET;
    serverSocketAddress->sin_port = htons( portNumber );

    printf("%s --\n",ipAddress);

}







void checkCommandLineArguments( int argc , char** argv )
{
    if (argc != 4)
    {
        fprintf(stderr, "Invalid number of command-line arguments. Expected 3 arguments as : <directory> <threadPoolSize> <portNumber>\n");
        exit(1); // Terminate the program with an error code
    }

    //Assigning command line arguments to the variables
    char* directory = argv[1];
    int threadPoolSize = atoi(argv[2]);
    int portNumber = atoi(argv[3]);


    // Validate thread pool size and port number
    if ( threadPoolSize <= 0 )
    {
        perror("Thread pool size must be greater than 0...\n");
        exit(1); // Terminate the program with an error code
    }
    if ( portNumber <= 0 )
    {
        perror("Port number must be greater than 0...\n");
        exit(1); // Terminate the program with an error code
    }


}


































