package com.YagizHakki;




public class NewSort extends Sort
{
	NewSort( int arrSize )
	{
		super( arrSize );
	}


	NewSort( int[] arr , int arrSize )
	{
		super( arr , arrSize );
	}


	public void sortArray()
	{
		tempArray = sortArray( tempArray , 0 , this.getSize()-1 );
	}



	/**
	*Returns 2d array that keeps min and max values
	*/
	private int[] min_max_finder( int[] arr , int head , int tail )
	{
		int[] values = new int[2];
		values[0] = 0;
		values[1] = 0;
		return min_max_finder( values , arr , head , tail );
	}

	/**
	*Returns 2d array that keeps min and max values,finds these values recursively
	*/
	private int[] min_max_finder( int[] values, int[] arr , int head , int tail )
	{

		if( arr[head]<=arr[values[0]] )
		{
			values[0] = head;		
		}
		if( arr[head]>=arr[values[1]] )
		{
			values[1] = head;	
		}
		


		if(head == tail)
			return values;
		else
			return min_max_finder(  values,  arr ,  head+1 ,  tail );

	}



	/**
	*Swaps two elements of the array
	*/
	private void swap( int[] arr , int head , int num )
	{
		int temp = arr[head];
		arr[head] = arr[num];
		arr[num] = temp;
	}


	/**
	*Sorts the array
	*/
	public int [] sortArray( int[] arr , int head , int tail )
	{
		if( head > tail )
		{
			return arr;
		}
		else
		{
			int min = min_max_finder( arr , head , tail )[0];
			int max = min_max_finder( arr , head , tail )[1];
			

			swap( arr , head, min);
			swap( arr , tail, max);



			return sortArray( arr, head , tail - 1 );

		}
	}

}