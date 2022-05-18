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

int sizeLL(Node *head)
{
    if (head->next == NULL)
    {
        return 1;
    }
    else
    {
        head = head->next;
        return 1 + sizeLL(head);
    }
}

Node *midPoint(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//! function to merge two sorted linked list
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
//? main function
Node *mergeSort(Node *head)
{
    if (head->next == NULL || head == NULL)
    {
        cout << "dad";
        return head;
    }

    Node *m = midPoint(head);
    Node *nxt = m->next;
    m->next = NULL;
    Node *x = mergeSort(head);
    Node *y = mergeSort(nxt);
    Node *z = mergeTwoSortedLinkedLists(x, y);
    return z;
}

int main()
{
    Node *head1 = takeInput();
    Node *head2 = mergeSort(head1);
    print(head2);
}