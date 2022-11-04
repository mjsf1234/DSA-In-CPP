#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

class Edge
{
public:
    int src;
    int des;
    int weight;

    Edge(int src, int des, int weight)
    {
        this->des = des;
        this->src = src;
        this->weight = weight;
    }
};

vector<Edge> Krushkal(vector<Edge> inputArray)
{
    vector<Edge> output;
    vector<int> parent(inputArray.size());
    for (int i = 0; i < inputArray.size(); i++)
    {
        parent[i] = i;
    }

    int count = 0;
    while (count < inputArray.size() - 1)
    {
        Edge curreEdge = inputArray[count];
        int src = curreEdge.src;
        int des = curreEdge.des;

        // check parent of src
        int p1 = src;

        while (parent[p1] != p1)
        {
            p1 = parent[p1];
        }

        // check parent of dese
        int p2 = des;

        while (parent[p2] != p2)
        {
            p2 = parent[p2];
        }
        if (p1 != p2)
        {
            output.push_back(curreEdge);
            count++;
            parent[p2] = p1;
        }
    }

    return output;
}

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

vector<Edge> takeInput()
{
    cout << "n,e" << endl;
    int n, e;
    cin >> n >> e;
    vector<Edge> inputArray;

    for (int i = 0; i < e; i++)
    {
        int src, des, weight;
        cin >> src >> des >> weight;

        inputArray.push_back(Edge(src, des, weight));
    }

    sort(inputArray.begin(), inputArray.end(), compare);

    return inputArray;
}

int main()
{
    vector<Edge> input = takeInput();
    vector<Edge> output = Krushkal(input);
    cout << " " << endl;
    for (auto &it : output)
    {
        if (it.src <= it.des)
        {
            cout << it.src << " " << it.des << " " << it.weight << endl;
        }
        else
        {
            cout << it.des << " " << it.src << " " << it.weight << endl;
        }
    }

    return 0;
}