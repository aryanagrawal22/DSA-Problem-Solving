/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connectRight(Node* node, int level, Node* &prev){
        
        if(!node) return;
        
        if(!level){
            if(!prev) {
                prev = node;
            }else{
                prev->next = node;
                prev = node;
            }
            return;
        }
        
        connectRight(node->left, level-1, prev);
        connectRight(node->right, level-1, prev);
        
    }
    
    int calcHeight(Node* node){
        if(!node) return 1;
        return max(calcHeight(node->left), calcHeight(node->right)) + 1;
    }
    
    Node* connect(Node* root) {
        int height = calcHeight(root);
        
        for(int i = 1; i<=height; i++){
            Node* node = NULL;
            connectRight(root, i, node);
        }
        
        return root; 
    }
};