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
        else if (node->data > data)
        {
            node->left = deleteHelper(data, node->left);
            return node;
        }
        else if (node->data < data)
        {
            node->right = deleteHelper(data, node->right);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteHelper(rightMin, node->right);
                return node;
            }
        }
    }

    void printTreeHelper(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << ":";
        if (node->left != NULL)
        {
            cout << "L:" << node->left->data;
        }
        if (node->right != NULL)
        {
            cout << ",R:" << node->right->data;
        }
        cout << endl;
        printTreeHelper(node->left);
        printTreeHelper(node->right);
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
    bool search(int data)
    {
        return hasDataHelper(data, root);
    }

    void insert(int data)
    {
        BinaryTreeNode<int> *tempRoot = insertHelper(root, data);
        this->root = tempRoot;
    }
    void remove(int data)
    {
        this->root = deleteHelper(data, root);
    }

    void print()
    {
        printTreeHelper(root);
    }
};
