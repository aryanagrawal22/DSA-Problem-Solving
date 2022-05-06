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
    root->left = newNode(7);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Vertical traversal of tree is: \n";
    verticalTraversal(root, 0);

    map< int,vector<int> > :: iterator it;
    for (it=hm.begin(); it!=hm.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
 
    return 0;
}