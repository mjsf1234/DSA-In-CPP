#include <iostream>
using namespace std;
template <typename T>
class BinaryTreeNode
{

public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    };
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    };
};
