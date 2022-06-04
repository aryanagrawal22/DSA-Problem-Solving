#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
};

int height(node* node);
node* newNode(int data);
 
int height(node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
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
    node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(60);
    root->left->right->left = newNode(90);
 
    
    int h = height(root);
    cout<<"Height of BT:"<<h;
    return 0;
}