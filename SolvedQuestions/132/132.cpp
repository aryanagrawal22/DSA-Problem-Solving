#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }

        Node *curr = head->next;
        Node *prev = head;
        unordered_set<int> us;

        us.insert(prev->data);

        while (curr != NULL)
        {
            
            if (us.find(curr->data) != us.end())
            {
                prev->next = curr->next;
                curr = prev->next;
            }
            else
            {
                us.insert(curr->data);
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};

int main()
{
    int K;
    cin >> K;
    struct Node *head = NULL;
    struct Node *temp = head;

    for (int i = 0; i < K; i++)
    {
        int data;
        cin >> data;
        if (head == NULL)
            head = temp = new Node(data);
        else
        {
            temp->next = new Node(data);
            temp = temp->next;
        }
    }

    Solution ob;
    Node *result = ob.removeDuplicates(head);
    print(result);
    cout << endl;

    return 0;
} 