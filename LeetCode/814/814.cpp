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
    bool dfs(TreeNode* root){
        if(!root) return true;
        
        bool ans1 = dfs(root->left); 
        bool ans2 = dfs(root->right);
        
        if(ans1) root->left = NULL;
        if(ans2) root->right = NULL;
        
        if(!root->val && ans1 && ans2) return true;
        
        return false;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        if(!root->left && !root->right && !root->val) return NULL;
        return root;
    }
};