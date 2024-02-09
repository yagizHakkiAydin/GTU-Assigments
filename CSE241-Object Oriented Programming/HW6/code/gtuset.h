#ifndef GTUSET_H
#define GTUSET_H



#include "iterable.h"


namespace cse241hw6
{


	template <class T>
	class GTUSet : public Iterable<T>
	{
		public:


			GTUSet<T>();

			GTUSet( const GTUSet& GTUSetObj );  //Copy constructor
			GTUSet& operator=( const GTUSet& GTUSetObj );   //Copy assigment operator
			
			GTUSet( GTUSet&& GTUSetObj );	  //Move constructor
			GTUSet& operator=( GTUSet&& GTUSetObj ); //Move assigment operator


			~GTUSet();



			bool empty() const override{ return (size()==0); }
			size_t size() const override{ return this->containerSize; }
			void clear() override{ this->containerSize = 0;  this->element = std::make_shared<containerElement<T>>(); }
 

			typedef typename Iterable<T>::GTUIterator iterator;
			typedef typename Iterable<T>::GTUIteratorConst const_iterator;


			void erase( iterator iteratorObj ) override{ erase(*iteratorObj); }



			iterator begin() override;
			iterator end() override;
			const const_iterator cbegin() const override;
			const const_iterator cend() const override;



			GTUSet<T> intersect( const GTUSet<T>& GTUSetObj );
			GTUSet<T> unionSet( const GTUSet<T>& GTUSetObj );


			T& operator[](int index);
			iterator insert( T obj );
			size_t erase ( const T& obj );



		private:
			void deleteRepetitiveElements();

			
	};










	template <class T> GTUSet<T>::GTUSet()
	{
		this->containerSize = 0;
		this->element = std::make_shared<containerElement<T>>();
	}











	template <class T> GTUSet<T>::GTUSet( const GTUSet<T>& GTUSetObj )
	{
		*(this) = GTUSetObj;

	}







	template <class T> GTUSet<T>& GTUSet<T>::operator=( const GTUSet& GTUSetObj )
	{

		GTUSet<T>::const_iterator iteratorObj = GTUSetObj.cbegin();
		std::shared_ptr<containerElement<T>> head = std::make_shared<containerElement<T>>();
		std::shared_ptr<containerElement<T>> tempPtr = head;
		tempPtr->data = *(iteratorObj);

		this->containerSize = GTUSetObj.size();



		for( int i=0 ; i<GTUSetObj.size() ; i++ )
		{
			iteratorObj++;

			std::shared_ptr<containerElement<T>> tempElement(new containerElement<T>());

			tempElement->previousElement = tempPtr;

			tempPtr->nextElement = tempElement;

			tempPtr = tempElement;

			tempPtr->data = *(iteratorObj);
		}

		this->element = head;


		return *this;
	}



			
	template <class T> GTUSet<T>::GTUSet( GTUSet<T>&& GTUSetObj )
	{
		this->element = GTUSetObj.element;
		this->containerSize = GTUSetObj.size();
		this->deleteRepetitiveElements();
	}




	template <class T> GTUSet<T>& GTUSet<T>::operator=( GTUSet&& GTUSetObj )
	{
		this->element = GTUSetObj.element;
		this->containerSize = GTUSetObj.size();
		this->deleteRepetitiveElements();

		return *(this);
	}
		




	template <class T> GTUSet<T>::~GTUSet()
	{
		this->element = nullptr;
		this->containerSize = -1;
	}














	template <class T> typename GTUSet<T>::iterator GTUSet<T>::insert( T obj )
	{

		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		std::shared_ptr<containerElement<T>> newElement(new containerElement<T>());




		while( tempPtr->nextElement != nullptr )
		{
			tempPtr = tempPtr->nextElement;
		}


		tempPtr->data = obj;

		tempPtr->nextElement = newElement;
		newElement->previousElement = tempPtr;

		this->containerSize++;


		this->deleteRepetitiveElements();


		return iterator();

	}









	template <class T> typename GTUSet<T>::iterator GTUSet<T>::end()  //goes most-right on the list and returns iterator of last element
	{
		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an end";
			exit(1);
		}



		GTUSet<T>::iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->nextElement != nullptr )
		{
			tempPtr = tempPtr->nextElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;
	}










	template <class T> typename GTUSet<T>::iterator GTUSet<T>::begin()  //goes most-left on the list and returns iterator of first element
	{

		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an begin";
			exit(1);
		}




		GTUSet<T>::iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->previousElement != nullptr )
		{
			tempPtr = tempPtr->previousElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;


	}






	template <class T> const typename GTUSet<T>::const_iterator GTUSet<T>::cbegin() const
	{

		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an begin";
			exit(1);
		}


		GTUSet<T>::const_iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->previousElement != nullptr )
		{
			tempPtr = tempPtr->previousElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;

	}






	template <class T> const typename GTUSet<T>::const_iterator GTUSet<T>::cend() const
	{

		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an end";
			exit(1);
		}



		GTUSet<T>::const_iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->nextElement != nullptr )
		{
			tempPtr = tempPtr->nextElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;
	}













	template <class T> T& GTUSet<T>::operator[](int index)
	{

		GTUSet<T>::iterator iteratorObj = begin();

		for( int i=0 ; i<index ; i++ )
		{
			iteratorObj++;
		}

		return iteratorObj->data;

	}






	template <class T> void GTUSet<T>::deleteRepetitiveElements()
	{


		GTUSet<T>::iterator iteratorObj1;
		GTUSet<T>::iterator iteratorObj2;



		for( iteratorObj1=( this->begin() ) ; iteratorObj1!=( this->end() ) ; iteratorObj1++ )
		{
			for( iteratorObj2=( this->begin() ) ; iteratorObj2!=(iteratorObj1) ; iteratorObj2++ )
			{
				if( *(iteratorObj1) == *(iteratorObj2) )
				{
					iteratorObj1->previousElement->nextElement = iteratorObj1->nextElement;
					iteratorObj1->nextElement->previousElement = iteratorObj1->previousElement;
					this->containerSize --;
					break;
				}
			}		
		}

	}







	template <class T> size_t GTUSet<T>::erase ( const T& obj )  //Find corresponding element of the doubly-list and connects previous and next elements
	{
		GTUSet<T>::iterator iteratorObj;



		for( iteratorObj=( this->begin() ) ; iteratorObj!=( this->end() ) ; iteratorObj++ )
		{
			if( *(iteratorObj) == obj)
			{
					iteratorObj->previousElement->nextElement = iteratorObj->nextElement;
					iteratorObj->nextElement->previousElement = iteratorObj->previousElement;
					this->containerSize --;
					break;	
			}
		}

		return this->containerSize;

	}





	template <class T> GTUSet<T> GTUSet<T>::intersect( const GTUSet<T>& GTUSetObj )
	{
		GTUSet<T> tempSet,intersectionSet;
		tempSet = GTUSetObj;




		for( auto it1 : *(this) )
		{
			for( auto it2 : tempSet )
			{
				if( it1 == it2 )
				{
					intersectionSet.insert(it1);
					break;
				}
			}
		}








		return intersectionSet;
	}








	template <class T> GTUSet<T> GTUSet<T>::unionSet( const GTUSet<T>& GTUSetObj )
	{
		GTUSet<T> unionSet;

		unionSet = GTUSetObj;


		for( auto it : *(this) )
		{
			unionSet.insert( it );
		}



		unionSet.deleteRepetitiveElements();


		return unionSet;
	}





}













#endif
