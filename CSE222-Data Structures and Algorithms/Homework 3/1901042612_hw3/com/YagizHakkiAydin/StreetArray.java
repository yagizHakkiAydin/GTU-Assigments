package com.YagizHakkiAydin;

import java.util.Scanner;

/**
*This class keeps all data about the street in simple array
*This class has functions to modify structures
*/
public class StreetArray extends Street
{

	/**
	*Default constructor,initializes the street with length of 30;
	*/
	StreetArray()
	{
		super( 30 );

	}



	/**
	*Constructor,initializes the street with length given by user;
	*@param lengthOfStreet parameter for constructor to initialize street length
	*/
	StreetArray( int lengthOfStreet )
	{


		super(lengthOfStreet);

		occupiedLandsOnLeftSide = new boolean[lengthOfStreet];

		occupiedLandsOnRightSide = new boolean[lengthOfStreet];

		numberOfStructuresOnLeftSide = 0;
		numberOfStructuresOnRightSide = 0;


		for( int countLandPosition = 0 ; countLandPosition < lengthOfStreet ; countLandPosition++ )
		{
			occupiedLandsOnLeftSide[ countLandPosition ] = false;
			occupiedLandsOnRightSide[ countLandPosition ] = false;
		}


	}



	































	/**
	*Creates a market object for wanted side of the street,but doesn't add to the street
	*@param obj used to initialize a new created market object by copying
	*@param landsOfTheChoosenSide includes boolean values for checking if the asked position is occupied,index of this array represents positions
	*@return result is a Market object
	*@throws StructureCannotBeAdded exception if object isn't added for some reason
	*/
	private Market createNewMarket( Market obj , boolean[] landsOfTheChoosenSide ) throws StructureCannotBeAdded
	{
		Scanner scannerObj = new Scanner(System.in);

		Market newMarket = new Market( obj );



		newMarket.FixBeginAndEndPositions();


		if( newMarket.GetHeight() <= 0 )
		{
			throw new StructureCannotBeAdded("Invalid value for height of Market");
		}
		else if( (newMarket.GetBeginPosition()<0) || (newMarket.GetEndPosition()<0))
		{
			throw new StructureCannotBeAdded("Market cannot be at a position less than 0");
		}
		else if( (newMarket.GetBeginPosition()>=GetStreetLength()) || (newMarket.GetEndPosition()>=GetStreetLength()))
		{
			throw new StructureCannotBeAdded("Market cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newMarket.GetBeginPosition() ; index<=newMarket.GetEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new StructureCannotBeAdded("Market cannot be at given area,because area is occupied");
				}
			}

		}


		return newMarket;
	}









	/**
	*Creates a market object for wanted side of the street with Getting properties from user,but doesn't add to the street
	*@param landsOfTheChoosenSide array that keeps positions that are occupied
	*@return Market object which is created by user
	*@throws StructureCannotBeAdded exception if object isn't added for some reason
	*/
	private Market createNewMarket( boolean[] landsOfTheChoosenSide ) throws StructureCannotBeAdded
	{
		Scanner scannerObj = new Scanner(System.in);

		Market newMarket = new Market();


		System.out.printf("Enter begin position for the Market = ");
		newMarket.SetBeginPosition( scannerObj.nextInt() );

		System.out.printf("Enter area for the Market = ");
		newMarket.SetEndPosition( newMarket.GetBeginPosition() + scannerObj.nextInt() );



		System.out.printf("Enter height for the Market = ");
		newMarket.SetHeight( scannerObj.nextInt() );


		System.out.printf("Enter opening time for the Market = ");
		newMarket.SetOpeningTime( scannerObj.nextInt() );

		System.out.printf("Enter closing time for the Market = ");
		newMarket.SetClosingTime( scannerObj.nextInt() );


		scannerObj.nextLine();

		System.out.printf("Enter owner for the Market = ");
		newMarket.SetOwnerName( scannerObj.nextLine() );


		newMarket.FixBeginAndEndPositions();


		if( newMarket.GetHeight() <= 0 )
		{
			throw new StructureCannotBeAdded("Invalid value for height of Market");
		}
		else if( (newMarket.GetBeginPosition()<0) || (newMarket.GetEndPosition()<0))
		{
			throw new StructureCannotBeAdded("Market cannot be at a position less than 0");
		}
		else if( (newMarket.GetBeginPosition()>=GetStreetLength()) || (newMarket.GetEndPosition()>=GetStreetLength()))
		{
			throw new StructureCannotBeAdded("Market cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newMarket.GetBeginPosition() ; index<=newMarket.GetEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new StructureCannotBeAdded("Market cannot be at given area,because area is occupied");
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
		catch( StructureCannotBeAdded e )
		{
			System.out.printf("%s , Market could not be added...\n" , e.getMessage());
		}
	}




	/**
	*Adds a new market to the left side of the street,Gets position and height information from the 'obj' and adds new Market 
	*object to the 'structuresOnLeftSide' array.Occupied lands are marked at 'occupiedLandsOnLeftSide' array.
	*@param obj object to be copied and it's copy Gets added to the 'structuresOnLeftSide' array.
	*/
	public void addMarketToLeftSide( Market obj )
	{

		try
		{
			Market newMarket = createNewMarket(obj,occupiedLandsOnLeftSide);


			if( newMarket.GetHeight() > GetMaxHeight() )
			{
				SetMaxHeight(newMarket.GetHeight());
			}


			for( int index=newMarket.GetBeginPosition() ; index<=newMarket.GetEndPosition() ; index++ )
			{
				occupiedLandsOnLeftSide[index] = true;
			}

			numberOfStructuresOnLeftSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnLeftSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnLeftSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnLeftSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnLeftSide - 1 ] = newMarket;

			structuresOnLeftSide = newStructuresArray;
		}
		catch( StructureCannotBeAdded e )
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
		catch( StructureCannotBeAdded e )
		{
			System.out.printf("%s , Market could not be added...\n" , e.getMessage());
		}
	}




	/**
	*Adds a new market to the Right side of the street,Gets position and height information from the 'obj' and adds new Market 
	*object to the 'structuresOnRightSide' array.Occupied lands are marked at 'occupiedLandsOnRightSide' array.
	*@param obj object to be copied and it's copy Gets added to the 'structuresOnRightSide' array.
	*/
	public void addMarketToRightSide( Market obj )
	{

		try
		{
			Market newMarket = createNewMarket(obj,occupiedLandsOnRightSide);

			if( newMarket.GetHeight() > GetMaxHeight() )
			{
				SetMaxHeight(newMarket.GetHeight());
			}

			for( int index=newMarket.GetBeginPosition() ; index<=newMarket.GetEndPosition() ; index++ )
			{
				occupiedLandsOnRightSide[index] = true;
			}

			numberOfStructuresOnRightSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnRightSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnRightSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnRightSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnRightSide - 1 ] = newMarket;

			structuresOnRightSide = newStructuresArray;

		}
		catch( StructureCannotBeAdded e )
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
		catch( StructureCannotBeAdded e )
		{
			System.out.printf("%s , Office could not be added...\n" , e.getMessage());
		}
	}



	/**
	*Adds a new Office to the Left side of the street,Gets position and height information from the 'obj' and adds new Office 
	*object to the 'structuresOnLeftSide' array.Occupied lands are marked at 'occupiedLandsOnLeftSide' array.
	*@param obj object to be copied and it's copy Gets added to the 'structuresOnLeftSide' array.
	*/
	public void addOfficeToLeftSide( Office obj )
	{

		try
		{
			Office newOffice = createNewOffice(obj,occupiedLandsOnLeftSide);


			if( newOffice.GetHeight() > GetMaxHeight() )
			{
				SetMaxHeight( newOffice.GetHeight() );
			}


			for( int index=newOffice.GetBeginPosition() ; index<=newOffice.GetEndPosition() ; index++ )
			{
				occupiedLandsOnLeftSide[index] = true;
			}

			numberOfStructuresOnLeftSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnLeftSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnLeftSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnLeftSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnLeftSide - 1 ] = newOffice;

			structuresOnLeftSide = newStructuresArray;
		}
		catch( StructureCannotBeAdded e )
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
		catch( StructureCannotBeAdded e )
		{
			System.out.printf("%s , Office could not be added...\n" , e.getMessage());
		}
	}



	/**
	*Adds a new Office to the Right side of the street,Gets position and height information from the 'obj' and adds new Office 
	*object to the 'structuresOnRightSide' array.Occupied lands are marked at 'occupiedLandsOnRightSide' array.
	*@param obj object to be copied and it's copy Gets added to the 'structuresOnRightSide' array.
	*/
	public void addOfficeToRightSide( Office obj )
	{

		try
		{
			Office newOffice = createNewOffice(obj,occupiedLandsOnRightSide);

			if( newOffice.GetHeight() > GetMaxHeight() )
			{
				SetMaxHeight( newOffice.GetHeight() );
			}

			for( int index=newOffice.GetBeginPosition() ; index<=newOffice.GetEndPosition() ; index++ )
			{
				occupiedLandsOnRightSide[index] = true;
			}

			numberOfStructuresOnRightSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnRightSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnRightSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnRightSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnRightSide - 1 ] = newOffice;

			structuresOnRightSide = newStructuresArray;

		}
		catch( StructureCannotBeAdded e )
		{
			System.out.printf("%s , Office could not be added...\n" , e.getMessage());
		}
	}




	/**
	*Creates a office object for wanted side of the street,but doesn't add to the street
	*@param obj used to initialize a new created office object by copying
	*@param landsOfTheChoosenSide includes boolean values for checking if the asked position is occupied,index of this array represents positions
	*@return copy of given office object as parameter
	*@throws StructureCannotBeAdded exception if object isn't added for some reason
	*/
	public Office createNewOffice( Office obj , boolean[] landsOfTheChoosenSide ) throws StructureCannotBeAdded
	{
		Office newOffice = new Office( obj );

		newOffice.FixBeginAndEndPositions();


		if( newOffice.GetHeight() <= 0 )
		{
			throw new StructureCannotBeAdded("Invalid value for height of Office");
		}
		else if( (newOffice.GetBeginPosition()<0) || (newOffice.GetEndPosition()<0))
		{
			throw new StructureCannotBeAdded("Office cannot be at a position less than 0");
		}
		else if( newOffice.GetBeginPosition() == newOffice.GetEndPosition() )
		{
			throw new StructureCannotBeAdded("Office area can't be 0");
		}
		else if( (newOffice.GetBeginPosition()>=GetStreetLength()) || (newOffice.GetEndPosition()>=GetStreetLength()))
		{
			throw new StructureCannotBeAdded("Office cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newOffice.GetBeginPosition() ; index<=newOffice.GetEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new StructureCannotBeAdded("Office cannot be at given area,because area is occupied");
				}
			}

		}


		return newOffice;
	}










	/**
	*Creates a Office object for wanted side of the street with Getting properties from user,but doesn't add to the street
	*@param landsOfTheChoosenSide array that keeps positions that are occupied
	*@return Office object which is created by user
	*@throws StructureCannotBeAdded exception if object isn't added for some reason
	*/
	private Office createNewOffice( boolean[] landsOfTheChoosenSide ) throws StructureCannotBeAdded
	{
		Scanner scannerObj = new Scanner(System.in);

		Office newOffice = new Office();


		System.out.printf("Enter begin position for the Office = ");
		newOffice.SetBeginPosition( scannerObj.nextInt() );

		System.out.printf("Enter area for the Office = ");
		newOffice.SetEndPosition( newOffice.GetBeginPosition() + scannerObj.nextInt() );



		System.out.printf("Enter height for the Office = ");
		newOffice.SetHeight( scannerObj.nextInt() );

		System.out.printf("Enter job type for the Office = ");
		newOffice.SetJobType( scannerObj.nextLine() );

		scannerObj.nextLine();

		System.out.printf("Enter owner for the Office = ");
		newOffice.SetOwnerName( scannerObj.nextLine() );


		newOffice.FixBeginAndEndPositions();


		if( newOffice.GetHeight() <= 0 )
		{
			throw new StructureCannotBeAdded("Invalid value for height of Office");
		}
		else if( (newOffice.GetBeginPosition()<0) || (newOffice.GetEndPosition()<0))
		{
			throw new StructureCannotBeAdded("Office cannot be at a position less than 0");
		}
		else if( (newOffice.GetBeginPosition()>=GetStreetLength()) || (newOffice.GetEndPosition()>=GetStreetLength()))
		{
			throw new StructureCannotBeAdded("Office cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newOffice.GetBeginPosition() ; index<=newOffice.GetEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new StructureCannotBeAdded("Office cannot be at given area,because area is occupied");
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
		catch( StructureCannotBeAdded e )
		{
			System.out.printf("%s , House could not be added...\n" , e.getMessage());
		}

	}


	/**
	*Adds a new House to the Left side of the street,Gets position and height information from the 'obj' and adds new House 
	*object to the 'structuresOnLeftSide' array.Occupied lands are marked at 'occupiedLandsOnLeftSide' array.
	*@param obj object to be copied and it's copy Gets added to the 'structuresOnLeftSide' array.
	*/
	public void addHouseToLeftSide( House obj )
	{


		try
		{
			House newHouse = createNewHouse(obj,occupiedLandsOnLeftSide);


			if( newHouse.GetHeight() > GetMaxHeight() )
			{
				SetMaxHeight( newHouse.GetHeight() );
			}


			for( int index=newHouse.GetBeginPosition() ; index<=newHouse.GetEndPosition() ; index++ )
			{
				occupiedLandsOnLeftSide[index] = true;
			}

			numberOfStructuresOnLeftSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnLeftSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnLeftSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnLeftSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnLeftSide - 1 ] = newHouse;

			structuresOnLeftSide = newStructuresArray;
		}
		catch( StructureCannotBeAdded e )
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
		catch( StructureCannotBeAdded e )
		{
			System.out.printf("%s , House could not be added...\n" , e.getMessage());
		}

	}


	/**
	*Adds a new House to the Right side of the street,Gets position and height information from the 'obj' and adds new House 
	*object to the 'structuresOnRightSide' array.Occupied lands are marked at 'occupiedLandsOnRightSide' array.
	*@param obj object to be copied and it's copy Gets added to the 'structuresOnRightSide' array.
	*/
	public void addHouseToRightSide( House obj )
	{

		try
		{
			House newHouse = createNewHouse(obj,occupiedLandsOnRightSide);

			if( newHouse.GetHeight() > GetMaxHeight() )
			{
				SetMaxHeight( newHouse.GetHeight() );
			}

			for( int index=newHouse.GetBeginPosition() ; index<=newHouse.GetEndPosition() ; index++ )
			{
				occupiedLandsOnRightSide[index] = true;
			}

			numberOfStructuresOnRightSide += 1;

			Structure[] newStructuresArray = new Structure[ numberOfStructuresOnRightSide ];

			for( int structuresArrayIndex=0 ; structuresArrayIndex<(numberOfStructuresOnRightSide-1) ; structuresArrayIndex++ )
			{
				newStructuresArray[structuresArrayIndex] = structuresOnRightSide[structuresArrayIndex];
			}

			newStructuresArray[ numberOfStructuresOnRightSide - 1 ] = newHouse;

			structuresOnRightSide = newStructuresArray;

		}
		catch( StructureCannotBeAdded e )
		{
			System.out.printf("%s , House could not be added...\n" , e.getMessage());
		}
	}





	/**
	*Creates a Office object for wanted side of the street with Getting properties from user,but doesn't add to the street
	*@param landsOfTheChoosenSide array that keeps positions that are occupied
	*@return Office object which is created by user
	*@throws StructureCannotBeAdded exception if object isn't added for some reason
	*/
	private House createNewHouse( boolean[] landsOfTheChoosenSide ) throws StructureCannotBeAdded
	{
		Scanner scannerObj = new Scanner(System.in);

		House newHouse = new House();


		System.out.printf("Enter begin position for the house = ");
		newHouse.SetBeginPosition( scannerObj.nextInt() );

		System.out.printf("Enter area for the house = ");
		newHouse.SetEndPosition( newHouse.GetBeginPosition() + scannerObj.nextInt() );



		System.out.printf("Enter height for the house = ");
		newHouse.SetHeight( scannerObj.nextInt() );

		System.out.printf("Enter number of the rooms  for the house = ");
		newHouse.SetNumberOfRooms( scannerObj.nextInt() );

		scannerObj.nextLine();

		System.out.printf("Enter owner for the house = ");
		newHouse.SetOwnerName( scannerObj.nextLine() );

		System.out.printf("Enter color for the house = ");
		newHouse.SetColor( scannerObj.nextLine() );

		newHouse.FixBeginAndEndPositions();


		if( newHouse.GetHeight() <= 0 )
		{
			throw new StructureCannotBeAdded("Invalid value for height of house");
		}
		else if( (newHouse.GetBeginPosition()<0) || (newHouse.GetEndPosition()<0))
		{
			throw new StructureCannotBeAdded("House cannot be at a position less than 0");
		}
		else if( (newHouse.GetBeginPosition()>=GetStreetLength()) || (newHouse.GetEndPosition()>=GetStreetLength()))
		{
			throw new StructureCannotBeAdded("House cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newHouse.GetBeginPosition() ; index<=newHouse.GetEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new StructureCannotBeAdded("House cannot be at given area,because area is occupied");
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
	*@throws StructureCannotBeAdded exception if object isn't added for some reason
	*/
	private House createNewHouse( House obj ,  boolean[] landsOfTheChoosenSide ) throws StructureCannotBeAdded
	{

		House newHouse = new House( obj );




		if( newHouse.GetHeight() <= 0 )
		{
			throw new StructureCannotBeAdded("Invalid value for height of house");
		}
		else if( (newHouse.GetBeginPosition()<0) || (newHouse.GetEndPosition()<0))
		{
			throw new StructureCannotBeAdded("House cannot be at a position less than 0");
		}
		else if( (newHouse.GetBeginPosition()>=GetStreetLength()) || (newHouse.GetEndPosition()>=GetStreetLength()))
		{
			throw new StructureCannotBeAdded("House cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newHouse.GetBeginPosition() ; index<=newHouse.GetEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new StructureCannotBeAdded("House cannot be at given area,because area is occupied");
				}
			}

		}

		return newHouse;
	}

		

































	/**
	*Creates a new PlayGround object with user input
	*@return new created PlayGround object
	*/
	private PlayGround createNewPlayGround( boolean[] landsOfTheChoosenSide ) throws StructureCannotBeAdded
	{
		Scanner scannerObj = new Scanner(System.in);

		PlayGround newPlayGround = new PlayGround();


		System.out.printf("Enter begin position for the PlayGround = ");
		newPlayGround.SetBeginPosition( scannerObj.nextInt() );

		System.out.printf("Enter area for the PlayGround = ");
		newPlayGround.SetEndPosition( newPlayGround.GetBeginPosition() + scannerObj.nextInt() );

		newPlayGround.FixBeginAndEndPositions();


		if( (newPlayGround.GetBeginPosition()<0) || (newPlayGround.GetEndPosition()<0))
		{
			throw new StructureCannotBeAdded("PlayGround cannot be at a position less than 0");
		}
		else if( (newPlayGround.GetBeginPosition()>=GetStreetLength()) || (newPlayGround.GetEndPosition()>=GetStreetLength()))
		{
			throw new StructureCannotBeAdded("PlayGround cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newPlayGround.GetBeginPosition() ; index<=newPlayGround.GetEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new StructureCannotBeAdded("PlayGround cannot be at given area,because area is occupied");
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
	private PlayGround createNewPlayGround( PlayGround obj ,  boolean[] landsOfTheChoosenSide ) throws StructureCannotBeAdded
	{

		PlayGround newPlayGround = new PlayGround( obj );




		if( (newPlayGround.GetBeginPosition()<0) || (newPlayGround.GetEndPosition()<0))
		{
			throw new StructureCannotBeAdded("PlayGround cannot be at a position less than 0");
		}
		else if( (newPlayGround.GetBeginPosition()>=GetStreetLength()) || (newPlayGround.GetEndPosition()>=GetStreetLength()))
		{
			throw new StructureCannotBeAdded("PlayGround cannot be at a position more than length of the street");
		}
		else
		{
			for( int index=newPlayGround.GetBeginPosition() ; index<=newPlayGround.GetEndPosition() ; index++ )
			{
				if( landsOfTheChoosenSide[index] == true )
				{
					throw new StructureCannotBeAdded("PlayGround cannot be at given area,because area is occupied");
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

		for( int i=0;i<numberOfStructuresOnLeftSide;i++ )
		{
			if( structuresOnLeftSide[i] instanceof House )
			{
				h = (House)structuresOnLeftSide[i];
				if( h.GetOwnerName().equals( choice ))
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

		for( int i=0;i<numberOfStructuresOnLeftSide;i++ )
		{
			if( structuresOnLeftSide[i] instanceof Office )
			{
				o = (Office)structuresOnLeftSide[i];
				if( o.GetJobType().equals(choice) )
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


			for( int i=0;i<numberOfStructuresOnLeftSide;i++ )
			{
				if( structuresOnLeftSide[i] instanceof Market )
				{
					m = (Market)structuresOnLeftSide[i];
					if( m.GetOpeningTime() == openingTimeChoice  &&  m.GetClosingTime() == closingTimeChoice )
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

		for( int i=0;i<numberOfStructuresOnRightSide;i++ )
		{
			if( structuresOnRightSide[i] instanceof House )
			{
				h = (House)structuresOnRightSide[i];
				if( h.GetOwnerName().equals(choice) )
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

			for( int i=0;i<numberOfStructuresOnRightSide;i++ )
			{
				if( structuresOnRightSide[i] instanceof Office )
				{
					o = (Office)structuresOnRightSide[i];
					if( o.GetJobType().equals(choice) )
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

			for( int i=0;i<numberOfStructuresOnRightSide;i++ )
			{
				if( structuresOnRightSide[i] instanceof Market )
				{
					m = (Market)structuresOnRightSide[i];
					if( m.GetOpeningTime() == openingTimeChoice  &&  m.GetClosingTime() == closingTimeChoice )
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
			numberOfStructuresOnLeftSide--;
			numberOfStructures = numberOfStructuresOnLeftSide;
		}
		else if( side == "right" )
		{
			occupiedLandsArray = occupiedLandsOnRightSide;
			structuresArray = structuresOnRightSide;
			numberOfStructuresOnRightSide--;
			numberOfStructures = numberOfStructuresOnRightSide;
		}

		Structure[] newStructuresArray = new Structure[ numberOfStructures ];



		for( int i=structuresArray[buildingIndex].GetBeginPosition();i<=structuresArray[buildingIndex].GetEndPosition() ; i++ )
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
				System.out.printf("Street view below...\n\n");
		printStreet();
		System.out.printf( "All structures on the left side are listed below...\n" );
		for( int i=0;i<numberOfStructuresOnLeftSide;i++ )
		{
			 System.out.printf( structuresOnLeftSide[i].toString() );
		}

		System.out.printf( "All structures on the right side are listed below...\n" );
		for( int i=0;i<numberOfStructuresOnRightSide;i++ )
		{
			System.out.printf( structuresOnRightSide[i].toString() );
		}
	}







	/**
	*Prints everything about the street
	*/
	public void printStreet()
	{

		String[] streetView = GetStreetView();
		for( int i=0;i<GetMaxHeight()+2;i++ )
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
	private final String[] GetEmptyStreetView()
	{
		String[] emptyStreetView;

		String emptyLine = "";
		String groundLine = "";



		emptyStreetView = new String[GetMaxHeight()+2];


		for( int countStreetLength=0; countStreetLength<=GetStreetLength()+3 ; countStreetLength++ )
		{
			emptyLine += " ";
			groundLine += "-";
		}



		for( int index=0;index<GetMaxHeight()+1;index++ )
		{
			emptyStreetView[index] = emptyLine;
		}

		emptyStreetView[GetMaxHeight()+1] = groundLine;

		return emptyStreetView;
	}








	/**
	*Sets building walls on string array
	*@return finalized street view(not silhouette)
	*/
	public final String[] GetStreetView()
	{

		String[] streetView = setBuildingCeilings();

		for( int index=0;index<numberOfStructuresOnLeftSide;index++ )
		{
			if( !( structuresOnLeftSide[index] instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)structuresOnLeftSide[index]).GetHeight();

				for( int i=1;i<=buildingHeight;i++ )
				{
					streetView[ GetMaxHeight() - i + 1 ] = addCharToIndex( streetView[ GetMaxHeight() - i + 1] , structuresOnLeftSide[index].GetBeginPosition() , '|' );
					streetView[ GetMaxHeight() - i + 1 ] = addCharToIndex( streetView[ GetMaxHeight() - i + 1] , structuresOnLeftSide[index].GetEndPosition() , '|' );
				}
			}
		}	


		for( int index=0;index<numberOfStructuresOnRightSide;index++ )
		{
			if( !( structuresOnRightSide[index] instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)structuresOnRightSide[index]).GetHeight();

				for( int i=1;i<=buildingHeight;i++ )
				{
					streetView[ GetMaxHeight() - i + 1 ] = addCharToIndex( streetView[ GetMaxHeight() - i + 1] , structuresOnRightSide[index].GetBeginPosition() , '|' );
					streetView[ GetMaxHeight() - i + 1 ] = addCharToIndex( streetView[ GetMaxHeight() - i + 1] , structuresOnRightSide[index].GetEndPosition()+1 , '|' );
				}
			}
		}


		return streetView;
	}





	/**
	*Returns street silhouette as string array
	*@return string array that represents street silhouette
	*/
	private final String[] GetSilhouette()
	{

		String[] silhouette = GetStreetView();


		for(int height = 0; height <= GetMaxHeight() ; height++)
		{
			for(int position=0;position<GetStreetLength();position++)
			{
				//for(int buildingIndex=0;buildingIndex<structuresOnRightSide;buildingIndex++)
				{

				}
			}
		}


		return silhouette;
	}









	/**
	*Gets string array of the street with 'GetEmptyStreetView()' and sets ceilings of the buildings
	*@return street view as string arrat
	*/
	private final String[] setBuildingCeilings()
	{
		String[] ceilings = GetEmptyStreetView();

		for( int index=0;index<numberOfStructuresOnLeftSide;index++ )
		{
			if( !( structuresOnLeftSide[index] instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)structuresOnLeftSide[index]).GetHeight();

				for( int i=structuresOnLeftSide[index].GetBeginPosition();i<=structuresOnLeftSide[index].GetEndPosition();i++ )
				{
					ceilings[ GetMaxHeight() - buildingHeight ] = addCharToIndex( ceilings[ GetMaxHeight() - buildingHeight] , i , '_' );
					ceilings[ GetMaxHeight() - buildingHeight ] = addCharToIndex( ceilings[ GetMaxHeight() - buildingHeight] , i , '_' );
				}
			}
		}	


		for( int index=0;index<numberOfStructuresOnRightSide;index++ )
		{
			if( !( structuresOnRightSide[index] instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)structuresOnRightSide[index]).GetHeight();

				for( int i=structuresOnRightSide[index].GetBeginPosition();i<=structuresOnRightSide[index].GetEndPosition();i++ )
				{
					ceilings[ GetMaxHeight() - buildingHeight ] = addCharToIndex( ceilings[ GetMaxHeight() - buildingHeight] , i , '_' );
					ceilings[ GetMaxHeight() - buildingHeight ] = addCharToIndex( ceilings[ GetMaxHeight() - buildingHeight] , i , '_' );
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
		result *=GetMaxHeight();
		result *=GetStreetLength();
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











	/**
	*Asks user properties and adds market created wit these properties
	*@param side side that market will be added
	*/
	@Override
	public void AddMarket( String side ) throws StructureCannotBeAdded
	{
		if( side.equals("left") )
		{
			addMarketToLeftSide();
		}
		else
		{
			addMarketToRightSide();
		}
	}


	/**
	*Asks user properties and adds house created wit these properties
	*@param side side that house will be added
	*/
	@Override
	public void AddHouse( String side ) throws StructureCannotBeAdded
	{
		if( side.equals("left") )
		{
			addHouseToLeftSide();
		}
		else
		{
			addHouseToRightSide();	
		}
	}



	/**
	*Asks user properties and adds office created wit these properties
	*@param side side that office will be added
	*/
	@Override
	public void AddOffice( String side ) throws StructureCannotBeAdded
	{
		if( side.equals("left") )
		{
			addOfficeToLeftSide();
		}
		else
		{
			addOfficeToRightSide();	
		}
	}



	/**
	*Takes and market referance and appends it to the street
	*@param side side that market will be added
	*@param obj market object referance to be appended
	*/
	@Override
	public void AddMarket( String side , Market obj ) throws StructureCannotBeAdded
	{
		if( side.equals("left") )
		{
			addMarketToLeftSide(obj);
		}
		else
		{
			addMarketToRightSide(obj);
		}
	}



	/**
	*Takes and house referance and appends it to the street
	*@param side side that house will be added
	*@param obj house object referance to be appended
	*/
	@Override
	public void AddHouse( String side , House obj ) throws StructureCannotBeAdded
	{
		if( side.equals("left") )
		{
			addHouseToLeftSide(obj);
		}
		else
		{
			addHouseToRightSide(obj);	
		}
	}


	/**
	*Takes and office referance and appends it to the street
	*@param side side that office will be added
	*@param obj office object referance to be appended
	*/
	@Override
	public void AddOffice( String side , Office obj ) throws StructureCannotBeAdded
	{
		if( side.equals("left") )
		{
			addOfficeToLeftSide(obj);
		}
		else
		{
			addOfficeToRightSide(obj);
		}
	}







	protected void ThrowExceptionİfStructureCannotBeAdded( String side , Structure obj ) throws StructureCannotBeAdded
	{
		if( !side.equals("left") && !side.equals("right") )
		{
			throw new StructureCannotBeAdded();
		}
		else if( (obj.GetBeginPosition() < 0) || (obj.GetEndPosition() > GetStreetLength()) )
		{
			throw new StructureCannotBeAdded();
		}
		else
		{
			for( int positionIndex = obj.GetBeginPosition(); positionIndex < obj.GetEndPosition() ; positionIndex++ )
			{
				if( side.equals("left") && (occupiedLandsOnLeftSide[positionIndex] == true) )
				{
					throw new StructureCannotBeAdded();
				}
				else if( side.equals("right") && (occupiedLandsOnRightSide[positionIndex] == true) )
				{
					throw new StructureCannotBeAdded();
				}
			}
		}
	}




	public void deleteMarket( String side )
	{
		if( side.equals("left") )
		{
			deleteMarketFromLeftSide();
		}
		else
		{
			deleteMarketFromRightSide();
		}
	}
	public void deleteHouse( String side )
	{
		if( side.equals("left") )
		{
			deleteHouseFromLeftSide();
		}
		else
		{
			deleteHouseFromRightSide();	
		}
	}
	public void deleteOffice( String side )
	{
		if( side.equals("left") )
		{
			deleteOfficeFromLeftSide();
		}
		else
		{
			deleteOfficeFromRightSide();
		}
	}

















	private Structure[] structuresOnLeftSide;


	private Structure[] structuresOnRightSide;


}