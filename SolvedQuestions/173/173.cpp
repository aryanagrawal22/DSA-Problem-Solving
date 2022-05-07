#include <bits/stdc++.h>
#include <map>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
};

void verticalTraversal(node* node, int mid);

map <int, vector<int>> hm;

void verticalTraversal(node* node, int mid){
    if(node==NULL){
        return;
    }

    hm[mid].push_back(node->data);

    verticalTraversal(node->left, mid-1);
    verticalTraversal(node->right, mid+1);
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
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    cout << "Vertical traversal of tree is: \n";
    verticalTraversal(root, 0);

    map< int,vector<int> > :: iterator it;
    for (it=hm.begin(); it!=hm.end(); it++)
    {
        cout << it->second[it->second.size()-1] << " ";
    }
 
    return 0;
}