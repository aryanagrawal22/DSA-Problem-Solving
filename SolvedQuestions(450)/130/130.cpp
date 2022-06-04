#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node *head)
{
    if (!head)
        return false;

    Node *fast = head->next;
    Node *slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node *head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

#include <bits/stdc++.h>
class Solution
{
public:
    Node* loopNode(Node *head)
    {
        unordered_set <Node*> us;
        Node *node = head;
        while(node!=NULL){
            if(us.find(node)!=us.end()){
                return node;
            }
            us.insert(node);
            node = node->next;
        }
        return NULL;
    }
};

int main()
{
    int n, num;
    cin >> n;

    Node *head, *tail;
    cin >> num;
    head = tail = new Node(num);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> num;
        tail->next = new Node(num);
        tail = tail->next;
    }

    int pos;
    cin >> pos;
    loopHere(head, tail, pos);

    Solution ob;
    Node* resHead = ob.loopNode(head);

    if(resHead!=NULL){
        cout<<"Loop at: "<<resHead->data<<"\n";
    }else{
        cout<<"No Loop"<<"\n";
    }

    return 0;
}