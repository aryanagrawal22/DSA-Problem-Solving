#include <bits/stdc++.h>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

node *newNode(int data);
void leftView(node *node);

void leftView(node *root)
{
    int c = 0;
    node *node;
    cout << root->data<<" ";
    if (root->left != NULL)
    {
        node = root->left;
    }
    else if (root->right != NULL)
    {
        node = root->right;
    }
    else
    {
        c = 1;
    }
    while (c != 1)
    {
        cout << node->data<<" ";
        if (node->left != NULL)
        {
            node = node->left;
        }
        else if (node->right != NULL)
        {
            node = node->right;
        }
        else
        {
            c = 1;
        }
    }
}

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(7);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->left = newNode(2);

    cout << "Left Side of the Tree : ";
    leftView(root);

    return 0;
}