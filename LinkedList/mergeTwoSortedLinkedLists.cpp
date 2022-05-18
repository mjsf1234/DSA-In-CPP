#include <iostream>
using namespace std;
#include "Node_Linked_List.cpp"

//* function to print the element of the list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
};

// taking the input from the user
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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *fh = NULL;
    Node *ft = NULL;
    if (head1->data < head2->data)
    {
        fh = head1;
        ft = head1;
        head1 = head1->next;
    }
    else
    {
        fh = head2;
        ft = head2;
        head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            ft->next = head1;
            ft = head1;
            head1 = head1->next;
        }
        else
        {
            ft->next = head2;
            ft = head2;
            head2 = head2->next;
        }
    }
    if (head1 == NULL)
    {
        ft->next = head2;
    }
    else
    {
        ft->next = head1;
    }
    return fh;
}

int main()
{
    cout << endl
         << "enter -1 at the end of the list" << endl
         << endl;
    cout << "enter the list1 element=> ";
    Node *head1 = takeInput();
    cout << "enter the list2 element=> ";
    Node *head2 = takeInput();
    print(head1);
    cout << endl;
    print(head2);
    cout << endl;
    Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
    cout << endl;
    cout << "sorted listed is =>";
    print(head3);

    return 0;
}