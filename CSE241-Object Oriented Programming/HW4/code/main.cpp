#include "dayofyearset.h"







void test();












int main()
{


	test();

	return 0;
}










void test()
{
	cse241DayOfYearSet::DayOfYearSet::DayOfYear d1(15,3),d2(15,4),d3(15,5),d4(15,6),d5(15,7),d6(15,8),d7(15,9),d8(9,1),d9(9,2),d10(9,3),d11(9,4),d12(9,5),d13(9,6),d14(9,7),d15(9,8);
	

	std::vector< cse241DayOfYearSet::DayOfYearSet::DayOfYear > vec1 = {d1,d2,d3,d4};
	std::vector< cse241DayOfYearSet::DayOfYearSet::DayOfYear > vec2 = {d1,d2,d3,d10,d11};
	std::vector< cse241DayOfYearSet::DayOfYearSet::DayOfYear > vec3 = {d7,d9,d2,d15};
	std::vector< cse241DayOfYearSet::DayOfYearSet::DayOfYear > vec4 = {d2,d3,d7,d11,d14};
	std::vector< cse241DayOfYearSet::DayOfYearSet::DayOfYear > vec5 = {d2,d3,d7,d14,d11};

	cse241DayOfYearSet::DayOfYearSet::DayOfYear testDayOne(15,11),testDayTwo(7,12);



	cse241DayOfYearSet::DayOfYearSet set1(vec1),set2(vec2),set3(vec3),set4(vec4),set5(vec5);









	system("clear");
	
	std::cout << "To print set1 and set2,enter 0" << std::endl;  //Tests << operator
	std::cout << "To print set3 and set4,enter 1" << std::endl;  //Tests << operator
	std::cout << "To print set1+set2,enter 2" << std::endl;    //Tests + operator
	std::cout << "To print set3+set4,enter 3" << std::endl;    //Tests + operator
	std::cout << "To print set1-set2,enter 4" << std::endl;    //Tests - operator
	std::cout << "To print set3-set4,enter 5" << std::endl;    //Tests - operator
	std::cout << "To print set1^set2,enter 6" << std::endl;    //Tests ^ operator
	std::cout << "To print set3^set4,enter 7" << std::endl;    //Tests ^ operator
	std::cout << "To print first element of set1,enter 8" << std::endl;    //Tests [] operator
	std::cout << "To print third element of set2,enter 9" << std::endl;    //Tests [] operator
	std::cout << "To print size of set1,enter 10" << std::endl;    //Tests size() function
	std::cout << "To print size of set2,enter 11" << std::endl;    //Tests size() function
	std::cout << "To add 'november 15th' to set1,enter 12" << std::endl;    //Tests add() function
	std::cout << "To add 'december 7th' to set2,enter 13" << std::endl;    //Tests add() function
	std::cout << "To remove last element of set1,enter 14" << std::endl;    //Tests remove() function
	std::cout << "To remove last element of set2,enter 15" << std::endl;    //Tests remove() function
	std::cout << "To check de morgan rules for set1 and set2,enter 16" << std::endl;  //Tests de morgan rules
	std::cout << "To check de morgan rules for set3 and set4,enter 17" << std::endl;  //Tests de morgan rules
	std::cout << "To print !set1,enter 18" << std::endl;  //Tests ! operator
	std::cout << "To print !set2,enter 19" << std::endl;  //Tests ! operator
	std::cout << "To print number of objects created so far,enter 20" << std::endl;  //Tests static function operator
	std::cout << "To check equality for set4 and set5,enter 21" << std::endl;  //Tests de morgan rules
	std::cout << "To check equality for set3 and set5,enter 22" << std::endl;  //Tests de morgan rules


	int choice = 0;

	std::cout << std::endl << "Your choice --> ";
	std::cin >> choice;


	if(choice == 0)
	{
		std::cout << std::endl << "Set1 is below " << std::endl << set1  << std::endl << std::endl << "set2 is below" << std::endl << set2  << std::endl << std::endl ;
	}
	else if(choice == 1)
	{
		std::cout << std::endl << "Set3 is below " << std::endl << set3  << std::endl << std::endl << "set4 is below" << std::endl << set4  << std::endl << std::endl ;
	}
	else if(choice == 2)
	{
		std::cout << std::endl << "Set1 is below " << std::endl << set1  << std::endl << std::endl << "set2 is below" << std::endl << set2  << std::endl << std::endl ;
		std::cout << std::endl << "Set1+Set2 is below " << std::endl << set1+set2;

	}
	else if(choice == 3)
	{
		std::cout << std::endl << "Set3 is below " << std::endl << set3  << std::endl << std::endl << "set4 is below" << std::endl << set4  << std::endl << std::endl ;
		std::cout << std::endl << "Set3+Set4 is below " << std::endl << set3+set4;
	}
	else if(choice == 4)
	{
		std::cout << std::endl << "Set1 is below " << std::endl << set1  << std::endl << std::endl << "set2 is below" << std::endl << set2  << std::endl << std::endl ;
		std::cout << std::endl << "Set1-Set2 is below " << std::endl << set1-set2;
	}
	else if(choice == 5)
	{
		std::cout << std::endl << "Set3 is below " << std::endl << set3  << std::endl << std::endl << "set4 is below" << std::endl << set4  << std::endl << std::endl ;
		std::cout << std::endl << "Set3-Set4 is below " << std::endl << set3-set4;
	}
	else if(choice == 6)
	{
		std::cout << std::endl << "Set1 is below " << std::endl << set1  << std::endl << std::endl << "set2 is below" << std::endl << set2  << std::endl << std::endl ;
		std::cout << std::endl << "Set1^Set2 is below " << std::endl << (set1^set2);
	}
	else if(choice == 7)
	{
		std::cout << std::endl << "Set3 is below " << std::endl << set3  << std::endl << std::endl << "set4 is below" << std::endl << set4  << std::endl << std::endl ;
		std::cout << std::endl << "Set3^Set4 is below " << std::endl << (set3^set4);
	}
	else if(choice == 8)
	{
		std::cout << std::endl << "Set1 is below " << std::endl << set1  << std::endl << std::endl;
		std::cout <<  "First element of set1 is below " << std::endl << set1[0].getDay() << "." << set1[0].getMounth() << "." << set1.getYear()  << std::endl << std::endl;
	}
	else if(choice == 9)
	{
		std::cout << std::endl << "Set2 is below " << std::endl << set1  << std::endl << std::endl;
		std::cout <<  "Third element of set2 is below " << std::endl << set2[2].getDay() << "." << set2[2].getMounth() << "." << set2.getYear()  << std::endl << std::endl;
	}
	else if(choice == 10)
	{
		std::cout << std::endl << "Set1 is below " << std::endl << set1  << std::endl << std::endl;
		std::cout <<  "Size of set1 is --> " << set1.size() <<std::endl << std::endl;
	}
	else if(choice == 11)
	{
		std::cout << std::endl << "Set2 is below " << std::endl << set2  << std::endl << std::endl;
		std::cout <<  "Size of set2 is --> " << set2.size() <<std::endl << std::endl;
	}
	else if(choice == 12)
	{
		std::cout << std::endl << "Set1 is below " << std::endl << set1  << std::endl << std::endl;
		set1.add( testDayOne );
		std::cout << std::endl << "Set1 is below after adding november 15th " << std::endl << set1  << std::endl << std::endl;

	}
	else if(choice == 13)
	{
		std::cout << std::endl << "Set2 is below " << std::endl << set2  << std::endl << std::endl;
		set2.add( testDayTwo );
		std::cout << std::endl << "Set2 is below after adding december 7th " << std::endl << set2  << std::endl << std::endl;
	}
	else if(choice == 14)
	{
		std::cout << std::endl << "Set1 is below " << std::endl << set1  << std::endl << std::endl;
		set1.remove();
		std::cout << std::endl << "Set1 is below after removing last element " << std::endl << set1  << std::endl << std::endl;
	}
	else if(choice == 15)
	{
		std::cout << std::endl << "Set2 is below " << std::endl << set2  << std::endl << std::endl;
		set2.remove();
		std::cout << std::endl << "Set2 is below after removing last element " << std::endl << set2  << std::endl << std::endl;
	}
	else if( choice == 16 )
	{
		std::cout << std::endl << "Set1 is below " << std::endl << set1  << std::endl << std::endl << "set2 is below" << std::endl << set2  << std::endl << std::endl ;		
		if( !(set1+set2) == (!set1^!set2) )
		{
			std::cout << "!(set1+set2) == !set1^!set2" << std::endl;
		}
		else
		{
			std::cout << "De morgan rule for set1 and set2 is false" << std::endl;
		}
	}
	else if( choice == 17 )
	{
		std::cout << std::endl << "Set3 is below " << std::endl << set3  << std::endl << std::endl << "set4 is below" << std::endl << set4  << std::endl << std::endl ;		
		if( !(set3+set4) == (!set3^!set4) )
		{
			std::cout << "!(set3+set4) == !set3^!set4" << std::endl;
		}
		else
		{
			std::cout << "De morgan rule for set3 and set4 is false" << std::endl;
		}
	}
	else if( choice == 18 )
	{
		std::cout << std::endl << "Set1 is below " << std::endl << set1  << std::endl << std::endl;

		std::cout << std::endl << "!Set1 is below" << std::endl << !set1;

	}
	else if( choice == 19 )
	{
		std::cout << std::endl << "Set2 is below " << std::endl << set2  << std::endl << std::endl;

		std::cout << std::endl << "!Set2 is below" << std::endl << !set2;
	}
	else if( choice == 20 )
	{
		std::cout << std::endl << "Number of objects created so far --> " <<  set1.getNumOfObjects();
	}
	else if( choice == 21 )
	{
		std::cout << std::endl << "Set4 is below " << std::endl << set4  << std::endl << std::endl << "set5 is below" << std::endl << set5  << std::endl << std::endl ;
		if( set4 == set5 )
		{
			std::cout << "set4 == set5" << std::endl;
		}
		else if( set4 != set5 )
		{
			std::cout << "set4 != set5" << std::endl;
		}
	}
	else if( choice == 22 )
	{
		std::cout << std::endl << "Set3 is below " << std::endl << set3  << std::endl << std::endl << "set5 is below" << std::endl << set5  << std::endl << std::endl ;
		if( set3 == set5 )
		{
			std::cout << "set3 == set5" << std::endl;
		}
		else if( set3 != set5 )
		{
			std::cout << "set3 != set5" << std::endl;
		}
	}


	

}















