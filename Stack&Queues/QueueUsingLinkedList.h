#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{

    Node *head;
    Node *tail;
    int size = 0;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
            size++;
            return;
        }
        tail->next = n;
        tail = n;
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }

        int ans = head->data;
        head = head->next;
        return ans;
    }

    int front()
    {
        return head->data;
    }
};
