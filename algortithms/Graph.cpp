#include <vector>
class Graph
{
    int nVertices;
    int nEdges;
    std::vector<std::vector<int>> adjacency;

public:
    Graph(int vertices);
    int getVertices();
    int getEdges();
    std::vector<int> getAdjacentToV(int v);
    void addEdge(int v, int w);
};

Graph::Graph(int vertices)
{
    nVertices = vertices;
    nEdges = 0;
    for (int i = 0; i < vertices; ++i)
    {
        std::vector<int> v;
        adjacency.push_back(v);
    }
}

int Graph::getVertices()
{
    return nVertices;
}

int Graph::getEdges()
{
    return nEdges;
}

std::vector<int> Graph::getAdjacentToV(int v)
{
    return adjacency[v];
}

void Graph::addEdge(int v, int w)
{
    adjacency[v].push_back(w);
    adjacency[w].push_back(v);
    nEdges++;
}