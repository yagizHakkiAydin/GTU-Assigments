package com.YagizHakki;

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

		setBeginPosition( obj.getBeginPosition() );

		setEndPosition( getBeginPosition() + obj.getArea() );

		setHeight( obj.getHeight() );

		setOwnerName( obj.getOwnerName() );

		setJobType( obj.getJobType() );

		setStructureType("Office");

	}

	/**
	*Constructor
	*@param beginPositionOfTheOffice begin position of the new Office
	*@param areaOfTheOffice area of the new Office
	*@param heightOfTheOffice height of the new Office
	*/
	Office( int beginPositionOfTheOffice , int areaOfTheOffice , int heightOfTheOffice )
	{	

		setBeginPosition( beginPositionOfTheOffice );

		setEndPosition( getBeginPosition() + areaOfTheOffice );

		setHeight( heightOfTheOffice );

		setOwnerName("ownerNotInitialized");

		setJobType("jobTypeNotInitialized");

		setStructureType("Office");

	}



	/**
	*Returns job type of the office
	*@return job type of the office
	*/
	public final String getJobType()
	{ 
		String copyOfJobYype = new String(jobType);

		return copyOfJobYype; 
	}


	/**
	*Sets job type of the office
	*@param jobTypeOfTheOffice job type of the office
	*/
	public final void setJobType( String jobTypeOfTheOffice )
	{ 
		jobType = new String(jobTypeOfTheOffice);
	}


	@Override
	public final void printInformation()
	{
		System.out.printf("\nBegin position of the office = %d\n",getBeginPosition());
		System.out.printf("End position of the office = %d\n",getEndPosition());
		System.out.printf("Area of the office = %d\n",getArea());
		System.out.printf("Height of the office = %d\n",getHeight());
		System.out.printf("Owner of the office = %s\n",getOwnerName());
		System.out.printf("Job type of the office = %s\n",getJobType());
	};













	@Override
	public Office clone() throws CloneNotSupportedException
	{
		Office obj = new Office();

		obj.setJobType(this.getJobType());

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

		if( !(o instanceof Office) )
		{
			return false;
		}

		Office obj;
		obj = (Office)o;


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
		else if( !this.getJobType().equals( obj.getJobType()) )
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
		result *=getJobType().hashCode();

		return result; 
	}



	@Override	
	public String toString()
	{
		String str = new String();

		str += "\nBegin position of the office = " + getBeginPosition();
		str += "\nEnd position of the office = " + getEndPosition();
		str += "\nArea of the office = " + getArea();
		str += "\nHeight of the office = " + getHeight();
		str += "\nOwner of the office = " + getOwnerName();
		str += "\nJob type of the rooms of the house = " + getJobType();
		str += "\n";

		return str;
	};









	private String jobType;




}