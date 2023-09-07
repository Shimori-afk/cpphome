#include <iostream>
#include <vector>

enum class ConnectionType {
    undirected,
    directed
};

class Graph {
public:
    Graph(int vertices, ConnectionType type = ConnectionType::undirected)
        : numVertices(vertices), connectionType(type) {
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    virtual void addEdge(int v, int w) {
        adjacencyMatrix[v][w] = 1;

        if (connectionType == ConnectionType::undirected) {
            adjacencyMatrix[w][v] = 1;
        }
    }

    virtual void DFS(int vertex = 0) {
        std::vector<bool> visited(numVertices, false);
        DFSRecursive(vertex, visited);
    }

private:
    int numVertices;
    ConnectionType connectionType;
    std::vector<std::vector<int>> adjacencyMatrix;

    void DFSRecursive(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        std::cout << "Visited vertex: " << vertex << std::endl;

        for (int i = 0; i < numVertices; ++i) {
            if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
                DFSRecursive(i, visited);
            }
        }
    }
};

class GraphAdjMatrix : public Graph {
public:
    GraphAdjMatrix(int vertices, ConnectionType type = ConnectionType::undirected)
        : Graph(vertices, type) {}

};

int main() {
    GraphAdjMatrix graph(5, ConnectionType::undirected);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    std::cout << "DFS traversal starting from vertex 0:" << std::endl;
    graph.DFS(0);

    return 0;
}
