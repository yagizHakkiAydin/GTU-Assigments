package com.YagizHakkiAydin;

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
		SetBeginPosition( beginPositionOfStructure );
		SetEndPosition(beginPositionOfStructure + areaOfStructure);
	}


	

	/**
	*Returns begin position of the structure
	*@return begin position of the structure
	*/
	public final int GetBeginPosition()
	{
		return beginPosition; 
	}


	/**
	*Returns end position of the structure
	*@return end position of the structure
	*/
	public final int GetEndPosition()
	{ 
		return endPosition; 
	}

	/**
	*Returns area of the structure
	*@return area of the structure
	*/
	public final int GetArea()
	{ 
		return area; 
	}


	/**
	*Returns Sets area with begin and end positions of the structure,called automatically within necessary functions
	*/
	private final void SetArea()
	{
		area = Math.abs(GetEndPosition() - GetBeginPosition() );
	}




	/**
	*Sets begin position for the structure
	*@param beginPositionOfStructure value of begin position for the structure
	*/
	public final void SetBeginPosition( int beginPositionOfStructure )
	{
		beginPosition = beginPositionOfStructure;
		SetArea();
	}

	/**
	*Sets end position for the structure
	*@param endPositionOfStructure value of end position for the structure
	*/
	public final void SetEndPosition( int endPositionOfStructure )
	{
		endPosition = endPositionOfStructure;
		SetArea();
	}





	/**
	*If begin position is greater than end position,this function fixes that
	*/
	public final void FixBeginAndEndPositions()
	{
		if( GetBeginPosition() > GetEndPosition() )
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
	public void PrintInformation()
	{
		System.out.printf("\nBegin position of the structure = %d\n",GetBeginPosition());
		System.out.printf("\nEnd position of the structure = %d\n",GetEndPosition());
		System.out.printf("\nArea of the structure = %d\n",GetArea());
		
	};






	/**
	*Begin position of the structure
	*/
	protected int beginPosition ;

	/**
	*End position of the structure
	*/
	protected int endPosition;

	/**
	*Area of the structure
	*/
	protected int area;




}