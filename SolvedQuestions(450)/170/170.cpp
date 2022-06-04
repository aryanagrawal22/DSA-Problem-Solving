// #include <bits/stdc++.h>
// #include <stack>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *left, *right;
// };

// node *newNode(int data);
// void leftView(node *node);

// void leftView(node *root)
// {
//     int c = 0;
//     node *node;
//     cout << root->data<<" ";
//     if (root->left != NULL)
//     {
//         node = root->left;
//     }
//     else if (root->right != NULL)
//     {
//         node = root->right;
//     }
//     else
//     {
//         c = 1;
//     }
//     while (c != 1)
//     {
//         cout << node->data<<" ";
//         if (node->left != NULL)
//         {
//             node = node->left;
//         }
//         else if (node->right != NULL)
//         {
//             node = node->right;
//         }
//         else
//         {
//             c = 1;
//         }
//     }
// }

// node *newNode(int data)
// {
//     node *Node = new node();
//     Node->data = data;
//     Node->left = NULL;
//     Node->right = NULL;

//     return (Node);
// }

// int main()
// {
//     node* root = newNode(4);
//     root->left = newNode(5);
//     root->right = newNode(2);
//     root->right->left = newNode(3);
//     root->right->right = newNode(1);

//     cout << "Left Side of the Tree : ";
//     leftView(root);

//     return 0;
// }



#include <bits/stdc++.h>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
};

void preorderLeftView(node* node, int level);

queue<int> q;

void preorderLeftView(node* node, int level){
    
    if (node == NULL){
        return;
    }

    if(q.size()==level){
        q.push(node->data);
    }

    preorderLeftView(node->left, level + 1);
    preorderLeftView(node->right, level + 1);

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
 

    preorderLeftView(root, 0);
    cout << "Left View of the tree:";
    while(!q.empty()){
		cout<<" "<<q.front();
		q.pop();
	}
 
    return 0;
}