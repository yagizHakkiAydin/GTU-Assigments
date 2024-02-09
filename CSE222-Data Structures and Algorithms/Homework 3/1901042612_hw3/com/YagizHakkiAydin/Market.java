package com.YagizHakkiAydin;

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
		SetBeginPosition( obj.GetBeginPosition() );

		SetEndPosition( obj.GetBeginPosition() + obj.GetArea() );

		SetHeight( obj.GetHeight() );

		SetOwnerName( obj.GetOwnerName() );

		SetOpeningTime( obj.GetOpeningTime() );

		SetClosingTime( obj.GetClosingTime() );

	}


	/**
	*Constructor
	*@param beginPositionOfTheMarket begin position of the new Market
	*@param areaOfTheMarket area of the new Market
	*@param heightOfTheMarket height of the new Market
	*/
	Market( int beginPositionOfTheMarket , int areaOfTheMarket , int heightOfTheMarket )
	{	

		SetBeginPosition( beginPositionOfTheMarket );

		SetEndPosition( GetBeginPosition() + areaOfTheMarket );

		SetHeight( heightOfTheMarket );

		SetOwnerName("ownerNotInitialized");

		SetOpeningTime(0);

		SetClosingTime(0);

	}


	/**
	*Return opening time of the market
	*@return opening time of the market
	*/
	public final int GetOpeningTime()
	{
		return openingTime;
	}


	/**
	*Sets opening time of the market
	*@param timeOfOpening opening time of the market
	*/
	public final void SetOpeningTime( int timeOfOpening )
	{
		openingTime = timeOfOpening;
	}

	/**
	*Return closing time of the market
	*@return closing time of the market
	*/
	public final int GetClosingTime()
	{
		return closingTime;
	}


	/**
	*Sets Closing time of the market
	*@param timeOfClosing Closing time of the market
	*/
	public final void SetClosingTime( int timeOfClosing )
	{
		closingTime = timeOfClosing;
	}


	/**
	*Prints all information about the market
	*/
	@Override
	public final void PrintInformation()
	{
		System.out.printf("\nBegin position of the market = %d\n",GetBeginPosition());
		System.out.printf("End position of the market = %d\n",GetEndPosition());
		System.out.printf("Area of the market = %d\n",GetArea());
		System.out.printf("Height of the market = %d\n",GetHeight());
		System.out.printf("Owner of the market = %s\n",GetOwnerName());
		System.out.printf("Opening time of the market = %d\n",GetOpeningTime());
		System.out.printf("Closing time of the market = %d\n",GetClosingTime());
	};











	@Override
	public Market clone() throws CloneNotSupportedException
	{
		Market obj = new Market();

		obj.SetOpeningTime(this.GetOpeningTime());

		obj.SetClosingTime(this.GetClosingTime());

		obj.SetHeight(this.GetHeight());

		obj.SetBeginPosition(this.GetBeginPosition());

		obj.SetEndPosition(this.GetEndPosition());

		obj.SetOwnerName(this.GetOwnerName());


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


		if( this.GetHeight() != obj.GetHeight() )
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
		else if( !this.GetOwnerName().equals( obj.GetOwnerName()) )
		{ 
			return false; 
		}
		else if( this.GetOpeningTime() != obj.GetOpeningTime() )
		{ 
			return false; 
		}
		else if( this.GetClosingTime() != obj.GetClosingTime() )
		{ 
			return false; 
		}
		return true;

	}




	@Override
	public int hashCode()
	{
		int result = 7;
		result *=GetHeight();
		result *=GetArea();
		result *=GetBeginPosition();
		result *=GetEndPosition();
		result *=GetOwnerName().hashCode();
		result *=GetOpeningTime();
		result *=GetClosingTime();

		return result; 
	}



	@Override	
	public String toString()
	{
		String str = new String();

		str += "\nBegin position of the market = " + GetBeginPosition();
		str += "\nEnd position of the market = " + GetEndPosition();
		str += "\nArea of the market = " + GetArea();
		str += "\nHeight of the market = " + GetHeight();
		str += "\nOwner of the market = " + GetOwnerName();
		str += "\nOpening time of the rooms of the market = " + GetOpeningTime();
		str += "\nClosing time of the rooms of the market = " + GetClosingTime();
		str += "\n";

		return str;
	};







	private int openingTime;

	private int closingTime;




}