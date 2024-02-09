#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>





int myDup( int fd );


int myDup2( int existingFd , int newFd );




void myDupTest();
void myDup2Test();
void myDupTestFailCases();
void myDup2TestFailCases();
void verifyFd();



int main(int argc , char* argv[])
{

	int choice = 0;
	printf("To test cases that myDup must handle,enter 1\n");
	printf("To test cases that myDup2 must handle,enter 2\n");
	printf("(Part 3)To verify that duplicated file descriptors share a file offset value and open file ,enter 5\n");
	printf("Your choice -> ");
	scanf("%d",&choice);





	switch(choice)
	{

		case 1:
			myDupTestFailCases();
		break;

		case 2:
			myDup2TestFailCases();
		break;
		case 3:
			verifyFd();
		break;

		default:
		break;
	}


	return 0;

}


int myDup( int fd )
{


	int result = fcntl( fd , F_DUPFD );

	if( fd < 0 )
	{
		errno = EBADF;
		return -1;
	}
	else if( result == -1 )
	{
		errno = EBADF;
		return -1;
	}

	return result;
}



int myDup2( int existingFd , int newFd )
{


	int isNewFdOpen = (fcntl( newFd , F_GETFL ) >= 0);

	if(isNewFdOpen)
	{
		close(newFd);
	}

	if( (existingFd < 0) || (newFd < 0) || (existingFd == newFd) )
	{
		errno = EBADF;
		return -1;
	}



	if((fcntl(newFd , F_GETFL) != -1) || (fcntl(existingFd , F_GETFL) != -1))
	{
		errno = EBADF;
		return -1;
	}



	return fcntl( existingFd , F_DUPFD , newFd );
}





//This function tests all possible cases where myDup must detect detect
void myDupTestFailCases()

{
	int fd = -1;

	int dup_fd = myDup(fd);


	//We test case where we pass -1 to myDup

	if (dup_fd == -1 && errno == EBADF)
	{
		printf("When we pass \"-1\" for myDup \"dup_fd == -1 && errno == EBADF\" condition is true...\n");
	}
	else
	{
		perror("When we pass \"-1\" for myDup \"dup_fd == -1 && errno == EBADF\" condition is false...\n");
	}



	fd = open("test_myDupTestFailCase", O_RDWR | O_CREAT, 0644);

	close( fd );

	dup_fd = myDup( fd );


	//We close fd,so fd is now an invalid file descriptor and myDup is performed

	if (dup_fd == -1 && errno == EBADF)
	{
		printf("When we pass \"fd\" for myDup and fd is invalid file descriptor ; \"dup_fd == -1 && errno == EBADF\" condition is true...\n");
	}
	else
	{
		printf("When we pass \"fd\" for myDup and fd is invalid file descriptor ; \"dup_fd == -1 && errno == EBADF\" condition is false...\n");
	}
}











//This function tests all possible cases where myDup2 must detect detect
void myDup2TestFailCases()
{
	int fileDescriptorOne = open( "myDup2TestFile1" , O_RDWR | O_CREAT , 0644 );
	int fileDescriptorTwo = open( "myDup2TestFile2" , O_RDWR | O_CREAT , 0644 );

	if((myDup2(-1,fileDescriptorTwo) == -1) && (myDup2(fileDescriptorOne,-1) == -1) && myDup2(-1,-1))
	{
		printf("If one of arguments equals to -1 for myDup2,result equals to -1\n");
	}

	close(fileDescriptorTwo);



	int res = myDup2(fileDescriptorOne,fileDescriptorTwo);
	if( res == -1 && errno == EBADF )
	{
		printf("If one of file descriptors for  myDup2 is invalid,result equals to -1 and errno equals EBADF\n");
	}
	else
	{
		printf("%d\n",res);
	}


}




void verifyFd()
{
	printf("\n");
	int fileDescriptorOne = open( "myDup2TestFile1" , O_RDWR | O_CREAT , 0644 );
	int fileDescriptorTwo = open( "myDup2TestFile2" , O_RDWR | O_CREAT , 0644 );

	myDup2(fileDescriptorOne,fileDescriptorTwo);


	write( fileDescriptorTwo , "testMyDup2" , 10 );



	printf("\nWe run code line -> \"myDup2(fileDescriptorOne,fileDescriptorTwo);\"\n ");

	if(lseek( fileDescriptorOne , 0 , SEEK_CUR ) == lseek( fileDescriptorTwo , 0 , SEEK_CUR ))
	{
		printf("When we run myDup2 , fd1 and fd2 have same offset...\n");
	}
	else
	{
		printf("fd1 and fd2 do not have same offsets...\n");
	}
	if(fcntl(fileDescriptorOne, F_GETFL, 0) == fcntl(fileDescriptorTwo, F_GETFL, 0))
	{
		printf("When we run myDup2 , fd1 and fd2 have open file...\n");
	}
	else
	{
		printf("fd1 and fd2 do not have same open file...\n");
	}




	int fileDescriptorThree = open( "myDupTestFile" , O_RDWR | O_CREAT , 0644 );
	int duplicatedFd = myDup(fileDescriptorThree);


	printf("\nWe run code line -> \"int duplicatedFd = myDup(fileDescriptorThree);\"\n ");

	if(lseek( fileDescriptorOne , 0 , SEEK_CUR ) == lseek( fileDescriptorTwo , 0 , SEEK_CUR ))
	{
		printf("When we run myDup , fd1 and fd2 have same offset...\n");
	}
	else
	{
		printf("fileDescriptorOne and fileDescriptorTwo do not have same offsets...\n");
	}
	if(fcntl(fileDescriptorOne, F_GETFL, 0) == fcntl(fileDescriptorTwo, F_GETFL, 0))
	{
		printf("When we run myDup , fd1 and fd2 have open file...\n");
	}
	else
	{
		printf("fileDescriptorThree and duplicatedFd do not have same open file...\n");
	}

}











