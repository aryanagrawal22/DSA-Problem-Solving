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
    void helper(TreeNode* node, vector<int>& ans, int level){
        
        if(!node) return;
        
        if(ans.size()<level+1){
            ans.push_back(node->val);
        }
        
        if(ans[level]<node->val){
            ans[level] = node->val;
        }
        
        helper(node->left, ans, level+1);
        helper(node->right, ans, level+1);
        
    }
    
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        helper(root, ans, 0);
        return ans;
    }
};