#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
};

node* newNode(int data);
void convertTreeToItsMirror(node* root);
void inorderTree(node* node);


void convertTreeToItsMirror(struct node* node) {
   if (node == NULL) {
      return;
   }
   else {
      struct node* temp;
      convertTreeToItsMirror(node->left);
      convertTreeToItsMirror(node->right);
      temp = node->left;
      node->left = node->right;
      node->right = temp;
   }
}


void inorderTree(node* node) {
   if (node == NULL) {
      return;
   }
   else {
      inorderTree(node->left);
      cout<<node->data<<" ";
      inorderTree(node->right);      
   }
}


node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(7);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->left = newNode(2);

    cout << "Inorder traversal of mirror tree : ";
    inorderTree(root);
 
    cout << "\nInorder traversal of mirror tree : ";
    convertTreeToItsMirror(root);
    inorderTree(root);
    return 0;
}