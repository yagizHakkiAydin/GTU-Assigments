package com.YagizHakkiAydin;

import java.io.*;


/**
*Class that represents a house
*/
public class House extends Building
{
	/**
	*Constructor
	*/
	House()
	{	
		this(0,0,0);

	}


	/**
	*Copy constructor
	*@param obj used to be copied to new object
	*/
	House( House obj )
	{
		SetBeginPosition( obj.GetBeginPosition() );

		SetEndPosition( obj.GetBeginPosition() + obj.GetArea() );

		SetHeight( obj.GetHeight() );

		SetOwnerName( obj.GetOwnerName() );

		SetColor( obj.GetColor() );

		SetNumberOfRooms( obj.GetNumberOfRooms() );

	}


	/**
	*Constructor
	*@param beginPositionOfTheHouse begin position of the new House
	*@param areaOfTheHouse area of the new House
	*@param heightOfTheHouse height of the new House
	*/
	House( int beginPositionOfTheHouse , int areaOfTheHouse , int heightOfTheHouse )
	{	

		SetBeginPosition( beginPositionOfTheHouse );

		SetEndPosition( GetBeginPosition() + areaOfTheHouse );

		SetHeight( heightOfTheHouse );

		SetOwnerName("ownerNotInitialized");

		SetColor("colorNotInitialized");

		SetNumberOfRooms(0);


	}



	/**
	*Returns number of the rooms of the house
	*@return number of the rooms of the house
	*/
	public final int GetNumberOfRooms()
	{
		return numberOfRooms;
	}


	/**
	*Sets number of the rooms of the house
	*@param numOfRooms number of the rooms of the house
	*/
	public final void SetNumberOfRooms( int numOfRooms )
	{
		numberOfRooms = numOfRooms;
	}


	/**
	*Returns color of the rooms of the house
	*@return color of the rooms of the house
	*/
	public final String GetColor()
	{ 
		String copyOfColor = new String(color);

		return copyOfColor; 
	}


	/**
	*Sets color of the rooms of the house
	*@param newColor color of the rooms of the house
	*/
	public final void SetColor( String newColor )
	{
		color =  new String(newColor);
	}



	@Override
	public final void PrintInformation()
	{
		System.out.printf("\nBegin position of the house = %d\n",GetBeginPosition());
		System.out.printf("End position of the house = %d\n",GetEndPosition());
		System.out.printf("Area of the house = %d\n",GetArea());
		System.out.printf("Height of the house = %d\n",GetHeight());
		System.out.printf("Owner of the house = %s\n",GetOwnerName());
		System.out.printf("Number of the rooms of the house = %d\n",GetNumberOfRooms());
		System.out.printf("Color of the house = %s\n",GetColor());
	};



	@Override
	public House clone() throws CloneNotSupportedException
	{
		House obj = new House();

		obj.SetColor(this.GetColor());

		obj.SetHeight(this.GetHeight());

		obj.SetBeginPosition(this.GetBeginPosition());

		obj.SetEndPosition(this.GetEndPosition());

		obj.SetOwnerName(this.GetOwnerName());

		obj.SetNumberOfRooms(this.GetNumberOfRooms());

		return obj;
	}





	@Override
	public boolean equals( Object o )
	{	
		boolean result = true;

		if( !(o instanceof House) )
		{
			return false;
		}

		House obj;
		obj = (House)o;
		

		if( !this.GetColor().equals( obj.GetColor()) )
		{
			return false; 
		}
		else if( this.GetHeight() != obj.GetHeight() )
		{ 
			return false; 
		}
		else if( this.GetArea() != obj.GetArea() )
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
		else if( !this.GetOwnerName().equals(obj.GetOwnerName()) )
		{ 
			return false; 
		}
		else if( this.GetNumberOfRooms() != obj.GetNumberOfRooms() )
		{ 
			return false; 
		}
		return result;

	}

	@Override
	public int hashCode()
	{
		int result = 7;
		result *= GetColor().hashCode();
		result *=GetHeight();
		result *=GetArea();
		result *=GetBeginPosition();
		result *=GetEndPosition();
		result *=GetOwnerName().hashCode();
		result *=GetNumberOfRooms();

		return result; 
	}

	@Override	
	public String toString()
	{
		String str = new String();

		str += "\nBegin position of the house = " + GetBeginPosition();
		str += "\nEnd position of the house = " + GetEndPosition();
		str += "\nArea of the house = " + GetArea();
		str += "\nHeight of the house = " + GetHeight();
		str += "\nOwner of the house = " + GetOwnerName();
		str += "\nNumber of the rooms of the house = " + GetNumberOfRooms();
		str += "\nColor of the house = " + GetColor();
		str += "\n";

		return str;
	};






	private int numberOfRooms;

	private String color;



}