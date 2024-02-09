package com.YagizHakki;

import java.util.*;


public class BinaryTree<E>
{


	public BinaryTree()
	{
		root = new Node<E>();
		root.index = 0;
	}


	protected BinaryTree(Node<E> root)
	{
		this.root = root;
	}


	public BinaryTree( E data , BinaryTree<E> leftTree , BinaryTree<E> rightTree )
	{
		root = new Node<E>();
		root.index = 0;
		root.data = data;
		root.leftTree = leftTree.root;
		root.rightTree = rightTree.root;
	}

	public BinaryTree<E> getLeftSubTree()
	{
		return new BinaryTree<E>( root.leftTree );
	}

	public BinaryTree<E> getRightSubTree()
	{
		return new BinaryTree<E>( root.leftTree );
	}


	public E getData()
	{
		return root.data;
	}

	public boolean isleaf()
	{
		return (root.leftTree==null) && (root.rightTree==null);
	} 


	public String toString()
	{
		return new String();
	}

	private void preOrderTraverse( Node<E> node , int depth , StringBuilder sb )
	{
		if (node != null) {
          sb = sb.append( node.toString() );
          depth++;
          preOrderTraverse( node.leftTree , depth , sb );
          preOrderTraverse( node.rightTree , depth , sb );
       } 
	}



	public Node<E> root;

	public class Node<E>
	{
		int index;
		E data;
		Node <E> upperNode;
		Node<E> leftTree;
		Node<E> rightTree;

		Node()
		{
			index = -1;
			data = null;
			leftTree = null;
			rightTree = null;
			upperNode = null;
		}
		Node(Node<E> upperNode)
		{
			this();
			this.upperNode = upperNode;
		}
		Node(E dataOfNode)
		{
			this();
			data = dataOfNode;
		}

		public void setData(E data)
		{
			this.data = data;
		}
		public E getData()
		{
			return this.data;
		}
		public String toString()
		{
			return data.toString();
		}

		public void addLeft(E item)
		{
			Node<E> newNode = new Node<E>( item );
			newNode.upperNode = this;
			leftTree = newNode;
		}
		public void addRight(E item)
		{
			Node<E> newNode = new Node<E>( item );
			newNode.upperNode = this;
			rightTree = newNode;
		}
	}


}