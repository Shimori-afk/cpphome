#pragma once
#include <list>
#include <vector>
#include <iostream>

class Graph
{
public:
	enum class ConnectionType
	{
		undirected,
		directed
	};

	Graph(int vertixes, ConnectionType type = ConnectionType::undirected)
		: m_vertixes(vertixes), m_connectionType(type) {}

	virtual void addEdge(int v, int w) = 0;

	virtual void BFS(int vertex = 0) {};
	virtual void DFS(int vertex = 0) {};

protected:
	unsigned int m_vertixes;
	ConnectionType m_connectionType;



};

// using adjacency list
class GraphAdjList : public Graph
{
public:
	GraphAdjList(int vertixes, ConnectionType type = ConnectionType::undirected);
	void addEdge(int v, int w) override;

	void DFS(int vertex = 0) override;

	//	void BFS(int vertex = 0) override;

	int numberOfNodesInLevel(int level)
	{
		if (level < 0 || level >= m_vertixes)
		{
			return 0;
		}

		int count = 0;

		for (int i = 0; i < m_vertixes; i++)
		{
			DFS(level);
		}

		return count;
	}


private:
	std::vector<std::list<int> > m_list;

};

//#TODO HW
class GraphAdjMatrix : public Graph
{
	GraphAdjMatrix(int vertixes, ConnectionType type = ConnectionType::undirected)
		: Graph(vertixes, type)
	{

	}; //#TODO, IMPLEMENT if needed

	void addEdge(int v, int w) override {}; //#TODO IMPLEMENT
	void DFS(int vertex = 0) override {};	//#TODO IMPLEMENT

private:
	//#TODO

};
