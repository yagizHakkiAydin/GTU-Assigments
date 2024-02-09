package com.YagizHakkiAydin;

import java.util.Scanner;

/**
*Abstract class for different street types
*This class has abstract functions and normal functions
*/
public abstract class Street
{


	/**
	*Constructor
	*/
	Street()
	{
		this(40);
	}


	/**
	*Constructor
	*@param lengthOfStreet length of the street
	*/
	Street( int lengthOfStreet )
	{
		streetLength = lengthOfStreet;

		maxBuildingHeight = 0;

		numberOfStructuresOnLeftSide = 0;

		numberOfStructuresOnRightSide = 0;

		numOfPlayGroundsOnLeft=0;
		numOfPlayGroundsOnRight=0;

		occupiedLandsOnLeftSide = new boolean[lengthOfStreet];
		occupiedLandsOnRightSide = new boolean[lengthOfStreet];

		for( int i=0 ; i<GetStreetLength() ; i++ )
		{
			occupiedLandsOnLeftSide[i] = false;
			occupiedLandsOnRightSide[i] = false;
		}
	}



	/**
	*Returns length of the street
	*@return length of the street
	*/
	public final int GetStreetLength()
	{
		return streetLength;
	}


	/**
	*Sets length of the street
	*@param lengthOfStreet length of the street
	*/
	public final void SetStreetLength( int lengthOfStreet )
	{
		streetLength = lengthOfStreet;
	}


	/**
	*returns max building height
	*@return max building height
	*/
	public final int GetMaxHeight()
	{
		return maxBuildingHeight;
	}
	/**
	*Returns NumOfPlayGrounds
	*@return NumOfPlayGrounds
	*/
	public final int GetNumOfPlayGrounds()
	{
		return numOfPlayGroundsOnRight + numOfPlayGroundsOnLeft;
	}
	/**
	*Sets maximum biliding height to printing street
	@param newMaxHeight max height of the street
	*/
	public final void SetMaxHeight( int newMaxHeight )
	{
		maxBuildingHeight = newMaxHeight;
	}



	/**
	*Adds market to given side
	*@param side side of the street
	*@throws StructureCannotBeAdded exception thrown when structure couldn't added
	*/
	public abstract void AddMarket( String side ) throws StructureCannotBeAdded;

	/**
	*Adds house to given side
	*@param side side of the street
	*@throws StructureCannotBeAdded exception thrown when structure couldn't added
	*/
	public abstract void AddHouse( String side ) throws StructureCannotBeAdded;

	/**
	*Adds office to given side
	*@param side side of the street
	*@throws StructureCannotBeAdded exception thrown when structure couldn't added
	*/
	public abstract void AddOffice( String side ) throws StructureCannotBeAdded;




	/**
	*Adds given market to given side
	*@param side side of the street
	*@throws StructureCannotBeAdded exception thrown when structure couldn't added
	*@param obj object to be added to the street
	*/
	public abstract void AddMarket( String side , Market obj ) throws StructureCannotBeAdded;

	/**
	*Adds given house to given side
	*@param side side of the street
	*@throws StructureCannotBeAdded exception thrown when structure couldn't added
	*@param obj object to be added to the street
	*/
	public abstract void AddHouse( String side , House obj ) throws StructureCannotBeAdded;

	/**
	*Adds given office to given side
	*@param side side of the street
	*@throws StructureCannotBeAdded exception thrown when structure couldn't added
	*@param obj object to be added to the street
	*/
	public abstract void AddOffice( String side , Office obj ) throws StructureCannotBeAdded;


	/**
	*Adds play ground to given side
	*@param side side of the street
	*@throws StructureCannotBeAdded exception thrown when structure couldn't added
	*@param obj object to be added to the street
	*/
	public final void AddPlayGround( String side , PlayGround obj ) throws StructureCannotBeAdded
	{
		for( int i=obj.GetBeginPosition();i<obj.GetEndPosition();i++ )
		{
			if( side.equals("left") )
			{
				if( occupiedLandsOnLeftSide[i] == true )
				{
					throw new StructureCannotBeAdded();
				}
			}
			else
			{
				if( occupiedLandsOnRightSide[i] == true )
				{
					throw new StructureCannotBeAdded();
				}
			}
		}
		
		
			if( side.equals("left") )
			{
				numOfPlayGroundsOnLeft++;
				for( int i=obj.GetBeginPosition();i<obj.GetEndPosition();i++ )
				{
					occupiedLandsOnLeftSide[i] = true;
				}
			}
			else
			{
				numOfPlayGroundsOnRight++;
				for( int i=obj.GetBeginPosition();i<obj.GetEndPosition();i++ )
				{
					occupiedLandsOnRightSide[i] = true;
				}
			}
		
	};






	/**
	*@param side side of the street
	*@param obj structure to be added
	*/
	protected void AddStructure( String side , Structure obj ){};



	/**
	*This function throws an exception if given structure can't be added to given side
	*@param side side of the street
	*@param obj structure to be added
	*/
	protected abstract void ThrowExceptionİfStructureCannotBeAdded( String side , Structure obj ) throws StructureCannotBeAdded;



	/**
	*Exception when structure couldn't be added
	*/
	protected class StructureCannotBeAdded extends Exception
	{
		/**
		*Exception constructor
		*/
		public StructureCannotBeAdded(){}
		/**
		*Exception constructor
		*@param errorMessage error message
		*/
		public StructureCannotBeAdded(String errorMessage){ super(errorMessage); }
	}

	/**
	*Asks user opening\closing time and deletes that market
	*@param side side of the street
	*/
	public abstract void deleteMarket( String side );
	/**
	*Asks user owner and deletes that house
	*@param side side of the street
	*/
	public abstract void deleteHouse( String side );

	/**
	*Asks user job type deletes that office
	*@param side side of the street
	*/
	public abstract void deleteOffice( String side );


	/**
	*Prints street view
	*/
	public abstract void printStreet();

	/**
	*Prints everything about the street
	*/
	public abstract void printAllStructureInformation();


	/**
	*Returns 2d string that represents street view
	*@return 2d string that represents street view
	*/
	public abstract String[] GetStreetView();


	/**
	*Length of the street
	*/
	private int streetLength;

	/**
	*maximum building height
	*/
	private int maxBuildingHeight;

	/**
	*numOfPlayGroundsOnLeft
	*/
	private int numOfPlayGroundsOnLeft;

	/**
	*numOfPlayGroundsOnRight
	*/
	private int numOfPlayGroundsOnRight;

	/**
	*numberOfStructuresOnLeftSide
	*/
	protected int numberOfStructuresOnLeftSide;

	/**
	*numberOfStructuresOnRightSide
	*/
	protected int numberOfStructuresOnRightSide;


	/**
	*occupiedLandsOnLeftSide boolean array to keep occupied lands
	*/
	protected boolean[] occupiedLandsOnLeftSide;

	/**
	*occupiedLandsOnRightSide boolean array to keep occupied lands
	*/
	protected boolean[] occupiedLandsOnRightSide;

}



