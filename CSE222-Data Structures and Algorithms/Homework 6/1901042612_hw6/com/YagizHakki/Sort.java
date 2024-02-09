package com.YagizHakki;


import java.util.Random;



public abstract class Sort
{
	Sort()
	{

	}


	/**
	*Gets size for array and creates array with random integers
	*@param arrSize size of random array
	*/
	Sort( int arrSize )
	{
		size = arrSize;
		randomArray = new int[size];
		tempArray = new int[size];

		Random randObj = new Random();

		for( int i=0 ; i<size ; i++ )
		{
			randomArray[i] = randObj.nextInt()%100000;
			tempArray[i] = randomArray[i];
		}
	}


	/**
	*Gets an array and size for array
	*@param arrSize size of given array
	*@param arr array to be sorted
	*/
	Sort( int[] arr , int arrSize )
	{
		size = arrSize;
		randomArray = new int[size];
		tempArray = new int[size];

		Random randObj = new Random();

		for( int i=0 ; i<size ; i++ )
		{
			randomArray[i] = arr[i];
			tempArray[i] = randomArray[i];
		}
	}


	/**
	*@return size of array
	*/
	public int getSize()
	{
		return size;
	}


	/**
	*@return copy of unsorted array
	*/
	public int[] getArrayCopy()
	{
		var newArray = new int[size];

		for( int i=0 ; i<size ; i++ )
		{
			newArray[i] = randomArray[i];
		}

		return newArray;
	}


	/**
	*Resets temp array to be sorted again
	*/
	public void resetTempArray()
	{
		for( int i=0 ; i<size ; i++ )
		{
			tempArray[i] = randomArray[i];
		}
	}


	/**
	*Sorts the temp array of the class
	*/
	public abstract void sortArray();


	/**
	*Prints the temp array
	*/
	public void printSortedArray()
	{
		for( int i=0 ; i<this.getSize() ; i++ )
		{
			System.out.printf("%d , ",tempArray[i]);
		}
		System.out.printf("\n\n\n\n");
	}



	/**
	*Random array,won't be changed
	*/
	protected int randomArray[];

	/**
	*Temp array,will be sorted
	*/
	protected int tempArray[];


	/**
	*Size of the array
	*/
	protected int size;

}