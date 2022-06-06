#include <iostream>
using namespace std;
int main()
{
    int ror = 3 | 4;
    int rand = 3 & 4;
    int rnot = ~3;
    int rxor = 3 ^ 4;
    int lshift = 3 << 2;
    int Rshift = 4 >> 2;

    cout << ror << endl;
    cout << rand << endl;
    cout << rnot << endl;
    cout << rxor << endl;
    cout << lshift << endl;
    cout << Rshift << endl;

    return 0;
}