#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>

// TODO : return the trancated value
int divide(int dividend, int divisor)
{
    int sign = 1;
    if ((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0))
    {
        sign = -1;
        // cout << sign << endl;
    }
    int quotient = 0;
    dividend = std::abs(dividend);
    divisor = std::abs(divisor);
    cout << dividend << endl;
    while (dividend >= divisor)
    {
        dividend -= divisor;
        quotient++;
    }

    cout << sign << endl;
    int ans = sign * quotient;
    if (ans > INT32_MAX)
    {
        return INT32_MAX;
    }
    if (ans < INT32_MIN)
    {
        return INT32_MIN;
    }
    return ans;
}

int main()
{
    cout << divide(-2147483648, -1);
    return 0;
}