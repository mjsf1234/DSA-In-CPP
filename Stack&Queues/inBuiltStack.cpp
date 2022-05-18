#include <iostream>
using namespace std;
#include <stack>

int main()
{
    stack<int> s1;
    s1.push(12);
    s1.push(13);
    s1.push(14);
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << " " << s1.empty() << endl;

    return 0;
}