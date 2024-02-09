package com.YagizHakki;




import java.util.*;

/** Interface to specify a Graph ADT. A graph is a set
*   of vertices and a set of edges. Vertices are
*   represented by integers from 0 to n - 1. Edges
*   are ordered pairs of vertices. Each implementation
*   of the Graph interface should provide a constructor
*   that specifies the number of vertices and whether
*   or not the graph is directed.
*   @author Koffman and Wolfgang
*/

public interface Graph<T> {

  // Accessor Methods
  /** Return the number of vertices.
      @return The number of vertices
   */
  public int getNumV();







  /** Determine whether this is a directed graph.
      @return true if this is a directed graph
   */
  public boolean isDirected();







  /** Insert a new edge into the graph.
      @param edge The new edge
   */
  public void insert(Edge edge);







  /** Determine whether an edge exists.
      @param source The source vertex
      @param dest The destination vertex
      @return true if there is an edge from source to dest
   */
  boolean isEdge(Vertex source, Vertex dest);







  /** Get the edge between two vertices.
      @param source The source vertex
      @param dest The destination vertex
      @return The Edge between these two vertices
              or an Edge with a weight of
              Double.POSITIVE_INFINITY if there is no edge
   */
  Edge getEdge(Vertex source, Vertex dest);







  /** Return an iterator to the edges connected
      to a given vertex.
      @param source The source vertex
      @return An Iterator<Edge> to the vertices
              connected to source
   */
  Iterator < Edge > edgeIterator(int source);







}
