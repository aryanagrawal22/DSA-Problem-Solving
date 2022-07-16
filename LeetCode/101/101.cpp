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
    bool helper(TreeNode* lTree, TreeNode* rTree){
        if(!lTree && !rTree) return true;
        if(!lTree || !rTree || lTree->val!=rTree->val ) return false;
        return helper(lTree->left, rTree->right) && helper(lTree->right, rTree->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};