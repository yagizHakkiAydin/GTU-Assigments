package com.YagizHakki;
import java.util.*;



public class MyGraph<T> implements DynamicGraph<T>
{


	private Vertex originVertex;

	private int latestAddedVertexId;

	private double bfsTotalWeight;

	private double dfsTotalWeight;

	private boolean isDirected;


	public MyGraph( boolean directed )
	{
		latestAddedVertexId = 0;
		originVertex = null;
		isDirected = directed;
	}



	/**
	*Generate a new vertex by given parameters.
	*/
	public Vertex newVertex(String label, double weight)
	{
		Vertex v = new Vertex<T>(-1,label,weight,null);
		return v;
	}


	

	/**
	*Add the given vertex to the graph.
	*/
	public void addVertex( Vertex new_vertex ) 
	{
		if( originVertex == null )
		{
			originVertex = new_vertex;
		}
		else
		{
			int maxIndex = 0;
			Queue<Vertex> q = this.BFSTraversal();
			while( !q.isEmpty() )
			{
				if( q.peek().getId() > maxIndex )
				{
					maxIndex = q.peek().getId();
				}
				q.poll();
			}
			q = this.BFSTraversal();


			if( maxIndex <= (new_vertex.getId()+1) )
			{
				if( isDirected )
				{
					q.peek().addNeighbour( new_vertex , 1.0 );
				}
				else
				{
					q.peek().addNeighbour( new_vertex , 1.0 );
					new_vertex.addNeighbour( q.peek() , 1.0 );
				}
			}
		}
	}




	

	/**
	*Add an edge between the given two vertices in the graph.
	*/
	public void addEdge(int vertexID1, int vertexID2, double weight)
	{
		Vertex vertex1 = null;
		Vertex vertex2 = null;

		Queue<Vertex> q = this.BFSTraversal();

		Edge newEdge = new Edge( null , null , 0.0 );

		while( !q.isEmpty() )
		{
			if( (vertex1!=null) && (vertex2!=null) )
			{
				break;
			}
			else if( q.peek().getId() == vertexID1 )
			{
				vertex1 = q.peek();
				newEdge.setSource( vertex1 );
			}
			else if( q.peek().getId() == vertexID2 )
			{
				vertex2 = q.peek();
				newEdge.setDest( vertex2 );
			}

			q.poll();
		}

		if( (vertex1!=null) && (vertex2!=null) )
		{
			boolean isV2neighnourOfV1 = false;

			for( int i=0;i<vertex1.adjecents.size();i++ )
			{
				if( vertex1.adjecents.get(i) == vertex2 )
				{
					isV2neighnourOfV1 = true;
					break;
				}
			}


			if( isV2neighnourOfV1 )
			{
				if( !isDirected )
				{
					vertex1.addArrowFromThisVertex(newEdge);
				}
			}
			else if( isDirected )
			{
				vertex1.addNeighbour( vertex2 , newEdge.getWeight() );
			}
			else
			{
				vertex1.addNeighbour( vertex2 , newEdge.getWeight() );
				vertex2.addNeighbour( vertex1 , newEdge.getWeight() );
			}

		}



	}


	

	/**
	*Remove the edge between the given two vertices.
	*/
	public void removeEdge(int vertexID1, int vertexID2)
	{

		Vertex vertex1 = null;
		Vertex vertex2 = null;

		Queue<Vertex> q = this.BFSTraversal();

		Edge newEdge = new Edge( null , null , 0.0 );

		while( !q.isEmpty() )
		{
			if( (vertex1!=null) && (vertex2!=null) )
			{
				break;
			}
			else if( q.peek().getId() == vertexID1 )
			{
				vertex1 = q.peek();
				newEdge.setSource( vertex1 );
			}
			else if( q.peek().getId() == vertexID2 )
			{
				vertex2 = q.peek();
				newEdge.setDest( vertex2 );
			}

			q.poll();
		}

		if( (vertex1!=null) && (vertex2!=null) )
		{
			vertex1.removeNeighbour( vertex2 );
			vertex2.removeNeighbour( vertex1 );
		}	
	}


	


	/**
	*Remove the vertex from the graph with respect to the given vertex id.
	*/
	public void removeVertex(int vertexID)
	{
		Vertex temp1 = originVertex;
		Vertex temp2 = originVertex;
		Vertex vertexToBeDeleted = null;

		Queue<Vertex> q = this.BFSTraversal();

		while( !q.isEmpty() )
		{
			temp1 = q.poll();
			if( temp1.getId() == vertexID )
			{
				vertexToBeDeleted = temp1;
				break;
			}

		}


		if( vertexToBeDeleted != null )
		{
			q = this.BFSTraversal();
			while( !q.isEmpty() )
			{
				q.poll().removeNeighbour( vertexToBeDeleted );
			}
		}

	}


	

	/**
	*Remove the vertices that have the given label from the graph.
	*/
	public void removeVertex(String label)
	{
		Vertex temp1 = originVertex;
		Vertex temp2 = originVertex;
		Vertex vertexToBeDeleted = null;

		Queue<Vertex> q = this.BFSTraversal();

		while( !q.isEmpty() )
		{
			temp1 = q.poll();
			if( temp1.getLabel() == label )
			{
				vertexToBeDeleted = temp1;
				break;
			}

		}


		if( vertexToBeDeleted != null )
		{
			q = this.BFSTraversal();
			while( !q.isEmpty() )
			{
				q.poll().removeNeighbour( vertexToBeDeleted );
			}
		}
	}


	

	/**
	*Filter the vertices by the given user-defined property and returns a subgraph of the graph.
	*/
	public void filterVertices(String key, String filter)
	{

	}


	

	/**
	* Generate the adjacency matrix representation of the graph and returns the matrix.
	*@return double array that represents the graph
	*/
	public double[][] exportMatrix()
	{
		ArrayList<Vertex> vertexArray = new ArrayList<Vertex>();
		Queue<Vertex> q = this.BFSTraversal();
		double[][] matrix = new double[q.size()][q.size()];

		while( !q.isEmpty() )
		{
			vertexArray.add( q.poll() );
		}


		for( int i=0;i<vertexArray.size();i++ )
		{
			for( int j=0;j<vertexArray.size();j++ )
			{
				if( vertexArray.get(j).getId() > vertexArray.get(i).getId() )
				{
					Collections.swap( vertexArray , j , i );
				}
			}
		}


		for( int i=0;i<vertexArray.size();i++ )
		{
			for( int j=0;j<vertexArray.size();j++ )
			{
				if( !isEdge( vertexArray.get(j),vertexArray.get(i) ) )
				{
					matrix[j][i] = 0.0;
				}
				else
				{
					matrix[j][i] = getEdge( vertexArray.get(j),vertexArray.get(i) ).getWeight();
				}
			}
		}



		return matrix;

	}


	/**
	*Prints the graph in matrix form
	*/
	public void printMatrix()
	{
		ArrayList<Vertex> vertexArray = new ArrayList<Vertex>();
		Queue<Vertex> q = this.BFSTraversal();
		double[][] matrix = exportMatrix();

		while( !q.isEmpty() )
		{
			vertexArray.add( q.poll() );
		}


		for( int i=0;i<vertexArray.size();i++ )
		{
			for( int j=0;j<vertexArray.size();j++ )
			{
				if( vertexArray.get(j).getId() > vertexArray.get(i).getId() )
				{
					Collections.swap( vertexArray , j , i );
				}
			}
		}



		System.out.printf("     ");
		for( int i=0;i<vertexArray.size();i++ )
		{
			System.out.printf("%d      ",vertexArray.get(i).getId());
		}


		System.out.println();
		for( int i=0;i<vertexArray.size();i++ )
		{
			System.out.printf("%d   ",vertexArray.get(i).getId());
			for( int j=0;j<vertexArray.size();j++ )
			{
				System.out.printf("%.2f   ",matrix[i][j]);
			}
			System.out.println();
			System.out.println();
		}
	}

	

	/**
	*Print the graph in adjacency list format (You should use the format that can be imported by the method in AbstarctGraph in the book).
	*/
	public void printGraph()
	{
		Queue<Vertex> bfsQueue = this.BFSTraversal();

		System.out.println("Graph is printed in adjacency list format :");

		while( !bfsQueue.isEmpty() )
		{
			Vertex temp = bfsQueue.poll();

			System.out.printf( "%d" , temp.getId() );

			for( int i=0;i<temp.adjecents.size();i++ )
			{
				System.out.printf( " --> %d" , ((Vertex)temp.adjecents.get(i)).getId() );
			}
			System.out.println();
			System.out.println();
		}
		System.out.println();
	}









	/**Accessor Methods
	*Return the number of vertices.
	*@return The number of vertices
	*/
	public int getNumV()
	{
		Queue<Vertex> q = this.BFSTraversal();

		int countNumOfVertices = 0;

		while( !q.isEmpty() )
		{

			countNumOfVertices++;

			q.poll();
		}

		return countNumOfVertices;
	}







	/** Determine whether this is a directed graph.
	*@return true if this is a directed graph
	*/
	public boolean isDirected()
	{
		return isDirected;
	}






	/** Insert a new edge into the graph.
	*@param edge The new edge
	*/
	public void insert(Edge edge)
	{

		Queue<Vertex> q = this.BFSTraversal();
		while( !q.isEmpty() )
		{
			if( edge.getSource() == q.peek() )
			{
				q.peek().addArrowFromThisVertex(edge);
				break;
			}

			q.poll();
		}
	}







	/** Determine whether an edge exists.
	*@param source The source vertex
	*@param dest The destination vertex
	*@return true if there is an edge from source to dest
	*/
	public boolean isEdge(Vertex source, Vertex dest)
	{


		for( int i=0;i<source.arrowsFromThisVertex.size();i++ )
		{
			if( ((Edge)source.arrowsFromThisVertex.get(i)).getDest() == dest )
			{
				return true;
			}
		}
		return false;
	}







	/** Get the edge between two vertices.
	*@param source The source vertex
	*@param dest The destination vertex
	*@return The Edge between these two vertices
	*or an Edge with a weight of
	*Double.POSITIVE_INFINITY if there is no edge
	*/
	public Edge getEdge(Vertex source, Vertex dest)
	{
		Edge result;


		for( int i=0;i<source.arrowsFromThisVertex.size();i++ )
		{
			if( ((Edge)source.arrowsFromThisVertex.get(i)).getDest() == dest )
			{
				return (Edge)source.arrowsFromThisVertex.get(i);
			}
		}
		return null;
	}






	/** Return an iterator to the edges connected
	*to a given vertex.
	*@param source The source vertex
	*@return An Iterator<Edge> to the vertices
	*connected to source
	*/
	public Iterator < Edge > edgeIterator(int source)
	{
		return null;
	}






	/**
	*@return all vertices in the graph in DFS order
	*/
	public Stack<Vertex> DFSTraversal()
	{
		Stack<Vertex> arr = new Stack<Vertex>();


		DFSTraversalhelper( arr , originVertex );


		clearVisitedMarks();
		return arr;
	}



	/**
	*Helps DFSTraversal()
	*@param arr stack that will be filled with vertices
	*@param v vertex that is currently being visited
	*/
	public void DFSTraversalhelper( Stack<Vertex> arr , Vertex v )
	{
		v.markVisited();

		for( int i=0;i<v.adjecents.size();i++ )
		{
			Vertex currentVertex = (Vertex)v.adjecents.get( v.adjecents.size() - i - 1);

			if( !currentVertex.isVisited() )
			{
				DFSTraversalhelper( arr,currentVertex );
			}
		}

		arr.push( v );
	}



	/**
	*@return vertices of the graph in BFS order
	*/
	public Queue<Vertex> BFSTraversal()
	{
		Queue<Vertex> traversalOrder = new LinkedList<Vertex>();
		Queue<Vertex> vertexQueue = new LinkedList<Vertex>();

		originVertex.markVisited();

		traversalOrder.offer(originVertex);
		vertexQueue.offer(originVertex);


		while( !vertexQueue.isEmpty() )
		{
			Vertex frontVertex = vertexQueue.poll();

			for( int i=0 ; i<frontVertex.adjecents.size() ; i++ )
			{
				Vertex neighbour = (Vertex)frontVertex.adjecents.get(i);

				if( !neighbour.isVisited() )
				{
					neighbour.markVisited();
					traversalOrder.offer(neighbour);
					vertexQueue.offer(neighbour);
				}
			}
		}


		clearVisitedMarks();
		return traversalOrder;

	}




	/**
	*Marks all vertices as unvisited
	*/
	private void clearVisitedMarks()
	{
		clearVisitedMarkshelper( originVertex );
	}


	/**
	*Helps clearVisitedMarks()
	*@param v start vertex
	*/
	private void clearVisitedMarkshelper( Vertex v )
	{
		v.markUnvisited();

		for( int i=0;i<v.adjecents.size();i++ )
		{
			Vertex currentVertex = (Vertex)v.adjecents.get( v.adjecents.size() - i - 1);

			if( currentVertex.isVisited() )
			{
				clearVisitedMarkshelper( currentVertex );
			}
		}
	}





	/**
	*This function calculates total distence between BFS and DFS
	*@param graph graph to be traversed
	*@return difference between BFS and DFS
	*/
	public static double traversalDifference( MyGraph graph ) throws Exception
	{
		Stack<Vertex> dfsStack = graph.DFSTraversal();
		Queue<Vertex> bfsQueue = graph.BFSTraversal();


		ArrayList<Vertex> dfsArray = new ArrayList<Vertex>();
		ArrayList<Vertex> bfsArray = new ArrayList<Vertex>();

		int sizeOfArrays = dfsStack.size();

		double dfsWeight = 0.0;
		double bfsWeight = 0.0;
		double difference = 0.0;


		if( dfsStack.size() != bfsQueue.size() )
		{
			throw new Exception("bfs and dfs different stack and queue size...");
		}


		while( !dfsStack.isEmpty() )
		{
			dfsArray.add( dfsStack.pop() );
			bfsArray.add( bfsQueue.poll() );
		}


		for( int i=0 ; i<sizeOfArrays ; i++ )
		{
			for( int j=i+1 ; j<sizeOfArrays ; j++ )
			{
				if( dfsArray.get(i).isNeighbour( dfsArray.get(j) )  )
				{
					dfsWeight += dfsArray.get(i).shortestPathWeightToTheNeighbour( dfsArray.get(j) );
				}
				if( bfsArray.get(i).isNeighbour( bfsArray.get(j) )  )
				{
					bfsWeight += bfsArray.get(i).shortestPathWeightToTheNeighbour( bfsArray.get(j) );
				}
			}	
		}
		return dfsWeight - bfsWeight;
	}






	/**
	*This function prints given graph in depth first search order
	*@param graph graph to be printed
	*/
	public static void printDFS( MyGraph graph )
	{
		Stack<Vertex> dfsStack = graph.DFSTraversal();


		System.out.printf("\nDfs treversal order --> ");
		while( !dfsStack.isEmpty() )
		{
			System.out.printf( "%d   " , dfsStack.pop().getId() );
		}
		System.out.println();
	}


	/**
	*This function prints given graph in breadth first search order
	*@param graph graph to be printed
	*/
	public static void printBFS( MyGraph graph )
	{
		Queue<Vertex> bfsQueue = graph.BFSTraversal();


		System.out.printf("\nBfs treversal order --> ");
		while( !bfsQueue.isEmpty() )
		{
			System.out.printf( "%d   " , bfsQueue.poll().getId() );
		}
		System.out.println();
	}




	/**
	*Returns origin vertex.
	*@return origin vertex
	*/
	public Vertex getOriginVertex()
	{
		return originVertex;
	}





	/**
	*This function calculates shortest paths between given start vertex and all other vertices
	*@param startVertex start vertex
	*/
	public void dijkstra( Vertex startVertex )
	{
		int numV = this.getNumV();
		Vertex keepOriginVertex = originVertex;
		originVertex = startVertex;
		Vertex[] p  = new Vertex[ numV ];
		double[] d = new double[ numV ];


		HashSet<Vertex> setVS = new HashSet<Vertex>(numV);



		Queue<Vertex> q = this.BFSTraversal();
		while( !q.isEmpty() )
		{
			if( q.peek() != startVertex )
			{
				setVS.add( q.peek() );
			}
			q.poll();
		}


		for( Vertex v: setVS )
		{
			p[v.getId()] = startVertex;
			if( this.getEdge( startVertex , v ) != null )
				d[v.getId()] =  this.getEdge( startVertex , v ).getWeight();
		}




		while( setVS.size() != 0 )
		{
			double minDistance = Double.POSITIVE_INFINITY;
			Vertex u = null;

			for( Vertex v : setVS )
			{
				if( d[v.getId()] < minDistance )
				{
					minDistance = d[ v.getId() ];
					u = v;
				}
			}

			setVS.remove( u );

			for( Vertex v : setVS )
			{
				if( this.isEdge( u , v ) )
				{
					double weight = getEdge( u , v ).getWeight();

					if( (d[ u.getId() ] + weight) < d[ v.getId() ] )
					{
						d[v.getId()] = d[u.getId()] + weight;
						p[v.getId()] = u;
					}
				}
			}
		}




		System.out.printf( "From vertex %d to...",startVertex.getId() );
		for(int i=0;i<numV;i++)
		{	
			if( i != startVertex.getId() )
			{
				System.out.println();
				System.out.printf("%d  -->  %.2f  ", i , d[i] );
			}
		}


		originVertex = keepOriginVertex;
	}












}




