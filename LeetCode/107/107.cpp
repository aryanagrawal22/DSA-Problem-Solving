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
    void helper(TreeNode* root, vector<vector<int>>& ans, int depth){
        if(!root) return;
        if(ans.size() == depth) ans.push_back(vector<int>());
        
        ans[depth].push_back(root->val);
        
        helper(root->left, ans, depth+1);
        helper(root->right, ans, depth+1);
        
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, ans, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};