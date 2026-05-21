#include <iostream>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, w;
};

bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

int parent[100];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    parent[rootA] = rootB;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Edge edges[E];

    cout << "Enter source destination weight:\n";

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges, edges + E, compare);

    for(int i = 0; i < V; i++)
        parent[i] = i;

    int minCost = 0;

    cout << "\nEdges in MST:\n";

    for(int i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if(find(u) != find(v))
        {
            cout << u << " - " << v << " : " << w << endl;

            minCost += w;

            unionSet(u, v);
        }
    }

    cout << "\nMinimum Cost = " << minCost;

    return 0;
}
