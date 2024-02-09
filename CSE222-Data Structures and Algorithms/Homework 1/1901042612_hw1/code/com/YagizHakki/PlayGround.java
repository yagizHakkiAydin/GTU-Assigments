package com.YagizHakki;

import java.io.*;


/**
*Class that represents play grount
*/
public class PlayGround extends Structure
{

	/**
	*Constructor
	*/
	PlayGround()
	{
		this(0,0);
	}


	/**
	*Constructor
	*@param beginPositionOfThePlayGround begin position of the playGround
	*@param areaOfThePlayGround area of the playGround
	*/
	PlayGround( int beginPositionOfThePlayGround , int areaOfThePlayGround)
	{	
		setBeginPosition( beginPositionOfThePlayGround );

		setEndPosition( getBeginPosition() + areaOfThePlayGround );

	}



	/**
	*Constructor
	*@param obj PlayGround object to be copied to create new object
	*/
	PlayGround( PlayGround obj )
	{	
		setBeginPosition( obj.getBeginPosition() );

		setEndPosition( obj.getBeginPosition() + obj.getArea() );

	}





	/**
	*Prints information about the object
	*/
	public final void printInformation(){}



	@Override
	public boolean equals( Object o )
	{

		if( !(o instanceof PlayGround) )
		{
			return false;
		}

		PlayGround obj  = (PlayGround)o;



		if( this.getArea() != obj.getArea() )
		{ 
			return false; 
		}
		else if( this.getBeginPosition() != obj.getBeginPosition() )
		{ 
			return false; 
		}
		else if( this.getEndPosition() != obj.getEndPosition() )
		{ 
			return false; 
		}

		return true;
	}




	@Override
	public PlayGround clone() throws CloneNotSupportedException
	{
		PlayGround obj = new PlayGround();

		obj.setBeginPosition(this.getBeginPosition());

		obj.setEndPosition(this.getEndPosition());

		return obj;
	}







	@Override
	public int hashCode()
	{
		int result = 7;
		result *= getBeginPosition();
		result *= getEndPosition();
		result *=getArea();

		return result; 
	}




	@Override	
	public String toString()
	{
		String str = new String();

		str += "\nBegin position of the play ground = " + getBeginPosition();
		str += "\nEnd position of the play ground = " + getEndPosition();
		str += "\nArea of the play ground = " + getArea();
		str += "\n";

		return str;
	};




}