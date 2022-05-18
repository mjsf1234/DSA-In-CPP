#include <stack>
#include <iostream>
#include <string>

#include <iostream>
using namespace std;

int main()
{

    return 0;
}
bool isBalanced(string expression)
{
    stack<char> s;
    string str = expression;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        };

        if (str[i] == ')')
        {
            if (s.empty())
            {
                return false;
            }
            else
            {
                s.pop();
            };
        }
    };

    return (s.size() == 0);
}