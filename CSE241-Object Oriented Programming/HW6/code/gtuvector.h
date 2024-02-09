#ifndef GTUVECTOR_H
#define GTUVECTOR_H


#include "iterable.h"


namespace cse241hw6
{


	template <class T>
	class GTUVector : public Iterable<T>
	{
		public:


			GTUVector<T>();

			GTUVector( const GTUVector& GTUVectorObj );  //Copy constructor
			GTUVector<T>& operator=( const GTUVector<T>& GTUVectorObj );   //Copy assigment operator
			
			GTUVector( GTUVector&& GTUVectorObj );	  //Move constructor
			GTUVector& operator=( GTUVector&& GTUVectorObj ); //Move assigment operator


			GTUVector( size_t size, T obj );   //creates a linked list with (given size + 1)(last element is end,doesn't count)

			~GTUVector();




			bool empty() const override{ return (size()==0); }
			size_t size() const override{ return this->containerSize; }
			void clear() override{	this->containerSize = 0;  this->element = std::make_shared<containerElement<T>>(); }


			typedef typename Iterable<T>::GTUIterator iterator;
			typedef typename Iterable<T>::GTUIteratorConst const_iterator;


			void erase( iterator iteratorObj ) override{ erase(*iteratorObj); }
			size_t erase ( const T& obj );



			iterator begin() override;
			iterator end() override;
			const const_iterator cbegin() const override;
			const const_iterator cend() const override;


			T& operator[](int index);
			T& operator[](int index) const;
			void push_back( T obj );
			void pop_back();

			void getTest();

		private:

			
	};









	template <class T> size_t GTUVector<T>::erase( const T& obj )  //Find corresponding element of the doubly-list and connects previous and next elements
	{
		GTUVector<T>::iterator iteratorObj;



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










	template <class T> GTUVector<T>::GTUVector()  
	{
		this->containerSize = 0;
		this->element = std::make_shared<containerElement<T>>();
	}







	template <class T> GTUVector<T>::GTUVector( const GTUVector<T>& GTUVectorObj )
	{

		*(this) = GTUVectorObj;

	}







	template <class T> GTUVector<T>& GTUVector<T>::operator=( const GTUVector<T>& GTUVectorObj )  //creates doubly linked list and gets correct element from GTUVectorObj at every step
	{


		std::shared_ptr<containerElement<T>> head = std::make_shared<containerElement<T>>();
		std::shared_ptr<containerElement<T>> tempPtr = head;
		tempPtr->data = GTUVectorObj[0];

		this->containerSize = GTUVectorObj.size();



		for( int i=0 ; i<GTUVectorObj.size() ; i++ )
		{
			std::shared_ptr<containerElement<T>> tempElement(new containerElement<T>());  //Next element of the list is created.

			tempElement->previousElement = tempPtr;

			tempPtr->nextElement = tempElement;

			tempPtr = tempElement;

			tempPtr->data = GTUVectorObj[i+1];
		}

		this->element = head;


		return *this;
	}





			
	template <class T> GTUVector<T>::GTUVector( GTUVector<T>&& GTUVectorObj )
	{
		this->element = GTUVectorObj.element;
		this->containerSize = GTUVectorObj.size();

	}




	template <class T> GTUVector<T>& GTUVector<T>::operator=( GTUVector&& GTUVectorObj )
	{
		this->element = GTUVectorObj.element;
		this->containerSize = GTUVectorObj.size();
		return *this;
	}
		




	template <class T> GTUVector<T>::~GTUVector()
	{
		this->element = nullptr;
		this->containerSize = -1;
	}








	template <class T> GTUVector<T>::GTUVector( size_t size, T obj )   //Creates doubly linked list and fills it with given value
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










	template <class T> void GTUVector<T>::push_back( T obj )   //creates a new element and adds it to list,not to end because last element doesn't count
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


	}










	template <class T> typename GTUVector<T>::iterator GTUVector<T>::begin()    //goes back on list until it finds first element
	{

		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an begin";
			exit(1);
		}




		GTUVector<T>::iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->previousElement != nullptr )
		{
			tempPtr = tempPtr->previousElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;


	}










	template <class T> typename GTUVector<T>::iterator GTUVector<T>::end()    //goes right on list until it finds last element
	{
		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an end";
			exit(1);
		}



		GTUVector<T>::iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->nextElement != nullptr )
		{
			tempPtr = tempPtr->nextElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;
	}







	template <class T> const typename GTUVector<T>::const_iterator GTUVector<T>::cend() const  //uses same logic with end()
	{

		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an end";
			exit(1);
		}



		GTUVector<T>::const_iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->nextElement != nullptr )
		{
			tempPtr = tempPtr->nextElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;
	}








	template <class T> const typename GTUVector<T>::const_iterator GTUVector<T>::cbegin() const   //uses same logic with begin()
	{

		if( this->containerSize == 0 )
		{
			std::cerr << "Container size 0,doesn't have an begin";
			exit(1);
		}


		GTUVector<T>::const_iterator iteratorObj;


		std::shared_ptr<containerElement<T>> tempPtr = this->element;

		

		while( tempPtr->previousElement != nullptr )
		{
			tempPtr = tempPtr->previousElement;
		}

		iteratorObj.setIteratorPointer( tempPtr );




		return iteratorObj;

	}











	template <class T> T& GTUVector<T>::operator[](int index)  //Finds corresponding iterator and returns referance of wanted element
	{

		GTUVector<T>::iterator iteratorObj = this->begin();

		for( int i=0 ; i<index ; i++ )
		{
			iteratorObj++;
		}

		return iteratorObj->data;

	}





	template <class T> T& GTUVector<T>::operator[](int index) const  //Finds corresponding iterator and returns referance of wanted element
	{

		GTUVector<T>::const_iterator iteratorObj = this->cbegin();

		for( int i=0 ; i<index ; i++ )
		{
			iteratorObj++;
		}

		return iteratorObj->data;

	}





	template <class T> void GTUVector<T>::pop_back()  //erases the element which is nearest to the last,because last one doesn't count
	{
		GTUVector<T>::iterator iteratorObj = this->end();
		iteratorObj--;
		this->erase( iteratorObj );
	}









}






#endif
