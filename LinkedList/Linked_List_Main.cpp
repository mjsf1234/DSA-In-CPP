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
// finding the size of the list
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
// ?inserting the node at the ith position
Node *insertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        return head;
    }
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    else
    {
        Node *x = insertNode(head->next, i - 1, data);
        head->next = x;
        return head;
    }
}

// * deleting the ith position Node recursively
Node *deleteNodeRec(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    if (pos == 0)
    {
        head = head->next;
        return head;
    }
    else
    {
        Node *x = deleteNodeRec(head->next, pos - 1);
        head->next = x;
        return head;
    }
}
int findNode(Node *head, int n)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == n)
    {
        return 0;
    }
    else
    {
        int j = findNode(head->next, n);
        if (j == -1)
        {
            return -1;
        }
        else
        {
            return 1 + j;
        }
    }
}
Node *appendLastNToFirst(Node *head, int n)
{
    if (n == 0)
    {
        return head;
    }
    else
    {
        // size of LL =m
        int m = 0, count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            m += 1;
            temp = temp->next;
        }
        // cout << "size" << m << endl;
        // Changing the head
        Node *temp2 = head;
        while (count < m - n - 1)
        {
            count += 1;
            temp2 = temp2->next;
        }
        Node *check = head;
        head = temp2->next;
        temp2->next = NULL;
        // Attaching the remaining list to last element
        Node *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = check;
        return head;
    }
}
Node *removeDuplicates(Node *head)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }
    else
    {
        Node *x = removeDuplicates(head->next);
        head->next = x;
        if (head->data == x->data)
        {
            return x;
        }
        else
        {
            return head;
        }
    }
}
void printReverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        printReverse(head->next);
        cout << head->data << " ";
    }
}
Node *ReverseList(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *x = ReverseList(head->next);
    Node *temp = x;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return x;
};
bool isPalindrome(Node *head)
{
    Node *temp = head;
    Node *tail = ReverseList(head);
    while (temp != NULL && tail != NULL)
    {
        if (temp->data != tail->data)
        {
            return false;
        }
        temp = temp->next;
        tail = tail->next;
    }
    return true;
};

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

int main()
{
    Node *head1 = takeInput();
    Node *head2 = takeInput();
    print(head1);
    cout << endl;
    print(head2);

    return 0;
}