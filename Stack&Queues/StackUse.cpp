#include <iostream>
using namespace std;
#include "StackUsingArrays.h"
int main()
{

    StackUsingArray s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);

    cout << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.push(100);
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << endl;

    return 0;
}