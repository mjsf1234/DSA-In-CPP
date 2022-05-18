#include <iostream>
using namespace std;
#include <queue>
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << " " << q.empty() << endl;

    return 0;
}