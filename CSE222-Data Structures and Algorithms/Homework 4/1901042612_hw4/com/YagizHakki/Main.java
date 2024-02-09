package com.YagizHakki;

import java.util.ArrayList;



public class Main
{
	/**
	*Runs driver function
	*/
	public static void main( String[] args )
	{
		Main m = new Main();
		m.driverFunction();
	}


	/**
	*Runs functions with all possible cases
	*/
	public void driverFunction(  )
	{

		ArrayList<Integer> arr = new ArrayList<Integer>();
		ArrayList<Integer> arr2 = new ArrayList<Integer>();


		arr2.add(1);
		arr2.add(1);
		arr2.add(2);
		arr2.add(3);
		arr2.add(4);
		arr2.add(8);
		arr2.add(8);
		arr2.add(8);
		arr2.add(9);
		

		arr.add(5);
		arr.add(8);
		arr.add(11);
		arr.add(15);
		arr.add(0,16);
		arr.add(3,17);
		arr.add(18);
		arr.add(19);
		arr.add(20);


		System.out.printf("\narr --> ");
		for( int i=0 ; i<arr.size() ; i++ )
		{
			System.out.printf("%d ,",arr.get(i));
		}


		System.out.printf("\narr2 --> ");
		for( int i=0 ; i<arr2.size() ; i++ )
		{
			System.out.printf("%d ,",arr2.get(i));
		}


		System.out.printf("\n\n\nTesting question 1 with main string -->abc123def123abcabcabc\n");
		System.out.printf("\nTesting question 1 with i = 2 and 1st occurrance at index --> %d\n",this.iThOcurrance( "abc123def123abcabcabc", "abc" , 0 , 0 ,2 ));
		System.out.printf("\nTesting question 1 with i = 6 and 3rd occurrance at index --> %d\n",this.iThOcurrance( "abc123def123abcabcabc", "abc" , 0 , 0 ,6 ));
		System.out.printf("\n\n\n\n\n\n\n\n\n");



		try
		{
			System.out.printf("\nTesting question 2 with arr2 and trying to find interval between 1,4...\n");
			findInterval(arr2,1,4,0,(arr2.size()-1));
		}
		catch( IndexOutOfBoundsException e )
		{
			System.out.printf("\nOutOfBounds...\n");
		}

		try{
			System.out.printf("\nTesting question 2 with arr and trying to find interval between 1,4...\n");
			findInterval(arr,1,4,0,(arr.size()-1));
		}
		catch( IndexOutOfBoundsException e )
		{
			System.out.printf("\nOutOfBounds...\n");
		}



		System.out.printf("\n\n\n\n\n\n\n\n\n");
		System.out.printf("\nTesting question 3 with arr,trying to find 33 as sum...\n");
		findSum(arr,33,0,0);





	}



	/**
	*Finds i'th occurrance of given string in main string
	*@param mainString main string,searched by function
	*@param queryString searched in the main string
	*@param howManyTimesOccured counts number of ocurrance of queryString in mainString,initial value = 0
	*@param indexController .
	*@param i target value of ocurrance of queryString in mainString
	*@return number of ocurrance of queryString in mainString
	*/
	public int iThOcurrance( String mainString , String queryString , int indexController , int howManyTimesOccured ,  int i )
	{
		if( indexController+queryString.length() > mainString.length() )
		{
			return -1;
		}
		else if( queryString.equals( mainString.substring( indexController , (indexController + queryString.length())  ) ) )
		{
			howManyTimesOccured++;
			if( howManyTimesOccured == i )
			{
				return indexController;
			}
		}

		return iThOcurrance( mainString , queryString , indexController+1 , howManyTimesOccured , i );
	}





	/**
	*Gets two numbers and prints indexes of given array within the given bounds and prints indexes of interval's border indexes
	*@param arr sorted array to be searched
	*@param leftBound small number,left border of the interval
	*@param rightBound big number,right border of the interval
	*@param leftIndex index of left border,initial value = 0
	*@param rightIndex index of left border,initial value = biggest possible value of index for arr
	*/
	public void findInterval( ArrayList<Integer> arr , int leftBound , int rightBound , int leftIndex , int rightIndex ) throws IndexOutOfBoundsException
	{

		if( leftIndex<0 || leftIndex>=arr.size() || rightIndex<0 || rightIndex>=arr.size() || leftIndex>=rightIndex )
		{
			throw new IndexOutOfBoundsException();
		}

		else if( arr.get(leftIndex) < leftBound )
		{
			findInterval( arr , leftBound , rightBound , (leftIndex + 1) , rightIndex );
		}

		else if( arr.get(leftIndex) > leftBound )
		{
			findInterval( arr , leftBound , rightBound , (leftIndex - 1) , rightIndex );
		}
		else if( arr.get(rightIndex) < rightBound )
		{
			findInterval( arr , leftBound , rightBound , leftIndex , (rightIndex+1) );
		}

		else if( arr.get(rightIndex) > rightBound )
		{
			findInterval( arr , leftBound , rightBound , leftIndex , (rightIndex - 1) );
		}
        else
        {
			System.out.printf("\nIndex of the left bound at the most left position --> %d",leftIndex);
			System.out.printf("\nIndex of the right bound at the most right position --> %d\n",rightIndex);
		}

	}




	/**
	*Searches array and prints pairs of numbers that is equal to given sum
	*@param arr array that is searched
	*@param sum asked sum value
	*@param firstIndex used to search array,initial value = 0
	*@param secondIndex used to search array,initial value = 0
	*/
	public void findSum(ArrayList<Integer> arr , int sum , int firstIndex , int secondIndex )
	{
		if( secondIndex < (arr.size()-1) )
		{
			firstIndex++;

			if(firstIndex == (arr.size()-1) )
			{
				secondIndex++;
				firstIndex = secondIndex;
			}
			if( ( (arr.get(firstIndex)+arr.get(secondIndex))==sum ) && firstIndex!=secondIndex )
			{
				System.out.printf("\nSum of elements at indexes at %d and %d equals to %d\n",firstIndex,secondIndex,sum);
			}
			findSum( arr , sum , firstIndex , secondIndex );


		


		}
	}



}














