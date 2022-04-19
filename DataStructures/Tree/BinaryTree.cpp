#include <bits/stdc++.h>
using namespace std;

struct bintree_node{
    bintree_node *left;
    bintree_node *right;
    char data;
};

class BinaryTree{
    bintree_node *root;
public:
    BinaryTree(){
        root=NULL;
    }
    int isEmpty(){
        return(root==NULL);
    };
    void insert_node(int item);
    void inorder_seq();
    void inorder(bintree_node *node);
};

void BinaryTree:: insert_node(int item){
    
};