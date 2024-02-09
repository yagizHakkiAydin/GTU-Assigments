package com.YagizHakki;




public class MergeSort extends Sort
{

	/**
	*Gets size for array and creates array with random integers
	*@param arrSize size of random array
	*/
	MergeSort( int arrSize )
	{
		super( arrSize );
	}


	/**
	*Gets an array and size for array
	*@param arrSize size of given array
	*@param arr array to be sorted
	*/
	MergeSort( int[] arr , int arrSize )
	{
		super( arr , arrSize );
	}



	public void sortArray(  )
	{
		sortArray( tempArray , 0 , (this.getSize()-1) );
	}




	/**
	*Divides array into two pieces recursively and divides those pieces too until getting smallest pieces,
	*then merges divided pieces with sorting them
	*/
	private void sortArray( int[] arr , int leftIndex , int rightIndex)
	{
		if( leftIndex < rightIndex )
		{
			int middleIndex = leftIndex + (rightIndex-leftIndex)/2;

			sortArray( arr , leftIndex , middleIndex );

			sortArray( arr , middleIndex + 1 , rightIndex );

			mergeArrays( arr , leftIndex , middleIndex , rightIndex );
		}
	}

	/**
	*Merges divided arrays with order
	*/
	private void mergeArrays(int[] arr , int leftIndex , int middleIndex , int rightIndex )
	{
	

		int leftArray[] = new int[ middleIndex + 1 - leftIndex ];
		int rightArray[] = new int[ rightIndex - middleIndex ];



		for( int i=0 ; i<( middleIndex + 1 - leftIndex ) ; i++ )
		{
			leftArray[i] = arr[ leftIndex + i ];
		}


		
		for( int i=0;i<( rightIndex - middleIndex ) ; i++ )
		{
			rightArray[i] = arr[ middleIndex + 1 + i ];
		}
		





		//Indexes for left and right array and k index for indicating part of the whole array
        int leftArrayIndex = 0, 
        	rightArrayIndex = 0 ,
          	k = leftIndex;
  


        while (  (leftArrayIndex < (middleIndex + 1 - leftIndex) )  && (  rightArrayIndex < (rightIndex - middleIndex) )  )
        {
            if(leftArray[leftArrayIndex] <= rightArray[rightArrayIndex])
            {
                arr[k] = leftArray[leftArrayIndex];
                leftArrayIndex++;
            }
            else
            {
                arr[k] = rightArray[rightArrayIndex];
                rightArrayIndex++;
            }

            k++;
        }
  
        //Rest of the left array elements copied to array 
        while(leftArrayIndex < (middleIndex + 1 - leftIndex))
        {
            arr[k] = leftArray[leftArrayIndex];
            leftArrayIndex++;
            k++;
        }
  
        //Rest of the right array elements copied to array 
        while( rightArrayIndex < (rightIndex - middleIndex) )
        {
            arr[k] = rightArray[rightArrayIndex];
            rightArrayIndex++;
            k++;
        }




	}


}