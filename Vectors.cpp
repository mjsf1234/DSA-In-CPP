#include <iostream>
using namespace std;
#include <vector>
int main()
{
    // statically vector allocation
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    cout << v.size() << " " << v.at(3) << endl;
    v.pop_back();

    return 0;
}