#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge
{
    int u, v, w;
};

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter source destination weight:\n";

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[source] = 0;

    for(int i = 0; i < V - 1; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    for(int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Negative weight cycle exists";
            return 0;
        }
    }

    cout << "\nVertex\tDistance\tPath\n";

    for(int i = 0; i < V; i++)
    {
        cout << i << "\t" << dist[i] << "\t\t";

        vector<int> path;
        int current = i;

        while(current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }

        for(int j = path.size() - 1; j >= 0; j--)
        {
            cout << path[j];

            if(j != 0)
                cout << " -> ";
        }

        cout << endl;
    }

    return 0;
}
