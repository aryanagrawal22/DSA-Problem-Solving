/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int height(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        else
        {
            /* compute the height of each subtree */
            int lheight = height(node->left);
            int rheight = height(node->right);

            /* use the larger one */
            if (lheight > rheight)
            {
                return (lheight + 1);
            }
            else
            {
                return (rheight + 1);
            }
        }
    }

    void printCurrentLevel(TreeNode *root, int level, vector<int> &arr)
    {
        if (root == NULL)
            return;
        if (level == 1)
            arr.push_back(root->val);
        else if (level > 1)
        {
            printCurrentLevel(root->left, level - 1, arr);
            printCurrentLevel(root->right, level - 1, arr);
        }
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        int h = height(root);
        vector<vector<int>> mat;
        for (int i = 1; i <= h; i++)
        {
            vector<int> arr;
            printCurrentLevel(root, i, arr);
            mat.push_back(arr);
        }
        return mat;
    }
};