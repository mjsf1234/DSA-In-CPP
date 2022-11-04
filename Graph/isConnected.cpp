#include <iostream>
using namespace std;

void DFS(int **edges, int v, int sv, bool *visited)
{
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[sv][i] == 1)
        {
            if (!visited[i])
            {
                DFS(edges, v, i, visited);
            }
        }
    }
}

bool isConnected(int **edges, int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    DFS(edges, v, 0, visited);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << "enter the number of v, e" << endl;
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

    cout << isConnected(edges, v);

    return 0;
}