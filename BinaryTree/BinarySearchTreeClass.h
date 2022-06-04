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
        else if (data > node->data)
        {
            return hasDataHelper(data, root->right);
        }
        else
        {
            return hasDataHelper(data, root->left);
        }
    }

    BinaryTreeNode<int> *insertHelper() {}
    BinaryTreeNode<int> *deleteHelper() {}

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
    }
    void deleteData(int data) {}
};

;