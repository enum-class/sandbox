#ifndef GRAPH_H_
#define GRAPH_H_

#include <array>
#include <vector>
#include <iostream>

using namespace std;

template <int V>
class GraphType1
{
public:
	typedef array<array<int, V>, V> Adjacency;

	explicit GraphType1(const Adjacency& adj)
	: adj(adj)
	{
	}

	GraphType1(const GraphType1& graph)
	: adj(graph.adj)
	{
	}

	GraphType1(GraphType1&& graph) noexcept
	: adj(std::move(graph.adj))
	{
	}

	GraphType1()
	{
		for (array<int, V>& row : adj)
			row.fill(0);
	}

	~GraphType1() = default;

	void addEdge(int source, int destination, int weight = 1)
	{
		adj[source][destination] = weight;
		adj[destination][source] = weight;
	}

	bool isConnected(int source, int destination) const noexcept
	{
		return adj[source][destination] != 0;
	}

	void removeVertex(int v)
	{
		adj[v].fill(0);
		for (array<int, V>& row : adj)
			row[v] = 0;
	}

	int getWeight(int v)
	{
		int weight = 0;
		for (const int& i : adj[v])
			weight += i;

		return weight;
	}

	void print() const noexcept
	{
		for (int i = 0; i < V; ++i)
		{
			for (int j = 0; j < V; ++j)
			{
				cout << adj[i][j] << " ";
			}

			cout << endl;
		}
	}

	Adjacency adj;
};

template <int V>
class GraphType2
{
public:
	typedef array<vector<int>, V> Adjacency;
	Adjacency adj;

	GraphType2() = default;
	~GraphType2() = default;

	explicit GraphType2(const Adjacency& adj)
	: adj(adj)
	{
	}

	GraphType2(const GraphType2& graph)
	: adj(graph.adj)
	{
	}

	GraphType2(GraphType2&& graph) noexcept
	: adj(std::move(graph.adj))
	{
	}

	void addEdge(int source, int destination)
	{
		adj[source].push_back(destination);
	}

	bool isConnected(int source, int destination) const noexcept
	{
		for (const int& ele : adj[source])
			if (ele == destination)
				return true;

		return false;
	}

	void print() const noexcept
	{
		for (int i = 0; i < V; ++i)
		{
			if (!adj[i].empty())
			{
				cout << "Node " << i << ": ";
				for (const int& ele : adj[i])
				{
					cout << ele << " ";
				}

				cout << endl;
			}
		}
	}
};

#endif
