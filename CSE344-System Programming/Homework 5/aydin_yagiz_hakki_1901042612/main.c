#include <stdio.h>
#include <sys/shm.h>
#include <signal.h>
#include "argumentcorrectnesscheck.h"
#include "timecount.h"
#include "threadoperations.h"
#include "filecopy.h"



void freeResources()
{

    free(consumerThreadPool.threads);
    free(consumerThreadPool.threadAvailable);

    shmdt(_bufferQueue.buffers);
    shmctl( shmget( IPC_PRIVATE , 0 , 0666) , IPC_RMID , NULL );


}



//   ./main <buffer size> <num of customers> <source directory> <destination directory>
int main(int argc, char* argv[])
{


    int bufferSize = atoi(argv[1]);
    int numOfCustomers = atoi(argv[2]);
    const char* sourceDirectory = argv[3];
    const char* destDirectory = argv[4];

    //Create buffer
    createBuffer(bufferSize);

    //Initialize consumer thread pool
    initializeConsumerThreadPool(numOfCustomers);

    //Start timing
    beginTimeCounter();

    //Start producer thread
    startProducerThread(sourceDirectory, destDirectory);

    //Wait for producer thread to finish
    pthread_join(producerThread, NULL);

    //Wait for all consumer threads to finish
    for (int i = 0; i < numOfCustomers; i++)
    {
        pthread_join(consumerThreadPool.threads[i], NULL);
    }

    //Calculate and print elapsed time
    long elapsedTime = getElapsedTimeInSeconds();
    printf("Total elapsed time: %ld seconds\n", elapsedTime);

    // Free resources
    freeResources();

    return 0;
}
























