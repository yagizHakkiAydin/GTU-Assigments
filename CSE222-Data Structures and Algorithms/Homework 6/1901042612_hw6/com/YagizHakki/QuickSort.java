package com.YagizHakki;




public class QuickSort extends Sort
{
	QuickSort( int arrSize )
	{
		super( arrSize );
	}


	QuickSort( int[] arr , int arrSize )
	{
		super( arr , arrSize );
	}







	 


	public void sortArray()
	{
		sortArray( tempArray , 0 , (this.getSize()-1) );
	}


	/**
	*Sorts the array with quick sort
	*/
	private void sortArray(int[] arr, int low, int high)
	{
	    if (low < high)
	    {
	        
	        int pivotIndex = divide(arr, low, high);
	 
	        //array gets divided into two pieces
	        sortArray(arr, low, pivotIndex - 1);
	        sortArray(arr, pivotIndex + 1, high);
	    }
	}

	/**
	*@return new pivot index for sorting
	*/
	private int divide(int[] arr, int low, int high)
	{
	    //pivot is selected as most-right element
	    int pivot = arr[high];
	     

	    int i = (low - 1);
	 

	 	//array is traversed left to right and elements are swapped by comparing pivot value
	    for(int j = low; j <= high - 1; j++)
	    {
	         
	        if (arr[j] < pivot)
	        {
	             
	            i++;

			    int temp = arr[i];
			    arr[i] = arr[j];
			    arr[j] = temp;
	        }
	    }
	    
		int temp = arr[i+1];
	    arr[i+1] = arr[high];
	    arr[high] = temp;


	    return (i+1);
	}
 

}