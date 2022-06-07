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
    
//     TreeNode *recurse(vector<int>& arr, int &ind, int max){
        
//         if(ind==arr.size() || arr[ind]>max) return NULL;
        
//         TreeNode *node = new TreeNode(arr[ind]);
//         ind++;
        
//         node->left = recurse(arr, ind, node->val);
//         node->right = recurse(arr, ind, max);
        
//         return node;
//     }
    
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int index=0;
//         int max = 99999;
//         TreeNode* root = recurse(preorder, index, max);
//         return root;
//     }
// };