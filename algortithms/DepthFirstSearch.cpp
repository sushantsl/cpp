#include "Graph.cpp"
#include <iostream>
#include <vector>
#include <stack>

class DepthFirstSearch
{
    std::vector<bool> marked;
    std::vector<int> edgeTo;
    int count;
    int source;

public:
    DepthFirstSearch(Graph g, int s);
    void dfs(Graph g, int vertex);
    bool hasPathTo(int v);
    int getCount();
    std::stack<int> pathTo(int v);
};
bool DepthFirstSearch::hasPathTo(int v)
{
    return marked[v];
}
int DepthFirstSearch::getCount()
{
    return count;
}
std::stack<int> DepthFirstSearch::pathTo(int v)
{
    std::stack<int> path;
    if (hasPathTo(v))
    {
        for (int x = v; x != source; x = edgeTo[x])
        {
            path.push(x);
        }
        path.push(source);
    }
    return path;
}
DepthFirstSearch::DepthFirstSearch(Graph g, int s)
{
    for (int i = 0; i < g.getVertices(); ++i)
    {
        marked.push_back(false);
        edgeTo.push_back(-1);
    }
    source = s;
    dfs(g, s);
}
void DepthFirstSearch::dfs(Graph g, int vertex)
{
    marked[vertex] = true;
    count++;
    for (int w : g.getAdjacentToV(vertex))
    {
        if (!marked[w])
        {
            edgeTo[w] = vertex;
            dfs(g, w);
        }
    }
}
