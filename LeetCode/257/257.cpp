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
    void helper(TreeNode* node, vector<string>& ans, string s){
        
        if(node->left==NULL && node->right==NULL) {
            s += to_string(node->val);
            ans.push_back(s);
            return;
        };
        
        s += to_string(node->val) + "->";
        
        if(node->left) helper(node->left, ans, s);
        if(node->right) helper(node->right, ans, s);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, ans, "");
        return ans;
    }
};