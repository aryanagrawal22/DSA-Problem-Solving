#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node()
    {
        data = 0;
        left = right = NULL;
    }
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:


    Node *lca(Node *node, int n1, int n2)
    {
        if(node==NULL){
            return NULL;
        }

        Node *ans1 = lca(node->left, n1, n2);
        Node *ans2 = lca(node->right, n1, n2);

        if(node->data==n1 || node->data==n2){
            return node;
        }

        if(ans1 && ans2){
            return node;
        }
        
        if(!ans1 && ans2){
            return ans2;
        }

        if(ans1 && !ans2){
            return ans1;
        }        

        return NULL;

    }
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void printInorder(Node *root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    int a, b;
    cin>>a>>b;
    
    Solution ob;
    cout << ob.lca(root, a, b)->data << endl;

    return 0;
}