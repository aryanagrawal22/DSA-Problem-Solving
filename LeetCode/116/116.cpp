// T - O(n) where n is number of nodes;
// S - O(1)

// class Solution {
// public:
//     Node* connect(Node* root) {
        
//         if (root == NULL || root->left == NULL){
//             return root;
//         }
//         root->left->next = root->right;
//         if (root->next){
//             root->right->next = root->next->left;
//         }
//         connect(root->left);
//         connect(root->right);
//         return root;
//     }
// };








// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };
// */

// class Solution {
// public:
    
//     Node* prev;
    
//     Node* nextPopulate(Node* node, int h){
//         if(node==NULL){
//             return NULL;
//         }
        
//         if(h==0){
//             if(prev) prev->next = node;
//             prev = node;
//         }
        
//         nextPopulate(node->left, h-1);
//         nextPopulate(node->right, h-1);
        
//         return node;
//     }
    
//     Node* connect(Node* root) {
        
//         if(!root) return root;
        
//         int height = 0;
//         Node* node = root;
//         while(node!=NULL){
//             height++;
//             node = node->left;
//         }
        
//         for(int i = 0; i<height; i++){
//             prev = NULL;
//             nextPopulate(root, i);    
//         }
        
//         return root;
//     }
// };