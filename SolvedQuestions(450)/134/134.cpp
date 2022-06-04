#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution
{
    public:
    
    int answer(Node *head){
        if(head->next==NULL){
            if(head->data + 1 != 10){
                head->data += 1;
                return 0;
            }else{
                head->data = 0;
                return 1;
            }
        }
        
        int val = answer(head->next);
        
        if(head->data + val != 10){
                head->data += val;
                return 0;
            }else{
                head->data = 0;
                return 1;
            }
        
    }
    
    Node* addOne(Node *head) 
    {
        int val = answer(head);
        if(val==1){
            Node *node = new Node(1);
            node->next = head;
            return node;
        }
        return head;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 