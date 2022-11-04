#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **edges, int v, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " ";

        for (int i = 0; i < v; i++)
        {
            if (edges[front][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int v)
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
            printBFS(edges, v, i, visited);
        }
    }
}

void printDFS(int **edges, int v, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[sv][i] == 1)
        {
            if (!visited[i])
            {
                printDFS(edges, v, i, visited);
            }
        }
    }
}

void DFS(int **edges, int v)
{
    // maintaining the visited array
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, v, i, visited);
        }
    }
}

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
    cout << "BFS" << endl;
    BFS(edges, v);
    cout << endl
         << endl;
    cout << "DFS" << endl;
    DFS(edges, v);

    return 0;
}