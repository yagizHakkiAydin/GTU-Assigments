package com.YagizHakkiAydin;

import java.util.Scanner;
import java.util.ArrayList;

/**
*This class keeps all data about the street in array list
*This class has functions to modify structures(including playgrounds)
*/
public class StreetArrayList extends Street
{


	StreetArrayList()
	{
		this(40);
	}


	StreetArrayList( int lengthOfStreet )
	{
		super(lengthOfStreet);
		leftSideOfTheStreet =  new ArrayList<Structure>();;
		rightSideOfTheStreet =  new ArrayList<Structure>();;
	}






	/**
	*Asks user properties and adds market created wit these properties
	*@param side side that market will be added
	*/
	@Override
	public void AddMarket( String side ) throws StructureCannotBeAdded
	{
		try
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


			if( (newMarket.GetHeight()<=0) || (newMarket.GetOpeningTime()<0) || (newMarket.GetClosingTime()<0)|| (newMarket.GetOpeningTime()>24) || (newMarket.GetClosingTime()>24) )
			{
				throw new StructureCannotBeAdded("Market cannot be added...");
			}


			AddMarket( side , newMarket );
		}
		catch( StructureCannotBeAdded exceptionObj )
		{
			throw new StructureCannotBeAdded("Market cannot be added...");
		}


	}





	/**
	*Asks user properties and adds house created wit these properties
	*@param side side that house will be added
	*/
	@Override
	public void AddHouse( String side ) throws StructureCannotBeAdded
	{
		try
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


			if( (newHouse.GetHeight()<=0) || (newHouse.GetNumberOfRooms()<=0) )
			{
				throw new StructureCannotBeAdded("House cannot be added...");
			}

			AddHouse( side , newHouse );


		}
		catch( StructureCannotBeAdded exceptionObj )
		{
			throw new StructureCannotBeAdded("House cannot be added...");
		}
	}





	/**
	*Asks user properties and adds office created wit these properties
	*@param side side that office will be added
	*/
	@Override
	public void AddOffice( String side ) throws StructureCannotBeAdded
	{
		try
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

			if( (newOffice.GetHeight()<=0) )
			{
				throw new StructureCannotBeAdded("Office cannot be added...");
			}

			AddOffice( side , newOffice );
		}
		catch( StructureCannotBeAdded exceptionObj )
		{
			throw new StructureCannotBeAdded("Office cannot be added...");
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
		obj.FixBeginAndEndPositions();

		try
		{
			ThrowExceptionİfStructureCannotBeAdded( side , obj );

			AddStructure( side , obj );
		}
		catch( StructureCannotBeAdded exceptionObj )
		{
			throw new StructureCannotBeAdded("Market cannot be added...");
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
		obj.FixBeginAndEndPositions();

		try
		{
			ThrowExceptionİfStructureCannotBeAdded( side , obj );
			AddStructure( side , obj );
			
		}
		catch( StructureCannotBeAdded exceptionObj )
		{
			throw new StructureCannotBeAdded("House cannot be added...");
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
		obj.FixBeginAndEndPositions();

		try
		{
			ThrowExceptionİfStructureCannotBeAdded( side , obj );

			AddStructure( side , obj );
			
		}
		catch( StructureCannotBeAdded exceptionObj )
		{
			throw new StructureCannotBeAdded("Office cannot be added...");
		}
	}











	/**
	*Appends given object to the container and sets occupied lands
	*@param side side that object to be appended
	*@param obj object to be appended
	*/
	@Override
	protected void AddStructure( String side , Structure obj )
	{

			if( obj instanceof Building )
			{
				Building tempObjReference = (Building)obj;
				if( tempObjReference.GetHeight() > GetMaxHeight() )
				{
					SetMaxHeight( tempObjReference.GetHeight() );
				}
			}


			if( side.equals("left") )
			{
				leftSideOfTheStreet.add(obj);

				for( int i=obj.GetBeginPosition() ; i<obj.GetEndPosition() ; i++)
				{
					occupiedLandsOnLeftSide[i] = true;
				}

				numberOfStructuresOnLeftSide++;
			}
			else
			{
				rightSideOfTheStreet.add(obj);

				for( int i=obj.GetBeginPosition() ; i<obj.GetEndPosition() ; i++)
				{
					occupiedLandsOnRightSide[i] = true;
				}
				numberOfStructuresOnRightSide++;
			}
	}





	@Override
	public void ThrowExceptionİfStructureCannotBeAdded( String side , Structure obj ) throws StructureCannotBeAdded
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







	






	public void deleteHouse( String side )
	{
		House h;


		System.out.printf("\nEnter the owner name of the house to be deleted -->");

		Scanner sc = new Scanner(System.in);

		String choice = sc.nextLine();

		ArrayList<Structure> streetSide = null;


		if( side.equals("left") )
		{
			streetSide = leftSideOfTheStreet;
		}
		else
		{
			streetSide = rightSideOfTheStreet;
		}


		for( int i=0;i<streetSide.size();i++ )
		{
			if( streetSide.get(i) instanceof House )
			{
				h = (House)streetSide.get(i);
				if( h.GetOwnerName().equals(choice) )
				{
					DeleteStructure(side,i);
					break;
				}
			}
		}
	}


	public void deleteOffice( String side )
	{
			Office o;


			System.out.printf("\nEnter the job type of the office to be deleted -->");

			Scanner sc = new Scanner(System.in);

			String choice = sc.nextLine();


			ArrayList<Structure> streetSide = null;


			if( side.equals("left") )
			{
				streetSide = leftSideOfTheStreet;
			}
			else
			{
				streetSide = rightSideOfTheStreet;
			}


			for( int i=0;i<streetSide.size();i++ )
			{
				if( streetSide.get(i) instanceof Office )
				{
					o = (Office)streetSide.get(i);
					if( o.GetJobType().equals(choice) )
					{
						DeleteStructure(side,i);
						break;
					}
				}
			}
	}




	public void deleteMarket( String side )
	{
			Market m;

			System.out.printf("\nEnter the opening time of the market to be deleted -->");

			Scanner sc = new Scanner(System.in);

			int openingTimeChoice = sc.nextInt();
			System.out.printf("\nEnter the closing time of the market to be deleted -->");
			int closingTimeChoice = sc.nextInt();

			ArrayList<Structure> streetSide = null;


			if( side.equals("left") )
			{
				streetSide = leftSideOfTheStreet;
			}
			else
			{
				streetSide = rightSideOfTheStreet;
			}


			for( int i=0;i<streetSide.size();i++ )
			{
				if( streetSide.get(i) instanceof Market )
				{
					m = (Market)streetSide.get(i);
					if( m.GetOpeningTime() == openingTimeChoice  &&  m.GetClosingTime() == closingTimeChoice )
					{
						DeleteStructure(side,i);
						break;
					}
				}
			}
	}





	/**
	*Deletes an element from the asked structures array at given index
	*@param side side of the deleted element
	*@param structureIndex index of the deleted element
	*/
	private void DeleteStructure( String side , int structureIndex )
	{
		if( side.equals("left") )
		{
			leftSideOfTheStreet.remove( structureIndex );
			numberOfStructuresOnLeftSide = leftSideOfTheStreet.size();
		}
		else if( side.equals("right") )
		{
			rightSideOfTheStreet.remove( structureIndex );
			numberOfStructuresOnRightSide = rightSideOfTheStreet.size();
		}
	}





	@Override
	public final String[] GetStreetView()
	{

		String[] streetView = GetStreetViewWithBuildingCeilings();

		StringBuilder temp;

		for( int index=0 ; index<numberOfStructuresOnLeftSide ; index++ )
		{
			if( !( leftSideOfTheStreet.get(index) instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)leftSideOfTheStreet.get(index)).GetHeight();

				for( int i=1;i<=buildingHeight;i++ )
				{
					temp = new StringBuilder(streetView[ GetMaxHeight() - i + 1 ]);
					temp.setCharAt( (leftSideOfTheStreet.get(index).GetBeginPosition()) , '|');
					temp.setCharAt( (leftSideOfTheStreet.get(index).GetEndPosition()-1) , '|');
					streetView[ GetMaxHeight() - i + 1 ] = temp.toString();
				}
			}
		}	


		for( int index=0 ; index<numberOfStructuresOnRightSide ; index++ )
		{
			if( !( rightSideOfTheStreet.get(index) instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)rightSideOfTheStreet.get(index)).GetHeight();

				for( int i=1;i<=buildingHeight;i++ )
				{
					temp = new StringBuilder(streetView[ GetMaxHeight() - i + 1 ]);
					temp.setCharAt( (rightSideOfTheStreet.get(index).GetBeginPosition()) , '|');
					temp.setCharAt( (rightSideOfTheStreet.get(index).GetEndPosition()-1) , '|');
					streetView[ GetMaxHeight() - i + 1 ] = temp.toString();	
				}
			}
		}


		return streetView;
	}









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




	private final String[] GetStreetViewWithBuildingCeilings()
	{
		String[] streetView = GetEmptyStreetView();

		StringBuilder temp;


		for( int index=0;index<leftSideOfTheStreet.size();index++ )
		{
			if( !( leftSideOfTheStreet.get(index) instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)leftSideOfTheStreet.get(index)).GetHeight();

				for( int i=leftSideOfTheStreet.get(index).GetBeginPosition();i<leftSideOfTheStreet.get(index).GetEndPosition();i++ )
				{

					temp = new StringBuilder(streetView[ GetMaxHeight() - buildingHeight ]);
					temp.setCharAt( i , '_');
					streetView[ GetMaxHeight() - buildingHeight ] = temp.toString();

				}
			}
		}	


		for( int index=0;index<numberOfStructuresOnRightSide;index++ )
		{
			if( !( rightSideOfTheStreet.get(index) instanceof PlayGround ) )
			{
				int buildingHeight = ((Building)rightSideOfTheStreet.get(index)).GetHeight();

				for( int i=rightSideOfTheStreet.get(index).GetBeginPosition();i<rightSideOfTheStreet.get(index).GetEndPosition();i++ )
				{
					temp = new StringBuilder(streetView[ GetMaxHeight() - buildingHeight ]);
					temp.setCharAt( i , '_');
					streetView[ GetMaxHeight() - buildingHeight ] = temp.toString();
				}
			}
		}	

		return streetView;

	}




	@Override
	public void printStreet()
	{
		String[] streetView = GetStreetView();
		for( int i=0;i<GetMaxHeight()+2;i++ )
		{
			System.out.printf("%s\n",streetView[i]);
		}
	}
	@Override
	public void printAllStructureInformation()
	{
		System.out.printf("Street view below...\n\n");
		printStreet();
		System.out.printf("Structures on the left side are listed below...\n\n");
		for( int i=0;i<leftSideOfTheStreet.size();i++ )
		{
			System.out.printf("%s\n",leftSideOfTheStreet.get(i).toString());
		}
		System.out.printf("Structures on the right side are listed below...\n\n");
		for( int i=0;i<rightSideOfTheStreet.size();i++ )
		{
			System.out.printf("%s\n",rightSideOfTheStreet.get(i).toString());
		}
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
		result *=leftSideOfTheStreet.hashCode();
		result *=rightSideOfTheStreet.hashCode();



		return result; 
	}



	@Override	
	public String toString()
	{
		String str = new String();

		return str;
	};



	ArrayList<Structure> leftSideOfTheStreet;
	ArrayList<Structure> rightSideOfTheStreet;
}