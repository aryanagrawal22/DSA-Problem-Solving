#include <bits/stdc++.h>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

node *newNode(int data);
void preorderTreeRecursive(node *node);
void preorderTreeIterative(node *root);

void preorderTreeRecursive(node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        cout << node->data << " ";
        preorderTreeRecursive(node->left);
        preorderTreeRecursive(node->right);
    }
}

void preorderTreeIterative(node *root)
{
    if (root == nullptr)
    return;
 
    stack<node*> stack;
    stack.push(root);
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // pop a node from the stack and print it
        node* curr = stack.top();
        stack.pop();
 
        cout << curr->data << " ";
 
        // push the right child of the popped node into the stack
        if (curr->right) {
            stack.push(curr->right);
        }
 
        // push the left child of the popped node into the stack
        if (curr->left) {
            stack.push(curr->left);
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

    cout << "Preorder traversal using recursive : ";
    preorderTreeRecursive(root);

    cout << "\nPreorder traversal using iterative : ";
    preorderTreeIterative(root);

    return 0;
}