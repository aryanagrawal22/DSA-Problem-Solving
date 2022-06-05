// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//         if(root==NULL){
//             return NULL;
//         }
        
//         TreeNode* ans1 = lowestCommonAncestor(root->left, p, q);
//         TreeNode* ans2 = lowestCommonAncestor(root->right, p, q);
    
//         if(root==p || root==q){
//             return root;
//         }
        
//         if(ans1 && ans2){
//             return root;
//         }
        
//         if(!ans1 && ans2){
//             return ans2;
//         }

//         if(ans1 && !ans2){
//             return ans1;
//         }
        
//         return NULL;
        
//     }
// };