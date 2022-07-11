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
    void traverse(vector<vector<int>>& ans, vector<int> sumArr, TreeNode* node, int target){
        
        //DFS travel where we find keep on decreacing target to to the current node val and when we reach the leaf then we check if target is 0
        if(!node) return;
        
        sumArr.push_back(node->val);
        target -= node->val;
        
        if(!node->left && !node->right && !target){
            ans.push_back(sumArr);
        } else {
            traverse(ans, sumArr, node->left, target);
            traverse(ans, sumArr, node->right, target);
        }
        return;
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> curSum;
        traverse(ans, curSum, root, targetSum);
        return ans;
    }
};