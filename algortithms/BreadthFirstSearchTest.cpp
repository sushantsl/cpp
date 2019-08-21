#include <iostream>
#include "BreadthFirstSearch.cpp"

int main()
{
    Graph g(13);
    g.addEdge(0, 5);
    g.addEdge(4, 3);
    g.addEdge(0, 1);
    g.addEdge(9, 12);
    g.addEdge(6, 4);
    g.addEdge(5, 4);
    g.addEdge(0, 2);
    g.addEdge(11, 12);
    g.addEdge(9, 10);
    g.addEdge(0, 6);
    g.addEdge(7, 8);
    g.addEdge(9, 11);
    g.addEdge(5, 3);

    BreadthFirstSearch bfs(g, 0);

    int X = 4;
    std::stack<int> pathToX = bfs.pathTo(X);
    for (int i = 0; i < pathToX.size(); ++i)
    {
        std::cout << pathToX.top() << " -> ";
        pathToX.pop();
    }
    std::cout << X << std::endl;

    return 0;
}
