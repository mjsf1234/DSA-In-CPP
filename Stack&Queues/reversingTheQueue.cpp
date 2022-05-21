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
    cout << q.size() << " " << q.front() << endl;
    int s = q.size();
    while (s != 0)
    {
        q.push(q.back());
        q.pop();
        s--;
    }
    cout << q.size() << " " << q.front() << endl;

    return 0;
}