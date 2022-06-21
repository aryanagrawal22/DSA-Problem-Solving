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
    
    int maxDiameter = 0;
    
    int recurssion(TreeNode* root) {
        
        //When at leaf node then return 0
        if(root == NULL) return 0;
        
        //Traverse to the deepest leaf and keep returning value as leftLen and rightLen which is the longest right or left len from that node
        int leftLen = recurssion(root->left);
        int rightLen = recurssion(root->right);
        
        //If leftLen + rightLen is greater than current maxDiameter than set it as new maxDiameter
        maxDiameter=max(maxDiameter,leftLen+rightLen);

        //Return max depth from that node either (left tree len or right tree len) + 1 //+1 because adding that node in the length
        return max(leftLen,rightLen)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        //Send the root for recurssion
        recurssion(root);
        return maxDiameter;
    }
}