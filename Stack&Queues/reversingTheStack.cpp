#include <iostream>
using namespace std;
#include <stack>

int main()
{

    stack<int> s1;
    stack<int> s2;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    cout << s1.top() << " " << s1.size() << endl;

    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    s1 = s2;
    cout << s1.top() << " " << s1.size() << endl;

    // cout << s2.top() << " " << s2.size() << endl;

    return 0;
}