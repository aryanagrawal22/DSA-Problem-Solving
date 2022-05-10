// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sumOfLongRootToLeafPath(Node *node)
    {
        if (!node)
            return 0;

        int maxSum = INT_MIN, maxLen = 0;

        // finding the maximum sum 'maxSum' for the
        // maximum length root to leaf path
        calc(node, 0, 0, maxLen, maxSum);

        // required maximum sum
        return maxSum;
    }

    void calc(Node *root, int sum, int len, int &maxLen, int &maxSum)
    {
        // if true, then we have traversed a
        // root to leaf path
        if (!root)
        {
            // update maximum length and maximum sum
            // according to the given conditions
            if (maxLen < len)
            {
                maxLen = len;
                maxSum = sum;
            }
            else if (maxLen == len && maxSum < sum)
                maxSum = sum;
            return;
        }

        // recur for left subtree
        calc(root->left, sum + root->data, len + 1, maxLen, maxSum);

        // recur for right subtree
        calc(root->right, sum + root->data, len + 1, maxLen, maxSum);
    }
};

// { Driver Code Starts.

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    Solution obj;
    int res = obj.sumOfLongRootToLeafPath(root);
    cout << res << "\n";
    return 0;
} // } Driver Code Ends