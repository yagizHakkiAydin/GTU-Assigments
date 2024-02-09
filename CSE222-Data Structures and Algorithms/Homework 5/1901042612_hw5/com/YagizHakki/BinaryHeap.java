package com.YagizHakki;




public class BinaryHeap<E> extends BinaryTree<E>
{

	/**
	*Constructor
	*/
	BinaryHeap()
	{
		root = new HeapNode();
		root.index = 0;
		lastIndex = 1;
	}

	/**
	*Adds item to given index
	*/
	public void addToLeft( E item , int index )
	{
		addToLeft( item , index , root );
	}

	public void increment(int index, E incrementedData ,HeapNode<E> node)
	{
		if( node.upper != null )
		{
			if( this == this.upper.leftTree )
			{
				this.upperNode.addLeft( incrementedData );
			}
			else
			{
				this.upperNode.addRight( incrementedData );
			}
		}
	}

	/**
	*Adds item to given index
	*/
	private void addToLeft(E item,int index,HeapNode<E> node)
	{
		if( node != null )
		{
			if( node.index == index )
			{
				node.addLeft( item  , lastIndex);
				lastIndex++;
			}
			addToLeft( item , index , node.leftTree );
			addToLeft( item , index , node.rightTree );
		}
	}
	/**
	*Adds item to given index
	*/
	public void addToRight( E item , int index )
	{
		addToRight( item , index , root );
	}

	/**
	*Adds item to given index
	*/
	private void addToRight(E item,int index,HeapNode<E> node)
	{
		if( node != null )
		{
			if( node.index == index )
			{
				node.addRight( item  , lastIndex);
				lastIndex++;
			}
			addToRight( item , index , node.leftTree );
			addToRight( item , index , node.rightTree );
		}
	}




	public class HeapNode<E> extends Node<E>
	{
		HeapNode<E> upperNode;
		HeapNode<E> leftTree;
		HeapNode<E> rightTree;

		HeapNode()
		{
			data = null;
			leftTree = null;
			rightTree = null;
			upperNode = null;
			index = -1;

		}

		HeapNode(HeapNode<E> upperNode)
		{
			this();
			this.upperNode = upperNode;
		}
		HeapNode(E dataOfNode)
		{
			this();
			data = dataOfNode;
		}


		public void addLeft(E item , int index)
		{
			HeapNode<E> newNode = new HeapNode<E>( item );
			newNode.upperNode = this;
			if(item instanceof Comparable)
			{
				Comparable<E> temp = (Comparable) item;

				if( temp.compareTo( this.getData() ) <= 0 )
				{
					System.out.printf( "Invalid Element for heap %s --> %s\n" , this.data.toString() , item.toString() );
					return;
				}
				else if( this.upperNode != null && this != this.upperNode.leftTree )
				{
					if( this.upperNode.leftTree != null )
					{
						if( (this.upperNode.leftTree.leftTree == null) )
						{
							System.out.printf( "Invalid Element for heap %s --> %s\n" , this.data.toString() , item.toString() );
							return;
						}
					}
					else
					{
						System.out.printf( "Invalid Element for heap %s --> %s\n" , this.data.toString() , item.toString() );
						return;
					}
				}
			}
			else
			{
				System.out.printf( "Invalid Element for heap %s --> %s\n" , this.data.toString() , item.toString() );
				return;
			}
			System.out.printf( "succes %s --> %s\n" , this.data.toString() , item.toString() );
			newNode.index = index;
			leftTree = newNode;
		}


		public void addRight(E item , int index)
		{
			HeapNode<E> newNode = new HeapNode<E>( item );
			newNode.upperNode = this;
			if(item instanceof Comparable)
			{
				Comparable<E> temp = (Comparable) item;

				if( temp.compareTo( this.getData() ) <= 0 )
				{
					System.out.printf( "Invalid Element for heap %s --> %s\n" , this.data.toString() , item.toString() );
					return;
				}
				else if( this.leftTree == null )
				{
					System.out.printf( "Invalid Element for heap %s --> %s\n" , this.data.toString() , item.toString() );
					return;
				}
				else if( this.upperNode != null )
				{
					if( this.upperNode.leftTree != null )
					{
						if( (this.upperNode.leftTree.leftTree == null) )
						{
							System.out.printf( "Invalid Element for heap %s --> %s\n" , this.data.toString() , item.toString() );
							return;
						}
					}
					else
					{
						System.out.printf( "Invalid Element for heap %s --> %s\n" , this.data.toString() , item.toString() );
						return;
					}
				}
			}
			else
			{
				System.out.printf( "Invalid Element for heap %s --> %s\n" , this.data.toString() , item.toString() );
				return;
			}
			System.out.printf( "succes %s --> %s\n" , this.data.toString() , item.toString() );
			newNode.index = index;
			rightTree = newNode;

		}
	}

	int lastIndex;
	HeapNode<E> root;


}