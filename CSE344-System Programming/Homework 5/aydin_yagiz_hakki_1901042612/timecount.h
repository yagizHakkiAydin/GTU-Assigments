#ifndef TIMECOUNT_H
#define TIMECOUNT_H


#include <sys/time.h>


struct timeval beginTimeValue;
struct timeval currentTimeValue;






//This sets the "beginTimeValue" with the value of current time
void beginTimeCounter()
{
	if( gettimeofday( &beginTimeValue , NULL ) != 0 )
	{
		perror( "Warning,time counter could not initialized because of \"gettimeofday\"\n" );
	}
}






//Returns time elapsed after beginTimeCounter() is called
long getElapsedTimeInSeconds()
{
	if( gettimeofday(&currentTimeValue , NULL) != 0 )
	{
		perror( "Warning,time could not obtained\n" );
		return -1;
	}
	else
	{
		long totalElapsedTime = currentTimeValue.tv_sec - beginTimeValue.tv_sec;
		return totalElapsedTime;
	}
}















#endif