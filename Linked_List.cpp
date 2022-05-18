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
    cout << endl;
};
int main()
{

    //statically

    /*  Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;
    Node *head = &n1;
    print(head);*/

    //dynaically

    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    print(node2);
}