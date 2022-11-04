#include <iostream>
#include <queue>
using namespace std;

bool hasPathUsingDFSHelper(int **edges, int v, int sv, int end, bool *visited)
{
    visited[sv] = true;
    if (sv == end)
    {
        return true;
    }
    for (int i = 0; i < v; i++)
    {
        if (edges[sv][i] == 1)
        {
            if (!visited[i])
            {
                if (hasPathUsingDFSHelper(edges, v, i, end, visited))
                {
                    return true;
                };
            }
        }
    }
    return false;
}

bool hasPathUsingDFS(int **edges, int v, int start, int end)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    if (hasPathUsingDFSHelper(edges, v, start, end, visited))
    {
        return true;
    };

    return false;
}
//!________________________________________________________*/

bool hasPathUsingBFSHelper(int **edges, int v, int sv, int end, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int front = q.front();
        if (front == end)
        {
            return true;
        }
        q.pop();

        for (int i = 0; i < v; i++)
        {
            if (edges[front][i] == 1)
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
                // visited + edge
            }
        }
    }
    return false;
}
bool hasPathUsingBFS(int **edges, int v, int start, int end)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    if (hasPathUsingBFSHelper(edges, v, start, end, visited))
    {
        return true;
    };

    return false;
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

    cout << "enter the vetexes to find path between them" << endl;
    cin >> v1 >> v2;

    cout << "has path using the DFS " << (hasPathUsingDFS(edges, v, v1, v2) ? "true" : "false") << endl;
    cout << "has path using the BFS " << (hasPathUsingBFS(edges, v, v1, v2) ? "true" : "false");

    return 0;
}

/*
4 4
0 1
0 3
1 2
2 3
1 3
*/
