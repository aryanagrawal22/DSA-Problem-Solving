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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        stack<TreeNode*> stack;
        TreeNode* last = NULL;
        while(!stack.empty() || root!=NULL){
            if (root) {
                stack.push(root);
                root = root -> left;
            } else {
                TreeNode* node = stack.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } else {
                    ans.push_back(node -> val);
                    last = node;
                    stack.pop();
                }
            }
        }
        return ans;
    }
};