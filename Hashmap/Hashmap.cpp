#include <iostream>
using namespace std;
#include <unordered_map>

int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        if (map.count(arr[i]) > 0)
        {
            arr[i] += 1;
        }
        map[arr[i]] = 1;
    }
    for (int i = map.begin(); i != map.end(); i++)
    {
    }
}

int main()
{
    unordered_map<string, int> ourmap; // unordered_map(key datatype, values datatype)
    // insertion operation
    ourmap["first"] = 1;
    ourmap["second"] = 2;
    ourmap["third"] = 3;
    // another methode of insertion
    pair<string, int> p("forth", 4);
    ourmap.insert(p);

    // access the element
    cout << ourmap.at("first") << endl; // this will throws the error of "out rof range" in case key not found
    cout << ourmap["first"] << endl;    // this will insert the zero(default) in case key not found

    // check if the key is present or not
    if (ourmap.count("first") > 0)
    {
        cout << "the value of first " << ourmap["first"] << endl;
    }

    // size of map
    cout << "the size of the map is " << ourmap.size() << endl;

    // erase
    ourmap.erase("second");
    cout << "the size of the map is " << ourmap.size() << endl;

    return 0;
}