#include <iostream>
using namespace std;

#define INF 999

int main()
{
    int n;
    int graph[10][10];
    int visited[10] = {0};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];

            // 0 means there is no edge
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    // Start from vertex 0
    visited[0] = 1;

    int edges = 0;
    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:" << endl;

    while (edges < n - 1)
    {
        int min = INF;
        int u = -1;
        int v = -1;

        // Find the smallest edge
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Add edge to MST
        cout << u << " - " << v << " : " << min << endl;

        totalCost += min;
        visited[v] = 1;
        edges++;
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}