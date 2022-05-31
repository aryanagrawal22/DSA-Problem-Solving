#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
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

void splitList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref);
struct Node *newNode(int key)
{
    struct Node *temp = new Node(key);

    return temp;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main()
{

    int n, i, x;
    struct Node *temp, *head = NULL;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    scanf("%d", &n);
    scanf("%d", &x);
    head = new Node(x);
    temp = head;
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &x);

        temp->next = new Node(x);

        temp = temp->next;
    }

    temp->next = head;

    splitList(head, &head1, &head2);

    // printf("\nFirst Circular Linked List");
    printList(head1);

    // printf("\nSecond Circular Linked List");
    printList(head2);

    return 0;
}

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *node = head->next;
    Node* start1, *start2;
    int len = 1, mid;

    while (node != head)
    {
        len++;
        node = node->next;
    }

    if (len % 2 == 0)
    {
        mid = len / 2;
    }
    else
    {
        mid = (len / 2) + 1;
    }

    head1_ref = &head;
    node = head;
    start1 = head;

    for (int i = 1; i <= len; i++)
    {
        if (i == mid)
        {
            Node *temp = node->next;
            start2 = temp;
            head2_ref = &temp;
            node->next = NULL;
            node = temp;
        }
        else
        {
            if(i!=len){
                node = node->next;
            }
        }
    }
    node->next = NULL;
    
    node = start1;
    while(node!=NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<"\n";
    node = start2;
    while(node!=NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<"\n";
    return;
}