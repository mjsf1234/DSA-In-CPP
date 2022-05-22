#include <iostream>
using namespace std;
#include <queue>
#include "TreeNodeClass.h"

/* ----------------Content---------------
! TODO: Print the Node as well as their children recursively
! TODO: Print the tree nodes levelwise
! TODO: Take input function levelwise
! TODO: take input from the users and return the address of the root
! TODO: count the number of Node recursively
! TODO: Number of nodes in the given tree
! TODO: Node with Max Data
! TODO: Find the height of the tree
! TODO: Print all the element at level k
! TODO: Number of lead Node
! TODO: Find whether X in present in tree or not
! TODO:  find the node whose value is greater than x ;
! TODO: Node with maximum child sum
! TODO: Replace the node with its depth value
! TODO: check if the tree is strucutal similar or not
! TODO: Find the next largest value
! TODO: find the second largest value in the generic tree
! TODO: Second Largest Element In Tree
*/

// TODO: Print the Node as well as their children recursively
void printTree(TreeNode<int> *root)
{
    cout << "_______________" << endl;
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
};

// TODO: Print the tree nodes levelwise

void printLevelWise(TreeNode<int> *root)
{
    cout << "_____________" << endl;
    if (root == NULL)
    {
        return;
    };

    queue<TreeNode<int> *> q; // initiallizing the queue to store the TreeNode<int>* (address)
    q.push(root);
    while (q.size() != 0) // iterating every element of the queue printing their element
    {
        TreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data;
            if (i != front->children.size() - 1)
            {
                cout << ",";
            }
            q.push(front->children[i]);
        };
        cout << endl;
    }
}

// TODO: Take input function levelwise

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "enter the root data: " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        TreeNode<int> *front = q.front();
        q.pop();
        int childNum;
        cout << "number of children of " << front->data << endl;
        cin >> childNum;
        for (int i = 0; i < childNum; i++)
        {
            int childData;
            cout << "enter the " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *node = new TreeNode<int>(childData);
            front->children.push_back(node);
            q.push(node);
        }
    }
    return root;
};

// TODO: take input from the users and return the address of the root

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "enter the numb of children" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
};

// TODO: count the number of Node recursively
int sumOfNodes(TreeNode<int> *root)
{
    int ans = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumOfNodes(root->children[i]);
    }
    return ans;
}

// TODO: Number of nodes in the given tree

int numbOfNodes(TreeNode<int> *root)
{
    int ans = 1;

    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumOfNodes(root->children[i]);
    }
    return ans;
}

// TODO  : Node with Max Data
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    TreeNode<int> *maxNode = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *TestMax = maxDataNode(root->children[i]);
        if (TestMax->data > maxNode->data)
        {
            maxNode = TestMax;
        }
    }
    return maxNode;
};

// TODO : Find the height of the tree

int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int maxHeight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int childHeight = getHeight(root->children[i]);
        if (childHeight > maxHeight)
        {
            maxHeight = childHeight;
        }
    }
    return (1 + maxHeight);
}
// TODO Print all the element at level k

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
};

// TODO : Number of lead Node

int getLeafNodeCount(TreeNode<int> *root)
{
    int ans = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        ans += getLeafNodeCount(root->children[i]);
    }
    return ans;
};
// TODO Find whether X in present in tree or not
bool isPresent(TreeNode<int> *root, int x)
{
    bool check = false;
    if (root->data == x)
    {
        return true;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        if (isPresent(root->children[i], x))
        {
            check = true;
            break;
        }
    }
    return check;
};

// TODO find the node whose value is greater than x ;
int getLargeNodeCount(TreeNode<int> *root, int x)
{
    int count = 0;
    if (root->data > x)
    {
        count += 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += getLargeNodeCount(root->children[i], x);
    }
    return count;
};

// TODO : Node with maximum child sum

int getTheNodeSum(TreeNode<int> *root)
{
    int sum = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    return sum;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    int max;
    TreeNode<int> *Node;

    int temp = getTheNodeSum(root);
    if (temp > max)
    {
        max = temp;
        Node = root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        int temp1 = getTheNodeSum(root->children[i]);
        if (temp1 > max)
        {
            max = temp1;
            Node = root->children[i];
        }
    }
    return Node;
};

// TODO : Replace the node with its depth value
void replaceWithDepthValue(TreeNode<int> *root)
{
    root->data = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
    }
};

// TODO : check if the tree is strucutal similar or not
bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    bool check = false;
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }
    if (root1->data == root2->data)
    {
        check = true;
    }
    for (int i = 0; i < root1->children.size(); i++)
    {
        bool temp = areIdentical(root1->children[i], root2->children[i]);
        if (temp = false)
        {
            check = false;
            break;
        }
    }
    return check;
};

// TODO : Find the next largest value
TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    TreeNode<int> *next = NULL;
    if (root->data > x)
    {
        next = root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *tempNode = getNextLargerElement(root->children[i], x);
        if (next != NULL)
        {
            if (tempNode != NULL && tempNode->data < next->data)
            {
                next = tempNode;
            }
        }
        else
        {
            if (tempNode != NULL)
            {
                next = tempNode;
            }
        }
    }
    return next;
};

// TODO : find the second largest value in the generic tree

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    TreeNode<int> *largest = NULL;
    TreeNode<int> *secondLargest = NULL;
    if (root != NULL)
    {
        largest = root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = getSecondLargestNode(root->children[i]);
        if (temp->data > largest->data)
        {
            largest = temp;
        };
    }
}
int main()
{
    /* TreeNode<int> *root = new TreeNode<int>(1);
       TreeNode<int> *node1 = new TreeNode<int>(2);
       TreeNode<int> *node2 = new TreeNode<int>(3);
       root->children.push_back(node1);
       root->children.push_back(node2);*/

    // TreeNode<int> *root = takeInput();
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    // printTree(root);
    // cout << sumOfNodes(root);
    // cout << maxDataNode(root)->data << endl;
    // cout << getHeight(root) << endl;
    // cout << "element at level 2 :";
    // printAtLevelK(root, 2);
    // cout << endl
    // cout << "total leaf is " << getLeafNodeCount(root) << endl;

    // cout << "present " << isPresent(root, 8);
    // cout << getLargeNodeCount(root, 6);
    cout << "answer" << maxSumNode(root)->data;
    delete root;

    return 0;
}