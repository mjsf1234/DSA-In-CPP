#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxSubstring(string s, string t)
{
    if (s.size() || t.size() == 0)
    {
        return 0;
    }

    if (s[0] == t[0])
    {
        return 1 + maxSubstring(s.substr(1), t.substr(1));
    }
    else
    {
        int a = maxSubstring(s.substr(1), t);
        int b = maxSubstring(s, t.substr(1));
        int c = maxSubstring(s.substr(1), t.substr(1));

        return max(a, max(b, c));
    }
}

int main()
{
    string s;
    string t;

    cin >> s;
    cin >> t;

    cout << maxSubstring(s, t);
}
