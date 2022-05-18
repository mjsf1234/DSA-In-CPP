#include <iostream>
using namespace std;
#include "Node_Linked_List.cpp"

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
};

Node *deleteNode(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    int count = 0;
    Node *temp = head;

    if (pos == 0)
    {
        head = head->next;
        return head;
    }
    else
    {
        while (count < pos - 1 && temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        if (temp->next != NULL)
        {
            temp->next = temp->next->next;
        }

        return head;
    }
}

//! Creating the take user input function
Node *takeInput()
{
    Node *head = NULL;
    Node *tail = NULL;

    int data;
    cin >> data;

    while (data != -1)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(data);
            head = newNode;
            tail = newNode;
        }
        else
        {
            //? This is travelling and finding the Null Node and then entering the value
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new Node(data);

            /**
             *! using the tail method
             * Node *newNode = new Node(data);
             * tail->next = newNode;
             *tail = newNode;*/
        }

        cin >> data;
    }

    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    int i;
    cin >> i;
    Node *head1 = deleteNode(head, i);
    print(head1);
    return 0;
}