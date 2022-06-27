/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //Goto the leafs first and then start coming up to root in search of p and q
        if(root==NULL){
            return NULL;
        }

        TreeNode *ans1 = lowestCommonAncestor(root->left, p, q);
        TreeNode *ans2 = lowestCommonAncestor(root->right, p, q);

        //If p or q is found then return that node
        if(root->val==p->val || root->val==q->val){
            return root;
        }

        //If both ans1 and ans2 were returned some val then return current val as LCA
        if(ans1 && ans2){
            return root;
        }
        
        //If one of the ans is returned then return that ans itself
        if(!ans1 && ans2){
            return ans2;
        }

        //If one of the ans is returned then return that ans itself
        if(ans1 && !ans2){
            return ans1;
        }        

        //If both ans1 and ans2 are NULL then return NULL
        return NULL;
        
    }
};