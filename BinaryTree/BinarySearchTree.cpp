#include <iostream>
using namespace std;
#include <queue>
#include "BinaryTreeNode.h"

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
bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    isBST(root->left);
    isBST(root->right);
}
// 5 3 7 2 4 6 8 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = TakeInputLevelWise();
    cout << " " << searchInBST(root, 4);
    cout << endl;
    elementsInRangeK1K2(root, 14, 17);

    return 0;
}