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
    
//     TreeNode* answer(vector<int>& arr, int start, int end)
// {
//     if (start > end)
//     return NULL;
 
//     int mid = (start + end)/2;
//     TreeNode *root = new TreeNode(arr[mid]);
 
//     root->left = answer(arr, start,
//                                     mid - 1);
 
//     root->right = answer(arr, mid + 1, end);
 
//     return root;
// }
    
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         int len = nums.size();
//         TreeNode* node = answer(nums, 0, len-1);
//         return node;
//     }
// };