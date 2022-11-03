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
class FindElements {
public:
    TreeNode* head=NULL;
    FindElements(TreeNode* root) {
        head=root;
        solve(root, 0);
    }
    
    void solve(TreeNode* node, int x){
        if(!node) return;
        node->val=x;
        solve(node->left, 2*x+1);
        solve(node->right, 2*x+2);
    }
    
    bool findNode(int target, TreeNode* node){
        if(!node) return false;
        if(node->val==target) return true;
        return findNode(target, node->left) || findNode(target, node->right);
    }
    
    bool find(int target) {
        return findNode(target, head);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */