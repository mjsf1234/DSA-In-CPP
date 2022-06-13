#include <iostream>
using namespace std;
#include <vector>
#include "../BinaryTree/BinaryTreeNode.h"
#include <queue>

void helperFunction(BinaryTreeNode<int> *node, vector<int> &v)
{

    if (node == NULL)
    {
        return;
    }
    helperFunction(node->left, v);
    v.push_back(node->data);
    helperFunction(node->right, v);
}

vector<int> inorderTraversal(BinaryTreeNode<int> *root)
{
    vector<int> v;
    cout << "type ";
    helperFunction(root, v);

    return v;
}
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

// TODO : problem 2: depth of

int maxDepth(BinaryTreeNode<int> *root)
{
    int height = 0;
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = maxDepth(root->left);
    int right = maxDepth(root->right);
    height = max(leftHeight, right);
    return 1 + height;
};

// TODO find wheather tree is symmteric or not

class HeightAndSymmteric
{
public:
    int Height;
    bool isTreeSymmetric;
};
HeightAndSymmteric *isSymmetricHelper(BinaryTreeNode<int> *root)
{
    HeightAndSymmteric *hs = new HeightAndSymmteric();
    if (root == NULL)
    {
        hs->Height = 0;
        hs->isTreeSymmetric = true;
        return hs;
    }
    HeightAndSymmteric *left = isSymmetricHelper(root->left);
    HeightAndSymmteric *right = isSymmetricHelper(root->right);
    if ((left->Height == right->Height) && (left->isTreeSymmetric && right->isTreeSymmetric))
    {
        hs->isTreeSymmetric = true;
    }
    else
    {
        hs->isTreeSymmetric = false;
    }

    hs->Height = max(left->Height, right->Height) + 1;

    return hs;
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    HeightAndSymmteric *ans = isSymmetricHelper(root);
    return ans->isTreeSymmetric;
}

bool isSymmteric(BinaryTreeNode<int> *root)
{
}

int main()
{
    BinaryTreeNode<int> *root = TakeInputLevelWise();
    // vector<int> v = inorderTraversal(root);
    // cout << "dad" << v.size() << endl;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << maxDepth(root);
    cout << isSymmetric(root);

    return 0;
}