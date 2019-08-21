#include "Graph.cpp"
#include <vector>
#include <queue>
#include <stack>

class BreadthFirstSearch
{
    std::vector<bool> marked;
    std::vector<int> edgeTo;
    int source;

public:
    BreadthFirstSearch(Graph g, int s);
    void bfs(Graph g, int source);
    bool hasPathTo(int v);
    std::stack<int> pathTo(int v);
};

BreadthFirstSearch::BreadthFirstSearch(Graph g, int s)
{
    for (int i = 0; i < g.getVertices(); ++i)
    {
        marked.push_back(false);
        edgeTo.push_back(-1);
    }
    source = s;
    bfs(g, source);
}

void BreadthFirstSearch::bfs(Graph g, int source)
{
    std::queue<int> q;
    marked[source] = true;
    q.push(source);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w : g.getAdjacentToV(v))
        {
            if (!marked[w])
            {
                edgeTo[w] = v;
                marked[w] = true;
                q.push(w);
            }
        }
    }
}

bool BreadthFirstSearch::hasPathTo(int v)
{
    return marked[v];
}
std::stack<int> BreadthFirstSearch::pathTo(int v)
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