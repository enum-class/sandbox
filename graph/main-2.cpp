#include <iostream>
#include <array>
#include <vector>
#include <queue>

#include "Graph.h"

using namespace std;

template<int V>
int BFS(GraphType2<V>& graph, int source, int destination)
{
	array<int, V> visited;
	visited.fill(0);

	queue<int> q;
	q.push(source);
	visited[source] = 1;

	while(!q.empty())
	{
		int node = q.front();
		cout << node << " -> ";
		q.pop();

		for (const int& n : graph.adj[node])
		{
			if (visited[n] == 0)
			{
				visited[n] = visited[node] + 1;
				q.push(n);
			}

			if (n == destination)
				return visited[n];
		}
	}
}

template <int SIZE>
void prime(int from, vector<int>& out)
{
	array<bool, SIZE> visited;
	visited.fill(false);

	for (int i=2; i * i <SIZE; i++)
	{
		if (!visited[i])
		{
			int tmp = i * i;
			while (tmp < SIZE)
			{
				visited[tmp] = true;
				tmp += i;
			}
		}
	}

	for (int i=from; i<SIZE; i++)
		if (!visited[i])
			out.push_back(i);
}

 //Returns true if num1 and num2 differ  
 // by single digit. 
bool hamming(int num1, int num2) 
{ 
	// To compare the digits 
	string s1 = to_string(num1); 
	string s2 = to_string(num2); 
	int c = 0;
	for (int i=0;i<s1.length();i++)
		if (s1[i] != s2[i]) 
			c++; 

	// If the numbers differ only by a single 
	// digit return true else false 
	return (c == 1); 
}

/**
 * Shortest path to reach one prime to other by changing single digit at a time
 *
 * Given two four digit prime numbers,
 * suppose 1033 and 8179, we need to find the shortest path from 1033 to 8179 by
 * altering only single digit at a time such that every number that we get afte
 * changing a digit is prime. For example a solution is 1033, 1733, 3733, 3739, 3779, 8779, 8179 
 */
void shortestPath(int source, int destination)
{
	vector<int> primes;
	prime<100>(10, primes);
	int size = primes.size();
	GraphType2<100> g;

	for (int i=0;i<primes.size();i++)
		for (int j=i+1;j<primes.size();j++)
			if (hamming(primes[i], primes[j]))
			{
				g.addEdge(primes[i], primes[j]);
				g.addEdge(primes[j], primes[i]);
			}

	g.print();
	cout << "LENGTH: " << BFS<100>(g, source, destination) << endl;
}

int main()
{
	shortestPath(11, 97);
//	vector<int> res;
//	prime<100>(10, res);
//	
//	for (int i : res)
//		cout << i << " ";
//
//	cout << endl << res.size() << endl;
	return 0;
}
