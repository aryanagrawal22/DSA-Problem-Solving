#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node *createCircularLL(int n){
    int val;
    cin>>val;
    Node *head, *tail;
    head = tail = new Node(val);
    for(int i = 0; i<n-1; i++){
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    tail->next = head;
    return head;
}

Node *removeNode(int data, Node *head, int len){

    if(head==NULL){
        return NULL;
    }
    
    Node *node = head;
    Node *prev = NULL;
    do{
        prev = node;
        node = node->next;

        if(node->data==data && node == head){
            prev->next = node->next;
            head = node->next;
            return head;
        }

        if(node->data==data){
            prev->next = node->next;
            return head;
        }

    }while(node!=head);
    
    return head;
}

int main (){
    int n;
    cin>>n;
    Node *head = createCircularLL(n);
    cout<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<" "<<head->next->next->next->data<<"\n";
    int data;
    cin>>data;
    head = removeNode(data, head, n);
    cout<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<" "<<head->next->next->next->data<<"\n";
    return 0;
}