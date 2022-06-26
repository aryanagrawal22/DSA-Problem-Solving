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
    
    void revPreorderRight(TreeNode *root, vector<int> &arr, int level){
        
        if (root == NULL){
            return;
        }

        if(arr.size()==level){
            arr.push_back(root->val);
        }

        revPreorderRight(root->right, arr, level + 1);
        revPreorderRight(root->left, arr, level + 1);
        
    } 
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        revPreorderRight(root, arr, 0);
        return arr;
    }
};