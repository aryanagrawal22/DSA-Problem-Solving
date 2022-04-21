#include <bits/stdc++.h>
using namespace std;
 

struct Node {
    int data;
    struct Node* next;
    int flag;
};
 
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;
 
    /* put in the data */
    new_node->data = new_data;
 
    new_node->flag = 0;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
// Meathod 1) Hash Map
// Meathod 2) Make modification in the Structure of linked list
            // Make a flag field initially set to zero and whenever we traverse over it then it is set to 1. If the node is traverssed again and found to have a value of 1 in the flag then true will be returned for loop found else false will be returned for loop found.
bool detectLoop(struct Node* h)
{
    while (h != NULL) {
        if (h->flag == 1)
            return true;
            
        h->flag = 1;
 
        h = h->next;
    }
 
    return false;
}
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
 
    return 0;
}