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
    
    void helper(TreeNode* node, int depth, int &minDepth){
        
        if(node==NULL) return;
        
        if(node->left==NULL && node->right==NULL){
            minDepth = min(minDepth, depth);
            return;
        }
        
        helper(node->left, depth+1, minDepth);
        helper(node->right, depth+1, minDepth);
        
        return;
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int depth = 1, minDepth = 99999;
        helper(root, depth, minDepth);
        return minDepth;
    }
};