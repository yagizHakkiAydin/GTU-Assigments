package com.YagizHakkiAydin;

import java.io.*;
import java.util.Scanner;



/**
*Main class that runs program
*/
public class Main
{
	public static void main( String[] args )
	{
 		System.out.printf("\033[H\033[2J");

		Main m = new Main();

		m.DriverFunction();


	}


	public void DriverFunction()
	{
		Street streetObj = new StreetArrayList();;

		int choice = -1;

		Scanner sc = new Scanner(System.in);

		System.out.printf("\033[H\033[2J");
		System.out.printf("To start program in Simple Array mode,enter 1\n");
		System.out.printf("To start program in ArrayList mode,enter 2\n");
		System.out.printf("To start program in LinkedList mode,enter 3\n");
		System.out.printf("To start program in StreetLDLinkedList mode,enter 4\n");
		System.out.printf("To start program in time test mode,enter 5\n");

		System.out.printf("Your choice -->");
		choice = sc.nextInt();


		if( choice == 1 )
		{
			streetObj = new StreetArray();
			streetObj = (StreetArray)streetObj;
		}
		else if( choice == 2 )
		{
			streetObj = new StreetArrayList();
			streetObj = (StreetArrayList)streetObj;
		}
		else if( choice == 3 )
		{
			streetObj = new StreetLinkedList();
			streetObj = (StreetLinkedList)streetObj;
		}
		else if( choice == 4 )
		{
			streetObj = new StreetLDLinkedList();
			streetObj = (StreetLDLinkedList)streetObj;
		}
		else if( choice == 5 )
		{
			timeTest(1);
		}
		else
		{
			System.exit(1);
		}









		System.out.printf("To run program in editing mode,enter 1\n");
		System.out.printf("To run program in view mode,enter 2\n");
		System.out.printf("To terminate program ,enter -1\n");
		System.out.printf("Your choice --> ");

		int mode;
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

		try
		{
			if( menuChoice == 0)
			{
				PlayGround p = new PlayGround();
				streetObj.AddPlayGround("left",p);
			}
			else if( menuChoice == 1)
			{
				AddHouseTest( streetObj );
			}
			else if( menuChoice == 2)
			{
				AddOfficeTest( streetObj );
			}
			else if( menuChoice == 3)
			{
				AddMarketTest( streetObj );
			}
			else if( menuChoice == 4)
			{
				streetObj.AddHouse("left");
			}
			else if( menuChoice == 5)
			{
				streetObj.AddOffice("left");
			}
			else if( menuChoice == 6)
			{
				streetObj.AddMarket("left");
			}
			else if( menuChoice == 7)
			{
				streetObj.AddHouse("right");
			}
			else if( menuChoice == 8)
			{
				streetObj.AddOffice("right");
			}
			else if( menuChoice == 9)
			{
				streetObj.AddMarket("right");
			}
			else if( menuChoice == 10)
			{
				streetObj.deleteHouse("left");
			}
			else if( menuChoice == 11)
			{
				streetObj.deleteOffice("left");
			}
			else if( menuChoice == 12)
			{
				streetObj.deleteMarket("left");
			}
			else if( menuChoice == 13)
			{
				streetObj.deleteHouse("right");
			}
			else if( menuChoice == 14)
			{
				streetObj.deleteOffice("right");
			}
			else if( menuChoice == 15)
			{
				streetObj.deleteMarket("right");
			}
			else if( menuChoice == 16)
			{
				runViewMode(streetObj);
			}
			else if( menuChoice == -1 )
			{
				System.exit(0);
			}
		}
		catch( Street.StructureCannotBeAdded ex )
		{

		}





		runEditingMode(streetObj);
	}




	/**
	*Runs program in view mode
	*@param streetObj street object to be modified
	*/
	public void runViewMode( Street streetObj )
	{


		streetObj.printAllStructureInformation();


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
	public void AddHouseTest( Street streetObj )
	{
		try
			{
			House houseToLeft = new House();

			houseToLeft.SetBeginPosition( 0 );

			houseToLeft.SetEndPosition( 5 );

			houseToLeft.SetHeight( 10 );

			houseToLeft.SetOwnerName( "John Doe" );

			houseToLeft.SetColor( "Red" );

			houseToLeft.SetNumberOfRooms( 22 );


			House houseToRight = new House();

			houseToRight.SetBeginPosition( 3 );

			houseToRight.SetEndPosition( 6 );

			houseToRight.SetHeight( 4 );

			houseToRight.SetOwnerName( "Jane Doe" );

			houseToRight.SetColor( "Blue" );

			houseToRight.SetNumberOfRooms( 10 );




			System.out.printf("\nAn house object created to be added left side with given properties below");
			System.out.printf("\n%s",houseToLeft.toString());

			System.out.printf("\n\n\n\nAn house object created to be added right side with given properties below");
			System.out.printf("\n%s",houseToRight.toString());

			streetObj.AddHouse("left", houseToLeft );
			streetObj.AddHouse("right", houseToRight );

		}
		catch( Street.StructureCannotBeAdded ex )
		{

		}
	}



	/**
	*Adds 2 predefided office and 2 user defined office objects to the street
	*@param streetObj street object to be modified
	*/
	public void AddOfficeTest( Street streetObj )
	{
		try{
			Office officeToLeft = new Office();

			officeToLeft.SetBeginPosition( 2 );

			officeToLeft.SetEndPosition( 5 );

			officeToLeft.SetHeight( 12 );

			officeToLeft.SetOwnerName( "Philip Brooklyn" );

			officeToLeft.SetJobType( "Advertisement" );




			Office officeToRight = new Office();

			officeToRight.SetBeginPosition( 4 );

			officeToRight.SetEndPosition( 8 );

			officeToRight.SetHeight( 7 );

			officeToRight.SetOwnerName( "Douglas Jackson" );

			officeToRight.SetJobType( "Software" );





			System.out.printf("\nAn office object created to be added left side with given properties below");
			System.out.printf("\n%s",officeToLeft.toString());

			System.out.printf("\n\n\n\nAn office object created to be added right side with given properties below");
			System.out.printf("\n%s",officeToRight.toString());


			streetObj.AddOffice( "left" , officeToLeft );
			streetObj.AddOffice( "right" , officeToRight );

		}
		catch( Street.StructureCannotBeAdded ex )
		{

		}

	}



	/**
	*Adds 2 predefided market and 2 user defined market objects to the street
	*@param streetObj street object to be modified
	*/
	public void AddMarketTest( Street streetObj )
	{
		try
		{
			Market marketToRight = new Market();

			marketToRight.SetBeginPosition( 2 );

			marketToRight.SetEndPosition( 5 );

			marketToRight.SetHeight( 9 );

			marketToRight.SetOwnerName( "Jeffrey Red" );

			marketToRight.SetOpeningTime( 7 );

			marketToRight.SetClosingTime( 21 );




			Market marketToLeft = new Market();

			marketToLeft.SetBeginPosition( 9 );

			marketToLeft.SetEndPosition( 14 );

			marketToLeft.SetHeight( 3 );

			marketToLeft.SetOwnerName( "Simon Morgan" );

			marketToLeft.SetOpeningTime( 6 );

			marketToLeft.SetClosingTime( 22 );





			System.out.printf("\nAn market object created to be added left side with given properties below");
			System.out.printf("\n%s",marketToLeft.toString());

			System.out.printf("\n\n\n\nAn market object created to be added right side with given properties below");
			System.out.printf("\n%s",marketToRight.toString());

			streetObj.AddMarket( "left" , marketToLeft );
			streetObj.AddMarket( "right" , marketToRight );


		}
		catch( Street.StructureCannotBeAdded ex )
		{

		}

	}







	/**
	*Adds 2 predefided PlayGround and 2 user defined PlayGround objects to the street
	*@param streetObj street object to be modified
	*/
	public void AddPlayGroundTest( Street streetObj )
	{
		try
		{	
			PlayGround playGroundToRight = new PlayGround();

			playGroundToRight.SetBeginPosition( 2 );

			playGroundToRight.SetEndPosition( 5 );


			PlayGround playGroundToLeft = new PlayGround();

			playGroundToLeft.SetBeginPosition( 9 );

			playGroundToLeft.SetEndPosition( 14 );




			System.out.printf("\nAn PlayGround object created to be added left side with given properties below");
			System.out.printf("\n%s",playGroundToLeft.toString());

			System.out.printf("\n\n\n\nAn PlayGround object created to be added right side with given properties below");
			System.out.printf("\n%s",playGroundToRight.toString());

			streetObj.AddPlayGround("left", playGroundToLeft );
			streetObj.AddPlayGround("right", playGroundToRight );




			System.out.printf("\n\n\n\nStreet view after houses added below\n");
			streetObj.printStreet();




			System.out.printf("\n\n\n\nStreet view after PlayGrounds added below\n");
			streetObj.printStreet();
		}
		catch( Street.StructureCannotBeAdded ex )
		{

		}

	}



	void timeTest(int multiplier)
	{

		if( multiplier >= 1000 )
		{
			return;
		}

		else
		{
			StreetArray stArr=new StreetArray(1000*multiplier);
			StreetArrayList stArrL=new StreetArrayList(1000*multiplier);
			StreetLinkedList stLL=new StreetLinkedList(1000*multiplier);
			StreetLDLinkedList stLDLL=new StreetLDLinkedList(1000*multiplier);


			House testHouse = new House();

			testHouse.SetBeginPosition( 0 );

			testHouse.SetEndPosition( 1 );

			testHouse.SetHeight( 10 );

			testHouse.SetOwnerName( "John Doe" );

			testHouse.SetColor( "Red" );

			testHouse.SetNumberOfRooms( 22 );



			long startTimeOne = System.nanoTime();
			for( int i=0;i<100*multiplier;i++ )
			{
				House tempHouse = new House(testHouse);
				tempHouse.SetBeginPosition( tempHouse.GetBeginPosition() + 2*i );
				tempHouse.SetEndPosition( tempHouse.GetEndPosition() + 2*i );
				try
				{
					stArr.AddHouse( "left" , tempHouse );
				}
				catch( Street.StructureCannotBeAdded e )
				{

				}
			}

			long endTimeOne   = System.nanoTime();
			long totalTimeOne = endTimeOne - startTimeOne;
			System.out.printf("%d time elapsed for multiplier %d for simple array \n",totalTimeOne,multiplier);



			long startTimeTwo = System.nanoTime();
			for( int i=0;i<100*multiplier;i++ )
			{
				House tempHouse = new House(testHouse);
				tempHouse.SetBeginPosition( tempHouse.GetBeginPosition() + 2*i );
				tempHouse.SetEndPosition( tempHouse.GetEndPosition() + 2*i );
				try
				{
					stArrL.AddHouse( "left" , tempHouse );
				}
				catch( Street.StructureCannotBeAdded e )
				{

				}
			}

			long endTimeTwo   = System.nanoTime();
			long totalTimeTwo = endTimeTwo - startTimeTwo;
			System.out.printf("%d time elapsed for multiplier %d for array list\n",totalTimeTwo,multiplier);



			long startTimeThree = System.nanoTime();
			for( int i=0;i<100*multiplier;i++ )
			{
				House tempHouse = new House(testHouse);
				tempHouse.SetBeginPosition( tempHouse.GetBeginPosition() + 2*i );
				tempHouse.SetEndPosition( tempHouse.GetEndPosition() + 2*i );
				try
				{
					stLL.AddHouse( "left" , tempHouse );
				}
				catch( Street.StructureCannotBeAdded e )
				{

				}
			}

			long endTimeThree   = System.nanoTime();
			long totalTimeThree = endTimeThree - startTimeThree;
			System.out.printf("%d time elapsed for multiplier %d for linked list\n",totalTimeThree,multiplier);



			long startTimeFour = System.nanoTime();
			for( int i=0;i<100*multiplier;i++ )
			{
				House tempHouse = new House(testHouse);
				tempHouse.SetBeginPosition( tempHouse.GetBeginPosition() + 2*i );
				tempHouse.SetEndPosition( tempHouse.GetEndPosition() + 2*i );
				try
				{
					stLDLL.AddHouse( "left" , tempHouse );
				}
				catch( Street.StructureCannotBeAdded e )
				{

				}
			}

			long endTimeFour   = System.nanoTime();
			long totalTimeFour = endTimeFour - startTimeFour;
			System.out.printf("%d time elapsed for multiplier %d for LDLinkedList\n\n\n",totalTimeFour,multiplier);
			timeTest( multiplier*10 );
		}
	}




}






























