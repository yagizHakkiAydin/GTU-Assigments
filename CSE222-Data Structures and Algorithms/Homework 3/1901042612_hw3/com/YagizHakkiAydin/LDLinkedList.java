package com.YagizHakkiAydin;
import java.util.List;
import java.util.AbstractList;
import java.util.Iterator;


public class LDLinkedList<T> extends AbstractList<T> implements List<T>
{

	/**
	*Constructor
	*/
	LDLinkedList()
	{
		head = new Node();
		size = 0;
		keeperListHead = new Node();
		keeperListSize = 0;
	}

	/**
	*Constructor
	*@param listHead head of another linked list
	*/
	LDLinkedList( Node listHead )
	{
		head = listHead;
		size = size();
	}




	/**
	*Adds object to the linked list
	*@param obj object to be added
	*@return always true
	*/
	@Override
	public boolean add( T obj )
	{
		if(size>1)
		add( (size-1) , obj );
		else
			add( (size) , obj );
		return true;
	}




	/**
	*Adds object to given index
	*@throws IndexOutOfBoundsException index out of bounds exception
	@param index index for new object
	@param obj new object
	*/
	@Override
	public void add( int index , T obj ) throws IndexOutOfBoundsException
	{
		if( (index<0) || (index>size) )
		{
			throw new IndexOutOfBoundsException("Element cannot be added at given index...");
		}


		Node temp = keeperListHead;
		Node newNode = null;
		boolean addNewNode = true;

		while( temp.next != null )
		{
			temp = temp.next;
			if( temp.data.equals( obj ) )
			{
				newNode = temp;
				addNewNode = false;
				break;
			}
		}


		if( addNewNode )
		{
			newNode = new Node(obj);
		}


		temp = head;

		for( int i=0 ; i<index ; i++ )
		{
			temp = temp.next;
		}

		newNode.next = temp.next;
		temp.next = newNode;

		size++;


	}


	/**
	*Removes object at given index
	*@param index index of the object to be removed
	*@return deleted object
	*/
	@Override
	public T remove( int index ) throws IndexOutOfBoundsException
	{
		if( (index<0) || (index>size) )
		{
			throw new IndexOutOfBoundsException("Element cannot be added at given index...");
		}

		Node tempNode = head;
		Node tempKeeperNode = keeperListHead;


		for( int i=0 ; i<index ; i++ )
		{
			tempNode = tempNode.next;
		}

		while( tempKeeperNode.next != null )
		{
			tempKeeperNode = tempKeeperNode.next;
		}

		tempKeeperNode.next = tempNode.next;

		tempKeeperNode.next.next = null;

		tempNode.next = tempNode.next.next;

		size--;


		return tempKeeperNode.next.data;

	}





	/**
	*Clears the list
	*/
	@Override
	public void clear()
	{
		head = new Node();
		size = 0;
	}





	/**
	*Checks equality of the linked lists,not implemented because not necessary for the program now
	*/
	@Override
	public boolean equals( Object obj )
	{
		return true;
	}



	/**
	*Returns elenent at given index
	*@return elenent at given index
	*@throws IndexOutOfBoundsException exception
	*/
	@Override
	public T get(int index) throws IndexOutOfBoundsException
	{	if( (index<0) || (index>size) )
		{
			throw new IndexOutOfBoundsException("Index out of bounds --> %d");
		}
		Node temp = new Node();
		temp = head;
		for( int i=0 ; i<=index ; i++ )
		{
			temp = temp.next;
		}

		return temp.data;
	}


	/**
	*returns hashCode,not implemented because function isn't used
	*/
	@Override
	public int hashCode()
	{
		return 1;
	}


	@Override
	public int indexOf( Object obj )
	{
		return 1;
	}




/*
	@Override
	public Itaretor<T> iterator()
	{
		//return new Iterator();
	}
*/


	@Override
	public int size()
	{
		return size;
	}





	public class Node
	{
		Node()
		{
			data = null;
			next = null;
		}
		Node( T nodeData )
		{
			data = nodeData;
			next = null;
		}

		public T data;
		public Node next;
	}


	private Node head;

	/**
	*Keeper list for lazy deletion
	*/
	private Node keeperListHead;



	private int size;
	private int keeperListSize;







}