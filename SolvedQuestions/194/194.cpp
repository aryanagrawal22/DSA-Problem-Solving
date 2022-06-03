#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node *newNode(int data){
    Node* node = new Node;
    node->data=data;
    node->left = node->right = NULL;
    return node;
}

Node *ancestor = NULL;

int kthancestor(Node *node, int data, int k){
    
    if(node==NULL){
        return -1;
    }

    if(node->data == data){
        if(k==0){
            ancestor=node;
            return 0;
        }
        return k;
    }

    int ans1 = kthancestor(node->left, data, k);
    int ans2 = kthancestor(node->right, data, k);

    if(ans1>0){
        ans1--;
        if(ans1==0){
            ancestor = node;
        }
        return ans1;
    }

    if(ans2>0){
        ans2--;
        if(ans2==0){
            ancestor = node;
        }
        return ans2;
    }

    if(ans1==0 || ans2==0){
        return 0;
    }

    return -1;
}

int main(){
    
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int k, data;
    cin>>data>>k;
    int ans = kthancestor(root, data, k);
    if(ans){
        cout<<"-1"<<"\n";
    }else{
        cout<<ancestor->data<<"\n";
    }
    
    return 0;
}