#include <iostream>
using namespace std;
#include "hashMap.h"

int main()
{
    ourmap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        // cout << key << " " << value << endl;
        map.insert(key, value);
    }

    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << " " << map.getValue(key) << endl;
    }

    return 0;
}