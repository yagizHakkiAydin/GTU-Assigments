package com.YagizHakki;

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
		setBeginPosition( obj.getBeginPosition() );

		setEndPosition( obj.getBeginPosition() + obj.getArea() );

		setHeight( obj.getHeight() );

		setOwnerName( obj.getOwnerName() );

		setColor( obj.getColor() );

		setNumberOfRooms( obj.getNumberOfRooms() );

		setStructureType("House");
	}


	/**
	*Constructor
	*@param beginPositionOfTheHouse begin position of the new House
	*@param areaOfTheHouse area of the new House
	*@param heightOfTheHouse height of the new House
	*/
	House( int beginPositionOfTheHouse , int areaOfTheHouse , int heightOfTheHouse )
	{	

		setBeginPosition( beginPositionOfTheHouse );

		setEndPosition( getBeginPosition() + areaOfTheHouse );

		setHeight( heightOfTheHouse );

		setOwnerName("ownerNotInitialized");

		setColor("colorNotInitialized");

		setNumberOfRooms(0);

		setStructureType("House");

	}



	/**
	*Returns number of the rooms of the house
	*@return number of the rooms of the house
	*/
	public final int getNumberOfRooms()
	{
		return numberOfRooms;
	}


	/**
	*Sets number of the rooms of the house
	*@param numOfRooms number of the rooms of the house
	*/
	public final void setNumberOfRooms( int numOfRooms )
	{
		numberOfRooms = numOfRooms;
	}


	/**
	*Returns color of the rooms of the house
	*@return color of the rooms of the house
	*/
	public final String getColor()
	{ 
		String copyOfColor = new String(color);

		return copyOfColor; 
	}


	/**
	*Sets color of the rooms of the house
	*@param newColor color of the rooms of the house
	*/
	public final void setColor( String newColor )
	{
		color =  new String(newColor);
	}



	@Override
	public final void printInformation()
	{
		System.out.printf("\nBegin position of the house = %d\n",getBeginPosition());
		System.out.printf("End position of the house = %d\n",getEndPosition());
		System.out.printf("Area of the house = %d\n",getArea());
		System.out.printf("Height of the house = %d\n",getHeight());
		System.out.printf("Owner of the house = %s\n",getOwnerName());
		System.out.printf("Number of the rooms of the house = %d\n",getNumberOfRooms());
		System.out.printf("Color of the house = %s\n",getColor());
	};



	@Override
	public House clone() throws CloneNotSupportedException
	{
		House obj = new House();

		obj.setColor(this.getColor());

		obj.setHeight(this.getHeight());

		obj.setBeginPosition(this.getBeginPosition());

		obj.setEndPosition(this.getEndPosition());

		obj.setOwnerName(this.getOwnerName());

		obj.setNumberOfRooms(this.getNumberOfRooms());

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
		

		if( !this.getColor().equals( obj.getColor()) )
		{
			return false; 
		}
		else if( this.getHeight() != obj.getHeight() )
		{ 
			return false; 
		}
		else if( this.getArea() != obj.getArea() )
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
		else if( !this.getOwnerName().equals(obj.getOwnerName()) )
		{ 
			return false; 
		}
		else if( this.getNumberOfRooms() != obj.getNumberOfRooms() )
		{ 
			return false; 
		}
		return result;

	}

	@Override
	public int hashCode()
	{
		int result = 7;
		result *= getColor().hashCode();
		result *=getHeight();
		result *=getArea();
		result *=getBeginPosition();
		result *=getEndPosition();
		result *=getOwnerName().hashCode();
		result *=getNumberOfRooms();

		return result; 
	}

	@Override	
	public String toString()
	{
		String str = new String();

		str += "\nBegin position of the house = " + getBeginPosition();
		str += "\nEnd position of the house = " + getEndPosition();
		str += "\nArea of the house = " + getArea();
		str += "\nHeight of the house = " + getHeight();
		str += "\nOwner of the house = " + getOwnerName();
		str += "\nNumber of the rooms of the house = " + getNumberOfRooms();
		str += "\nColor of the house = " + getColor();
		str += "\n";

		return str;
	};






	private int numberOfRooms;

	private String color;



}