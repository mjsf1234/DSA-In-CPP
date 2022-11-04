#include <iostream>
using namespace std;

void connectedIslandHelper(int **edges, int v, int sv, bool *visited)
{
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[sv][i] == 1)
        {
            if (!visited[i])
            {
                connectedIslandHelper(edges, v, i, visited);
            }
        }
    }
}

int connectedIsland(int **edges, int v)
{

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    int count = 0;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            count += 1;
            connectedIslandHelper(edges, v, i, visited);
        }
    }
    return count;
}

int main()
{
    int v, e, v1, v2;
    cin >> v >> e;

    // adjacent matrix
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int first, second;
        cin >> first >> second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    cout << connectedIsland(edges, v);
    return 0;
}