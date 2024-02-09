package com.YagizHakki;


public class Main
{
	public static void main( String [] args )
	{		
		Main m = new Main();
		m.driver();
	}


	/**
	*Tests binary heap
	*/
	void driver()
	{
		BinaryHeap<Integer> test = new BinaryHeap<Integer>();

		test.root.setData(10);
		test.addToLeft(15,0);
		test.addToRight(30,0);
		test.addToLeft(40,1);
		test.addToRight(50,1);
		test.addToLeft(100,2);
		test.addToRight(40,2);


		test.addToRight(50,3);
		test.addToLeft(30,3);
		test.addToLeft(50,3);
	}
}






/*
	     10
	   /    \
	 15      30
	/  \     / \
  40   50   100  40


*/