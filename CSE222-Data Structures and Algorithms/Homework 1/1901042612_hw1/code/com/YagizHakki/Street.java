package com.YagizHakki;

import java.util.Scanner;

/**
*This class keeps all data about the street
*This class has functions to modify structures(including playgrounds)
*/
public class Street
{

	/**
	*Default constructor,initializes the street with length of 30;
	*/
	Street()
	{
		this( 30 );

	}



	/**
	*Constructor,initializes the street with length given by user;
	*@param lengthOfStreet parameter for constructor to initialize street length
	*/
	Street( int lengthOfStreet )
	{


		streetLength = lengthOfStreet;

		occupiedLandsOnLeftSide = new boolean[lengthOfStreet];

		occupiedLandsOnRightSide = new boolean[lengthOfStreet];

		numberOfStructuresOnTheLeftSide = 0;
		numberOfStructuresOnTheRightSide = 0;


		for( int countLandPosition = 0 ; countLandPosition < lengthOfStreet ; countLandPosition++ )
		{
			occupiedLandsOnLeftSide[ countLandPosition ] = false;
			occupiedLandsOnRightSide[ countLandPosition ] = false;
		}


	}



	/**
	*Returns length of the street
	*@return length of the street
	*/
	public int getLengthOfStreet()
	{
		return streetLength;
	}































	/**
	*Creates a market object for wanted side of the street,but doesn't add to the street
	*@param obj used to initialize a new created market object by copying
	*@param landsOfTheChoosenSide includes boolean values for checking if the asked position is occupied,index of this array represents positions
	*@return result is a Market object
	*@throws MarketCannotBeAdded exception if object isn't added for some reason
	*/
	private Market createNewMarket( Market obj , boolean[] landsOfTheChoosenSide ) throws MarketCannotBeAdded
	{
		Scanner scannerObj = new Scanner(System.in);

		Market newMarket = new Market( obj );



		newMarket.fixBeginAndEndPositions();


		if( newMarket.getHeight() <= 0 )
		{
			throw new MarketCannotBeAdded("Invalid value for height of Market");
		}
		else if( (newMarket.getBeginPosition()<0) || (newMarket.getEndPosition()<0))
		{
			throw new MarketCannotBeAdded("Market cannot be at a position less than 0");
		}
		else if( (newMarket.getBeginPosition()>=getLengthOfStreet()) || (newMarket.getEndPosition()>=getLengthOfStreet()))
		{
			throw new MarketCannotBeAdded("Market cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newMarket.getBeginPosition() ; index<=newMarket.getEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new MarketCannotBeAdded("Market cannot be at given area,because area is occupied");
				}
			}

		}


		return newMarket;
	}









	/**
	*Creates a market object for wanted side of the street with getting properties from user,but doesn't add to the street
	*@param landsOfTheChoosenSide array that keeps positions that are occupied
	*@return Market object which is created by user
	*@throws MarketCannotBeAdded exception if object isn't added for some reason
	*/
	private Market createNewMarket( boolean[] landsOfTheChoosenSide ) throws MarketCannotBeAdded
	{
		Scanner scannerObj = new Scanner(System.in);

		Market newMarket = new Market();


		System.out.printf("Enter begin position for the Market = ");
		newMarket.setBeginPosition( scannerObj.nextInt() );

		System.out.printf("Enter area for the Market = ");
		newMarket.setEndPosition( newMarket.getBeginPosition() + scannerObj.nextInt() );



		System.out.printf("Enter height for the Market = ");
		newMarket.setHeight( scannerObj.nextInt() );


		System.out.printf("Enter opening time for the Market = ");
		newMarket.setOpeningTime( scannerObj.nextInt() );

		System.out.printf("Enter closing time for the Market = ");
		newMarket.setClosingTime( scannerObj.nextInt() );


		scannerObj.nextLine();

		System.out.printf("Enter owner for the Market = ");
		newMarket.setOwnerName( scannerObj.nextLine() );


		newMarket.fixBeginAndEndPositions();


		if( newMarket.getHeight() <= 0 )
		{
			throw new MarketCannotBeAdded("Invalid value for height of Market");
		}
		else if( (newMarket.getBeginPosition()<0) || (newMarket.getEndPosition()<0))
		{
			throw new MarketCannotBeAdded("Market cannot be at a position less than 0");
		}
		else if( (newMarket.getBeginPosition()>=getLengthOfStreet()) || (newMarket.getEndPosition()>=getLengthOfStreet()))
		{
			throw new MarketCannotBeAdded("Market cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newMarket.getBeginPosition() ; index<=newMarket.getEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new MarketCannotBeAdded("Market cannot be at given area,because area is occupied");
				}
			}

		}


		return newMarket;
	}





	/**
	*Creates a market by using 'createNewMarket()' and adds it to left side of the street by 'addMarketToLeftSide()'
	*/
	public void addMarketToLeftSide()
	{
		try
		{
			Market o = createNewMarket(occupiedLandsOnLeftSide);
			addMarketToLeftSide(o);
		}
		catch( MarketCannotBeAdded e )
		{
			System.out.printf("%s , Market could not be added...\n" , e.getMessage());
		}
	}




	/**
	*Adds a new market to the left side of the street,gets position and height information from the 'obj' and adds new Market 
	*object to the 'structuresOnLeftSide' array.Occupied lands are marked at 'occupiedLandsOnLeftSide' array.
	*@param obj object to be copied and it's copy gets added to the 'structuresOnLeftSide' array.
	*/
	public void addMarketToLeftSide( Market obj )
	{

		try
		{
			Market newMarket = createNewMarket(obj,occupiedLandsOnLeftSide);


			if( newMarket.getHeight() > maxHeight )
			{
				maxHeight = newMarket.getHeight();
			}


			for( int index=newMarket.getBeginPosition() ; index<=newMarket.getEndPosition() ; index++ )
			{
				occupiedLandsOnLeftSide[index] = true;
			}

			numberOfStructuresOnTheLeftSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnTheLeftSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnTheLeftSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnLeftSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnTheLeftSide - 1 ] = newMarket;

			structuresOnLeftSide = newStructuresArray;
		}
		catch( MarketCannotBeAdded e )
		{
			System.out.printf("%s , Market could not be added...\n" , e.getMessage());
		}
	}


	/**
	*Creates a market by using 'createNewMarket()' and adds it to right side of the street by 'addMarketToRightSide()'
	*/
	public void addMarketToRightSide()
	{
		try
		{
			Market o = createNewMarket(occupiedLandsOnRightSide);
			addMarketToRightSide(o);
		}
		catch( MarketCannotBeAdded e )
		{
			System.out.printf("%s , Market could not be added...\n" , e.getMessage());
		}
	}




	/**
	*Adds a new market to the Right side of the street,gets position and height information from the 'obj' and adds new Market 
	*object to the 'structuresOnRightSide' array.Occupied lands are marked at 'occupiedLandsOnRightSide' array.
	*@param obj object to be copied and it's copy gets added to the 'structuresOnRightSide' array.
	*/
	public void addMarketToRightSide( Market obj )
	{

		try
		{
			Market newMarket = createNewMarket(obj,occupiedLandsOnRightSide);

			if( newMarket.getHeight() > maxHeight )
			{
				maxHeight = newMarket.getHeight();
			}

			for( int index=newMarket.getBeginPosition() ; index<=newMarket.getEndPosition() ; index++ )
			{
				occupiedLandsOnRightSide[index] = true;
			}

			numberOfStructuresOnTheRightSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnTheRightSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnTheRightSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnRightSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnTheRightSide - 1 ] = newMarket;

			structuresOnRightSide = newStructuresArray;

		}
		catch( MarketCannotBeAdded e )
		{
			System.out.printf("%s , Market could not be added...\n" , e.getMessage());
		}
	}


































	/**
	*Creates a Office by using 'createNewOffice()' and adds it to left side of the street by 'addOfficeToLeftSide()'
	*/
	public void addOfficeToLeftSide()
	{	
		try
		{
			Office o = createNewOffice( occupiedLandsOnLeftSide );
			addOfficeToLeftSide( o );
		}
		catch( OfficeCannotBeAdded e )
		{
			System.out.printf("%s , Office could not be added...\n" , e.getMessage());
		}
	}



	/**
	*Adds a new Office to the Left side of the street,gets position and height information from the 'obj' and adds new Office 
	*object to the 'structuresOnLeftSide' array.Occupied lands are marked at 'occupiedLandsOnLeftSide' array.
	*@param obj object to be copied and it's copy gets added to the 'structuresOnLeftSide' array.
	*/
	public void addOfficeToLeftSide( Office obj )
	{

		try
		{
			Office newOffice = createNewOffice(obj,occupiedLandsOnLeftSide);


			if( newOffice.getHeight() > maxHeight )
			{
				maxHeight = newOffice.getHeight();
			}


			for( int index=newOffice.getBeginPosition() ; index<=newOffice.getEndPosition() ; index++ )
			{
				occupiedLandsOnLeftSide[index] = true;
			}

			numberOfStructuresOnTheLeftSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnTheLeftSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnTheLeftSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnLeftSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnTheLeftSide - 1 ] = newOffice;

			structuresOnLeftSide = newStructuresArray;
		}
		catch( OfficeCannotBeAdded e )
		{
			System.out.printf("%s , Office could not be added...\n" , e.getMessage());
		}
	}








	/**
	*Creates a Office by using 'createNewOffice()' and adds it to right side of the street by 'addOfficeToLeftSide()'
	*/
	public void addOfficeToRightSide()
	{	
		try
		{
			Office o = createNewOffice( occupiedLandsOnRightSide );
			addOfficeToRightSide( o );
		}
		catch( OfficeCannotBeAdded e )
		{
			System.out.printf("%s , Office could not be added...\n" , e.getMessage());
		}
	}



	/**
	*Adds a new Office to the Right side of the street,gets position and height information from the 'obj' and adds new Office 
	*object to the 'structuresOnRightSide' array.Occupied lands are marked at 'occupiedLandsOnRightSide' array.
	*@param obj object to be copied and it's copy gets added to the 'structuresOnRightSide' array.
	*/
	public void addOfficeToRightSide( Office obj )
	{

		try
		{
			Office newOffice = createNewOffice(obj,occupiedLandsOnRightSide);

			if( newOffice.getHeight() > maxHeight )
			{
				maxHeight = newOffice.getHeight();
			}

			for( int index=newOffice.getBeginPosition() ; index<=newOffice.getEndPosition() ; index++ )
			{
				occupiedLandsOnRightSide[index] = true;
			}

			numberOfStructuresOnTheRightSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnTheRightSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnTheRightSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnRightSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnTheRightSide - 1 ] = newOffice;

			structuresOnRightSide = newStructuresArray;

		}
		catch( OfficeCannotBeAdded e )
		{
			System.out.printf("%s , Office could not be added...\n" , e.getMessage());
		}
	}




	/**
	*Creates a office object for wanted side of the street,but doesn't add to the street
	*@param obj used to initialize a new created office object by copying
	*@param landsOfTheChoosenSide includes boolean values for checking if the asked position is occupied,index of this array represents positions
	*@return copy of given office object as parameter
	*@throws OfficeCannotBeAdded exception if object isn't added for some reason
	*/
	public Office createNewOffice( Office obj , boolean[] landsOfTheChoosenSide ) throws OfficeCannotBeAdded
	{
		Office newOffice = new Office( obj );

		newOffice.fixBeginAndEndPositions();


		if( newOffice.getHeight() <= 0 )
		{
			throw new OfficeCannotBeAdded("Invalid value for height of Office");
		}
		else if( (newOffice.getBeginPosition()<0) || (newOffice.getEndPosition()<0))
		{
			throw new OfficeCannotBeAdded("Office cannot be at a position less than 0");
		}
		else if( newOffice.getBeginPosition() == newOffice.getEndPosition() )
		{
			throw new OfficeCannotBeAdded("Office area can't be 0");
		}
		else if( (newOffice.getBeginPosition()>=getLengthOfStreet()) || (newOffice.getEndPosition()>=getLengthOfStreet()))
		{
			throw new OfficeCannotBeAdded("Office cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newOffice.getBeginPosition() ; index<=newOffice.getEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new OfficeCannotBeAdded("Office cannot be at given area,because area is occupied");
				}
			}

		}


		return newOffice;
	}










	/**
	*Creates a Office object for wanted side of the street with getting properties from user,but doesn't add to the street
	*@param landsOfTheChoosenSide array that keeps positions that are occupied
	*@return Office object which is created by user
	*@throws OfficeCannotBeAdded exception if object isn't added for some reason
	*/
	private Office createNewOffice( boolean[] landsOfTheChoosenSide ) throws OfficeCannotBeAdded
	{
		Scanner scannerObj = new Scanner(System.in);

		Office newOffice = new Office();


		System.out.printf("Enter begin position for the Office = ");
		newOffice.setBeginPosition( scannerObj.nextInt() );

		System.out.printf("Enter area for the Office = ");
		newOffice.setEndPosition( newOffice.getBeginPosition() + scannerObj.nextInt() );



		System.out.printf("Enter height for the Office = ");
		newOffice.setHeight( scannerObj.nextInt() );

		System.out.printf("Enter job type for the Office = ");
		newOffice.setJobType( scannerObj.nextLine() );

		scannerObj.nextLine();

		System.out.printf("Enter owner for the Office = ");
		newOffice.setOwnerName( scannerObj.nextLine() );


		newOffice.fixBeginAndEndPositions();


		if( newOffice.getHeight() <= 0 )
		{
			throw new OfficeCannotBeAdded("Invalid value for height of Office");
		}
		else if( (newOffice.getBeginPosition()<0) || (newOffice.getEndPosition()<0))
		{
			throw new OfficeCannotBeAdded("Office cannot be at a position less than 0");
		}
		else if( (newOffice.getBeginPosition()>=getLengthOfStreet()) || (newOffice.getEndPosition()>=getLengthOfStreet()))
		{
			throw new OfficeCannotBeAdded("Office cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newOffice.getBeginPosition() ; index<=newOffice.getEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new OfficeCannotBeAdded("Office cannot be at given area,because area is occupied");
				}
			}

		}


		return newOffice;
	}



























































	/**
	*Creates a House by using 'createNewOffice()' and adds it to left side of the street by 'addHouseToLeftSide()'
	*/
	public void addHouseToLeftSide()
	{
		try
		{
			House newHouse = createNewHouse(occupiedLandsOnLeftSide);
			addHouseToLeftSide( newHouse );
		}
		catch( HouseCannotBeAdded e )
		{
			System.out.printf("%s , House could not be added...\n" , e.getMessage());
		}

	}


	/**
	*Adds a new House to the Left side of the street,gets position and height information from the 'obj' and adds new House 
	*object to the 'structuresOnLeftSide' array.Occupied lands are marked at 'occupiedLandsOnLeftSide' array.
	*@param obj object to be copied and it's copy gets added to the 'structuresOnLeftSide' array.
	*/
	public void addHouseToLeftSide( House obj )
	{


		try
		{
			House newHouse = createNewHouse(obj,occupiedLandsOnLeftSide);


			if( newHouse.getHeight() > maxHeight )
			{
				maxHeight = newHouse.getHeight();
			}


			for( int index=newHouse.getBeginPosition() ; index<=newHouse.getEndPosition() ; index++ )
			{
				occupiedLandsOnLeftSide[index] = true;
			}

			numberOfStructuresOnTheLeftSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnTheLeftSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnTheLeftSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnLeftSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnTheLeftSide - 1 ] = newHouse;

			structuresOnLeftSide = newStructuresArray;
		}
		catch( HouseCannotBeAdded e )
		{
			System.out.printf("%s , House could not be added...\n" , e.getMessage());
		}
	}



	/**
	*Creates a House by using 'createNewHouse()' and adds it to Right side of the street by 'addHouseToRightSide()'
	*/
	public void addHouseToRightSide()
	{
		try
		{
			House newHouse = createNewHouse(occupiedLandsOnRightSide);
			addHouseToRightSide( newHouse );
		}
		catch( HouseCannotBeAdded e )
		{
			System.out.printf("%s , House could not be added...\n" , e.getMessage());
		}

	}


	/**
	*Adds a new House to the Right side of the street,gets position and height information from the 'obj' and adds new House 
	*object to the 'structuresOnRightSide' array.Occupied lands are marked at 'occupiedLandsOnRightSide' array.
	*@param obj object to be copied and it's copy gets added to the 'structuresOnRightSide' array.
	*/
	public void addHouseToRightSide( House obj )
	{

		try
		{
			House newHouse = createNewHouse(obj,occupiedLandsOnRightSide);

			if( newHouse.getHeight() > maxHeight )
			{
				maxHeight = newHouse.getHeight();
			}

			for( int index=newHouse.getBeginPosition() ; index<=newHouse.getEndPosition() ; index++ )
			{
				occupiedLandsOnRightSide[index] = true;
			}

			numberOfStructuresOnTheRightSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnTheRightSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnTheRightSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnRightSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnTheRightSide - 1 ] = newHouse;

			structuresOnRightSide = newStructuresArray;

		}
		catch( HouseCannotBeAdded e )
		{
			System.out.printf("%s , House could not be added...\n" , e.getMessage());
		}
	}





	/**
	*Creates a Office object for wanted side of the street with getting properties from user,but doesn't add to the street
	*@param landsOfTheChoosenSide array that keeps positions that are occupied
	*@return Office object which is created by user
	*@throws HouseCannotBeAdded exception if object isn't added for some reason
	*/
	private House createNewHouse( boolean[] landsOfTheChoosenSide ) throws HouseCannotBeAdded
	{
		Scanner scannerObj = new Scanner(System.in);

		House newHouse = new House();


		System.out.printf("Enter begin position for the house = ");
		newHouse.setBeginPosition( scannerObj.nextInt() );

		System.out.printf("Enter area for the house = ");
		newHouse.setEndPosition( newHouse.getBeginPosition() + scannerObj.nextInt() );



		System.out.printf("Enter height for the house = ");
		newHouse.setHeight( scannerObj.nextInt() );

		System.out.printf("Enter number of the rooms  for the house = ");
		newHouse.setNumberOfRooms( scannerObj.nextInt() );

		scannerObj.nextLine();

		System.out.printf("Enter owner for the house = ");
		newHouse.setOwnerName( scannerObj.nextLine() );

		System.out.printf("Enter color for the house = ");
		newHouse.setColor( scannerObj.nextLine() );

		newHouse.fixBeginAndEndPositions();


		if( newHouse.getHeight() <= 0 )
		{
			throw new HouseCannotBeAdded("Invalid value for height of house");
		}
		else if( (newHouse.getBeginPosition()<0) || (newHouse.getEndPosition()<0))
		{
			throw new HouseCannotBeAdded("House cannot be at a position less than 0");
		}
		else if( (newHouse.getBeginPosition()>=getLengthOfStreet()) || (newHouse.getEndPosition()>=getLengthOfStreet()))
		{
			throw new HouseCannotBeAdded("House cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newHouse.getBeginPosition() ; index<=newHouse.getEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new HouseCannotBeAdded("House cannot be at given area,because area is occupied");
				}
			}

		}

		return newHouse;
	}



	/**
	*Creates a House object for wanted side of the street,but doesn't add to the street
	*@param obj used to initialize a new created House object by copying
	*@param landsOfTheChoosenSide includes boolean values for checking if the asked position is occupied,index of this array represents positions
	*@return copy of given House object as parameter
	*@throws HouseCannotBeAdded exception if object isn't added for some reason
	*/
	private House createNewHouse( House obj ,  boolean[] landsOfTheChoosenSide ) throws HouseCannotBeAdded
	{

		House newHouse = new House( obj );




		if( newHouse.getHeight() <= 0 )
		{
			throw new HouseCannotBeAdded("Invalid value for height of house");
		}
		else if( (newHouse.getBeginPosition()<0) || (newHouse.getEndPosition()<0))
		{
			throw new HouseCannotBeAdded("House cannot be at a position less than 0");
		}
		else if( (newHouse.getBeginPosition()>=getLengthOfStreet()) || (newHouse.getEndPosition()>=getLengthOfStreet()))
		{
			throw new HouseCannotBeAdded("House cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newHouse.getBeginPosition() ; index<=newHouse.getEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new HouseCannotBeAdded("House cannot be at given area,because area is occupied");
				}
			}

		}

		return newHouse;
	}

		


































	/**
	*Adds playground to the left side of the street by taking properties from user
	*/
	public void addPlayGroundToLeftSide()
	{
		try
		{
			PlayGround newPlayGround = createNewPlayGround(occupiedLandsOnLeftSide);
			addPlayGroundToLeftSide( newPlayGround );
		}
		catch( PlayGroundCannotBeAdded e )
		{
			System.out.printf("%s , PlayGround could not be added...\n" , e.getMessage());
		}

	}


	/**
	*Adds playground to the left side of the street with the copy of given object
	*@param obj playground object to be copied
	*/
	public void addPlayGroundToLeftSide( PlayGround obj )
	{


		try
		{
			PlayGround newPlayGround = createNewPlayGround(obj,occupiedLandsOnLeftSide);



			for( int index=newPlayGround.getBeginPosition() ; index<=newPlayGround.getEndPosition() ; index++ )
			{
				occupiedLandsOnLeftSide[index] = true;
			}


			numberOfStructuresOnTheLeftSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnTheLeftSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnTheLeftSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnLeftSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnTheLeftSide - 1 ] = newPlayGround;

			structuresOnLeftSide = newStructuresArray;
		}
		catch( PlayGroundCannotBeAdded e )
		{
			System.out.printf("%s , House could not be added...\n" , e.getMessage());
		}
	}


	/**
	*Adds playground to the right side of the street by taking properties from user
	*/
	public void addPlayGroundToRightSide()
	{
		try
		{
			PlayGround newPlayGround = createNewPlayGround(occupiedLandsOnRightSide);
			addPlayGroundToRightSide( newPlayGround );
		}
		catch( PlayGroundCannotBeAdded e )
		{
			System.out.printf("%s , PlayGround could not be added...\n" , e.getMessage());
		}

	}

	/**
	*Adds playground to the right side of the street with the copy of given object
	*@param obj playground object to be copied
	*/
	public void addPlayGroundToRightSide( PlayGround obj )
	{

		try
		{
			PlayGround newPlayGround = createNewPlayGround(obj,occupiedLandsOnRightSide);


			for( int index=newPlayGround.getBeginPosition() ; index<=newPlayGround.getEndPosition() ; index++ )
			{
				occupiedLandsOnRightSide[index] = true;
			}

			numberOfStructuresOnTheRightSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnTheRightSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnTheRightSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnRightSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnTheRightSide - 1 ] = newPlayGround;

			structuresOnRightSide = newStructuresArray;

		}
		catch( PlayGroundCannotBeAdded e )
		{
			System.out.printf("%s , House could not be added...\n" , e.getMessage());
		}
	}




	/**
	*Creates a new PlayGround object with user input
	*@return new created PlayGround object
	*/
	private PlayGround createNewPlayGround( boolean[] landsOfTheChoosenSide ) throws PlayGroundCannotBeAdded
	{
		Scanner scannerObj = new Scanner(System.in);

		PlayGround newPlayGround = new PlayGround();


		System.out.printf("Enter begin position for the PlayGround = ");
		newPlayGround.setBeginPosition( scannerObj.nextInt() );

		System.out.printf("Enter area for the PlayGround = ");
		newPlayGround.setEndPosition( newPlayGround.getBeginPosition() + scannerObj.nextInt() );

		newPlayGround.fixBeginAndEndPositions();


		if( (newPlayGround.getBeginPosition()<0) || (newPlayGround.getEndPosition()<0))
		{
			throw new PlayGroundCannotBeAdded("PlayGround cannot be at a position less than 0");
		}
		else if( (newPlayGround.getBeginPosition()>=getLengthOfStreet()) || (newPlayGround.getEndPosition()>=getLengthOfStreet()))
		{
			throw new PlayGroundCannotBeAdded("PlayGround cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newPlayGround.getBeginPosition() ; index<=newPlayGround.getEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new PlayGroundCannotBeAdded("PlayGround cannot be at given area,because area is occupied");
				}
			}

		}

		return newPlayGround;
	}




	/**
	*Creates a PlayGround object with copying given object
	*@param obj PlayGround object to be copied
	*@param landsOfTheChoosenSide array that keeps occupied position on the street
	*@return new created PlayGround object
	*/
	private PlayGround createNewPlayGround( PlayGround obj ,  boolean[] landsOfTheChoosenSide ) throws PlayGroundCannotBeAdded
	{

		PlayGround newPlayGround = new PlayGround( obj );




		if( (newPlayGround.getBeginPosition()<0) || (newPlayGround.getEndPosition()<0))
		{
			throw new PlayGroundCannotBeAdded("PlayGround cannot be at a position less than 0");
		}
		else if( (newPlayGround.getBeginPosition()>=getLengthOfStreet()) || (newPlayGround.getEndPosition()>=getLengthOfStreet()))
		{
			throw new PlayGroundCannotBeAdded("PlayGround cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newPlayGround.getBeginPosition() ; index<=newPlayGround.getEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new PlayGroundCannotBeAdded("PlayGround cannot be at given area,because area is occupied");
				}
			}

		}

		return newPlayGround;
	}













	/**
	*Asks user to enter owner name time and deletes corresponding house from the left side of the street
	*/
	public void deleteHouseFromLeftSide()
	{

		House h;

		System.out.printf("\nEnter the owner name of the house to be deleted -->");

		Scanner sc = new Scanner(System.in);

		String choice = sc.nextLine();

		for( int i=0;i<numberOfStructuresOnTheLeftSide;i++ )
		{
			if( structuresOnLeftSide[i] instanceof House )
			{
				h = (House)structuresOnLeftSide[i];
				if( h.getOwnerName().equals( choice ))
				{
					System.out.printf("dsadadadasda");
					deleteBuilding("left",i);
					break;
				}
			}
		}
	}


	/**
	*Asks user to enter job type time and deletes corresponding office from the left side of the street
	*/
	public void deleteOfficeFromLeftSide()
	{
		Office o;

		System.out.printf("\nEnter the job type of the office to be deleted -->");

		Scanner sc = new Scanner(System.in);

		String choice = sc.nextLine();

		for( int i=0;i<numberOfStructuresOnTheLeftSide;i++ )
		{
			if( structuresOnLeftSide[i] instanceof Office )
			{
				o = (Office)structuresOnLeftSide[i];
				if( o.getJobType().equals(choice) )
				{
					deleteBuilding("left",i);
					break;
				}
			}
		}
	}







	/**
	*Asks user to enter opening/closing time and deletes corresponding market from the left side of the street
	*/
	public void deleteMarketFromLeftSide()
	{
			Market m;


			System.out.printf("\nEnter the opening time of the market to be deleted -->");

			Scanner sc = new Scanner(System.in);

			int openingTimeChoice = sc.nextInt();
			System.out.printf("\nEnter the closing time of the market to be deleted -->");
			int closingTimeChoice = sc.nextInt();


			for( int i=0;i<numberOfStructuresOnTheLeftSide;i++ )
			{
				if( structuresOnLeftSide[i] instanceof Market )
				{
					m = (Market)structuresOnLeftSide[i];
					if( m.getOpeningTime() == openingTimeChoice  &&  m.getClosingTime() == closingTimeChoice )
					{
						deleteBuilding("left",i);
						break;
					}
				}
			}



	}







	/**
	*Asks user to enter owner name and deletes corresponding house from the right side of the street
	*/
	public void deleteHouseFromRightSide()
	{
		House h;


		System.out.printf("\nEnter the owner name of the house to be deleted -->");

		Scanner sc = new Scanner(System.in);

		String choice = sc.nextLine();

		for( int i=0;i<numberOfStructuresOnTheRightSide;i++ )
		{
			if( structuresOnRightSide[i] instanceof House )
			{
				h = (House)structuresOnRightSide[i];
				if( h.getOwnerName().equals(choice) )
				{
					deleteBuilding("right",i);
					break;
				}
			}
		}
	}




	/**
	*Asks user to enter job type and deletes corresponding office from the right side of the street
	*/
	public void deleteOfficeFromRightSide()
	{

			Office o;


			System.out.printf("\nEnter the job type of the office to be deleted -->");

			Scanner sc = new Scanner(System.in);

			String choice = sc.nextLine();

			for( int i=0;i<numberOfStructuresOnTheRightSide;i++ )
			{
				if( structuresOnRightSide[i] instanceof Office )
				{
					o = (Office)structuresOnRightSide[i];
					if( o.getJobType().equals(choice) )
					{
						deleteBuilding("right",i);
						break;
					}
				}
			}
	
	}





	/**
	*Asks user to enter opening/closing time and deletes corresponding market from the right side of the street
	*/
	public void deleteMarketFromRightSide()
	{
			Market m;

			System.out.printf("\nEnter the opening time of the market to be deleted -->");

			Scanner sc = new Scanner(System.in);

			int openingTimeChoice = sc.nextInt();
			System.out.printf("\nEnter the closing time of the market to be deleted -->");
			int closingTimeChoice = sc.nextInt();

			for( int i=0;i<numberOfStructuresOnTheRightSide;i++ )
			{
				if( structuresOnRightSide[i] instanceof Market )
				{
					m = (Market)structuresOnRightSide[i];
					if( m.getOpeningTime() == openingTimeChoice  &&  m.getClosingTime() == closingTimeChoice )
					{
						deleteBuilding("right",i);
						break;
					}
				}
			}
	}



	/**
	*Deletes an element from the asked structures array at given index
	*@param side side of the deleted element
	*@param buildingIndex index of the deleted element
	*/
	private void deleteBuilding( String side , int buildingIndex )
	{


		boolean[] occupiedLandsArray = new boolean[1];
		Structure[] structuresArray = new Structure[1];
		int numberOfStructures = 0;

		if( side == "left" )
		{
			occupiedLandsArray = occupiedLandsOnLeftSide;
			structuresArray = structuresOnLeftSide;
			numberOfStructuresOnTheLeftSide--;
			numberOfStructures = numberOfStructuresOnTheLeftSide;
		}
		else if( side == "right" )
		{
			occupiedLandsArray = occupiedLandsOnRightSide;
			structuresArray = structuresOnRightSide;
			numberOfStructuresOnTheRightSide--;
			numberOfStructures = numberOfStructuresOnTheRightSide;
		}

		Structure[] newStructuresArray = new Structure[ numberOfStructures ];



		for( int i=structuresArray[buildingIndex].getBeginPosition();i<=structuresArray[buildingIndex].getEndPosition() ; i++ )
		{
			occupiedLandsArray[i] = false;
		}

		for( int i=0; i<buildingIndex ; i++ )
		{
			newStructuresArray[i] = structuresArray[i];
		}

		for( int i=buildingIndex; i<numberOfStructures ; i++ )
		{
			newStructuresArray[i] = structuresArray[i+1];
		}

		structuresArray = newStructuresArray;




		
	}












	/**
	*Prints all information about all structures within structure arrays
	*/
	public void printAllStructureInformation()
	{
		System.out.printf( "All structures on the left side are listed below...\n" );
		for( int i=0;i<numberOfStructuresOnTheLeftSide;i++ )
		{
			 System.out.printf( structuresOnLeftSide[i].toString() );
		}

		System.out.printf( "All structures on the right side are listed below...\n" );
		for( int i=0;i<numberOfStructuresOnTheRightSide;i++ )
		{
			System.out.printf( structuresOnRightSide[i].toString() );
		}
	}







	/**
	*Prints everything about the street
	*/
	public void printStreet()
	{

		int numberOfPlayGrounds = 0;
		int totalHeight = 0;

		System.out.printf("\nEmpty land positions on the left side below...\n");
		for( int i=0;i<getLengthOfStreet();i++ )
		{
			if( occupiedLandsOnLeftSide[i] == false )
			{
				System.out.printf("%d , ",i);
			}
		}
		System.out.printf("\nEmpty land positions on the right side below...\n");
		for( int i=0;i<getLengthOfStreet();i++ )
		{
			if( occupiedLandsOnRightSide[i] == false )
			{
				System.out.printf("%d , ",i);
			}
		}


		System.out.printf("\n\n\nAll structures on the street are listed below...\n");
		printAllStructureInformation();



		for( int i=0;i<numberOfStructuresOnTheLeftSide;i++ )
		{
			if( structuresOnLeftSide[i] instanceof PlayGround )
			{
				numberOfPlayGrounds++;
			}
		}
		for( int i=0;i<numberOfStructuresOnTheRightSide;i++ )
		{
			if( structuresOnRightSide[i] instanceof PlayGround )
			{
				numberOfPlayGrounds++;
			}
		}

		System.out.printf("\n\n\nNumber of play grounds = %d , detailed information is above...\n",numberOfPlayGrounds);





		for( int index=0;index<numberOfStructuresOnTheLeftSide;index++ )
		{
			if( !( structuresOnLeftSide[index] instanceof PlayGround ) )
			{
				totalHeight += ((Building)structuresOnLeftSide[index]).getHeight();
			}
		}	


		for( int index=0;index<numberOfStructuresOnTheRightSide;index++ )
		{
			if( !( structuresOnRightSide[index] instanceof PlayGround ) )
			{
				totalHeight += ((Building)structuresOnRightSide[index]).getHeight();
			}
		}


		System.out.printf("\n\n\nTotal height of buildings = %d \n",totalHeight);



		String[] streetView = getStreetView();
		for( int i=0;i<maxHeight+2;i++ )
		{
			System.out.printf("%s\n",streetView[i]);
		}

	}











	/**
	*Used to change a character of a string at specific index
	*@param str string to be modified
	*@param index index of the string to be replaced with given char
	*@param ch new character for the string
	*@return modified version of the given string
	*/
	public String addCharToIndex( String str , int index , char ch )
	{
		String tempStr = "";
		tempStr += str.substring(0,index);
		tempStr += ch;
		tempStr += str.substring( (index+1) , str.length() );
		return tempStr;
	}






	/**
	*Creates string array with height of highest building and creates ground
	*@return empty street view with only ground as string array
	*/
	private final String[] getEmptyStreetView()
	{
		String[] emptyStreetView;

		String emptyLine = "";
		String groundLine = "";



		emptyStreetView = new String[maxHeight+2];


		for( int countStreetLength=0; countStreetLength<=getLengthOfStreet()+3 ; countStreetLength++ )
		{
			emptyLine += " ";
			groundLine += "-";
		}



		for( int index=0;index<maxHeight+1;index++ )
		{
			emptyStreetView[index] = emptyLine;
		}

		emptyStreetView[maxHeight+1] = groundLine;

		return emptyStreetView;
	}








	/**
	*Sets building walls on string array
	*@return finalized street view(not silhouette)
	*/
	private final String[] getStreetView()
	{

		String[] streetView = setBuildingCeilings();

		for( int index=0;index<numberOfStructuresOnTheLeftSide;index++ )
		{
			if( !( structuresOnLeftSide[index] instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)structuresOnLeftSide[index]).getHeight();

				for( int i=1;i<=buildingHeight;i++ )
				{
					streetView[ maxHeight - i + 1 ] = addCharToIndex( streetView[ maxHeight - i + 1] , structuresOnLeftSide[index].getBeginPosition() , '|' );
					streetView[ maxHeight - i + 1 ] = addCharToIndex( streetView[ maxHeight - i + 1] , structuresOnLeftSide[index].getEndPosition() , '|' );
				}
			}
		}	


		for( int index=0;index<numberOfStructuresOnTheRightSide;index++ )
		{
			if( !( structuresOnRightSide[index] instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)structuresOnRightSide[index]).getHeight();

				for( int i=1;i<=buildingHeight;i++ )
				{
					streetView[ maxHeight - i + 1 ] = addCharToIndex( streetView[ maxHeight - i + 1] , structuresOnRightSide[index].getBeginPosition() , '|' );
					streetView[ maxHeight - i + 1 ] = addCharToIndex( streetView[ maxHeight - i + 1] , structuresOnRightSide[index].getEndPosition()+1 , '|' );
				}
			}
		}


		return streetView;
	}





	/**
	*Returns street silhouette as string array
	*@return string array that represents street silhouette
	*/
	private final String[] getSilhouette()
	{

		String[] silhouette = getStreetView();


		for(int height = 0; height <= maxHeight ; height++)
		{
			for(int position=0;position<getLengthOfStreet();position++)
			{
				//for(int buildingIndex=0;buildingIndex<structuresOnRightSide;buildingIndex++)
				{

				}
			}
		}


		return silhouette;
	}









	/**
	*Gets string array of the street with 'getEmptyStreetView()' and sets ceilings of the buildings
	*@return street view as string arrat
	*/
	private final String[] setBuildingCeilings()
	{
		String[] ceilings = getEmptyStreetView();

		for( int index=0;index<numberOfStructuresOnTheLeftSide;index++ )
		{
			if( !( structuresOnLeftSide[index] instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)structuresOnLeftSide[index]).getHeight();

				for( int i=structuresOnLeftSide[index].getBeginPosition();i<=structuresOnLeftSide[index].getEndPosition();i++ )
				{
					ceilings[ maxHeight - buildingHeight ] = addCharToIndex( ceilings[ maxHeight - buildingHeight] , i , '_' );
					ceilings[ maxHeight - buildingHeight ] = addCharToIndex( ceilings[ maxHeight - buildingHeight] , i , '_' );
				}
			}
		}	


		for( int index=0;index<numberOfStructuresOnTheRightSide;index++ )
		{
			if( !( structuresOnRightSide[index] instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)structuresOnRightSide[index]).getHeight();

				for( int i=structuresOnRightSide[index].getBeginPosition();i<=structuresOnRightSide[index].getEndPosition();i++ )
				{
					ceilings[ maxHeight - buildingHeight ] = addCharToIndex( ceilings[ maxHeight - buildingHeight] , i , '_' );
					ceilings[ maxHeight - buildingHeight ] = addCharToIndex( ceilings[ maxHeight - buildingHeight] , i , '_' );
				}
			}
		}	

		return ceilings;

	}

























	@Override
	public boolean equals( Object o )
	{	
		boolean result = true;

		if( !(o instanceof Market) )
		{
			result = false;
		}
		else if( o.hashCode() != hashCode() )
		{
			result = false;
		}

		
		return result;

	}




	@Override
	public int hashCode()
	{
		int result = 7;
		result *=maxHeight;
		result *=getLengthOfStreet();
		result *= occupiedLandsOnLeftSide.hashCode();
		result *= occupiedLandsOnRightSide.hashCode();
		result *=structuresOnLeftSide.hashCode();
		result *=structuresOnLeftSide.hashCode();



		return result; 
	}



	@Override	
	public String toString()
	{
		String str = new String();

		return str;
	};


























	private class HouseCannotBeAdded extends Exception
	{
		public HouseCannotBeAdded(){}
		public HouseCannotBeAdded(String errorMessage){ super(errorMessage); }
	}

	private class OfficeCannotBeAdded extends Exception
	{
		public OfficeCannotBeAdded(){}
		public OfficeCannotBeAdded(String errorMessage){ super(errorMessage); }
	}


	private class MarketCannotBeAdded extends Exception
	{
		public MarketCannotBeAdded(){}
		public MarketCannotBeAdded(String errorMessage){ super(errorMessage); }
	}

	private class PlayGroundCannotBeAdded extends Exception
	{
		public PlayGroundCannotBeAdded(){}
		public PlayGroundCannotBeAdded(String errorMessage){ super(errorMessage); }
	}




	private int maxHeight;

	private int streetLength;

	private int numberOfStructuresOnTheLeftSide;

	private int numberOfStructuresOnTheRightSide;


	private boolean[] occupiedLandsOnLeftSide;


	/**
	*@param 
	*/
	private Structure[] structuresOnLeftSide;


	private boolean[] occupiedLandsOnRightSide;

	private Structure[] structuresOnRightSide;


}