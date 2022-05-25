#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"
#include <algorithm>
#include <queue>

// TODO : Print function

void PrintTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L " << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R " << root->right->data << " ";
    }
    cout << endl;
    PrintTree(root->left);
    PrintTree(root->right);
};

// TODO : Print the element levelwise
void printLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    if (root != NULL)
    {
        q.push(root);
    }
    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << ":";
        cout << "L:";
        if (front->left != NULL)
        {
            cout << front->left->data << ",";
            q.push(front->left);
        }
        else
        {
            cout << -1 << ",";
        };
        cout << "R:";
        if (front->right != NULL)
        {
            cout << front->right->data;
            q.push(front->right);
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
};

// TODO : Find the number of the node
int numNode(BinaryTreeNode<int> *root)
{
    int ans;
    if (root == NULL)
    {
        return 0;
    }
    return 1 + numNode(root->left) + numNode(root->right);
}

// TODO : Take Input function1

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "enter the root data: ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>{rootData};

    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
};
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// TODO : Take input Level Wise

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
// TODO : find the node containing the int X
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{

    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    return (isNodePresent(root->left, x) || isNodePresent(root->right, x));
};

// TODO : Height of the binary tree
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
};
// TODO : mirror the element
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
};

// TODO : preorder Binary tree

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

// TODO : postOrder

void postOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// 1 2 3 4 5 6 7 - 1 - 1 - 1 - 1 - 1 - 1 - 1 - 1
int main()
{
    // BinaryTreeNode<int> *root = takeInput();
    BinaryTreeNode<int> *root = TakeInputLevelWise();
    // cout << "node:" << numNode(root) << endl;
    // bool c = isNodePresent(root, 1);
    // cout << "C " << c;
    // cout << "H" << height(root);
    // mirrorBinaryTree(root);
    printLevelWise(root);
    cout << "------------------" << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);

    return 0;
}