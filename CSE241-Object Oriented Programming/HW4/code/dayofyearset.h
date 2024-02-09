#ifndef DAYOFYEARSET_H
#define DAYOFYEARSET_H

#include <iostream>
#include <vector>


namespace cse241DayOfYearSet{

class DayOfYearSet
{
	public:


						class DayOfYear
						{
							public:
								DayOfYear() : DayOfYear( 0 , 0 ){ /*Intentionally Empty*/ }
								DayOfYear( int dayOfDay , int mounthOfDay ) : day( dayOfDay ) , mounth( mounthOfDay ){ /*Intentionally Empty*/ }
								DayOfYear( const DayOfYear &obj );
								~DayOfYear(){};
								DayOfYear& operator=( const DayOfYear &obj );
								inline unsigned int getDay() const { return day; }
								inline unsigned int getMounth() const{ return mounth; }
								inline void setDay( unsigned int newDay ) { day = newDay; }
								inline void setMounth( unsigned int newMounth ) { mounth = newMounth; }
								inline bool operator==(const DayOfYear &obj) const { return (  (getDay()==obj.getDay()) && (getMounth()==obj.getMounth())  ); }
								inline bool operator!=(const DayOfYear &obj) const { return !( *this == obj ); }


							private:
								unsigned int day;
								unsigned int mounth;
						};








		DayOfYearSet();

		DayOfYearSet( const std::vector<DayOfYear>& vec );

		~DayOfYearSet(){ delete[] set; objCount--; }



		inline size_t getSetSize() const{ return setArraySize; }  //returns setArraySize variable

		inline int getYear() const{ return year; }  //returns year variable

		inline void setYear( int newYear ){ year = newYear; }  //changes year variable

		inline void setSize( size_t newSize ){ setArraySize = newSize; }  //changes setArraySize variable

		const DayOfYear& getSetMember( const int setIndex) const;  //returns element at given position


		inline int size() const{ return getSetSize(); }  //returns size of this set

		void add( DayOfYear &day );  //adds given element 

		void remove();  //removes element at the end



		friend std::ostream& operator<<( std::ostream& ostObj , const cse241DayOfYearSet::DayOfYearSet& obj );  //prints all days of this object

		bool operator==( const DayOfYearSet& obj )const;  //checks equivalence of two sets

		bool operator!=( const DayOfYearSet& obj )const{ return !( obj == (*this) ); }  //checks inequivalence of two sets

		

		void replaceSet( DayOfYear *newSet );  //replaces given array with set array of this object

		void copySet( DayOfYear *newSet , int sizeOfNewSet );  //copies given array to set array of this object

		void removeDuplicates();  //removes duplicate elements from the set

		DayOfYearSet operator+( const DayOfYearSet& obj )const;  //returns union of two sets

		DayOfYearSet operator-( const DayOfYearSet& obj )const;  //returns difference of two sets

		DayOfYearSet operator^( const DayOfYearSet& obj )const;  //returns intersection of two sets

		DayOfYearSet operator!()const;  //returns complement of the set

		DayOfYear operator[]( int index ){ return set[index]; }  //returns element at given position

		const DayOfYear operator[]( int index ) const{ return set[index]; }  //returns element at given position for const

		static int getNumOfObjects(){ return objCount; }  //returns number of DayOfYearSet objects created so far






	private:


		DayOfYear *set;

		size_t setArraySize;

		int year;

		int returnNumOfDuplicates();

		static int objCount;



};

}


#endif