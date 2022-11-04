#include <iostream>
using namespace std;
#include <vector>

void printAllConnectedComponentHelper(int **edges, int v, int sv, bool *visited, vector<int> &res)
{
    res.push_back(sv);
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[sv][i] == 1)
        {
            if (!visited[i])
            {
                printAllConnectedComponentHelper(edges, v, i, visited, res);
            }
        }
    }
}
void printAllConnectedComponent(int **edges, int v)
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
            vector<int> res;
            printAllConnectedComponentHelper(edges, v, i, visited, res);
            for (int i = 0; i < res.size(); i++)
            {
                cout << res[i] << " ";
            }
            cout << endl;
        }
    }
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

    printAllConnectedComponent(edges, v);

    return 0;
}