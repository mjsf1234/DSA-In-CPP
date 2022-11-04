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

/* take input functions*/
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
    // for (auto i : inputArray)
    // {
    //     cout << i.des << " " << i.src << " " << i.weight << endl;
    // }

    return inputArray;
}

int main()
{
    takeInput();

    return 0;
}