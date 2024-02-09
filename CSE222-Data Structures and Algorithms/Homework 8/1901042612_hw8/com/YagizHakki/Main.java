package com.YagizHakki;

import java.util.*;


public class Main
{
	public static void main( String[] args )
	{
		Main m = new Main();
		m.driver();
	}


	public void driver()
	{
		MyGraph g = new MyGraph(true);

		Vertex<Integer> vertex0 = new Vertex(); 
		Vertex<Integer> vertex1 = new Vertex(); 
		Vertex<Integer> vertex2 = new Vertex(); 
		Vertex<Integer> vertex3 = new Vertex(); 
		Vertex<Integer> vertex4 = new Vertex(); 
		Vertex<Integer> vertex5 = new Vertex(); 
		Vertex<Integer> vertex6 = new Vertex(); 
		Vertex<Integer> vertex7 = new Vertex(); 


		vertex0.setId(0);
		vertex1.setId(1);
		vertex2.setId(2);
		vertex3.setId(3);
		vertex4.setId(4);


		g.addVertex(vertex2);
		vertex0.addNeighbour(vertex1,4.0);
		vertex0.addNeighbour(vertex3,22.0);
		vertex0.addNeighbour(vertex2,2.0);
		vertex1.addNeighbour(vertex2,3.0);
		vertex2.addNeighbour(vertex0,4.0);
		vertex2.addNeighbour(vertex3,5.0);
		vertex3.addNeighbour(vertex3,6.0);
		g.addVertex( vertex4 );







		g.printGraph();
		System.out.println("Graph printed as matrix below...");
		g.printMatrix();
		g.printDFS( g );
		g.printBFS( g );
		try
		{
			System.out.printf("Difference between traversals --> %f\n",g.traversalDifference( g ));
			System.out.println();
		}
		catch( Exception e )
		{

		}
		g.dijkstra( vertex0 );

		System.out.printf("\n Edge between vertices 0 and 3 --> %s",g.getEdge(vertex0,vertex3).toString());


	}


}
