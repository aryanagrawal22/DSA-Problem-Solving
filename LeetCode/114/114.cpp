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
    
    //Reverse approach where we go first to the rightmost deepest element 
    //and start by making its left element as its right and storing its 
    //own value in a previous (prev) pointer to be used for next time 
    //as the right pointer
    void traversal(TreeNode* root, TreeNode* &prev){
        if(root==NULL) return;
        traversal(root->right, prev);
        traversal(root->left, prev);
        root->right = prev;
        root->left = NULL;
        prev = root;
        return;
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* prev = NULL;
        traversal(root, prev);
        return;
    }
};