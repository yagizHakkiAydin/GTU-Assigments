#ifndef FILECOPY_H
#define FILECOPY_H
#include <sys/shm.h>
#include <string.h>


typedef struct
{
	char sourcePath[508];
	char destinationPath[508];
	int sourceFileDescriptor;
	int destinationFileDescriptor;

}Buffer;





typedef struct
{
	Buffer* buffers;
	int bufferSize;

}BufferQueue;



BufferQueue _bufferQueue;	//









void createBuffer( int bufferSize )
{
	int sharedMemoryID = shmget( IPC_PRIVATE , ( bufferSize * sizeof(Buffer) ) , 0666 );

	if( sharedMemoryID == -1 )
	{
		perror("Buffer shared memory could not created correctly...\n");
		exit(1);
	}

    _bufferQueue.buffers = shmat( sharedMemoryID , NULL , 0 );
    _bufferQueue.bufferSize = bufferSize;

    if ( _bufferQueue.buffers == (char)-1 )
    {
        perror("Buffer shared memory space could not attached correctly...\n");
        exit(1);
    }

    for( int i=0 ; i<bufferSize ; i++ )
    {
		strcpy(_bufferQueue.buffers[i].sourcePath, "");
		strcpy(_bufferQueue.buffers[i].destinationPath, "");
    	_bufferQueue.buffers[i].sourceFileDescriptor = -1;
    	_bufferQueue.buffers[i].destinationFileDescriptor = -1; 
    }

}





int isBufferFull()
{
	if( _bufferQueue.buffers[ _bufferQueue.bufferSize-1 ].sourcePath[0] != '\0' )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isBufferEmpty()
{
	if( _bufferQueue.buffers[0].sourcePath[0] != '\0' )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}




void enqueue( char* sourcePath , char* destPath , int sourceFd , int destFd ) 
{
	if( isBufferFull() == 1 )
	{
		perror("Buffer queue full...\n");
		return;
	}

	int queueFront = 0;
	for( queueFront=0 ; queueFront<_bufferQueue.bufferSize ; queueFront++ )
	{
		if( _bufferQueue.buffers[queueFront].sourcePath[0] == '\0' )
		{
			strcpy( _bufferQueue.buffers[queueFront].sourcePath , sourcePath );
			strcpy( _bufferQueue.buffers[queueFront].destinationPath , destPath );
			_bufferQueue.buffers[ queueFront ].sourceFileDescriptor = sourceFd;
			_bufferQueue.buffers[ queueFront ].destinationFileDescriptor = destFd;

			return;
		}
	}
}




void dequeue() 
{
	if( isBufferEmpty() == 1 )
	{
		perror("Dequeue operation on empty buffer queue...\n");
		return;
	}

	int queueFront;

	for( queueFront = (_bufferQueue.bufferSize-1) ; queueFront >= 0 ; queueFront-- )
	{
		if( _bufferQueue.buffers[queueFront].sourcePath[0] == '\0' )
		{
			strcpy( _bufferQueue.buffers[queueFront].sourcePath , "" );
			strcpy( _bufferQueue.buffers[queueFront].destinationPath , "" );
			_bufferQueue.buffers[ queueFront ].sourceFileDescriptor = -1;
			_bufferQueue.buffers[ queueFront ].destinationFileDescriptor = -1;

			return;
		}
	}
}



void copyFile( int sourceFd , int destFd )
{
	if( ( sourceFd == -1 ) || ( destFd == -1 ) )
	{
		perror("Copyfile error...\n");
		exit(1);
	}



    char copyBuffer[8192];
    ssize_t bytesRead = read( sourceFd , copyBuffer , sizeof(copyBuffer) );
    while ( bytesRead > 0)
    {
        ssize_t bytesWritten = write(destFd, copyBuffer, bytesRead);
        if (bytesWritten == -1)
        {
            perror("Write error");
            exit(1);
        }
        bytesRead = read( sourceFd , copyBuffer , sizeof(copyBuffer) );
    }

    if (bytesRead == -1)
    {
        perror("Read error");
        exit(1);
    }




}






#endif