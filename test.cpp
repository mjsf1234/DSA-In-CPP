#include <iostream>
using namespace std;
#include <vector>

// todo: find the maximum
int maxProfit(int a[], int size)
{
    int buy = INT32_MAX;
    int sell = 0;
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        buy = min(buy, a[i]);
        int profit = a[i] - buy;
        ans = max(ans, profit);
    }
    return ans;
}
int main()
{
    int a[] = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(a, 6);

    return 0;
}