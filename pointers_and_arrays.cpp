#include <iostream>

using namespace std;
int main()
{
    int marks[4] = {12, 32, 34, 45};
    cout << marks[0] << endl;
    cout << marks[1] << endl;
    cout << marks[2] << endl;
    cout << marks[3] << endl;
    cout << "this is the address and value using pointers" << endl;

    int *p = marks;
    for (int i = 0; i < 4; i++)
    {
        cout << "the value of the mark[0]is " << *(p + 1) << endl;
    }

    return 0;
}