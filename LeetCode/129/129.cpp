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
    void traverse(TreeNode* node, int& sum, string s){
        
        if(!node) return;
        
        s += to_string(node->val);
        
        if(!node->left && !node->right){
            sum += stoi(s);
        } else {
            traverse(node->left, sum, s);
            traverse(node->right, sum, s);   
        }
        
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        traverse(root, sum, "");
        return sum;
    }
};