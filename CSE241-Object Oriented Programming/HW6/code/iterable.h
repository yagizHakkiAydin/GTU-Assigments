#ifndef ITERABLE_H
#define ITERABLE_H


#include <iostream>
#include <memory>







namespace cse241hw6
{

	template <class T> 
	struct containerElement  //Doubly linked list that contains elements of the container
	{
		std::shared_ptr<containerElement> previousElement = nullptr;
		std::shared_ptr<containerElement> nextElement = nullptr;
		T data;
	};





	
	template <class T> class Iterable
	{
		public:




			class GTUIterator : public std::iterator<std::random_access_iterator_tag,T>
			{
				public:
					GTUIterator(){ ptr = nullptr; }
					T& operator*(){ return (ptr->data); }
					GTUIterator& operator=( const GTUIterator obj ){ ptr = obj.getIteratorPointer(); return *(this);}
					GTUIterator& operator++(int){ ptr = ptr->nextElement; return *(this);}
					GTUIterator& operator--(int){ ptr = ptr->previousElement; return *(this);}
					GTUIterator& operator++(){ ptr = ptr->nextElement; return *(this);}
					GTUIterator& operator--(){ ptr = ptr->previousElement; return *(this);}
					T operator-(const GTUIterator& n) {return (this->ptr->data - n.ptr->data);}
			        GTUIterator operator+(T d) {return *(this);}
			        GTUIterator operator-(T d) { return *(this);}
			        GTUIterator& operator+=(T d) {ptr->data += d; return *this;}
        			GTUIterator& operator-=(T d) {ptr->data -= d; return *this;}
					std::shared_ptr< containerElement<T> > operator->() const{ return ptr; }
					bool operator!=( const GTUIterator &obj ){ return ( (this->ptr) != obj.ptr ); }
					bool operator==( const GTUIterator &obj ){ return ( (this->ptr) == obj.ptr ); }
					//bool operator>=( const GTUIterator obj ){ return ( (this->ptr->data) >= obj.ptr->data ); }
					//bool operator<=( const GTUIterator obj ){ return ( (this->ptr->data) <= obj.ptr->data ); }
					//bool operator>( const GTUIterator &obj ){ return ( (this->ptr) > obj.ptr); }
					//bool operator<( const GTUIterator &obj ){ return ( (this->ptr) < obj.ptr); }
					friend inline bool operator>( const GTUIterator &obj,const GTUIterator &obj2 ){ return false; }
					friend inline bool operator<( const GTUIterator &obj,const GTUIterator &obj2 ){ return true; }

					void setIteratorPointer( std::shared_ptr< containerElement<T> > iteratorPointer ){ ptr = iteratorPointer; }
					std::shared_ptr< containerElement<T> > getIteratorPointer() const{ return ptr; }
				private:
					std::shared_ptr< containerElement<T> > ptr;
			};





			class GTUIteratorConst : public std::iterator<std::random_access_iterator_tag,const T>
			{
				public:
					GTUIteratorConst(){ ptr = nullptr; }
					const T& operator*(){ return (ptr->data); }
					GTUIteratorConst& operator=( const GTUIteratorConst obj ){ ptr = obj.getIteratorPointer(); return *(this);}
					const GTUIteratorConst& operator++(int){ ptr = ptr->nextElement; return *(this);}
					const GTUIteratorConst& operator--(int){ ptr = ptr->previousElement; return *(this);}
					const GTUIteratorConst& operator++(){ ptr = ptr->nextElement; return *(this);}
					const GTUIteratorConst& operator--(){ ptr = ptr->previousElement; return *(this);}
					T operator-(const GTUIterator& n) {return (this->ptr->data - n.ptr->data);}
			        const GTUIterator operator+(T d) {return *(this);}
			        const GTUIterator operator-(T d) { return *(this);}
			        const GTUIterator& operator+=(T d) {ptr->data += d; return *this;}
        			const GTUIterator& operator-=(T d) {ptr->data -= d; return *this;}
					std::shared_ptr< containerElement<T> > operator->() const{ return ptr; }
					bool operator!=( const GTUIterator obj ){ return ( (this->ptr) != obj.ptr ); }
					bool operator==( const GTUIterator obj ){ return ( (this->ptr) == obj.ptr ); }
					bool operator>( const GTUIterator obj ){ return ( (this->ptr) > obj.ptr ); }
					bool operator<( const GTUIterator obj ){ return ( (this->ptr) < obj.ptr ); }
					void setIteratorPointer( std::shared_ptr< containerElement<T> > iteratorPointer ){ ptr = iteratorPointer; }
					std::shared_ptr< containerElement<T> > getIteratorPointer() const{ return ptr; }
				private:
					std::shared_ptr< containerElement<T> > ptr;

			};






			Iterable(){/*Intentionally Empty*/};  //Default constructor

			Iterable( const Iterable& iterableObj ){/*Intentionally Empty*/};  //Copy constructor
			Iterable& operator=( const Iterable& iterableObj ){/*Intentionally Empty*/};   //Copy assigment operator
			
			Iterable( Iterable&& iterableObj ){/*Intentionally Empty*/};	  //Move constructor
			Iterable& operator=( Iterable&& iterableObj ){/*Intentionally Empty*/}; //Move assigment operator
			

			~Iterable(){/*Intentionally Empty*/};


			virtual bool empty() const = 0;
			virtual size_t size() const = 0;
			virtual void clear() = 0;

			virtual void erase( GTUIterator iteratorObj ) = 0;
			virtual GTUIterator begin() = 0;
			virtual GTUIterator end() = 0;
			virtual const GTUIteratorConst cbegin() const = 0;
			virtual const GTUIteratorConst cend() const = 0;




		protected:
			std::shared_ptr< containerElement<T> > element;
			size_t containerSize;
	};





}








#endif