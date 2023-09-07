#include "Graph.h"
#include <unordered_set>
#include <unordered_map>

GraphAdjList::GraphAdjList(int Vertixes, ConnectionType type)
	: Graph(Vertixes, type)
{
	m_list.resize(Vertixes);
}

void GraphAdjList::addEdge(int v, int w)
{

	m_list[v].push_back(w);

	if (m_connectionType == ConnectionType::undirected)
	{
		m_list[w].push_back(v);
	}
}

void GraphAdjList::DFS(int v)
{
	std::unordered_map<int, bool> visited;
	std::unordered_map<int, std::list<int> > adj;

	void addEdge(int v, int w);

	void DFS(int v);

	visited[v] = true;

	std::cout << v << " ";

	std::list<int>::iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (!visited[*i])
		{
			DFS(*i);
		}
	}


};

//void GraphAdjList::BFS(int vertex)
//{
//	// Mark all the vertices as not visited
//	std::unordered_set<int> visited;
//	std::list<int> queue;
//
//	// Mark the current node as visited and enqueue it
//	visited.insert(vertex);
//	queue.push_back(vertex);
//
//	while (!queue.empty())
//	{
//		// Dequeue a vertex from queue and print it
//		int currentVertex = queue.front();
//		std::cout << currentVertex << " ";  //or make anything else with it: push to vector, string, another object, whatever
//		queue.pop_front();
//
//		// Get all adjacent vertices
//		for (int adjacent : m_list[currentVertex])
//		{
//			if (!visited.count(adjacent))
//			{
//				visited.insert(adjacent);
//				queue.push_back(adjacent);
//			}
//		}
//	}
//}

