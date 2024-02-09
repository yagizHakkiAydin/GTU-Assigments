package com.YagizHakki;

import java.io.*;
import java.util.Scanner;



/**
*Main class that runs program
*/
public class Main
{

	/**
	*Main function that runs program
	*@param args no command line arguments are available
	*/
	public static void main( String[] args )
	{

		System.out.printf("\033[H\033[2J");

		Main m = new Main();

		m.DriverFunction();

	}


	private int mode;



	/**
	*Driver function that tests all possible actions
	*/
	public void DriverFunction()
	{
		Street streetObj = new Street(60);
		System.out.printf("To run program in editing mode,enter 1\n");
		System.out.printf("To run program in view mode,enter 2\n");
		System.out.printf("To terminate program ,enter -1\n");
		System.out.printf("Your choice --> ");

		Scanner sc = new Scanner(System.in);

		mode = sc.nextInt();


		if( mode == 1 )
		{
			runEditingMode(streetObj);
		}
		else if( mode == 2 )
		{
			runViewMode(streetObj);
		}
		else if( mode == -1 )
		{
			System.exit(0);
		}
		else
		{
			System.out.printf("\nPlease make a valid choice ");
		}



	}


	/**
	*Runs program in editing mode
	*@param streetObj street object to be modified
	*/
	public void runEditingMode( Street streetObj )
	{
		EditingMenu newMenuObj = new EditingMenu();
		newMenuObj.PrintMenu();

		int menuChoice = newMenuObj.GetChoice();

		if( menuChoice == 0)
		{
			streetObj.addPlayGroundToLeftSide();
		}
		else if( menuChoice == 1)
		{
			addHouseTest( streetObj );
		}
		else if( menuChoice == 2)
		{
			addOfficeTest( streetObj );
		}
		else if( menuChoice == 3)
		{
			addMarketTest( streetObj );
		}
		else if( menuChoice == 4)
		{
			streetObj.addHouseToLeftSide();
		}
		else if( menuChoice == 5)
		{
			streetObj.addOfficeToLeftSide();
		}
		else if( menuChoice == 6)
		{
			streetObj.addMarketToLeftSide();
		}
		else if( menuChoice == 7)
		{
			streetObj.addHouseToRightSide();
		}
		else if( menuChoice == 8)
		{
			streetObj.addOfficeToRightSide();
		}
		else if( menuChoice == 9)
		{
			streetObj.addMarketToRightSide();
		}
		else if( menuChoice == 10)
		{
			streetObj.deleteHouseFromLeftSide();
		}
		else if( menuChoice == 11)
		{
			streetObj.deleteOfficeFromLeftSide();
		}
		else if( menuChoice == 12)
		{
			streetObj.deleteMarketFromLeftSide();
		}



		else if( menuChoice == 16)
		{
			runViewMode(streetObj);
		}


		else if( menuChoice == -1 )
		{
			System.exit(0);
		}





		runEditingMode(streetObj);
	}





	/**
	*Runs program in view mode
	*@param streetObj street object to be modified
	*/
	public void runViewMode( Street streetObj )
	{
		streetObj.printStreet();


		ViewModeMenu newMenuObj = new ViewModeMenu();
		newMenuObj.PrintMenu();

		int menuChoice = newMenuObj.GetChoice();

		if( menuChoice == 1)
		{
			runEditingMode(streetObj);
		}
		else if( menuChoice == -1 )
		{
			System.exit(0);
		}
	}


	/**
	*Adds 2 predefided house and 2 user defined house objects to the street
	*@param streetObj street object to be modified
	*/
	public void addHouseTest( Street streetObj )
	{
		
		House houseToLeft = new House();

		houseToLeft.setBeginPosition( 0 );

		houseToLeft.setEndPosition( 5 );

		houseToLeft.setHeight( 10 );

		houseToLeft.setOwnerName( "John Doe" );

		houseToLeft.setColor( "Red" );

		houseToLeft.setNumberOfRooms( 22 );


		House houseToRight = new House();

		houseToRight.setBeginPosition( 3 );

		houseToRight.setEndPosition( 6 );

		houseToRight.setHeight( 4 );

		houseToRight.setOwnerName( "Jane Doe" );

		houseToRight.setColor( "Blue" );

		houseToRight.setNumberOfRooms( 10 );




		System.out.printf("\nAn house object created to be added left side with given properties below");
		System.out.printf("\n%s",houseToLeft.toString());

		System.out.printf("\n\n\n\nAn house object created to be added right side with given properties below");
		System.out.printf("\n%s",houseToRight.toString());

		System.out.printf("\n\n\n\nList of object before houses added below...\n");
		streetObj.printAllStructureInformation();
		System.out.printf("\n\n\n\nList of objects after houses added below\n");
		streetObj.addHouseToLeftSide( houseToLeft );
		streetObj.addHouseToRightSide( houseToRight );
		streetObj.printAllStructureInformation();


		System.out.printf("\n\n\n\nStreet view after houses added below\n");
		streetObj.printStreet();




		System.out.printf("\n\n\nTo add house to left with entering properties\n");
		streetObj.addHouseToLeftSide( );
		System.out.printf("\n\n\nTo add house to right with entering properties\n");
		streetObj.addHouseToRightSide( );
		//streetObj.printAllStructureInformation();


		//System.out.printf("\n\n\n\nStreet view after houses added below\n");
		//streetObj.printStreet();
	}



	/**
	*Adds 2 predefided office and 2 user defined office objects to the street
	*@param streetObj street object to be modified
	*/
	public void addOfficeTest( Street streetObj )
	{
		
		Office officeToLeft = new Office();

		officeToLeft.setBeginPosition( 2 );

		officeToLeft.setEndPosition( 5 );

		officeToLeft.setHeight( 12 );

		officeToLeft.setOwnerName( "Philip Brooklyn" );

		officeToLeft.setJobType( "Advertisement" );

		officeToLeft.setStructureType("Office");


		Office officeToRight = new Office();

		officeToRight.setBeginPosition( 4 );

		officeToRight.setEndPosition( 8 );

		officeToRight.setHeight( 7 );

		officeToRight.setOwnerName( "Douglas Jackson" );

		officeToRight.setJobType( "Software" );

		officeToRight.setStructureType("Office");




		System.out.printf("\nAn office object created to be added left side with given properties below");
		System.out.printf("\n%s",officeToLeft.toString());

		System.out.printf("\n\n\n\nAn office object created to be added right side with given properties below");
		System.out.printf("\n%s",officeToRight.toString());

		System.out.printf("\n\n\n\nList of object before offices added below...\n");
		streetObj.printAllStructureInformation();
		System.out.printf("\n\n\n\nList of objects after offices added below\n");
		streetObj.addOfficeToLeftSide( officeToLeft );
		streetObj.addOfficeToRightSide( officeToRight );
		streetObj.printAllStructureInformation();


		System.out.printf("\n\n\n\nStreet view after houses added below\n");
		streetObj.printStreet();




		System.out.printf("\n\n\nTo add office to left with entering properties\n");
		streetObj.addOfficeToLeftSide( );
		System.out.printf("\n\n\nTo add office to right with entering properties\n");
		streetObj.addOfficeToRightSide( );
		//streetObj.printAllStructureInformation();


		//System.out.printf("\n\n\n\nStreet view after offices added below\n");
		//streetObj.printStreet();

	}



	/**
	*Adds 2 predefided market and 2 user defined market objects to the street
	*@param streetObj street object to be modified
	*/
	public void addMarketTest( Street streetObj )
	{
		
		Market marketToRight = new Market();

		marketToRight.setBeginPosition( 2 );

		marketToRight.setEndPosition( 5 );

		marketToRight.setHeight( 9 );

		marketToRight.setOwnerName( "Jeffrey Red" );

		marketToRight.setOpeningTime( 7 );

		marketToRight.setClosingTime( 21 );

		marketToRight.setStructureType("Market");



		Market marketToLeft = new Market();

		marketToLeft.setBeginPosition( 9 );

		marketToLeft.setEndPosition( 14 );

		marketToLeft.setHeight( 3 );

		marketToLeft.setOwnerName( "Simon Morgan" );

		marketToLeft.setOpeningTime( 6 );

		marketToLeft.setClosingTime( 22 );

		marketToLeft.setStructureType("Market");




		System.out.printf("\nAn market object created to be added left side with given properties below");
		System.out.printf("\n%s",marketToLeft.toString());

		System.out.printf("\n\n\n\nAn market object created to be added right side with given properties below");
		System.out.printf("\n%s",marketToRight.toString());

		System.out.printf("\n\n\n\nList of object before offices added below...\n");
		streetObj.printAllStructureInformation();
		System.out.printf("\n\n\n\nList of objects after offices added below\n");
		streetObj.addMarketToLeftSide( marketToLeft );
		streetObj.addMarketToRightSide( marketToRight );
		streetObj.printAllStructureInformation();


		System.out.printf("\n\n\n\nStreet view after houses added below\n");
		streetObj.printStreet();




		System.out.printf("\n\n\nTo add market to left with entering properties\n");
		streetObj.addMarketToLeftSide( );
		System.out.printf("\n\n\nTo add market to right with entering properties\n");
		streetObj.addMarketToRightSide( );
		//streetObj.printAllStructureInformation();


		//System.out.printf("\n\n\n\nStreet view after markets added below\n");
		//streetObj.printStreet();

	}







	/**
	*Adds 2 predefided PlayGround and 2 user defined PlayGround objects to the street
	*@param streetObj street object to be modified
	*/
	public void addPlayGroundTest( Street streetObj )
	{
		
		PlayGround playGroundToRight = new PlayGround();

		playGroundToRight.setBeginPosition( 2 );

		playGroundToRight.setEndPosition( 5 );


		PlayGround playGroundToLeft = new PlayGround();

		playGroundToLeft.setBeginPosition( 9 );

		playGroundToLeft.setEndPosition( 14 );




		System.out.printf("\nAn PlayGround object created to be added left side with given properties below");
		System.out.printf("\n%s",playGroundToLeft.toString());

		System.out.printf("\n\n\n\nAn PlayGround object created to be added right side with given properties below");
		System.out.printf("\n%s",playGroundToRight.toString());

		System.out.printf("\n\n\n\nList of object before offices added below...\n");
		streetObj.printAllStructureInformation();
		System.out.printf("\n\n\n\nList of objects after offices added below\n");
		streetObj.addPlayGroundToLeftSide( playGroundToLeft );
		streetObj.addPlayGroundToRightSide( playGroundToRight );
		streetObj.printAllStructureInformation();




		System.out.printf("\n\n\n\nStreet view after houses added below\n");
		streetObj.printStreet();




		System.out.printf("\n\n\nTo add PlayGround to left with entering properties\n");
		streetObj.addPlayGroundToLeftSide( );
		System.out.printf("\n\n\nTo add PlayGround to right with entering properties\n");
		streetObj.addPlayGroundToRightSide( );
		streetObj.printAllStructureInformation();


		System.out.printf("\n\n\n\nStreet view after PlayGrounds added below\n");
		streetObj.printStreet();

	}







}