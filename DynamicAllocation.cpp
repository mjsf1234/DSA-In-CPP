#include <iostream>
using namespace std;

int main()
{
    // different type of memory allocation at heap
    //   int* p = new int;
    //   *p = 10;
    //   cout<<*p<<endl;
    //   cout<<sizeof(p)<<endl;

    //  double* pd = new double;
    //  *pd = 10.4;
    //  cout<<*pd<<endl;

    // char* cp = new char;
    // *cp = 'a';
    // cout<<*cp<<endl;

    // float * fp = new float;
    // *fp = 45.5;
    // cout<<*fp<<endl;

    // dynamic memory allocation of array

    // int *pa = new int[50];

    // cout << "enter the size of array: " << endl;
    // int n;
    // cin >> n;
    // int *pa2 = new int[n];
    // int max = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> pa2[i];
    //     if (pa2[i] > max)
    //     {
    //         max = pa2[i];
    //     }
    // }
    // cout << "the max is " << max << endl;
    // Infinite loop is each time new 4 byte is forming check the memeory usage from task manager

    while (true)
    {
        int *p = new int;
    }
    return 0;
}