// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
    
//     TreeNode* recurse(TreeNode* node, int &k){
        
//         if(node==NULL) return NULL;
        
//         TreeNode* ans1 = recurse(node->left, k);
//         if(ans1) return ans1;
        
//         k--;
//         if(k==0){
//             return node;
//         }
        
//         TreeNode *ans2 = recurse(node->right, k);
//         return ans2;
//     }
    
//     int kthSmallest(TreeNode* root, int &k) {
//         TreeNode* ans = recurse(root, k);
//         return ans->val;
//     }
// };