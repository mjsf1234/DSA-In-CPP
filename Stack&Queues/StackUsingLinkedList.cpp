#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    // constructor
    Node(T x)
    {
        this->data = x;
        this->next = NULL;
    }
};

template <typename T>
class Stack
{
private:
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    bool isEmpty() { return (size == 0); }

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        T ans = head->data;
        head = head->next;
        size--;
        return ans;
    }

    T top()
    {

        if (isEmpty())
        {
            return 0;
        }

        return head->data;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{

    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getSize() << " " << s.top() << endl;
    s.pop();
    s.pop();
    s.push(40);
    cout << s.getSize() << ' ' << s.top();

    return 0;
}