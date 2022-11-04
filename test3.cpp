#include <iostream>
using namespace std;

int minimumMoves(int A, int B)
{
    if (A == B)
    {
        return 1;
    }

    if (A > B)
    {

        if ((A % B) == 0)
        {
            return A / B;
        }
        return ((A / B) + minimumMoves(A % B, B));
    }
    if (B > A)
    {
        if ((B % A) == 0)
        {
            return B / A;
        };
        return ((B / A) + minimumMoves(A, B % A));
    }
}

int main()
{
    int a = 3;
    int b = 8;
    cout << minimumMoves(a, b);

    return 0;
}