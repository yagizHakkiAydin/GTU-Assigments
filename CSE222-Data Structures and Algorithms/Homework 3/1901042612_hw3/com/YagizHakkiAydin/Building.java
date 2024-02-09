package com.YagizHakkiAydin;



/**
*Parent for the House,Office and Market classes
*/
abstract public class Building extends Structure
{
	/**
	*Constructor for Building
	*/
	Building()
	{
		final int defaultBuildingHeight = 5;

		SetHeight( defaultBuildingHeight );
	}


	/**
	*Constructor for Building
	*@param beginPositionOfBuilding begin position of the building
	*@param areaOfBuilding area value of the building to be created
	*@param heightOfBuilding height value of the building
	*@param nameOfOwner name of the owner of the building
	*/
	Building( int beginPositionOfBuilding , int areaOfBuilding , int heightOfBuilding , String nameOfOwner )
	{
		super(beginPositionOfBuilding,areaOfBuilding);
		SetOwnerName( nameOfOwner );
		SetHeight( heightOfBuilding );
	}


	/**
	*Returns height of the building
	*@return height of the building
	*/
	public final int GetHeight()
	{ 
		return height; 
	}


	/**
	*Sets the height of the building
	*@param heightOfBuilding height of the building
	*/
	public final void SetHeight( int heightOfBuilding )
	{
		height = heightOfBuilding;
	}





	/**
	*Returns owner name
	*@return owner name
	*/
	public final String GetOwnerName()
	{ 
		return new String(ownerName); 
	}


	/**
	*Sets owner name
	*@param owner owner name
	*/
	public final void SetOwnerName( String owner )
	{
		ownerName =  new String(owner);
	}





	protected int height;

	protected String ownerName;

}