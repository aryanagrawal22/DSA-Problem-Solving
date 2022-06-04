#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    Node* root = newNode(stoi(ip[0]));
        
    queue<Node*> queue;
    queue.push(root);
        
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        Node* currNode = queue.front();
        queue.pop();
            
        string currVal = ip[i];
            
        if(currVal != "N") {
                
            currNode->left = newNode(stoi(currVal));
                
            queue.push(currNode->left);
        }
            
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        if(currVal != "N") {
                
            currNode->right = newNode(stoi(currVal));
                
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

class Solution{
  public:
    
    int level = 0;
    int c = -1;
    bool check(Node *root)
    {
        int depth = 1;
        iterate(root, depth);
        return c?true:false;
    }
    
    void iterate(Node *node, int depth){
        
        if(node==NULL){
            return;
        }
        
        if(node->left==NULL && node->right==NULL){
            if(level){
                if(depth==level && c!=0){
                    c = 1;
                    return;
                }else{
                    c = 0;
                    return;
                }
            }else{
                level = depth;
                c = 1;
                return;
            }
        }
        
                
        iterate(node->left , depth+1);
        iterate(node->right, depth+1);
        
        return;
        
    }
};

int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}