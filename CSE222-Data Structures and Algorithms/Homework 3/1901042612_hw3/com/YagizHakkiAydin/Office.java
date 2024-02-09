package com.YagizHakkiAydin;

import java.io.*;


/**
*The class that represents a office
*/
public class Office extends Building
{
	/**
	*Constructor
	*/
	Office()
	{	

		this(0,0,0);

	}

	/**
	*Copy constructor
	*@param obj used to be copied to new object
	*/
	Office( Office obj )
	{	

		SetBeginPosition( obj.GetBeginPosition() );

		SetEndPosition( GetBeginPosition() + obj.GetArea() );

		SetHeight( obj.GetHeight() );

		SetOwnerName( obj.GetOwnerName() );

		SetJobType( obj.GetJobType() );

	}

	/**
	*Constructor
	*@param beginPositionOfTheOffice begin position of the new Office
	*@param areaOfTheOffice area of the new Office
	*@param heightOfTheOffice height of the new Office
	*/
	Office( int beginPositionOfTheOffice , int areaOfTheOffice , int heightOfTheOffice )
	{	

		SetBeginPosition( beginPositionOfTheOffice );

		SetEndPosition( GetBeginPosition() + areaOfTheOffice );

		SetHeight( heightOfTheOffice );

		SetOwnerName("ownerNotInitialized");

		SetJobType("jobTypeNotInitialized");

	}



	/**
	*Returns job type of the office
	*@return job type of the office
	*/
	public final String GetJobType()
	{ 
		String copyOfJobYype = new String(jobType);

		return copyOfJobYype; 
	}


	/**
	*Sets job type of the office
	*@param jobTypeOfTheOffice job type of the office
	*/
	public final void SetJobType( String jobTypeOfTheOffice )
	{ 
		jobType = new String(jobTypeOfTheOffice);
	}


	@Override
	public final void PrintInformation()
	{
		System.out.printf("\nBegin position of the office = %d\n",GetBeginPosition());
		System.out.printf("End position of the office = %d\n",GetEndPosition());
		System.out.printf("Area of the office = %d\n",GetArea());
		System.out.printf("Height of the office = %d\n",GetHeight());
		System.out.printf("Owner of the office = %s\n",GetOwnerName());
		System.out.printf("Job type of the office = %s\n",GetJobType());
	};













	@Override
	public Office clone() throws CloneNotSupportedException
	{
		Office obj = new Office();

		obj.SetJobType(this.GetJobType());

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

		if( !(o instanceof Office) )
		{
			return false;
		}

		Office obj;
		obj = (Office)o;


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
		else if( !this.GetJobType().equals( obj.GetJobType()) )
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
		result *=GetJobType().hashCode();

		return result; 
	}



	@Override	
	public String toString()
	{
		String str = new String();

		str += "\nBegin position of the office = " + GetBeginPosition();
		str += "\nEnd position of the office = " + GetEndPosition();
		str += "\nArea of the office = " + GetArea();
		str += "\nHeight of the office = " + GetHeight();
		str += "\nOwner of the office = " + GetOwnerName();
		str += "\nJob type of the rooms of the house = " + GetJobType();
		str += "\n";

		return str;
	};









	private String jobType;




}