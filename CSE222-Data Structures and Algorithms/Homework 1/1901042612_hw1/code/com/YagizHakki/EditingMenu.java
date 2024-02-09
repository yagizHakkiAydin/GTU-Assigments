package com.YagizHakki;



import java.util.Scanner;


/**
*Class that allows user to make choice at editing mode
*/
public class EditingMenu implements Menu
{

	@Override
	public void PrintMenu()
	{
		System.out.printf("To add a play ground to right side,enter 0\n");

		System.out.printf("\n\n\nTo test adding house,enter 1\n");
		System.out.printf("To test adding office,enter 2\n");
		System.out.printf("To test adding market,enter 3\n");

		System.out.printf("To add a house to left side,enter 4\n");
		System.out.printf("To add a office to left side,enter 5\n");
		System.out.printf("To add a market to left side,enter 6\n");

		System.out.printf("To add a house to right side,enter 7\n");
		System.out.printf("To add a office to right side,enter 8\n");
		System.out.printf("To add a market to right side,enter 9\n");

		System.out.printf("To remove a house from left side,enter 10\n");
		System.out.printf("To remove a office from left side,enter 11\n");
		System.out.printf("To remove a market from left side,enter 12\n");

		System.out.printf("To remove a house from right side,enter 13\n");
		System.out.printf("To remove a office from right side,enter 14\n");
		System.out.printf("To remove a market from right side,enter 15\n");


		System.out.printf("To switch view mode,enter 16\n");
		System.out.printf("To exit,enter -1\n");
	}

	@Override
	public int GetChoice()
	{
		Scanner sc = new Scanner(System.in);

		int choice = sc.nextInt();

		return choice;
	}






}