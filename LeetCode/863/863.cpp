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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> visit;
    vector<int> ans;
    
    void findParent(TreeNode* root){
        if(!root) return;
        
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        
        findParent(root->left);
        findParent(root->right);
    }
    
    void dfs(TreeNode* root, int k){
        if(!root) return;
        if (visit[root]) return;
        visit[root]=1;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        dfs(root->left, k-1);
        dfs(root->right, k-1);
        dfs(parent[root], k-1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParent(root);
        dfs(target, k);
        return ans;
    }
};