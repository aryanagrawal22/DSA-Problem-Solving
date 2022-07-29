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
    int tiltNode(TreeNode* root, int& ans){
        if(!root) return 0;
        
        int ans1 = tiltNode(root->left, ans);
        int ans2 = tiltNode(root->right, ans);
        
        ans+=abs(ans1-ans2);
        
        return ans1+ans2+root->val;
    }
    
    int findTilt(TreeNode* root) {
        int ans = 0;
        tiltNode(root, ans);
        return ans;
    }
};