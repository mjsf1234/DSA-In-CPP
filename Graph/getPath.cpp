#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>

vector<int> getpathUsingDFSHelper(int **edges, int v, int start, int end, bool *visited)
{
    visited[start] = true;

    vector<int> _v;
    if (start == end)
    {
        return {end};
    }

    for (int i = 0; i < v; i++)
    {
        if (edges[start][i] == 1)
        {
            if (!visited[i])
            {
                _v = getpathUsingDFSHelper(edges, v, i, end, visited);
                _v.push_back(start);
                return _v;
            }
        }
    }
    return {};
}

vector<int> getpathUsingDFS(int **edges, int v, int start, int end)
{
    // visited array
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    return getpathUsingDFSHelper(edges, v, start, end, visited);
}

vector<int> getpathUsingBFSHelper(int **edges, int v, int start, int end, bool *visited)
{
    vector<int> res;
    unordered_map<int, int> m;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        if (front == end)
        {
            res.push_back(end);
            unordered_map<int, int>::iterator it = m.find(end);
            while (it != m.end())
            {
                res.push_back(it->second);
                it = m.find(it->second);
            }
            return res;
        }
        for (int i = 0; i < v; i++)
        {
            if (edges[front][i] == 1)
            {
                if (!visited[i])
                {
                    m[i] = front;
                    q.push(i);

                    visited[i] = true;
                    if (i == end)
                    {
                        break;
                    }
                }
            }
        }
    }
    return res;
}

vector<int> getpathUsingBFS(int **edges, int v, int start, int end)
{
    // visited array
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    return getpathUsingBFSHelper(edges, v, start, end, visited);
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

    // vector<int> res = getpathUsingDFS(edges, v, v1, v2);
    vector<int> res = getpathUsingBFS(edges, v, v1, v2);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

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