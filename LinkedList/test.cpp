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
        this->next = NULL;
    }
};

Node *addTwoNumbers(Node *l1, Node *l2)
{

    Node *head = NULL;
    Node *tail = NULL;

    int carry = 0;
    while (l1 != NULL && l2 != NULL)
    {

        int sum = (l1->data + l2->data + carry);
        cout << sum << endl;

        carry = (l1->data + l2->data + carry) / 10;

        Node *node = new Node(sum);

        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != NULL)
    {
        int sum = (l1->data + carry) % 10;
        int carry = (l1->data + carry) / 10;
        Node *node = new Node(sum);
        tail->next = node;
        tail = node;
        l1 = l1->next;
    }

    while (l2 != NULL)
    {
        int sum = (l2->data + carry) % 10;
        int carry = (l2->data + carry) / 10;
        Node *node = new Node(sum);
        tail->next = node;
        tail = node;
        l2 = l2->next;
    }

    if (carry != 0)
    {

        Node *node = new Node(carry);
        tail->next = node;
        tail = node;
    }

    return head;
}

int main()
{
    Node *head1 = new Node(2);
    Node *n2 = new Node(4);
    head1->next = n2;
    Node *n3 = new Node(3);
    n2->next = n3;

    Node *head2 = new Node(5);
    Node *n4 = new Node(6);
    head2->next = n4;
    Node *n5 = new Node(4);
    n4->next = n5;

    addTwoNumbers(head1, head2);

    return 0;
}