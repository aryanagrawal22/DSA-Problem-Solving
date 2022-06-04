// class Solution {
// public:
//     bool recurse(TreeNode* node, long long lower, long long upper){
//         if(!node) return true;
        
//         if(node->val <= lower) return false;
//         if(node->val >= upper) return false;
        
//         if(!recurse(node->left, lower, node->val)) return false;
//         if(!recurse(node->right, node->val, upper)) return false;
        
//         return true;
//     }
    
//     bool isValidBST(TreeNode* root) {
//         return recurse(root, LLONG_MIN, LLONG_MAX);
//     }
// };