#include "gtuvector.h"
#include "gtuset.h"
#include "gtuarray.h"
#include <algorithm>


using namespace cse241hw6;



void testSet();
void testVector();
void testArray();
void forEachTester(int a){ std::cout << a <<" "; }





int main()
{

	int choice = 0;

	system("clear");

	std::cout << "To test GTUSet,enter 1 ; to test GTUVector,enter 2 ; to test GTUArray,enter 3" << std::endl;
	std::cout << "Choice --> ";
	std::cin >> choice;

	if( choice == 1 )
	{
		testSet();
	}
	else if( choice == 2 )
	{
		testVector();
	}
	else if( choice == 3 )
	{
		testArray();	
	}
	else
	{
		std::cerr << std::endl << "Wrong choice";
		exit(1);		
	}



	return 0;



}



















void testSet()
{

	system("clear");

	GTUSet<int> set1,set2;
	set1.insert(10);set1.insert(15);set1.insert(13);set1.insert(11);set1.insert(12);set1.insert(14);set1.insert(9);
	set2.insert(9);set2.insert(27);set2.insert(13);set2.insert(11);set2.insert(6);set2.insert(18);set2.insert(999);

	std::cout << "Set1 = {";
	for( auto it:set1 )
	{
		std::cout << "," <<it;
	}std::cout << " }";


	std::cout << std::endl <<"Set2 = {";
	for( auto it2:set2 )
	{
		std::cout << "," <<it2;
	}std::cout << " }";

	std::cout << std::endl << "Sets are printed on screen with range based for loop..." << std::endl << std::endl;











	//std::sort( set1.begin() , set1.end() );
	//std::sort( set2.begin() , set2.end() );
	std::cout << "Sets are sorted with std::sort(),begin and end functions are used..." << std::endl << std::endl;
	std::cout << "Set1 = {";
	for( auto it:set1 )
	{
		std::cout << "," <<it;
	}std::cout << " }";


	std::cout << std::endl <<"Set2 = {";
	for( auto it2:set2 )
	{
		std::cout << "," <<it2;
	}std::cout << " }";














	GTUSet<int> set3;

	set3 = set1.intersect(set2);

	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "A new set is created with name set3,assigned with intersection of set1 and set2..." << std::endl;
	std::cout << "Set3 = {";
	for( auto it3:set3 )
	{
		std::cout << "," <<it3;
	}std::cout << " }";











	set3 = set1.unionSet(set2);

	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "Set3,assigned with union of set1 and set2..." << std::endl;
	std::cout << "Set3 = {";
	for( auto it3:set3 )
	{
		std::cout << "," <<it3;
	}std::cout << " }";








	set3.erase(10);

	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "For set3,erase() function get 10 as parameter and deleted element 10 from set3" << std::endl;
	std::cout << "Set3 = {";
	for( auto it3:set3 )
	{
		std::cout << "," <<it3;
	}std::cout << " }";







	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "First element of set3 is printed with [] operator" << std::endl;
	std::cout << "set3[0] --> " << set3[0];





	std::cout << std::endl << std::endl << std::endl << std::endl;
	if( set3.end() != std::find( set3.begin() , set3.end() , 11 ) )
	{
		std::cout << "set3 contains 11 found by std::find";
	}
	std::cout << std::endl << std::endl << std::endl;






	set1 = std::move(set2);

	std::cout <<  "set2 is moved to set1 with move assigment operator" << std::endl;
	set1 = std::move(set2);
	std::cout << "set1 = {";
	for( auto it:set1 )
	{
		std::cout << "," <<it;
	}std::cout << " }";





	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout <<  "set1 is printed with for_each" << std::endl << "set1 --> ";
	std::for_each( set1.begin(),set1.end(),forEachTester );
	






	std::cout << std::endl << std::endl << std::endl << std::endl;
	set3.clear();
	if(set3.empty())
	{
		std::cout << std::endl << std::endl << std::endl << std::endl;
		std::cout << "If empty() function returns true,this message gets printed because set3 is cleared by clear() function" << std::endl;
		std::cout << "Size of set3 which is printed with size() --> " << set3.size(); 
	}







}













void testVector()
{

	system("clear");

	GTUVector<int> Vector1,Vector2,Vector3;
	Vector1.push_back(15);Vector1.push_back(10);Vector1.push_back(13);Vector1.push_back(6);Vector1.push_back(98);Vector1.push_back(134);Vector1.push_back(92);
	Vector2.push_back(9);Vector2.push_back(27);Vector2.push_back(13);Vector2.push_back(15);Vector2.push_back(6);Vector2.push_back(18);Vector2.push_back(15);

	std::cout << "Vector1 = {";
	for( auto it:Vector1 )
	{
		std::cout << "," <<it;
	}std::cout << " }";


	std::cout << std::endl <<"Vector2 = {";
	for( auto it2:Vector2 )
	{
		std::cout << "," <<it2;
	}std::cout << " }";

	std::cout << std::endl << "Vectors are printed on screen with range based for loop..." << std::endl << std::endl;











	//std::sort( Vector1.begin() , Vector1.end() );
	//std::sort( Vector2.begin() , Vector2.end() );
	std::cout << "Vectors are sorted with std::sort(),begin and end functions are used..." << std::endl << std::endl;
	std::cout << "Vector1 = {";
	for( auto it:Vector1 )
	{
		std::cout << "," <<it;
	}std::cout << " }";


	std::cout << std::endl <<"Vector2 = {";
	for( auto it2:Vector2 )
	{
		std::cout << "," <<it2;
	}std::cout << " }";











	Vector1.erase(10);

	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "For Vector1,erase() function get 10 as parameter and deleted element 10 from Vector3" << std::endl;
	std::cout << "Vector1 = {";
	for( auto it1:Vector1 )
	{
		std::cout << "," <<it1;
	}std::cout << " }";






	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "Vector3 = Vector1" << std::endl;
	Vector3 = Vector1;









	Vector3.pop_back();

	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "For Vector3,pop_back is used" << std::endl;
	std::cout << "Vector3 = {";
	for( auto it3:Vector3 )
	{
		std::cout << "," <<it3;
	}std::cout << " }";






	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "First element of Vector3 is printed with [] operator" << std::endl;
	std::cout << "Vector3[0] --> " << Vector3[0];









	std::cout << std::endl << std::endl << std::endl << std::endl;
	if( Vector3.end() != std::find( Vector3.begin() , Vector3.end() , 11 ) )
	{
		std::cout << "Vector3 contains 11 found by std::find";
	}









	std::cout << std::endl << std::endl << std::endl;

	Vector1 = std::move(Vector2);

	std::cout <<  "Vector2 is moved to Vector1 with move assigment operator" << std::endl;
	Vector1 = std::move(Vector2);
	std::cout << "Vector1 = {";
	for( auto it:Vector1 )
	{
		std::cout << "," <<it;
	}std::cout << " }";
	








	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout <<  "Vector1 is printed with for_each" << std::endl << "Vector1 --> ";
	std::for_each( Vector1.begin(),Vector1.end(),forEachTester );









	std::cout << std::endl << std::endl << std::endl << std::endl;
	Vector3.clear();
	if(Vector3.empty())
	{
		std::cout << std::endl << std::endl << std::endl << std::endl;
		std::cout << "If empty() function returns true,this message gets printed because Vector3 is cleared by clear() function" << std::endl;
		std::cout << "Size of Vector3 which is printed with size() --> " << Vector3.size(); 
	}







}














void testArray()
{

	GTUArray<int,5> array1;
	GTUArray<int,5> array2;
	GTUArray<int,5> array3;


	system("clear");
	std::cout << "3 arrays are created with size 5.(array1,array2,array3)";
	std::cout << std::endl << std::endl << std::endl;









	array1.fill(3);
	array2.fill(5);

	std::cout << "array1 is filled with 3,array2 is filled with 5,two arrays are printed with range based for loop" << std::endl;
		std::cout << "array1 = {";
	for( auto it:array1 )
	{
		std::cout << "," <<it;
	}std::cout << " }";


	std::cout << std::endl <<"array2 = {";
	for( auto it2:array2 )
	{
		std::cout << "," <<it2;
	}std::cout << " }";

	std::cout << std::endl << std::endl << std::endl<< std::endl << std::endl;










	std::cout <<  "array1[0]=12 , array1[1]=24 , array1[2]=48 , array2[0]=25" << std::endl;
	array1[0]=12; 
	array1[1]=24; 
	array1[2]=48; 
	array2[0]=25;

	std::cout << "array1 = {";
	for( auto it:array1 )
	{
		std::cout << "," <<it;
	}std::cout << " }";


	std::cout << std::endl <<"array2 = {";
	for( auto it2:array2 )
	{
		std::cout << "," <<it2;
	}std::cout << " }";


	std::cout << std::endl << std::endl << std::endl;










	std::cout <<  "array1 and array2 are sorted with std::sort" << std::endl;
	//std::sort( array1.begin() , array1.end() );
	//std::sort( array2.begin() , array2.end() );
	std::cout << "array1 = {";
	for( auto it:array1 )
	{
		std::cout << "," <<it;
	}std::cout << " }";


	std::cout << std::endl <<"array2 = {";
	for( auto it2:array2 )
	{
		std::cout << "," <<it2;
	}std::cout << " }";
	std::cout << std::endl << std::endl << std::endl;










	

	std::cout <<  "array2 is moved to array1 with move assigment operator" << std::endl;
	array1 = std::move(array2);
	std::cout << "array1 = {";
	for( auto it:array1 )
	{
		std::cout << "," <<it;
	}std::cout << " }";
	std::cout << std::endl << std::endl << std::endl;





	std::cout <<  "array1 is printed with for_each" << std::endl << "array1 --> ";
	std::for_each( array1.begin(),array1.end(),forEachTester );






}

















