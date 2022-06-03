#include <iostream>
using namespace std;
#include <vector>
int searchInsert(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return start;
}

vector<int> takeInput()
{
    vector<int> v;
    int n;
    cout << "enter the size of array: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        v.push_back(j);
    }
    return v;
}

int main()
{
    vector<int> v = takeInput();
    cout << v.size() << endl;
    int ans = searchInsert(v, 2);
    cout << ans;

    return 0;
}