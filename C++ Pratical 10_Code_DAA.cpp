#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

// Find the parent of a vertex
int findParent(int parent[], int x)
{
    if (parent[x] == x)
        return x;

    return findParent(parent, parent[x]);
}

// Join two sets
void unionSet(int parent[], int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    parent[v] = u;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[20];

    cout << "Enter edges (u v weight):" << endl;

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Sort edges by weight
    sort(edges, edges + E, [](Edge a, Edge b)
    {
        return a.weight < b.weight;
    });

    int parent[20];

    // Initially, every vertex is its own parent
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int totalCost = 0;
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        // If different parents, no cycle is formed
        if (parentU != parentV)
        {
            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unionSet(parent, u, v);

            count++;
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}