#include <iostream>
using namespace std;
#include <cmath>

/* operations allowed
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).
*/

int countMinStepsToOne(int n)
{
    if (n == 1)
    {
        return 0;
    }
    int count1 = INT32_MAX;
    int count2 = INT32_MAX;
    int count3 = INT32_MAX;
    int count = INT32_MAX;
    if (n % 3 == 0)
    {
        count1 = countMinStepsToOne(n / 3);
    }
    if (n % 2 == 0)
    {
        count2 = countMinStepsToOne(n / 2);
    }
    count3 = countMinStepsToOne(n - 1);
    count = min(count1, min(count2, count3)) + 1;
    return count;
}

// using DP

int countStepToOneHelper(int n, int *ans)
{
    if (n <= 1)
    {
        return 0;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    // small calculation
    int count1 = INT32_MAX;
    int count2 = INT32_MAX;
    int count3 = INT32_MAX;
    int count = INT32_MAX;
    if (n % 3 == 0)
    {
        count1 = countStepToOneHelper(n / 3, ans);
    }
    if (n % 2 == 0)
    {
        count2 = countStepToOneHelper(n / 2, ans);
    }
    count3 = countStepToOneHelper(n - 1, ans);
    count = min(count1, min(count2, count3)) + 1;
    ans[n] = count;
    return count;
}

int countStepsToOne(int n)
{
    int *ans = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    return countStepToOneHelper(n, ans);
}

// TODO staircase problem;

long staicaseHelper(int n, long *ans, long target)
{
    // base case
    if (n == target)
    {
        return 1;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    long count1 = 0;
    long count2 = 0;
    long count3 = 0;
    long count = 0;
    count1 = staicaseHelper(n + 1, ans, target);
    if (n + 2 <= target)
    {
        count2 = staicaseHelper(n + 2, ans, target);
    }
    if (n + 3 <= target)
    {
        count3 = staicaseHelper(n + 3, ans, target);
    }
    count = count1 + count2 + count3;
    ans[n] = count;
    return count;
}

long staircase(int n)
{
    long target = n;
    long *ans = new long[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return staicaseHelper(0, ans, target);
}

// TODO mincount of square of number add upto to n;  n = x^2 + y^2 + ....

int minCountHelper(int n, int *ans, int target)
{
    int count = INT32_MAX;
    if (n <= 1)
    {
        count = n;
        return count;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    for (int i = 1; i <= sqrt(n); i++)
    {
        int temp = minCountHelper(n - pow(i, 2), ans, target) + 1;
        if (temp < count)
        {
            count = temp;
        }
    }
    ans[n] = count;
    return count;
}
int minCount(int n)
{
    int *ans = new int[n + 1];
    int target = n;
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    return minCountHelper(n, ans, target);
}

int balancedBTs(int n)
{
    // Write your code here
}
int main()
{
    // int ans = countMinStepsToOne(9);
    // int ans = countStepsToOne(9);
    // long ans = staircase(4);
    int ans = minCount(4);

    cout << ans;

    return 0;
}