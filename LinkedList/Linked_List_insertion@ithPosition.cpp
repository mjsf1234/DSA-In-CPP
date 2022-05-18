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

Node *insertNode(Node *head, int i, int data)
{
    int count = 0;
    Node *newNode = new Node(data);
    Node *temp = head;
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    else
    {
        while (temp != NULL && count < i - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp != NULL)
        {
            Node *check = temp->next;
            temp->next = newNode;
            newNode->next = check;
        }
        else
        {
            cout << "input is out of range" << endl;
        }
        return head;
    }
}

//!Creating the take user input function
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
    int i, data;
    cin >> i >> data;
    Node *head1 = insertNode(head, i, data);
    print(head1);

    return 0;
}