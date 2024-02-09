#include "dayofyearset.h"




int cse241DayOfYearSet::DayOfYearSet::objCount = 0;








cse241DayOfYearSet::DayOfYearSet::DayOfYear::DayOfYear( const DayOfYear &obj )
{
	day = obj.getDay();
	mounth = obj.getMounth();

}





cse241DayOfYearSet::DayOfYearSet::DayOfYear& cse241DayOfYearSet::DayOfYearSet::DayOfYear::operator=( const cse241DayOfYearSet::DayOfYearSet::DayOfYear &obj )
{
	setDay( obj.getDay() );
	setMounth( obj.getMounth() );

	return *this;
}








cse241DayOfYearSet::DayOfYearSet::DayOfYearSet()
{

	objCount++;

	set = new DayOfYear[365];

	setArraySize = 365;

	year = 2021;




	for( int countDay=1 ; countDay<=365 ; countDay++ )  //this loop sets every day of the year according to how many days each mounth have
	{
		if( countDay<32 )
		{
			set[countDay-1].setMounth(1);
			set[countDay-1].setDay(countDay);
		}
		else if( countDay<60 )
		{
			set[countDay-1].setMounth(2);
			set[countDay-1].setDay(countDay-31);
		}
		else if( countDay<91 )
		{
			set[countDay-1].setMounth(3);
			set[countDay-1].setDay(countDay-59);
		}
		else if( countDay<121 )
		{
			set[countDay-1].setMounth(4);
			set[countDay-1].setDay(countDay-90);
		}
		else if( countDay<152 )
		{
			set[countDay-1].setMounth(5);
			set[countDay-1].setDay(countDay-120);
		}
		else if( countDay<182 )
		{
			set[countDay-1].setMounth(6);
			set[countDay-1].setDay(countDay-151);
		}
		else if( countDay<213 )
		{
			set[countDay-1].setMounth(7);
			set[countDay-1].setDay(countDay-181);
		}
		else if( countDay<244 )
		{
			set[countDay-1].setMounth(8);
			set[countDay-1].setDay(countDay-212);
		}
		else if( countDay<274 )
		{
			set[countDay-1].setMounth(9);
			set[countDay-1].setDay(countDay-243);
		}
		else if( countDay<305 )
		{
			set[countDay-1].setMounth(10);
			set[countDay-1].setDay(countDay-273);
		}
		else if( countDay<335 )
		{
			set[countDay-1].setMounth(11);
			set[countDay-1].setDay(countDay-304);
		}
		else
		{
			set[countDay-1].setMounth(12);
			set[countDay-1].setDay(countDay-334);
		}



	}



}
















cse241DayOfYearSet::DayOfYearSet::DayOfYearSet( const std::vector<DayOfYear>& vec )
{

	objCount++;

	year = 2021;
	
	const int size = vec.size();

	set = new DayOfYear[size];

	setArraySize = size;



	int index=0;

	for( auto day : vec )
	{
		set[index] = day;
		index++;
	}


}














const cse241DayOfYearSet::DayOfYearSet::DayOfYear& cse241DayOfYearSet::DayOfYearSet::getSetMember( const int setIndex ) const
{
	if( setIndex >= getSetSize() )  //checks set size to avoid segmentation fault
	{
		system("clear");
		std::cerr << "getSetMember() function out of range" << setIndex << std::endl;
		exit(1);
	}
	else
	{
		return set[setIndex];  //returns element at wanted location
	}
	

}









std::ostream& cse241DayOfYearSet::operator<<( std::ostream& ostObj , const cse241DayOfYearSet::DayOfYearSet& obj )

{
	for( int setIndex=0 ; setIndex < obj.getSetSize() ; setIndex++ )  //prints all days of the year day by day
	{
		ostObj << obj.getSetMember(setIndex).getDay() << "." << obj.getSetMember(setIndex).getMounth() << "." << obj.getYear() << std::endl;
	}

	return ostObj;
}











bool cse241DayOfYearSet::DayOfYearSet::operator==( const DayOfYearSet& obj )const
{



	if( obj.getSetSize() != getSetSize() )  //if two sets have different size,those can't be equal
	{
		return false;
	}


	for( int indexOne=0 ; indexOne<getSetSize() ; indexOne++ )  //if two sets have different elements
	{
		bool isEqual = false;
		for( int indexTwo=0 ; indexTwo<getSetSize() ; indexTwo++ )
		{
			if( getSetMember(indexOne) == obj.getSetMember(indexTwo) )
			{
				isEqual=true;
				break;
			}
		}

		if(!isEqual)
		{
			return false;
		}
	}

	return true;

}













void cse241DayOfYearSet::DayOfYearSet::removeDuplicates()
{





	const int newSetSize = (getSetSize() - returnNumOfDuplicates() );  //new size of the set after removing duplicates

	




	int *nonDuplicateElementsIndexArr = new int[newSetSize];  //a new array allocated with new size

	int nonDuplicateElementsIndexArrIndex = 0;  

	DayOfYear *newSet = new DayOfYear[newSetSize];











	for( int indexOne = 0 ; indexOne<getSetSize()-1 ; indexOne++ )
	{
		bool isDuplicate = false;

		for( int indexTwo = indexOne+1 ; indexTwo<(getSetSize()) ; indexTwo++ )
		{
			if( getSetMember(indexOne) == getSetMember(indexTwo) )
			{

				isDuplicate = true;
				break;
			}
				
		}
		if( (isDuplicate!=true) )  //nonDuplicateElementsIndexArr gets index of non-duplicate element's index
		{
				nonDuplicateElementsIndexArr[ nonDuplicateElementsIndexArrIndex ] = indexOne;
				nonDuplicateElementsIndexArrIndex++;
		}		
	}
	nonDuplicateElementsIndexArr[ nonDuplicateElementsIndexArrIndex ] = getSetSize()-1;







	for( int index = 0 ; index<newSetSize ; index++ )  //newSet gets filled with non-duplicate elements
	{
			newSet[index] = getSetMember( nonDuplicateElementsIndexArr[index] );				
	}	


	delete[] set;

	set = new DayOfYear[newSetSize];


		
	for( int index = 0 ; index<newSetSize ; index++ )
	{
		set[index] = newSet[index] ;				
	}	

	setArraySize = newSetSize;



}













int cse241DayOfYearSet::DayOfYearSet::returnNumOfDuplicates()
{
	int numOfDuplicates{0};


	//these loops count number of duplicate elements in set
	for( int indexOne = 0 ; indexOne<(getSetSize()-1) ; indexOne++ )
	{
		for( int indexTwo = (indexOne+1) ; indexTwo<getSetSize() ; indexTwo++ )
		{
			if( getSetMember(indexOne) == getSetMember(indexTwo) )
			{
				numOfDuplicates++;
				break;
			}
				
		}
			
	}

	return numOfDuplicates;

}










cse241DayOfYearSet::DayOfYearSet cse241DayOfYearSet::DayOfYearSet::operator+( const cse241DayOfYearSet::DayOfYearSet& obj )const
{
	DayOfYearSet tempObj;


	const int newSetSize =  getSetSize() + obj.getSetSize() ;  //size of new set array


	decltype(set) newSet = new DayOfYear[newSetSize];


	tempObj.setSize( newSetSize );



	for( int firstSetIndex=0 ; firstSetIndex<getSetSize() ; firstSetIndex++  )
	{
		newSet[firstSetIndex] = getSetMember( firstSetIndex );

	}

	for( int secondSetIndex=getSetSize() ; secondSetIndex<tempObj.getSetSize() ; secondSetIndex++  )
	{
		newSet[secondSetIndex] = obj.getSetMember( secondSetIndex-getSetSize() );
	}


	//new set array is created by appending two set arrays of objects


	

	tempObj.replaceSet( newSet );  //new set is replaced with current set of tempObj


	tempObj.removeDuplicates();   //duplicate elements are removed from tempObj



	return tempObj;

}


























cse241DayOfYearSet::DayOfYearSet cse241DayOfYearSet::DayOfYearSet::operator-( const cse241DayOfYearSet::DayOfYearSet& obj ) const
{
	DayOfYearSet tempSet;
	tempSet.copySet( set , getSetSize() );  //copies current set array to tempSet
	tempSet.setSize( getSetSize() );

	std::vector<bool> indexesForElementsWillBeRemoved( tempSet.getSetSize() , false );  //this vector is used to decide which elements will be removed from first set
	
	std::vector<DayOfYear> newSetVector;  //used to keep new elements of the first set





	//these loops sets which elements will be removed
	for( int tempSetIndex=0; tempSetIndex<tempSet.getSetSize() ; tempSetIndex++  )
	{
		for( int secondSetIndex=0 ; secondSetIndex<obj.getSetSize() ; secondSetIndex++ )
		{
			if( tempSet.getSetMember( tempSetIndex ) == obj.getSetMember( secondSetIndex ) )
			{
				indexesForElementsWillBeRemoved[tempSetIndex]=true;
				break;
			}
		}
	}



	//this loop fills newSetVector without elements will be removed which are decided by "indexesForElementsWillBeRemoved" vector
	for( int tempSetIndex=0; tempSetIndex<tempSet.getSetSize() ; tempSetIndex++  )
	{
		if(  indexesForElementsWillBeRemoved[tempSetIndex]==false)
		{
			newSetVector.push_back( tempSet.getSetMember( tempSetIndex ) );
		}
	}





	const int newSetSize = newSetVector.size();  // size of the new set

	decltype(set) newSet = new DayOfYear[ newSetSize ];  //new set array is allocated with size of new set




	for( int index=0; index<newSetSize ; index++  )
	{
		newSet[index] = newSetVector[index];
	}

	tempSet.replaceSet(newSet);

	tempSet.setSize(newSetSize);


	tempSet.removeDuplicates();

	return tempSet;
}











cse241DayOfYearSet::DayOfYearSet cse241DayOfYearSet::DayOfYearSet::operator^( const cse241DayOfYearSet::DayOfYearSet& obj ) const
{
	DayOfYearSet tempSet;  //temp object is created
	std::vector<DayOfYear> daysVector;   //keeps days that are intersection of two sets



	for( int firstSetSize=0 ; firstSetSize<getSetSize() ; firstSetSize++ )//fills daysVector with intersections
	{
		for( int secSetSize=0 ; secSetSize<obj.getSetSize() ; secSetSize++ )
		{
			if( getSetMember(firstSetSize) == obj.getSetMember(secSetSize) )
			{
				daysVector.push_back( getSetMember(firstSetSize) );
				break;
			}
		}
	}


	const int tempSetSize = daysVector.size();  //sets size of new set

	DayOfYear *newSet = new DayOfYear[ tempSetSize ];  //allocates a new array for new set

	tempSet.setSize( tempSetSize );   //adjusts size of the object to new set's size




	for( int index=0 ; index<getSetSize() ; index++ )//fills new set with days from vector
	{
		newSet[index] = daysVector[index];
	}


	tempSet.replaceSet( newSet );  //replaces current set with new one





	tempSet.removeDuplicates();

	return tempSet;


}






















cse241DayOfYearSet::DayOfYearSet cse241DayOfYearSet::DayOfYearSet::operator!() const
{
	DayOfYearSet tempSet;  //creates a default object which has all days of a year

	return tempSet-(*this);
}







void cse241DayOfYearSet::DayOfYearSet::add( cse241DayOfYearSet::DayOfYearSet::DayOfYear &day )
{

	const int newSetSize = getSetSize()+1;  //increments current size by one

	DayOfYear *newSet = new DayOfYear[newSetSize];   //allocates a new array with new size


	for( int index=0 ; index<getSetSize() ; index++ )  //fills new array with current array
	{
		newSet[index] = getSetMember( index );
	}

	newSet[ newSetSize-1 ] = day;  //adds given object to end of the new array

	setSize( newSetSize );  //sets setArraySize member

	replaceSet( newSet );   //replaces old array with new one

	removeDuplicates();   //clears duplicate elements

}











void cse241DayOfYearSet::DayOfYearSet::remove()
{

	const int newSetSize = getSetSize()-1;

	DayOfYear *newSet = new DayOfYear[newSetSize];


	for( int index=0 ; index<(getSetSize()-1) ; index++ )
	{
		newSet[index] = getSetMember( index );
	}


	setSize( newSetSize );

	replaceSet( newSet );

	removeDuplicates();

}













void cse241DayOfYearSet::DayOfYearSet::replaceSet( cse241DayOfYearSet::DayOfYearSet::DayOfYear *newSet )
{
		delete[] set;

		set = newSet;

		removeDuplicates();
}














void cse241DayOfYearSet::DayOfYearSet::copySet( cse241DayOfYearSet::DayOfYearSet::DayOfYear *newSet , int sizeOfNewSet )
{

		const int size = sizeOfNewSet;

		delete[] set;

		setSize( size );

		set = new DayOfYear[size];


		for( int index=0 ; index<size ; index++ )
		{
			set[index] = newSet[index];
		}

		removeDuplicates();


}









