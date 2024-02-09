package com.YagizHakki;



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
		int defaultBuildingHeight = 9;

		setHeight( defaultBuildingHeight );
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
		setOwnerName( nameOfOwner );
		setHeight( heightOfBuilding );
	}


	/**
	*Returns height of the building
	*@return height of the building
	*/
	public final int getHeight()
	{ 
		return height; 
	}


	/**
	*Sets the height of the building
	*@param heightOfBuilding height of the building
	*/
	public final void setHeight( int heightOfBuilding )
	{
		height = heightOfBuilding;
	}





	/**
	*Returns owner name
	*@return owner name
	*/
	public final String getOwnerName()
	{ 
		String copyOfOwnerName = new String(ownerName);

		return copyOfOwnerName; 
	}


	/**
	*Sets owner name
	*@param owner owner name
	*/
	public final void setOwnerName( String owner )
	{
		ownerName =  new String(owner);;
	}





	private int height;

	private String ownerName;

}