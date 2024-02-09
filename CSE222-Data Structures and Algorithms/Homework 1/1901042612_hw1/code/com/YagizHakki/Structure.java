package com.YagizHakki;

import java.lang.Math;


/**
*Abstract class that is parent for Building class and PlayGround class
*/
abstract public class Structure
{
	
	/**
	*Constructor for the Structure class
	*/
	Structure()
	{
		structureType = "undefinedStructure";
		beginPosition = 0;
		endPosition = 0;
		area = 0;
	}

	/**
	*Constructor for the Structure class
	*@param beginPositionOfStructure begin position for new created structure object
	*@param areaOfStructure area for new created structure object
	*/
	Structure( int beginPositionOfStructure , int areaOfStructure )
	{
		setBeginPosition( beginPositionOfStructure );
		setEndPosition(beginPositionOfStructure + areaOfStructure);
	}


	

	/**
	*Returns begin position of the structure
	*@return begin position of the structure
	*/
	public final int getBeginPosition()
	{
		return beginPosition; 
	}


	/**
	*Returns end position of the structure
	*@return end position of the structure
	*/
	public final int getEndPosition()
	{ 
		return endPosition; 
	}

	/**
	*Returns area of the structure
	*@return area of the structure
	*/
	public final int getArea()
	{ 
		return area; 
	}


	/**
	*Returns sets area with begin and end positions of the structure,called automatically within necessary functions
	*/
	private final void setArea()
	{
		area = Math.abs(getEndPosition() - getBeginPosition() );
	}




	/**
	*Sets begin position for the structure
	*@param beginPositionOfStructure value of begin position for the structure
	*/
	public final void setBeginPosition( int beginPositionOfStructure )
	{
		beginPosition = beginPositionOfStructure;
		setArea();
	}

	/**
	*Sets end position for the structure
	*@param endPositionOfStructure value of end position for the structure
	*/
	public final void setEndPosition( int endPositionOfStructure )
	{
		endPosition = endPositionOfStructure;
		setArea();
	}


	/**
	*Returns structure type
	*@return string of structure type
	*/
	public final String getStructureType()
	{
		return structureType;
	}

	/**
	*Sets structure type,used only creating structure
	*@param type name of the structure's type
	*/
	public final void setStructureType( String type )
	{
		structureType = type;
	}




	/**
	*If begin position is greater than end position,this function fixes that
	*/
	public final void fixBeginAndEndPositions()
	{
		if( getBeginPosition() > getEndPosition() )
		{
			int temp;
			 
			temp = beginPosition;
			beginPosition = endPosition;
			endPosition = temp;
		}
	}



	/**
	*Prints information about structure,overriden in child classes
	*/
	public void printInformation()
	{
		System.out.printf("\nType of the structure = %s\n",getStructureType());
		System.out.printf("\nBegin position of the structure = %d\n",getBeginPosition());
		System.out.printf("\nEnd position of the structure = %d\n",getEndPosition());
		System.out.printf("\nArea of the structure = %d\n",getArea());
		
	};










	private String structureType;

	private int beginPosition ;

	private int endPosition;

	private int area;




}