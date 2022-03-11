#include <iostream>
#include <queue>
#include <array>
#include "Graph.h"

using namespace std;

template<int V>
void BFS(GraphType2<V>& graph, int source)
{
	array<bool, V> visited;
	visited.fill(false);

	queue<int> q;
	q.push(source);
	visited[source] = true;

	while(!q.empty())
	{
		int node = q.front();
		cout << node << " -> ";
		q.pop();

		for (const int& n : graph.adj[node])
		{
			if (!visited[n])
			{
				visited[n] = true;
				q.push(n);
			}
		}
	}
}

template<int V>
void DFS(GraphType2<V>& graph, array<bool, V>& visited, int source)
{
	visited[source] = true;
	cout << source << " -> ";
	
	for (const int& node : graph.adj[source])
	{
		if (!visited[node])
			DFS<V>(graph, visited, node);
	}
}

/**
 * A mother vertex in a graph G = (V,E) is a vertex v such that
 * all other vertices in G can be reached by a path from v.
 *
 * A Naive approach : 
 * A trivial approach will be to perform a DFS/BFS on all the vertices and
 * find whether we can reach all the vertices from that vertex.
 * This approach takes O(V(E+V)) time, which is very inefficient for large graphs.
 *
 * We can find a mother vertex in O(V+E) time. 
 * If there exist mother vertex (or vertices), then one of the mother vertices is
 * the last finished vertex in DFS. (Or a mother vertex has the maximum finish time in DFS traversal).
 */
void motherVertex()
{
}

/**
 * Given a directed graph, find out if a vertex v is reachable from another vertex u for all vertex pairs (u, v) in the given graph.
 * Here reachable mean that there is a path from vertex u to v. The reach-ability matrix is called transitive closure of a graph.
 */
template<int V>
void transitiveClosure(GraphType2<V>& graph)
{
	array< array<bool, V>, V > reachability;
	for (array<bool, V>& row : reachability)
		row.fill(false);

	array<bool, V> visited;

	for (int i=0; i < V; i++)
	{
		visited.fill(false);
		DFS<V>(graph, visited, i);
		reachability[i] = visited;
	}

	for (array<bool, V>& row : reachability)
	{
		for (bool& ele : row)
			cout << ele << " ";
		cout << endl;
	}
}

/**
 * Given a graph G and an integer K, K-cores of the graph are connected components
 * that are left after all vertices of degree less than k have been removed`
 */
template<int V>
void kCores(GraphType1<V>& g, int k)
{
	for (int i=0; i < V; i++)
	{
		int w = g.getWeight(i);
		if (w < k && w > 0)
		{
			g.removeVertex(i);
			kCores(g, k);
		}
	}
}

template<int V>
void countAllPath(GraphType1<V>& g, int source, int destination)
{
}

int main()
{
	GraphType2<4> g;
	
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	
	GraphType1<9> g2;
	g2.addEdge(0, 1); 
	g2.addEdge(0, 2); 
	g2.addEdge(1, 2); 
	g2.addEdge(1, 5); 
	g2.addEdge(2, 3); 
	g2.addEdge(2, 4); 
	g2.addEdge(2, 5); 
	g2.addEdge(2, 6); 
	g2.addEdge(3, 4); 
	g2.addEdge(3, 6); 
	g2.addEdge(3, 7); 
	g2.addEdge(4, 6); 
	g2.addEdge(4, 7); 
	g2.addEdge(5, 6); 
	g2.addEdge(5, 8); 
	g2.addEdge(6, 7); 
	g2.addEdge(6, 8);
	g2.print();

	return 0;
}
