#ifndef GTUARRAY_H
#define GTUARRAY_H




#include "iterable.h"


namespace cse241hw6
{




	template < class T ,size_t S >
	class GTUArray : public Iterable<T>
	{
		public:


			GTUArray<T,S>();  //Default constructor,takes 2 template parameter

			GTUArray( const GTUArray& GTUArrayObj );  //Copy constructor
			GTUArray<T,S>& operator=( const GTUArray<T,S>& GTUArrayObj );   //Copy assigment operator
			
			GTUArray( GTUArray&& GTUArrayObj );	  //Move constructor
			GTUArray& operator=( GTUArray&& GTUArrayObj ); //Move assigment operator


			GTUArray( size_t size, T obj );   //creates a linked list with (given size + 1)(last element is end,doesn't count)

			~GTUArray() = default;



			bool empty() const override{ return (size()==0); }
			size_t size() const override{ return this->containerSize; }
			void clear() override{};
 

			typedef typename Iterable<T>::GTUIterator iterator;
			typedef typename Iterable<T>::GTUIteratorConst const_iterator;


			void erase( iterator iteratorObj ) override{/*Intentionally empty*/};



			iterator begin() override;
			iterator end() override;
			const const_iterator cbegin() const override;
			const const_iterator cend() const override;


			T& operator[](int index);
			T& operator[](int index) const;


			iterator insert( T obj );

			void fill( const T& obj );




			
	};











	template <class T,size_t S> GTUArray<T,S>::GTUArray()
	{
		
		std::shared_ptr<containerElement<T>> head = std::make_shared<containerElement<T>>();
		std::shared_ptr<containerElement<T>> tempPtr = head;


		this->containerSize = S;


		for( int i=0 ; i<S ; i++ )
		{
			std::shared_ptr<containerElement<T>> tempElement(new containerElement<T>());  //Next element of the list is created.

			tempElement->previousElement = tempPtr;

			tempPtr->nextElement = tempElement;

			tempPtr = tempElement;

		}

		this->element = head;
	}











	template <class T,size_t S> GTUArray<T,S>::GTUArray( const GTUArray& GTUArrayObj )
	{

		*(this) = GTUArrayObj;

	}











	template <class T,size_t S> GTUArray<T,S>& GTUArray<T,S>::operator=( const GTUArray<T,S>& GTUArrayObj )  //creates doubly linked list and fills it from objects of given object at the same time
	{

		if( this->size() != GTUArrayObj.size() )
		{
			std::cerr << "An array with different size can't be copied to another array";
			exit(1);
		}


		std::shared_ptr<containerElement<T>> head = std::make_shared<containerElement<T>>();
		std::shared_ptr<containerElement<T>> tempPtr = head;
		tempPtr->data = GTUArrayObj[0];

		this->containerSize = GTUArrayObj.size();



		for( int i=0 ; i<GTUArrayObj.size() ; i++ )
		{
			std::shared_ptr<containerElement<T>> tempElement(new containerElement<T>());  //Next element of the list is created.

			tempElement->previousElement = tempPtr;

			tempPtr->nextElement = tempElement;

			tempPtr = tempElement;

			tempPtr->data = GTUArrayObj[i+1];
		}

		this->element = head;


		return *this;
	}









			
	template <class T,size_t S> GTUArray<T,S>::GTUArray( GTUArray&& GTUArrayObj )
	{
		this->element = GTUArrayObj.element;
		this->containerSize = GTUArrayObj.size();
	}









	template <class T,size_t S> GTUArray<T,S>& GTUArray<T,S>::operator=( GTUArray&& GTUArrayObj )
	{
		this->element = GTUArrayObj.element;
		this->containerSize = GTUArrayObj.size();
		return *this;
	}









	template <class T,size_t S> GTUArray<T,S>::GTUArray( size_t size, T obj )
	{

		std::shared_ptr<containerElement<T>> head = std::make_shared<containerElement<T>>();
		std::shared_ptr<containerElement<T>> tempPtr = head;

		head->data = obj;

		this->containerSize = size;


		for( int i=0 ; i<size ; i++ )
		{
			std::shared_ptr<containerElement<T>> tempElement(new containerElement<T>());  //Next element of the list is created.

			tempElement->previousElement = tempPtr;

			tempPtr->nextElement = tempElement;

			tempPtr = tempElement;

			tempPtr->data = obj;
		}

		this->element = head;

	}
















	template <class T,size_t S> typename GTUArray<T,S>::iterator GTUArray<T,S>::end()
	{
		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an end";
			exit(1);
		}



		GTUArray<T,S>::iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->nextElement != nullptr )
		{
			tempPtr = tempPtr->nextElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;
	}







	template <class T,size_t S> const typename GTUArray<T,S>::const_iterator GTUArray<T,S>::cend() const
	{

		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an end";
			exit(1);
		}



		GTUArray<T,S>::const_iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->nextElement != nullptr )
		{
			tempPtr = tempPtr->nextElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;
	}










	template <class T,size_t S> typename GTUArray<T,S>::iterator GTUArray<T,S>::begin()
	{

		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an begin";
			exit(1);
		}




		GTUArray<T,S>::iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->previousElement != nullptr )
		{
			tempPtr = tempPtr->previousElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;


	}








	template <class T,size_t S> const typename GTUArray<T,S>::const_iterator GTUArray<T,S>::cbegin() const
	{

		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an begin";
			exit(1);
		}


		GTUArray<T,S>::const_iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->previousElement != nullptr )
		{
			tempPtr = tempPtr->previousElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;

	}
















	template <class T,size_t S> void GTUArray<T,S>::fill( const T& obj )
	{
		iterator iteratorObj = this->begin();


		for( iteratorObj=(this->begin()) ; iteratorObj!=(this->end()) ; iteratorObj++ )
		{
			iteratorObj->data = obj;
		}

	}






	template <class T,size_t S> T& GTUArray<T,S>::operator[](int index)
	{

		GTUArray<T,S>::iterator iteratorObj = this->begin();

		for( int i=0 ; i<index ; i++ )
		{
			iteratorObj++;
		}

		return iteratorObj->data;

	}





	template <class T,size_t S> T& GTUArray<T,S>::operator[](int index) const
	{

		GTUArray<T,S>::const_iterator iteratorObj = this->cbegin();

		for( int i=0 ; i<index ; i++ )
		{
			iteratorObj++;
		}

		return iteratorObj->data;

	}










}



















#endif
