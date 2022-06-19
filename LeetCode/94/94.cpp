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
    vector<int> inorderTraversal(TreeNode* root) {
        
        //Declare a stack to store all the traversed parent
        stack<TreeNode*> stack;
        vector<int> arr;
        
        TreeNode* curr = root;

        while(!stack.empty() || curr != NULL){
            
            //If curr not NULL then add it to stack and go to its left
            if(curr!= NULL){
                stack.push(curr);
                curr = curr->left;
            //If curr is NULL then curr is stack top and then go to its right
            }else{
                curr = stack.top();
                stack.pop();
                arr.push_back(curr->val);
                curr = curr->right;
            }
            
        }
        
        return arr;
    }
};