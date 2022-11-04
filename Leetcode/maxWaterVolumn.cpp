#include <iostream>
using namespace std;
#include <vector>

int maxArea(vector<int> &height)
{
    int front = 0;
    int back = height.size() - 1;

    int ans = 0;

    while (front != back)
    {

        int area = (back - front) * min(height[front], height[back]);

        ans = max(ans, area);

        if (height[front] > height[back])
        {
            back--;
        }
        else
        {
            front++;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(v);

    return 0;
}