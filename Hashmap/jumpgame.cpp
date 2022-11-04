#include <vector>
#include <iostream>
using namespace std;

int jump(vector<int> &nums)
{

    vector<int> v(nums.size(), 0);

    int n = nums.size(); // size of the array
    int last = n - 1;
    v[last] = 0;

    for (int i = 1; i < n; i++)
    {

        if (nums[last - i] > i)
        {
            v[last - i] = 1;
        }

        if (nums[last - i] == 0)
        {
            v[last - i] = 0;
        }

        else
        {

            int min = INT32_MAX;
            for (int j = 1; j <= nums[last - i]; j++)
            {
                if ((v[last - i + j] + 1) < min)
                {
                    min = v[last - i + j] + 1;
                }
            }

            v[last - i] = min;
        }
    }
    return v[0];
};

int main()
{
    vector<int> v{2, 3, 1, 1, 4};
    cout << jump(v);
    return 0;
}