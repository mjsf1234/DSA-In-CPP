#include <iostream>
using namespace std;
#include <vector>
int main()
{

    vector<int> v{1, 2, 3, 4};
    vector<int> v1(v.begin(), v.end());
    std::vector<int>::iterator it = v1.begin();
    while (it != v1.end())
    {
        std::cout << *it << ' ';
        ++it;
    }
    return 0;
}