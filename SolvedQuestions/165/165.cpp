#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
};

int height(node* node);
node* newNode(int data);
void diameter(node* root);

int maxDiameter = 0;

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


void diameter(node* node){
    
    if (node==NULL){
        return;
    }

    int lheight = height(node->left);
    int rheight = height(node->right);

    maxDiameter = max(maxDiameter, lheight+rheight+1);

    diameter(node->left);
    diameter(node->right);
 
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
 
    cout << "Diameter of tree is: ";
    diameter(root);
    cout << maxDiameter;
    return 0;
}