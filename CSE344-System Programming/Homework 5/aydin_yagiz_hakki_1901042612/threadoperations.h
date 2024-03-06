#ifndef THREADOPERATIONS_H
#define THREADOPERATIONS_H


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "filecopy.h"




typedef struct
{
	char sourcePath[512];
	char destinationPath[512];

}ProducerThreadInfo;




typedef struct
{
	pthread_t* threads;
	int* threadAvailable;
	int threadPoolSize;

}ThreadPool;


pthread_mutex_t bufferMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bufferNotFull = PTHREAD_COND_INITIALIZER;
pthread_cond_t bufferNotEmpty = PTHREAD_COND_INITIALIZER;



ThreadPool consumerThreadPool;

pthread_t producerThread;






void initializeConsumerThreadPool( int consumerNumber )
{
	consumerThreadPool.threadPoolSize = consumerNumber;
	consumerThreadPool.threads = malloc( sizeof(pthread_t) * consumerNumber );
	consumerThreadPool.threadAvailable = malloc( sizeof(int) * consumerNumber );


	for( int i=0 ; i<consumerNumber ; i++ )
	{
		consumerThreadPool.threadAvailable[i] = 1;
	}
}
	




void* consumerThreadFunction(void* arg)
{
    while (1)
    {
        pthread_mutex_lock(&bufferMutex);

        while (isBufferEmpty())
        {
            pthread_cond_wait(&bufferNotEmpty, &bufferMutex);
        }

        Buffer fileBuffer;
        for( int i=0;i<_bufferQueue.bufferSize;i++ )
        {
        	if( _bufferQueue.buffers[i].sourcePath[0] == '\0' )
        	{
        		strcpy(fileBuffer.sourcePath , _bufferQueue.buffers[i].sourcePath);
        		strcpy(fileBuffer.destinationPath , _bufferQueue.buffers[i].destinationPath);
        		fileBuffer.sourceFileDescriptor = _bufferQueue.buffers[i].sourceFileDescriptor;
        		fileBuffer.destinationFileDescriptor = _bufferQueue.buffers[i].destinationFileDescriptor;
        		break;
        	}
        }

  
        pthread_cond_signal(&bufferNotFull);


        pthread_mutex_unlock(&bufferMutex);

        // Perform the file copying operation
        int sourceFile = open(fileBuffer.sourcePath, O_RDONLY);
        int destFile = open(fileBuffer.destinationPath, (O_WRONLY | O_CREAT | O_TRUNC), S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

        if (sourceFile == -1 || destFile == -1)
        {
            perror("Error opening files");
            continue;
        }

        copyFile(sourceFile, destFile);

        close(sourceFile);
        close(destFile);


    }

    return NULL;
}






void producerThreadFunction(void* threadInfo)
{
    ProducerThreadInfo* info = (ProducerThreadInfo*)threadInfo;

    DIR* directory = opendir(info->sourcePath);
    
    if (directory == NULL)
    {
        perror("Error opening directory");
        return;
    }

    struct dirent* entry;

    while ((entry = readdir(directory)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }
        
        char sourceFilePath[512];
        char destinationFilePath[512];

        strcpy(sourceFilePath, info->sourcePath);
        strcat(sourceFilePath, "/");
        strcat(sourceFilePath, entry->d_name);

        strcpy(destinationFilePath, info->destinationPath);
        strcat(destinationFilePath, "/");
        strcat(destinationFilePath, entry->d_name);
        
        DIR* subDirectory = opendir(sourceFilePath);
        
        if (subDirectory != NULL)
        {
            closedir(subDirectory);

            ProducerThreadInfo pt;
            strcpy(pt.sourcePath,sourceFilePath);
            strcpy(pt.destinationPath,destinationFilePath);
            producerThreadFunction((void*)&pt);
        }
        else
        {
            int sourceFile = open(sourceFilePath, O_RDONLY);
            
            if (sourceFile == -1)
            {
                perror("Error opening source file");
                continue;
            }
            
            // Create the destination directory if it does not exist
            struct stat st = {0};
            if (stat(info->destinationPath, &st) == -1)
            {
                if (mkdir(info->destinationPath, 0777) == -1)
                {
                    perror("Error creating destination directory");
                    continue;
                }
            }
            
            int destFile = open(destinationFilePath, (O_WRONLY | O_CREAT | O_TRUNC), (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
            
            if (destFile == -1)
            {
                perror("Error opening destination file");
                continue;
            }
            
            char buffer[4096];
            ssize_t bytesRead;
            
            while ((bytesRead = read(sourceFile, buffer, sizeof(buffer))) > 0)
            {
                write(destFile, buffer, bytesRead);
            }
            
            close(sourceFile);
            close(destFile);
        }
    }
    
    closedir(directory);
}





void startProducerThread( const char* source , const char* destination )
{
	ProducerThreadInfo _producerThreadInfo;
	strcpy( _producerThreadInfo.sourcePath , source );
	strcpy( _producerThreadInfo.destinationPath , destination );

	pthread_create( &producerThread , NULL , producerThreadFunction , (void*)&_producerThreadInfo );
}










#endif
