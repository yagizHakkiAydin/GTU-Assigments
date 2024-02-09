package com.YagizHakkiAydin;

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
		SetBeginPosition( beginPositionOfThePlayGround );

		SetEndPosition( GetBeginPosition() + areaOfThePlayGround );

	}



	/**
	*Constructor
	*@param obj PlayGround object to be copied to create new object
	*/
	PlayGround( PlayGround obj )
	{	
		SetBeginPosition( obj.GetBeginPosition() );

		SetEndPosition( obj.GetBeginPosition() + obj.GetArea() );

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



		if( this.GetArea() != obj.GetArea() )
		{ 
			return false; 
		}
		else if( this.GetBeginPosition() != obj.GetBeginPosition() )
		{ 
			return false; 
		}
		else if( this.GetEndPosition() != obj.GetEndPosition() )
		{ 
			return false; 
		}

		return true;
	}




	@Override
	public PlayGround clone() throws CloneNotSupportedException
	{
		PlayGround obj = new PlayGround();

		obj.SetBeginPosition(this.GetBeginPosition());

		obj.SetEndPosition(this.GetEndPosition());

		return obj;
	}







	@Override
	public int hashCode()
	{
		int result = 7;
		result *= GetBeginPosition();
		result *= GetEndPosition();
		result *=GetArea();

		return result; 
	}




	@Override	
	public String toString()
	{
		String str = new String();

		str += "\nBegin position of the play ground = " + GetBeginPosition();
		str += "\nEnd position of the play ground = " + GetEndPosition();
		str += "\nArea of the play ground = " + GetArea();
		str += "\n";

		return str;
	};




}