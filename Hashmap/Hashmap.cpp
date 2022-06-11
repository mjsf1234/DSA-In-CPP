#include <iostream>
using namespace std;
#include <unordered_map>

int main()
{
    unordered_map<string, int> ourmap;
    ourmap["firsts"] = 1;
    ourmap["second"] = 2;
    ourmap["third"] = 3;
    cout << ourmap["third"];
    return 0;
}