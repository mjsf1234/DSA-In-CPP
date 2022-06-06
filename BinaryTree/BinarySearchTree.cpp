#include <iostream>
using namespace std;
#include <queue>
// #include "BinaryTreeNode.h"
#include "BinarySearchTreeClass.h"
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

void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

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
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT32_MIN;
    }
    return max((root->data), (max(maximum(root->left), maximum(root->right))));
}

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT32_MAX;
    }
    return min((root->data), min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool check = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return check;
}

// todo: check isBST (Time complexity =O(n))
class IsBSTReturn
{
public:
    int min;
    int max;
    bool isBST;
};
IsBSTReturn isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        IsBSTReturn output;
        output.min = INT32_MAX;
        output.max = INT32_MIN;
        output.isBST = true;
        return output;
    }
    IsBSTReturn left = isBST2(root->left);
    IsBSTReturn right = isBST2(root->right);

    int maximum = max(root->data, max(left.max, right.max));
    int minimum = min(root->data, min(left.min, right.min));
    bool isBSTFinal = left.isBST && right.isBST;

    IsBSTReturn output;
    output.min = minimum;
    output.max = maximum;
    output.isBST = isBSTFinal;
    return output;
}

// todo : find isBST () with top to bottom approach (time complexity O(n))

bool isBST3(BinaryTreeNode<int> *root, int min = INT32_MIN, int max = INT32_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > max || root->data < min)
    {
        return false;
    }
    return (isBST3(root->left, INT32_MIN, root->data - 1) && isBST3(root->right, root->data, INT32_MAX));
}
//!____________________________________________________________________________________

// todo: create the binary search tree from the sortted array
BinaryTreeNode<int> *constructTreeHelper(int *input, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int lenght = end + start;
    int middle = int((start + end)) / 2;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[middle]);

    int ls = start;
    int le = middle - 1;
    int rs = middle + 1;
    int re = end;

    BinaryTreeNode<int> *left = constructTreeHelper(input, ls, le);
    BinaryTreeNode<int> *right = constructTreeHelper(input, rs, re);
    root->left = left;
    root->right = right;

    return root;
}

BinaryTreeNode<int> *constructTree(int *input, int n)
{
    if (n == 0)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = constructTreeHelper(input, 0, n - 1);
    return root;
};
//!____________________________________________________________________________________

// TODO : create the sorted Linked List from BST

class NodeReturn
{
public:
    Node<int> *head;
    Node<int> *tail;
};

NodeReturn constructLinkedListHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        NodeReturn n;
        n.head = NULL;
        n.tail = NULL;
        return n;
    }
    NodeReturn left = constructLinkedListHelper(root->left);
    NodeReturn right = constructLinkedListHelper(root->right);
    Node<int> *tempRoot = new Node<int>(root->data);
    NodeReturn final;
    if (left.tail == NULL && right.head == NULL)
    {
        final.head = tempRoot;
        final.tail = tempRoot;
        return final;
    }
    if (left.tail == NULL)
    {
        final.head = tempRoot;
    }
    else
    {
        final.head = left.head;
        left.tail->next = tempRoot;
    }
    if (right.head == NULL)
    {
        final.tail = tempRoot;
    }
    else
    {
        tempRoot->next = right.head;
        final.tail = right.tail;
    }

    return final;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    return constructLinkedListHelper(root).head;
}

//!____________________________________________________________________________________
// TODO : get the path from root to target
vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getPath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getPath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    // BinaryTreeNode<int> *root = TakeInputLevelWise();
    // printLevelWise(root);
    // cout << "_______" << endl;
    // // cout << isBST(root) << endl;
    // // cout << isBST2(root).isBST << endl;
    // cout << isBST3(root) << endl;
    // int ans[8] = {1, 2, 3, 4, 5, 6, 7};
    // BinaryTreeNode<int> *root2 = constructTree(ans, 7);
    // preOrder(root2);
    // Node<int> *head = constructLinkedList(root);
    // while (head != NULL)
    // {
    //     cout << head->data << " ";
    //     head = head->next;
    // }
    // vector<int> *v = getPath(root, 8);
    // for (int i = 0; i < v->size(); i++)
    // {
    //     cout << v->at(i) << " ";
    // }
    // delete v;

    BST b;
    b.insert(4);
    b.insert(6);
    b.insert(5);
    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(7);
    b.insert(8);
    b.printTree();
    cout << b.hasData(6) << endl;
    b.deleteData(6);
    cout << "_____" << endl;
    b.printTree();
    cout << b.hasData(6) << endl;

    return 0;
}