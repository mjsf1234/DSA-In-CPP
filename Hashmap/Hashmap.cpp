#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

int highestFrequency(int arr[], int n)
{
    int ans = arr[1];
    int max = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count += 1;
            }
        }
        if (count > max)
        {
            ans = arr[i];
            max = count;
        }
    }
    return ans;
}

// TODO : delete the repeating character in the string

string uniqueChar(string str)
{
    unordered_map<char, int> map;
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (map.count(str[i]) > 0)
        {
            continue;
        }

        ans += str[i];
        map[str[i]] = 1;
    }
    return ans;
}

void getPairsWithDifferenceK(int *arr, int n, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        int first = arr[i] + k;
        int second = arr[i] - k;

        unordered_map<int, int>::iterator it = map.find(first);
        unordered_map<int, int>::iterator it1 = map.find(second);
        if (it != map.end())
        {
            pair<int, int> p(arr[i], it->second);
            cout << p.first << " " << p.second << endl;
        }
        else if (it1 != map.end())
        {
            pair<int, int> p(arr[i], it1->second);
            cout << p.first << " " << p.second << endl;
        }
        else
        {
            map[arr[i]] = arr[i];
        }
    }
}

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
}

int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    // Write your code here
}

int main()
{
    /* unordered_map<string, int> ourmap; // unordered_map(key datatype, values datatype)
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
     cout << "the size of the map is " << ourmap.size() << endl;*/

    /*higher frequency array;
    int arr[] = {1, 2, 2, 1};
    cout << highestFrequency(arr, 4);*/

    /* string ans = uniqueChar("codingninjas");
     cout << ans;*/

    int ans[] = {4, 4, 4, 4};
    getPairsWithDifferenceK(ans, 4, 0);

    return 0;
}