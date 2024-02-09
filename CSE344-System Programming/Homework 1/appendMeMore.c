#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>




void writeWithFlag( char *fileName,int numOfBytes );
void writeWithoutFlag( char *fileName , int numOfBytes );
int stoi(char* str);





int main(int argc , char* argv[])
{


	if( argc == 3 )
	{
		const int numOfBytes = stoi(argv[2]);
		writeWithFlag( argv[1] , numOfBytes );
	}
	else if( argc == 4 )
	{
		const int numOfBytes = stoi(argv[2]);
		writeWithoutFlag( argv[1] , numOfBytes );
	}
	else
	{
		perror("Invalid number of arguments,terminating...\n");
		return 1;
	}



	return 0;

}









void writeWithFlag(char *fileName,int numOfBytes)
{

	int fileDescriptor = open( fileName , (O_RDWR | O_APPEND | O_CREAT) , 0644 );

	const int howManyBytes = numOfBytes;



	if( fileDescriptor == -1 )
	{
		perror("Invalid file descriptor,terminating...\n");
		exit(1);		
	}
	else if( numOfBytes == -1 )
	{
		perror("Invalid number of bytes,terminating...\n");
		exit(1);
	}



	for(int i=0 ; i<howManyBytes ; i++ )
	{
		char temp = 'a' + (i%26);
		write( fileDescriptor , &temp , 1 );
	}

	close(fileDescriptor);

}




void writeWithoutFlag(char *fileName, int numOfBytes)
{

	int fileDescriptor = open( fileName , (O_RDWR | O_CREAT) , 0644 );

	const int howManyBytes = numOfBytes;

	int position = lseek(fileDescriptor, 0, SEEK_END);



	if( position == -1 )
	{
		perror("lseek error,terminating...\n");
		exit(1);
	}
	else if( fileDescriptor == -1 )
	{
		perror("Invalid file descriptor,terminating...\n");
		exit(1);		
	}
	else if( numOfBytes == -1 )
	{
		perror("Invalid number of bytes,terminating...\n");
		exit(1);
	}



	for (int i = 0; i < howManyBytes; i++)
	{
		char temp = 'a' + (i % 26);
		write(fileDescriptor, &temp, 1);
		position = lseek(fileDescriptor, 0, SEEK_END);
	}

	close(fileDescriptor);
}




int stoi(char* str)
{
	int result = 0;

	int index = 0;

	while( str[index] != '\0' )
	{
		if( str[index] >= '0' && str[index] <= '9' )
		{
			result *= 10;
			result += str[index] - 48;
		}
		else
		{
			return -1;
		}
		index++;
	}

	return result;

}




