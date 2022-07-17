#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include "../BinaryTree/BinaryTreeNode.h"
#include "../LinkedList/Node_Linked_List.cpp"
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
bool isSymmetricHelper(BinaryTreeNode<int> *left, BinaryTreeNode<int> *right)
{

    if (left == NULL || right == NULL)
    {
        return left == right;
    }
    else if (left->data != right->data)
    {
        return false;
    }
    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}
bool isSymmetric(BinaryTreeNode<int> *root)
{
    return (root == NULL || isSymmetricHelper(root->left, root->right));
}

// TODO MIN COST MEMOISATION

/*int minCostPathMemoisation(int **input, int m, int n, int row, int column, int **output)
{
    // base case
    if (m == row - 1 && n == column - 1)
    {
        return input[m][n];
    }

    int bottom = INT32_MAX;
    int right = INT32_MAX;
    int diagnol = INT32_MAX;

    if (m >= row || n >= column)
    {
        return INT32_MAX;
    }

    // if answer already exist
    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    bottom = minCostPathHelper(input, m + 1, n, row, column);
    right = minCostPathHelper(input, m, n + 1, row, column);
    diagnol = minCostPathHelper(input, m + 1, n + 1, row, column);

    int minCostPath = min(right, min(bottom, diagnol));

    // save the answer
    output[m][n] = minCostPath + input[m][n];
    return (input[m][n] + minCostPath);
}*/

int minCostPathHelper(int **input, int m, int n, int row, int column)
{
    // base case
    if (m == row - 1 && n == column - 1)
    {
        return input[m][n];
    }

    int bottom = INT32_MAX;
    int right = INT32_MAX;
    int diagnol = INT32_MAX;

    if (m >= row || n >= column)
    {
        return INT32_MAX;
    }

    /*if (m < row - 1)
    {
        // call the bottomm

        bottom = minCostPathHelper(input, m + 1, n, row, column);
    }
    if (n < column - 1)
    {
        // call left
        right = minCostPathHelper(input, m, n + 1, row, column);
    }
    if (n < column - 1 && m < row - 1)
    {
        // call the diagnol
        diagnol = minCostPathHelper(input, m + 1, n + 1, row, column);
    }*/

    bottom = minCostPathHelper(input, m + 1, n, row, column);
    right = minCostPathHelper(input, m, n + 1, row, column);
    diagnol = minCostPathHelper(input, m + 1, n + 1, row, column);

    int minCostPath = min(right, min(bottom, diagnol));

    return (input[m][n] + minCostPath);
}

int minCostPath(int **input, int m, int n)
{

    return minCostPathHelper(input, 0, 0, m, n);
}

//*===================================================================================================*//

// TODO to fnd the number appearing twice
int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!map.count(nums.at(i)))
        {
            map[nums.at(i)] = 1;
        }
        else
        {
            map[nums.at(i)] += 1;
        }
    }
    unordered_map<int, int>::iterator it;
    it = map.begin();

    int ans;

    while (it != map.end())
    {
        if (it->second == 1)
        {
            ans = it->first;
            break;
        }
        it++;
    }
    return ans;
}

// TODO XOX approch

int singleElement_XOX(vector<int> v)
{
    int result = 0;
    for (int i = 0; i < v.size(); i++)
    {
        result ^= v[i];
    }
    return result;
}

//*===================================================================================================*//

//*===================================================================================================*//
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//*===================================================================================================*//

//*===================================================================================================*//
// TODO Min cost path using DP
int minCostPath_DP(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    // fill the last value of matrix to output array
    output[m - 1][n - 1] = input[m - 1][n - 1];

    // filing the last column (bottom to top)

    for (int i = m - 2; i >= 0; i--)
    {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }

    // filling the last row (right to left)

    for (int j = n - 2; j >= 0; j--)
    {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    // filling the remaining values
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i + 1][j], min(output[i][j + 1], output[i + 1][j + 1])) + input[i][j];
        }
    }

    return output[0][0];
}
//*===================================================================================================*//

int main()
{
    /* BinaryTreeNode<int> *root = TakeInputLevelWise();*/
    // vector<int> v = inorderTraversal(root);
    // cout << "dad" << v.size() << endl;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << maxDepth(root);
    /*cout << isSymmetric(root);*/

    /* int **arr, n, m;
     cin >> n >> m;
     arr = new int *[n];
     for (int i = 0; i < n; i++)
     {
         arr[i] = new int[m];
     }
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < m; j++)
         {
             cin >> arr[i][j];
         }
     }
     int ans = minCostPath_DP(arr, n, m);*/

    vector<int> v;
    v.push_back(4);
    v.push_back(4);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(3);
    // cout << singleNumber(v);
    cout << singleElement_XOX(v);

    // cout << ans;
    return 0;
}