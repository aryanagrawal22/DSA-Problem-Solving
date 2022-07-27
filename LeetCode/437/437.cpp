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
class Solution {
public:
    //This solution is DFS from each node which is reached by DFS, if target found then add ans by 1
    void curRootBFS(TreeNode* root, int targetSum, int& ans, double curSum) {
        if(!root) return;
        curSum += root->val;
        if(curSum==targetSum) ans++;
        curRootBFS(root->left, targetSum, ans, curSum);
        curRootBFS(root->right, targetSum, ans, curSum);
    }
    
    void BFS(TreeNode* root, int targetSum, int& ans){
        if(!root) return;
        BFS(root->left, targetSum, ans);
        BFS(root->right, targetSum, ans);
        curRootBFS(root, targetSum, ans, 0);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int ans = 0;
        BFS(root, targetSum, ans);
        return ans;
    }
};