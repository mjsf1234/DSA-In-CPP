#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"

class BST
{
    BinaryTreeNode<int> *root;

private:
    bool hasDataHelper(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        if (data > node->data)
        {
            return hasDataHelper(data, node->right);
        }
        else
        {
            return hasDataHelper(data, node->left);
        }
    }

    BinaryTreeNode<int> *insertHelper(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
            return node;
        }
        if (data >= node->data)
        {
            BinaryTreeNode<int> *rightNewNode = insertHelper(node->right, data);
            node->right = rightNewNode;
        }
        else
        {
            BinaryTreeNode<int> *leftNewNode = insertHelper(node->left, data);
            node->left = leftNewNode;
        }
        return node;
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
    BinaryTreeNode<int> *deleteHelper(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (node->data == data && node->left == NULL && node->right == NULL)
        {
            delete node;
            return NULL;
        }
        if (node->data == data)
        {
            BinaryTreeNode<int> *tempLeft = node->left;
            BinaryTreeNode<int> *tempRight = node->right;
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }
    bool hasData(int data)
    {
        return hasDataHelper(data, root);
    }

    void insert(int data)
    {
        BinaryTreeNode<int> *tempRoot = insertHelper(root, data);
        this->root = tempRoot;
    }
    void deleteData(int data)
    {
        this->root = deleteHelper(data, root);
    }

    void printTree()
    {
        preOrder(root);
    }
};

;