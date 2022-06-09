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
};

Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main()
{

    /*
    !Statically creates object
    Node n1(10);
    Node n2(20);
    Node n3(30);
    Node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    print(head);
    cout << endl;*/

    //?Dynamically created Node
    // Node *n4 = new Node(40);
    // Node *n5 = new Node(50);
    // Node *n6 = new Node(60);
    // Node *head1 = n4;
    // n4->next = n5;
    // n5->next = n6;
    // print(n4);
    // delete n4, n5, n6, head1;

    //*Taking input from the users

    Node *head = takeInput();
    print(head);
    cout << "__" << endl;
    Node *head1 = reverseList(head);
    print(head1);

    return 0;
}