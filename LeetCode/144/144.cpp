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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        
        //If node is not null then push it to ans and stack else go to stack top's right and pop the top after that.
        //Do this process till both stack becomes empty and node becomes null 
        while(!stk.empty() || root!=NULL){
            if(root){
                ans.push_back(root->val);
                stk.push(root);
                root = root->left;
            }else{
                TreeNode* curr = stk.top();
                stk.pop();
                root = curr->right;
            }
        }
        return ans;
    }
};