package com.YagizHakki;

import java.io.*;


/**
*The class that represents a market
*/
public class Market extends Building
{


	/**
	*Constructor
	*/
	Market()
	{
		this(0,0,0);
	}


	/**
	*Copy constructor
	*@param obj used to be copied to new object
	*/
	Market( Market obj )
	{
		setBeginPosition( obj.getBeginPosition() );

		setEndPosition( obj.getBeginPosition() + obj.getArea() );

		setHeight( obj.getHeight() );

		setOwnerName( obj.getOwnerName() );

		setOpeningTime( obj.getOpeningTime() );

		setClosingTime( obj.getClosingTime() );

		setStructureType("Market");
	}


	/**
	*Constructor
	*@param beginPositionOfTheMarket begin position of the new Market
	*@param areaOfTheMarket area of the new Market
	*@param heightOfTheMarket height of the new Market
	*/
	Market( int beginPositionOfTheMarket , int areaOfTheMarket , int heightOfTheMarket )
	{	

		setBeginPosition( beginPositionOfTheMarket );

		setEndPosition( getBeginPosition() + areaOfTheMarket );

		setHeight( heightOfTheMarket );

		setOwnerName("ownerNotInitialized");

		setOpeningTime(0);

		setClosingTime(0);

		setStructureType("Market");
	}


	/**
	*Return opening time of the market
	*@return opening time of the market
	*/
	public final int getOpeningTime()
	{
		return openingTime;
	}


	/**
	*Sets opening time of the market
	*@param timeOfOpening opening time of the market
	*/
	public final void setOpeningTime( int timeOfOpening )
	{
		openingTime = timeOfOpening;
	}

	/**
	*Return closing time of the market
	*@return closing time of the market
	*/
	public final int getClosingTime()
	{
		return closingTime;
	}


	/**
	*Sets Closing time of the market
	*@param timeOfClosing Closing time of the market
	*/
	public final void setClosingTime( int timeOfClosing )
	{
		closingTime = timeOfClosing;
	}


	/**
	*Prints all information about the market
	*/
	@Override
	public final void printInformation()
	{
		System.out.printf("\nBegin position of the market = %d\n",getBeginPosition());
		System.out.printf("End position of the market = %d\n",getEndPosition());
		System.out.printf("Area of the market = %d\n",getArea());
		System.out.printf("Height of the market = %d\n",getHeight());
		System.out.printf("Owner of the market = %s\n",getOwnerName());
		System.out.printf("Opening time of the market = %d\n",getOpeningTime());
		System.out.printf("Closing time of the market = %d\n",getClosingTime());
	};











	@Override
	public Market clone() throws CloneNotSupportedException
	{
		Market obj = new Market();

		obj.setOpeningTime(this.getOpeningTime());

		obj.setClosingTime(this.getClosingTime());

		obj.setHeight(this.getHeight());

		obj.setBeginPosition(this.getBeginPosition());

		obj.setEndPosition(this.getEndPosition());

		obj.setOwnerName(this.getOwnerName());


		return obj;
	}





	@Override
	public boolean equals( Object o )
	{	
		boolean result = true;

		if( !(o instanceof Market) )
		{
			return false;
		}

		Market obj;
		obj = (Market)o;


		if( this.getHeight() != obj.getHeight() )
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
		else if( !this.getOwnerName().equals( obj.getOwnerName()) )
		{ 
			return false; 
		}
		else if( this.getOpeningTime() != obj.getOpeningTime() )
		{ 
			return false; 
		}
		else if( this.getClosingTime() != obj.getClosingTime() )
		{ 
			return false; 
		}
		return true;

	}




	@Override
	public int hashCode()
	{
		int result = 7;
		result *=getHeight();
		result *=getArea();
		result *=getBeginPosition();
		result *=getEndPosition();
		result *=getOwnerName().hashCode();
		result *=getOpeningTime();
		result *=getClosingTime();

		return result; 
	}



	@Override	
	public String toString()
	{
		String str = new String();

		str += "\nBegin position of the market = " + getBeginPosition();
		str += "\nEnd position of the market = " + getEndPosition();
		str += "\nArea of the market = " + getArea();
		str += "\nHeight of the market = " + getHeight();
		str += "\nOwner of the market = " + getOwnerName();
		str += "\nOpening time of the rooms of the market = " + getOpeningTime();
		str += "\nClosing time of the rooms of the market = " + getClosingTime();
		str += "\n";

		return str;
	};








	









	private int openingTime;

	private int closingTime;




}