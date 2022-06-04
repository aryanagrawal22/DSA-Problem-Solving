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
void postorderTreeRecursive(node *node);
void postorderTreeIterative(node *root);

void postorderTreeRecursive(node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        postorderTreeRecursive(node->left);
        postorderTreeRecursive(node->right);
        cout << node->data << " ";
    }
}

void postorderTreeIterative(node *root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<node*> s;
    s.push(root);
 
    // create another stack to store postorder traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
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

    cout << "Postorder traversal using recursive : ";
    postorderTreeRecursive(root);

    cout << "\nPostorder traversal using iterative : ";
    postorderTreeIterative(root);

    return 0;
}