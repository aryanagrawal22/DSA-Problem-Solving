#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = newNode(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {

            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    int iterate(Node *root)
    {

        if(!root){
            return 0;
        }

        if (!(root->left) && !(root->right))
        {
            // cout<<root->data;
            return root->data;
        }

        int ans1 = iterate(root->left);
        int ans2 = iterate(root->right);
        
        if (ans1 + ans2 == root->data)
        {
            return root->data+ans1+ans2;
        }

        return 0;
    }

    bool isSumTree(Node *root)
    {
        int ans = iterate(root);
        if (ans)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    Solution ob;
    cout<<ob.isSumTree(root)<<"\n";

    return 1;
}