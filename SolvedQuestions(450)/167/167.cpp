#include <bits/stdc++.h>
#include <stack>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
};

node* newNode(int data);
void inorderTreeRecursive(node* node);
void inorderTreeInerative(node* node);

void inorderTreeRecursive(node* node) {
   if (node == NULL) {
      return;
   }
   else {
      inorderTreeRecursive(node->left);
      cout<<node->data<<" ";
      inorderTreeRecursive(node->right);      
   }
}

void inorderTreeIterative(node* root) {
    stack<node*> stack;

    node* curr = root;

    while(!stack.empty() || curr != NULL){
        if(curr!= NULL){
            stack.push(curr);
            curr = curr->left;
        }else{
            curr = stack.top();
            stack.pop();
            cout<<curr->data<<" ";

            curr = curr->right;
        }
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

    cout << "Inorder traversal using recursive : ";
    inorderTreeRecursive(root);

    cout << "\nInorder traversal using iterative : ";
    inorderTreeIterative(root);

    return 0;
}