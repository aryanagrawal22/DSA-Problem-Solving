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
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return helper(root)!=-1?true:false;
    }
    
    //Do a DFS and return bigger depth between left subtree and right subtree and if difference between left subtree and righttree is greater than 1 than return -1 and keep it returning as the tree is not balanced
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int left = helper(root->left);
        int right = helper(root->right);
        if(left == -1 || right == -1 || abs(left - right) > 1){
            return -1;
        }
        return max(left, right) + 1;
    }

};