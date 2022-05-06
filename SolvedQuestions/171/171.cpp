#include <bits/stdc++.h>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
};

void revPreorderRight(node* node, int level);

queue<int> q;

void revPreorderRight(node* node, int level){
    
    if (node == NULL){
        return;
    }

    if(q.size()==level){
        q.push(node->data);
    }

    revPreorderRight(node->right, level + 1);
    revPreorderRight(node->left, level + 1);

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
    node* root = newNode(4);
    root->left = newNode(5);
    root->right = newNode(2);
    root->right->left = newNode(3);
    root->right->right = newNode(1);
    root->right->right->right = newNode(9);
 

    revPreorderRight(root, 0);
    cout << "Right View of the tree:";
    while(!q.empty()){
		cout<<" "<<q.front();
		q.pop();
	}
 
    return 0;
}