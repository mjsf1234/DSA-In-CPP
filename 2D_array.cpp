#include <iostream>
using namespace std;

int main()
{
    cout << "enter row,column" << endl;
    int m, n, x, y;
    cin >> m >> n;
    int **p = new int *[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }
    cout << "enter the index" << endl;

    cin >> x >> y;
    cout << p[x][y] << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] p[i];
    }
    delete[] p;

    return 0;
}