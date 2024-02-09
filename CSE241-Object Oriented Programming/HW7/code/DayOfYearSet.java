

import java.util.Scanner;
import java.util.ArrayList;
import java.io.File;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;



/**
*The class that keeps days of a year and the year value as a set
*/
public class DayOfYearSet
{

			/**
			*Static inner class that represents one element of DayOfYearSet
			*/
			public static class DayOfYear
			{


					/**
					*Default constructor,sets object as 1 january
					*/
					public DayOfYear()
					{
						day = 1;
						mounth = 1;
					}



					/**
					*Sets object with given day and mounth value
					*@param newDay is the day value of the object
					*@param newMounth is the mounth value of the object
					*/
					public DayOfYear( int newDay , int newMounth )
					{
						setMounth(newMounth);
						setDay(newDay);
					}



					/**
					*Changes day value of the object
					*@param newDay is the new value of the day
					*/
					public void setDay( int newDay )
					{ 
						IllegalArgumentException ex = new IllegalArgumentException("Invalid day value for DayOfYear");

						if( newDay<0 )
						{
								throw ex;
						}
						else if( (getMounth()==1) ||(getMounth()==3) ||(getMounth()==5) ||(getMounth()==7) ||(getMounth()==8) ||(getMounth()==10) ||(getMounth()==12) )
						{
							if( newDay>31 )
							{
								throw ex;
							}
						}
						else if( (getMounth()==4) ||(getMounth()==6) ||(getMounth()==9) ||(getMounth()==11) )
						{
							if( newDay>30 )
							{
								throw ex;
							}
						}
						else if ( newDay>28)
						{

							throw ex;
							
						}
						day = newDay; 
					}



					/**
					*Changes mounth value of the object
					*@param newMounth is the new mounth value
					*/
					public void setMounth( int newMounth )
					{
						if( (newMounth>12) || (newMounth<1) )
						{
							IllegalArgumentException ex = new IllegalArgumentException("Invalid mounth value for DayOfYear");
							throw ex;
						}
						mounth = newMounth;
					}


					/**
					*Returns day value of the object
					*@return day is the day value of DayOfYear object
					*/
					public int getDay(){ return day; }


					/**
					*Returns mounth value of the object
					*@return mounth is the mounth value of DayOfYear object
					*/
					public int getMounth(){ return mounth; }


					/**
					*Checks if object is equal with given object
					*@param obj is the given object that is checked is it's equal to corresponding object
					*@return equals is the return value
					*/
					public boolean isEqual( DayOfYear obj )
					{
						boolean equals = ( (obj.getDay() == getDay() ) && (obj.getMounth() == getMounth()) );
						return  equals;  
					} 

					private int day;

					private int mounth;
			}






	public void save( String fileName )
	{
	    try
	    {
	     	FileWriter saveFile = new FileWriter(fileName);

			for( int countDay=0 ; countDay<setSize ; countDay++ )
			{
				String str = String.valueOf( getCopyOfElementAtGivenIndex(countDay).getDay() );
				saveFile.write( str );
				saveFile.write(".");
				str = String.valueOf( getCopyOfElementAtGivenIndex(countDay).getMounth() );
				saveFile.write( str );
				saveFile.write(".");
				str = String.valueOf( getYear() );
				saveFile.write( str );
				saveFile.write("\n");
			}
	     	saveFile.close();
	    } 
	    catch (IOException e)
	    {
	    	System.out.printf("Error writing save file...\n");
	    }
	}





	/**
	*Default constructor,sets year to 2000 and sets the set to null
	*/
	public DayOfYearSet()
	{
		set = null;
		setSize = 0;
		year = 2000;
	}







	/**
	*Sets the set with given DayOfYear objects from ArrayList,sets year to 2000 defaultly
	*@param newSetArrayList is the ArrayList which DayOfYear objects are taken from
	*/
	public DayOfYearSet( ArrayList<DayOfYear> newSetArrayList )
	{
		year = 2000;

		setSize = newSetArrayList.size();

		set = new DayOfYear[ setSize ];

		for( int i=0; i<setSize ; i++ )
		{
			var tempDay = new DayOfYear( newSetArrayList.get(i).getDay() , newSetArrayList.get(i).getDay()  );
			set[i] = tempDay;
		}

		numberOfAliveDayOfYearObjects += size();

	}





	/**
	*Fulls the set with available 365 days in a year,sets year to given value
	*@param setYear is set as value of the year
	*/
	public DayOfYearSet(int setYear)
	{

			set = new DayOfYear[365];

			setSize = 365;

			year = setYear;



			for( int countDay=1 ; countDay<=365 ; countDay++ )  //this loop sets every day of the year according to how many days each mounth have
			{
				DayOfYear o = new DayOfYear();
				if( countDay<32 )
				{
					o.setMounth(1);
					o.setDay(countDay);
				}
				else if( countDay<60 )
				{
					o.setMounth(2);
					o.setDay(countDay-31);
				}
				else if( countDay<91 )
				{
					o.setMounth(3);
					o.setDay(countDay-59);
				}
				else if( countDay<121 )
				{
					o.setMounth(4);
					o.setDay(countDay-90);
				}
				else if( countDay<152 )
				{
					o.setMounth(5);
					o.setDay(countDay-120);
				}
				else if( countDay<182 )
				{
					o.setMounth(6);
					o.setDay(countDay-151);
				}
				else if( countDay<213 )
				{
					o.setMounth(7);
					o.setDay(countDay-181);
				}
				else if( countDay<244 )
				{
					o.setMounth(8);
					o.setDay(countDay-212);
				}
				else if( countDay<274 )
				{
					o.setMounth(9);
					o.setDay(countDay-243);
				}
				else if( countDay<305 )
				{
					o.setMounth(10);
					o.setDay(countDay-273);
				}
				else if( countDay<335 )
				{
					o.setMounth(11);
					o.setDay(countDay-304);
				}
				else
				{
					o.setMounth(12);
					o.setDay(countDay-334);
				}
				set[countDay-1] = o;
		}

		numberOfAliveDayOfYearObjects += size();
	}


	/**
	*Sets year value to given year
	*@param newYear is the new value of the year value
	*/
	public void setYear(int newYear){ year = newYear; }



	/**
	*Returns year value
	*@return year is the return value
	*/
	public int getYear(){ return year; }



	/**
	*Returns set size
	*@return setSize is the return value
	*/
	public int size(){ return setSize; }








	/**
	*returns if given DayOfYearSet is equal to this DayOfYearSet
	*@param obj is the set that will be checked if it's equal
	*@return equals is the return value
	*/
	public boolean equals( DayOfYearSet obj )
	{

			boolean equals = true;

			if( obj.setSize != size() )  //if two sets have different size,those can't be equal
			{
				equals = false;
				return equals;
			}
			else if( obj.getYear() != getYear() )
			{
				equals = false;
				return equals;
			}

			for( int indexOne=0 ; indexOne<size() ; indexOne++ )  //if two sets have different elements
			{
				boolean isEqual = false;
				for( int indexTwo=0 ; indexTwo<size() ; indexTwo++ )
				{
					if( set[indexOne].isEqual(obj.set[indexTwo]) )
					{
						isEqual=true;
						break;
					}
				}

				if(!isEqual)
				{
					equals = false;
					return equals;
				}
			}

			return equals;
	}









	/**
	*Prints elements of the set
	*/
	public void ToString()
	{
		for( int countDay=0 ; countDay<setSize ; countDay++ )
		{
			System.out.printf("%d.%d.%d\n",set[countDay].getDay(),set[countDay].getMounth(),getYear() );
		}
	}









	/**
	*Returns how many elements are same in the set
	*/
	private int getNumOfRepetitiveElements()
	{
		int numOfDuplicates = 0;


		//these loops count number of duplicate elements in set
		for( int indexOne = 0 ; indexOne<(setSize-1) ; indexOne++ )
		{
			for( int indexTwo = (indexOne+1) ; indexTwo<setSize ; indexTwo++ )
			{
				if( set[indexOne].isEqual(set[indexTwo]) )
				{
					numOfDuplicates++;
					break;
				}
					
			}
				
		}

		return numOfDuplicates;

	}













	/**
	*Removes repetitive elements
	*/
	private void removeRepetitiveElements()
	{

		int newSetSize = (size() - getNumOfRepetitiveElements() );  //new size of the set after removing duplicates

		DayOfYear newSet[] = new DayOfYear[newSetSize];

		for( int i=0 ; i<newSetSize ; i++ )
		{
			DayOfYear o = new DayOfYear();
			newSet[i] = o;
		}



		int newSetIndex = 0;

		for( int indexOne=0 ; indexOne<size() ; indexOne++ )
		{
			boolean addElement = true;
			for( int indexTwo=0 ; indexTwo<indexOne ; indexTwo++ )
			{
				if( set[indexOne].isEqual(set[indexTwo]) )
				{
					addElement = false;
					break;
				}

			}
			if( addElement )
			{
				newSet[newSetIndex] = set[indexOne];
				newSetIndex++;
			}
		}


		setSize = newSetSize;

	}





	/**
	*Adds a new day with given parameters
	*@param day is day value of the added day
	*@param mounth is the mounth value of the added day
	*/
	public void add( int day,int mounth )
	{
		var newDay = new DayOfYear( day,mounth );
		add( newDay );

		if( getNumOfRepetitiveElements() == 0 )
		{
			numberOfAliveDayOfYearObjects++ ;
		}
		removeRepetitiveElements();

	}




	/**
	*Adds a new day with given parameters
	*@param newDay is the new DayOfYear object which is added to the set
	*/
	public void add( DayOfYear newDay )
	{
		var newSetSize = size()+1;  //increments current size by one

		DayOfYear newSet[] = new DayOfYear[newSetSize];   //allocates a new array with new size


		for( int index=0 ; index<size() ; index++ )  //fills new array with current array
		{
			newSet[index] = set[index];
		}

		newSet[ newSetSize-1 ] = newDay;  //adds given object to end of the new array

		setSize = newSetSize;

		set = newSet;


		removeRepetitiveElements();

	}




	/**
	*Removes the day with given parameters from the set.
	*@param day is day value of the day that will be removed
	*@param mounth is mounth value of the day that will be removed
	*/
	public void remove( int day , int mounth  )
	{
		DayOfYear tempSet[] = new DayOfYear[ size() ];
		var removedObjectCopy = new DayOfYear( day,mounth );

		for( int i=0 ; i<size() ; i++ )
		{
			var tempDay = new DayOfYear( set[i].getDay() , set[i].getMounth() );
			tempSet[i] = tempDay;
		}

		set = null;
		int count = size();
		setSize = 0;


		numberOfAliveDayOfYearObjects -= size() ;
		

		for( int i=0 ; i<count ; i++ )
		{
			if( !tempSet[i].isEqual( removedObjectCopy ) )
			{
				add( tempSet[i] );
			}

		}





	}



	/**
	*Returns an DayOfYearSet object which is union of corresponding set and given set
	*@param secondSet secondSet is the set that is used to get union 
	*@return newSet is the return value
	*/
	public DayOfYearSet union( DayOfYearSet secondSet )
	{

		var newSet = new DayOfYearSet();


		for( int i=0;i<size();i++ )
		{
			newSet.add( getCopyOfElementAtGivenIndex(i) );
		}
		for( int i=0;i<secondSet.size();i++ )
		{
			newSet.add( secondSet.getCopyOfElementAtGivenIndex(i) );
		}


		numberOfAliveDayOfYearObjects+= newSet.size() ;
		
		return newSet;
	}




	/**
	*Returns intersection of the sets
	*@param secondSet is the set that is the set that is used to get intersection
	*@return newSet is the return value
	*/
	public DayOfYearSet intersection( DayOfYearSet secondSet )
	{

		var newSet = new DayOfYearSet();


		for( int i=0;i<size();i++ )
		{
			for( int m=0;m<secondSet.size();m++ )
			{
				if( getCopyOfElementAtGivenIndex(i).isEqual( secondSet.getCopyOfElementAtGivenIndex(m) ) )
				{
					newSet.add( getCopyOfElementAtGivenIndex(i) );
				}
			}
		}

		numberOfAliveDayOfYearObjects+= newSet.size() ;


		return newSet;
	}




	/**
	*Returns compliment of the given set which is diferrence of given set and full set
	*@return complement is the return value
	*/
	public DayOfYearSet complement()
	{

		var complement = new DayOfYearSet( getYear() );


		for( int i=0;i<size();i++ )
		{
			complement.remove( getCopyOfElementAtGivenIndex(i).getDay() , getCopyOfElementAtGivenIndex(i).getMounth() );
		}

		numberOfAliveDayOfYearObjects+= complement.size();

		return complement;

	}


	/**
	*Returns an DayOfYearSet object which is union of corresponding set and given set
	*@param secondSet secondSet is the set that is the set that is used to get difference
	*@return newSet is the return value
	*/
	public DayOfYearSet difference( DayOfYearSet secondSet )
	{

		var difference = new DayOfYearSet();


		for( int i=0;i<size();i++ )
		{
			difference.add( getCopyOfElementAtGivenIndex(i) );
		}


		for( int m=0;m<secondSet.size();m++ )
		{
			difference.remove( secondSet.getCopyOfElementAtGivenIndex(m).getDay() , secondSet.getCopyOfElementAtGivenIndex(m).getMounth()  );
		}

		

		numberOfAliveDayOfYearObjects+= difference.size();

		return difference;

	}










	/**
	*Returns of a copy of DayOfYear object at given index
	*@param index is index of the copied DayOfYear object
	*/
	private DayOfYear getCopyOfElementAtGivenIndex( int index )
	{
		if( ( index>=size() ) || (index<0) )
		{
			IndexOutOfBoundsException ex = new IndexOutOfBoundsException();
			throw ex;
		}

		var tempDay = new DayOfYear( set[index].getDay() , set[index].getMounth() );

		return tempDay;
	}






	private DayOfYear set[];
	private int setSize;
	private int year;
	public static int numberOfAliveDayOfYearObjects;



	/**
	*Main function that tests DayOfYearSet methods
	*@param args is the argument of main function
	*/
	public static void main( String args[] )
	{

		DayOfYearSet set1 = new DayOfYearSet();
		DayOfYearSet set2 = new DayOfYearSet();
		DayOfYearSet set3 = new DayOfYearSet();
		DayOfYearSet set4;
		DayOfYearSet set5 = new DayOfYearSet();


		ArrayList<DayOfYear> arrListObj = new ArrayList<DayOfYear>();
		arrListObj.add( new DayOfYear(11,11) );
		arrListObj.add( new DayOfYear(3,4) );
		arrListObj.add( new DayOfYear(1,8) );


		set1.add(1,2);
		set1.add(1,3);
		set1.add(25,4);
		set1.add(19,6);
		set2.add(19,6);
		set2.add(25,11);
		set2.add(26,12);
		set3.add(19,7);
		set3.add(22,11);
		set3.add(18,3);
		set3.add(13,5);
		set5.add(19,7);
		set5.add(22,11);
		set5.add(18,3);
		set5.add(13,5);

		set4 = new DayOfYearSet( arrListObj );




		Scanner input = new Scanner(System.in);

		int choice=0;

		System.out.printf( "To print set1 and set2,enter 0\n");
		System.out.printf( "To print set3 and set4,enter 1\n");
		System.out.printf( "To print set1+set2,enter 2\n");
		System.out.printf( "To print set3+set4,enter 3\n");
		System.out.printf( "To print set1-set2,enter 4\n");
		System.out.printf( "To print set3-set5,enter 5\n");
		System.out.printf( "To print set1^set2,enter 6\n");
		System.out.printf( "To print set3^set4,enter 7\n");
		System.out.printf( "To print number of all DayOfYear objects alive,enter 8\n");
		System.out.printf( "To print number of all DayOfYear objects alive,enter 9\n");
		System.out.printf( "To print size of set1,enter 10\n");
		System.out.printf( "To print size of set2,enter 11\n");
		System.out.printf( "To add 'november 15th' to set1,enter 12\n");
		System.out.printf( "To add 'june 19th' to set2,enter 13\n");
		System.out.printf( "To remove july 19th from set3,enter 14\n");
		System.out.printf( "To remove december 31th set4,enter 15\n");
		System.out.printf( "To check de morgan rules for set1 and set2,enter 16\n");
		System.out.printf( "To check de morgan rules for set3 and set4,enter 17\n");
		System.out.printf( "To print !set1,enter 18\n");
		System.out.printf( "To print !set2,enter 19\n");
		System.out.printf( "To check equality for set4 and set5,enter 20\n");
		System.out.printf( "To check equality for set3 and set5,enter 21\n");
		System.out.printf( "To save sets,enter 22\n");
		System.out.printf( "\n\n\n\nYour choice --> ");

		choice = input.nextInt();


		System.out.printf(" \033[H\033[2J");
		if( choice == 0 )
		{
			System.out.printf("Set 1 is below...\n");
			set1.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("Set 2 is below...\n");
			set2.ToString();
		}
		else if( choice == 1 )
		{
			System.out.printf("Set 3 is below...\n");
			set3.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("Set 4 is below...\n");
			set4.ToString();
		}
		else if( choice == 2 )
		{
			DayOfYearSet unionSet = set1.union(set2);
			System.out.printf("Set 1 is below...\n");
			set1.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("Set 2 is below...\n");
			set2.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("set1+set2 is below...\n");
			unionSet.ToString();
		}
		else if( choice == 3 )
		{
			DayOfYearSet unionSet = set3.union(set4);
			System.out.printf("Set 3 is below...\n");
			set3.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("Set 4 is below...\n");
			set4.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("set3+set4 is below...\n");
			unionSet.ToString();
		}
		else if( choice == 4 )
		{
			DayOfYearSet differenceSet = set1.difference(set2);
			System.out.printf("Set 1 is below...\n");
			set1.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("Set 2 is below...\n");
			set2.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("set1-set2 is below...\n");
			differenceSet.ToString();
		}
		else if( choice == 5 )
		{
			DayOfYearSet differenceSet = set3.difference(set5);
			System.out.printf("Set 3 is below...\n");
			set3.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("Set 5 is below...\n");
			set5.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("set3-set5 is below...\n");
			differenceSet.ToString();
		}
		else if( choice == 6 )
		{
			DayOfYearSet intersectionSet = set1.intersection(set2);
			System.out.printf("Set 1 is below...\n");
			set1.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("Set 2 is below...\n");
			set2.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("set1^set2 is below...\n");
			intersectionSet.ToString();
		}
		else if( choice == 7 )
		{
			DayOfYearSet intersectionSet = set3.intersection(set4);
			System.out.printf("Set 3 is below...\n");
			set3.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("Set 4 is below...\n");
			set4.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("set3^set4 is below...\n");
			intersectionSet.ToString();
		}
		else if( choice == 8 )
		{
			System.out.printf("Set 1 is below...\n");
			set1.ToString();
			System.out.printf("Set 2 is below...\n");
			set2.ToString();
			System.out.printf("Set 3 is below...\n");
			set3.ToString();
			System.out.printf("Set 4 is below...\n");
			set4.ToString();
			System.out.printf("Set 5 is below...\n");
			set5.ToString();
			DayOfYearSet o = new DayOfYearSet();
			System.out.printf("Number of DayOfYear objects = %d\n",o.numberOfAliveDayOfYearObjects);
		}
		else if( choice == 9 )
		{
			System.out.printf("Set 1 is below...\n");
			set1.ToString();
			System.out.printf("Set 2 is below...\n");
			set2.ToString();
			System.out.printf("Set 3 is below...\n");
			set3.ToString();
			System.out.printf("Set 4 is below...\n");
			set4.ToString();
			System.out.printf("Set 5 is below...\n");
			set5.ToString();
			DayOfYearSet o = new DayOfYearSet();
			System.out.printf("Number of DayOfYear objects = %d\n",o.numberOfAliveDayOfYearObjects);
		}
		else if( choice == 10 )
		{
			System.out.printf("Set 1 is below...\n");
			set1.ToString();
			System.out.printf("Size of set1 = %d\n",set1.size());
		}
		else if( choice == 11 )
		{
			System.out.printf("Set 2 is below...\n");
			set2.ToString();
			System.out.printf("Size of set2 = %d\n",set2.size());
		}
		else if( choice == 12 )
		{
			System.out.printf("Set 1 is below...\n");
			set1.ToString();
			set1.add( new DayOfYear(15,11) );
			System.out.printf("november 15th is added to the set1...\n");
			System.out.printf("Set 1 is below...\n");
			set1.ToString();

		}
		else if( choice == 13 )
		{
			System.out.printf("Set 2 is below...\n");
			set2.ToString();
			set2.add( 19,6 );
			System.out.printf("june 19th is added to the set2...\n");
			System.out.printf("Set 2 is below...\n");
			set2.ToString();
		}
		else if( choice == 14 )
		{
			System.out.printf("Set 3 is below...\n");
			set3.ToString();
			set3.remove( 19,7 );
			System.out.printf("june 19th is added to the set3...\n");
			System.out.printf("Set 3 is below...\n");
			set3.ToString();
		}
		else if( choice == 15 )
		{
			System.out.printf("Set 4 is below...\n");
			set4.ToString();
			set4.remove( 31,12 );
			System.out.printf("june 19th is added to the set4...\n");
			System.out.printf("Set 4 is below...\n");
			set4.ToString();
		}
		else if( choice == 16 )
		{
			System.out.printf("Set 1 is below...\n");
			set1.ToString();
			System.out.printf("Set 2 is below...\n");
			set2.ToString();

			var testSetOne = set1.union(set2);
			var testSetTwo = testSetOne.complement();  //left side
			var testSetThree = set1.complement();
			var testSetFour = set2.complement();
			var testSetFive = testSetThree.intersection(testSetFour); //right side
			
			if( testSetFive.equals( testSetTwo ) )
			{
				System.out.printf("!(s1+s2) = !s1 ^ !s2 \n");
			}

		}
		else if( choice == 17 )
		{
			System.out.printf("Set 3 is below...\n");
			set3.ToString();
			System.out.printf("Set 4 is below...\n");
			set4.ToString();

			var testSetOne = set3.union(set4);
			var testSetTwo = testSetOne.complement();  //left side
			var testSetThree = set3.complement();
			var testSetFour = set4.complement();
			var testSetFive = testSetThree.intersection(testSetFour); //right side
			
			if( testSetFive.equals( testSetTwo ) )
			{
				System.out.printf("!(s3+s4) = !s3 ^ !s4 \n");
			}

		}
		else if( choice == 18 )
		{
			System.out.printf("set1 is below...\n");
			set1.ToString();
			var compSet1 = set1.complement();
			System.out.printf("!set1 is below...\n");
			compSet1.ToString();

		}
		else if( choice == 19 )
		{
			System.out.printf("set2 is below...\n");
			set2.ToString();
			var compSet2 = set2.complement();
			System.out.printf("!set2 is below...\n");
			compSet2.ToString();

		}
		else if( choice == 20 )
		{
			DayOfYearSet unionSet = set1.union(set2);
			System.out.printf("Set 4 is below...\n");
			set4.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("Set 5 is below...\n");
			set5.ToString();
			System.out.printf("\n\n\n");
			
			if( set4.equals(set5) )
			{
				System.out.printf("set4 == set5\n");
			}
			else
			{
				System.out.printf("set4 != set5\n");
			}

		}
		else if( choice == 21 )
		{
			DayOfYearSet unionSet = set1.union(set2);
			System.out.printf("Set 3 is below...\n");
			set3.ToString();
			System.out.printf("\n\n\n");
			System.out.printf("Set 5 is below...\n");
			set5.ToString();
			System.out.printf("\n\n\n");
			
			if( set3.equals(set5) )
			{
				System.out.printf("set3 == set5\n");
			}
			else
			{
				System.out.printf("set3 != set5\n");
			}

		}
		else if( choice == 22 )
		{
			set1.save("set1.txt");
			set2.save("set2.txt");
			set3.save("set3.txt");
			set4.save("set4.txt");
			set5.save("set5.txt");
		}



	}
	
}







