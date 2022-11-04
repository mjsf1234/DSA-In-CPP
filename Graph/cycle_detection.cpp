#include <iostream>
#include <queue>
using namespace std;

bool isCyclicUsingDFSHelper(int **edges, int sv, int v, int parent, bool *visited)
{
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[sv][i] == 1)
        {
            if (!visited[i])
            {
                return isCyclicUsingDFSHelper(edges, i, v, sv, visited);
            }
            // visited + edge
            else if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCyclicGraphUsingDFS(int **edges, int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            bool result = isCyclicUsingDFSHelper(edges, i, v, -1, visited);
            if (result)
            {
                return true;
            }
        }
    }
    return false;
}

//*! _____________________________________________________________*/

//? detect the cycle in graph using BFS

bool isCyclicGraphUingBFSHelper(int **edges, int v, int sv, bool *visited)
{
    queue<pair<int, int>> q;
    q.push(pair<int, int>(sv, -1));
    visited[sv] = true;

    while (!q.empty())
    {
        int front = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int i = 0; i < v; i++)
        {
            if (edges[front][i] == 1)
            {
                if (!visited[i])
                {
                    q.push(pair<int, int>(i, front));
                    visited[i] = true;
                }

                // have edges and visited
                else if (i != parent)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool isCyclicGraphUsingBFS(int **edges, int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            bool result = isCyclicGraphUingBFSHelper(edges, v, i, visited);
            if (result)
            {
                return true;
            }
        }
    }
    return false;
}

//*! _____________________________________________________________*/

int main()
{
    cout << "enter the number of v, e" << endl;
    int v, e;
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

    cout << "is cyclic using DFS  " << isCyclicGraphUsingDFS(edges, v) << endl;
    cout << "is cyclic using BFS  " << isCyclicGraphUsingBFS(edges, v);

    return 0;
}