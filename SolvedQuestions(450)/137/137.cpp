#include <iostream>

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

int intersectPoint(struct Node *head1, struct Node *head2);
Node *iterate(struct Node *node1, struct Node *node2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

int main()
{
    int n1, n2, n3;

    cin >> n1 >> n2 >> n3;

    Node *head1 = inputList(n1);
    Node *head2 = inputList(n2);
    Node *common = inputList(n3);

    Node *temp = head1;
    while (temp != NULL && temp->next != NULL)
        temp = temp->next;
    if (temp != NULL)
        temp->next = common;

    temp = head2;
    while (temp != NULL && temp->next != NULL)
        temp = temp->next;
    if (temp != NULL)
        temp->next = common;

    cout << intersectPoint(head1, head2) << endl;

    return 0;
}

int intersectPoint(Node *head1, Node *head2)
{

    Node* ptr1 = head1;
    Node* ptr2 = head2;
 
    if (ptr1 == NULL || ptr2 == NULL)
        return NULL;
 
    while (ptr1 != ptr2) {
 
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
 
        if (ptr1 == ptr2)
            return ptr1->data;

        if (ptr1 == NULL)
            ptr1 = head2;

        if (ptr2 == NULL)
            ptr2 = head1;
    }
    return ptr1->data;
}
