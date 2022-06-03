#include <iostream>
using namespace std;
#include <vector>

// todo : find the maximum subarray
int maxSubArray(vector<int> &nums)
{
    int maxSum = nums[0];
    int currSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (currSum < 0)
        {
            currSum = 0;
        }
        currSum += nums[i];
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}

long int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int climbStairs(int n)
{
    int i = 0;
    int sum = 0;
    while ((n - 2 * i) >= 0)
    {
        sum += factorial(n - i) / (factorial(n - 2 * i) * factorial(i));
        i++;
    }
    return sum;
}

int main()
{
    cout << climbStairs(35);

    return 0;
}