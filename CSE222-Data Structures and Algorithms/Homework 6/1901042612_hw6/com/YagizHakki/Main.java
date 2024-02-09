package com.YagizHakki;


public class Main
{
	public static void main( String[] args )
	{
		Main m = new Main();
		m.drive();
	}

	/**
	*Drive function
	*/
	public void drive()
	{
		MergeSort m = new MergeSort(10);
		QuickSort q = new QuickSort( m.getArrayCopy() , m.getSize() );
		NewSort n = new NewSort( m.getArrayCopy() , m.getSize() );

		MergeSort m1 = new MergeSort(100);
		QuickSort q1 = new QuickSort( m.getArrayCopy() , m.getSize() );
		NewSort n1 = new NewSort( m.getArrayCopy() , m.getSize() );

		MergeSort m2 = new MergeSort(1000);
		QuickSort q2 = new QuickSort( m.getArrayCopy() , m.getSize() );
		NewSort n2 = new NewSort( m.getArrayCopy() , m.getSize() );

		MergeSort m3 = new MergeSort(10000);
		QuickSort q3 = new QuickSort( m.getArrayCopy() , m.getSize() );
		NewSort n3 = new NewSort( m.getArrayCopy() , m.getSize() );



		System.out.println("Tests done with 10 length array...\n");

		System.out.println("Before merge sort...\n");
		m.printSortedArray();
		m.sortArray();
		System.out.println("After merge sort...\n");
		m.printSortedArray();


		System.out.println("Before quick sort...\n");
		q.printSortedArray();
		q.sortArray();
		System.out.println("After quick sort...\n");
		q.printSortedArray();


		System.out.println("Before new sort...\n");
		n.printSortedArray();
		n.sortArray();
		System.out.println("After new sort...\n");
		n.printSortedArray();







		long beginm1 = System.nanoTime(); 
		m1.sortArray();
		long endm1 = System.nanoTime(); 

		long beginq1= System.nanoTime(); 
		q1.sortArray();
		long endq1 = System.nanoTime(); 


		long beginn1 = System.nanoTime(); 
		n1.sortArray();
		long endn1 = System.nanoTime(); 


		long beginm2 = System.nanoTime(); 
		m2.sortArray();
		long endm2 = System.nanoTime(); 

		long beginq2= System.nanoTime(); 
		q2.sortArray();
		long endq2 = System.nanoTime(); 


		long beginn2 = System.nanoTime(); 
		n2.sortArray();
		long endn2 = System.nanoTime(); 



		long beginm3 = System.nanoTime(); 
		m3.sortArray();
		long endm3 = System.nanoTime(); 

		long beginq3= System.nanoTime(); 
		q3.sortArray();
		long endq3 = System.nanoTime(); 


		long beginn3 = System.nanoTime(); 
		n3.sortArray();
		long endn3 = System.nanoTime(); 




		System.out.printf("Runtime for mergesort for 100 length array = %d\n",endm1-beginm1);
		System.out.printf("Runtime for mergesort for 1000 length array = %d\n",endm2-beginm2);
		System.out.printf("Runtime for mergesort for 10000 length array = %d\n\n\n\n\n",endm3-beginm3);


		System.out.printf("Runtime for quicksort for 100 length array = %d\n",endq1-beginq1);
		System.out.printf("Runtime for quicksort for 1000 length array = %d\n",endq2-beginq2);
		System.out.printf("Runtime for quicksort for 10000 length array = %d\n\n\n\n\n",endq3-beginq3);


		System.out.printf("Runtime for newsort for 100 length array = %d\n",endn1-beginn1);
		System.out.printf("Runtime for newsort for 1000 length array = %d\n",endn2-beginn2);
		System.out.printf("Runtime for newsort for 10000 length array = %d\n\n\n\n\n",endn3-beginn3);




	}




}


















