#include <iostream>
using namespace std;
#include <queue>
#include <stack>
#include "BinaryTreeNode.h"

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// TODO : take input levelwise
BinaryTreeNode<int> *TakeInputLevelWise()
{
    int rootData;
    cout << "enter the data: " << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    queue<BinaryTreeNode<int> *> q;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    q.push(root);
    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        int leftData;
        cout << "enter the Left data of " << front->data << " : " << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftData);
            front->left = leftChild;
            q.push(leftChild);
        };
        int rightData;
        cout << "enter the Right data of " << front->data << " : " << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightData);
            front->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
};

// TODO : print the element in levelwise
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        int count = q.size();
        while (count != 0)
        {

            BinaryTreeNode<int> *front = q.front();
            q.pop();
            cout << front->data << " ";
            if (front->left != NULL)
            {

                q.push(front->left);
            }
            if (front->right != NULL)
            {

                q.push(front->right);
            }
            count--;
        }
        cout << endl;
    }
}

// TODO : to find the the element in the tree

bool searchInBST(BinaryTreeNode<int> *root, int k)
{

    if (root == NULL)
    {
        return false;
    }
    if (root->data == k)
    {
        return true;
    }
    if (k > root->data)
    {
        return searchInBST(root->right, k);
    }
    else
    {
        return searchInBST(root->left, k);
    }
}

// TODO : print the element int the range

void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= k1 && root->data <= k2)
    {
        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right, k1, k2);
    };
    if (root->data < k1)
    {
        elementsInRangeK1K2(root->right, k1, k2);
    }
    if (root->data > k2)
    {
        elementsInRangeK1K2(root->left, k1, k2);
    }
};

// TODO : check if tree is binary or not

// TODO : remove the leaf node
BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return NULL;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}

// TODO : Diameter of tree
// TODO : preorder and inorder

// TODO : Lavel wise linked list
vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> v;
    if (root == NULL)
    {
        v.push_back(NULL);
        return v;
    }

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        int count = q.size();
        Node<int> *head = NULL;
        Node<int> *tail = NULL;
        while (count > 0)
        {
            BinaryTreeNode<int> *front = q.front();
            q.pop();
            Node<int> *node = new Node<int>(front->data);
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
            if (front->left != NULL)
            {

                q.push(front->left);
            }
            if (front->right != NULL)
            {

                q.push(front->right);
            }
            count--;
        }
        v.push_back(head);
    }
    return v;
}

// TODO : to print the above Linked List
void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

pair<int, int> getHeightDiameter(BinaryTreeNode<int> *root)
{
    pair<int, int> pair;
    if (root == NULL)
    {
        pair.first = 0;
        pair.second = 0;
        return pair;
    }

    int lh = getHeightDiameter(root->left).first;
    int ld = getHeightDiameter(root->left).second;
    int rh = getHeightDiameter(root->right).first;
    int rd = getHeightDiameter(root->right).second;
    int Height = max(lh, rh);
    int diameter = max((lh + rh), max(ld, rd));
    pair.first = Height + 1;
    pair.second = diameter;
    return pair;
}
// TODO : min and max pair of the binary tree
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    pair<int, int> p;
    if (root == NULL)
    {
        p.first = INT32_MAX;
        p.second = 0;
        return p;
    }
    pair<int, int> leftPair = getMinAndMax(root->left);
    pair<int, int> rightPair = getMinAndMax(root->right);
    int MIN = min((leftPair.first), (min(root->data, rightPair.first)));
    int MAX = max(leftPair.second, max(rightPair.second, root->data));
    p.first = MIN;
    p.second = MAX;
    return p;
};

// TODO : print the binary tree in zigzag manner
void zigZagOrder(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int> *> s1; // right to left
    stack<BinaryTreeNode<int> *> s2; // left to right
    if (root == NULL)
    {
        return;
    }
    s1.push(root);
    while (!(s1.empty() && s2.empty()))
    {

        while (!s1.empty())
        {

            BinaryTreeNode<int> *front = s1.top();
            s1.pop();
            cout << front->data << " ";
            if (front->left != NULL)
            {
                s2.push(front->left);
            }
            if (front->right != NULL)
            {
                s2.push(front->right);
            }
        }
        cout << endl;
        while (!s2.empty())
        {

            BinaryTreeNode<int> *front = s2.top();
            s2.pop();
            cout << front->data << " ";
            if (front->right != NULL)
            {
                s1.push(front->right);
            }
            if (front->left != NULL)
            {
                s1.push(front->left);
            }
        }
        cout << endl;
    }
}
// 5 3 7 2 4 6 8 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = TakeInputLevelWise();
    // cout << " " << searchInBST(root, 4);
    // cout << endl;
    // elementsInRangeK1K2(root, 14, 17);
    // printLevelWise(root);
    // cout << "_______" << endl;

    /*pair<int, int> p = getHeightDiameter(root);
    cout << "Height"
         << ":" << p.first << " "
         << "diameter : " << p.second << endl;*/

    /*pair<int, int> pair = getMinAndMax(root);
    cout << "min: " << pair.first << " "
         << "max: " << pair.second << endl;*/

    // printLevelWise(removeLeafNodes(root));
    // vector<Node<int> *> ans = constructLinkedListForEachLevel(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     print(ans[i]);
    // }

    zigZagOrder(root);
    return 0;
}