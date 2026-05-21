#include <iostream>
using namespace std;

int graph[10][10], visited[10], n;

bool dfs(int current, int destination)
{
    if(current == destination)
        return true;

    visited[current] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[current][i] == 1 && visited[i] == 0)
        {
            if(dfs(i, destination))
                return true;
        }
    }

    return false;
}

int main()
{
    int edges, u, v, source, destination;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    for(int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter source and destination: ";
    cin >> source >> destination;

    if(dfs(source, destination))
        cout << "Path exists";
    else
        cout << "Path does not exist";

    return 0;
}
