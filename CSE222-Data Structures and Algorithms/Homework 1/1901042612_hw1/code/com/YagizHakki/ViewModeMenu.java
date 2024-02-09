package com.YagizHakki;


import java.util.Scanner;

/**
*Class that allows user to make choice at view mode
*/
public class ViewModeMenu implements Menu
{

	@Override
	public void PrintMenu()
	{
		System.out.printf("\n\n\nTo switch to edit mode,enter 1\n");
		System.out.printf("To exit,enter -1\n");
	}

	public int GetChoice()
	{
		Scanner sc = new Scanner(System.in);

		int choice = sc.nextInt();

		return choice;
	}
}