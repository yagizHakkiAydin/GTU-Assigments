package com.YagizHakki;

import java.util.ArrayList;

//index (ID), a label, and a weight.

public class Vertex<T>
{

	private int Id;

	private String label;

	private double weight;

	private T data;

	private boolean isVisited;

	private double boostValue;

	public ArrayList<Edge> arrowsFromThisVertex;

	public ArrayList<Vertex> adjecents;




	public Vertex()
	{
		this( -1 , null , 0.0 , null );
	}




	public Vertex( int vertexId , String vertexLabel , double vertexWeight , T vertexData)
	{
		Id = vertexId;
		label = vertexLabel;
		weight = vertexWeight;
		data = vertexData;
		isVisited = false;
		arrowsFromThisVertex = new ArrayList<Edge>();
		adjecents = new ArrayList<Vertex>();
		boostValue = 0.0;
	}



	public Vertex( Vertex v )
	{
		Id = v.getId();
		label = v.getLabel();
		weight = v.getWeight();
		data = (T)v.getData();
		isVisited = v.isVisited();
		arrowsFromThisVertex = new ArrayList<Edge>(v.arrowsFromThisVertex);
		adjecents = new ArrayList<Vertex>( v.adjecents );
		boostValue = v.getBoostValue();
	}



	public void setId( int newId )
	{
		Id = newId;
	}




	public void setLabel( String newLabel )
	{
		label = newLabel;
	}





	public void setWeight( double newWeight )
	{
		weight = newWeight;
	}
	

	public void setData(T data)
	{
		this.data = data;
	}



	public void setBoostValue(double v)
	{
		this.boostValue = v;
	}










	public int getId()
	{
		return Id;
	}




	public String getLabel()
	{
		return label;
	}





	public double getWeight()
	{
		return weight;
	}
	


	public T getData()
	{
		return data;
	}



	public boolean hasNeighbour()
	{
		return !adjecents.isEmpty();
	}


	public double getBoostValue()
	{
		return boostValue;
	}


	public Vertex getFirstNeighbour()
	{
		if( !this.hasNeighbour() )
		{
			return null;
		}
		else
		{
			return adjecents.get(0);
		}
	}

	public void addArrowFromThisVertex( Edge e )
	{
		for(int i=0;i<arrowsFromThisVertex.size();i++)
		{
			if( e == arrowsFromThisVertex.get(i) )
			{
				return;
			}
		}
		arrowsFromThisVertex.add( e );

		this.setWeight( this.getWeight() + e.getWeight() );
	}


	public void addNeighbour( Vertex newNeighbour , double weightOfPath )
	{
		Edge arrowFromThisVertexToNewNeighbour = new Edge( this,newNeighbour,weightOfPath );
		adjecents.add( newNeighbour );
		this.addArrowFromThisVertex(arrowFromThisVertexToNewNeighbour);
	}


	public void removeNeighbour( Vertex neighbourToBeRemoved )
	{
		for( int i=0;i<adjecents.size();i++ )
		{
			if( adjecents.get(i) == neighbourToBeRemoved )
			{
				adjecents.remove(i);
				arrowsFromThisVertex.remove(i);
				break;
			}
		}
	}






	public void printNeighbours()
	{

		System.out.printf("%d",this.getId());

		for( int i=0;i<adjecents.size();i++ )
		{
			System.out.printf("-->");
			System.out.printf("%d",adjecents.get(i).getId());
		}
	}


	public void markVisited()
	{
		isVisited = true;
	}

	public void markUnvisited()
	{
		isVisited = false;
	}


	public boolean isVisited()
	{
		return isVisited;
	}







	public double shortestPathWeightToTheNeighbour( Vertex neighbour )
	{
		double weight = -1.0;

		for( int i=0 ; i<arrowsFromThisVertex.size() ; i++ )
		{
			if( arrowsFromThisVertex.get(i).getDest() == neighbour )
			{
				if( weight == -1.0 )
				{
					weight = arrowsFromThisVertex.get(i).getWeight();
				}
				else if( weight > arrowsFromThisVertex.get(i).getWeight() )
				{
					weight = arrowsFromThisVertex.get(i).getWeight();
				}
			}
		}

		return weight;
	}


	public boolean isNeighbour(Vertex v)
	{
		for( int i=0 ; i<adjecents.size() ; i++ )
		{
			if( adjecents.get(i) == v )
			{
				return true;
			}
		}
		return false;
	}







}









