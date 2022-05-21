#include <iostream>
using namespace std;
#include <vector>

// TreeNodeClass
template <typename T>
class TreeNode
{

public:
    T data;
    vector<TreeNode<T> *> children; // vector store the address of the TreeNode of type T;
    TreeNode(T element)
    {
        this->data = element;
    }

    // destructor to delete every tree node
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
