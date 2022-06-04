#include <iostream>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }

    /* Function to find the middle element */
    void middleElement(){
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){

            slow = slow->next;
            fast = fast->next->next;
        
        }
        cout<<slow->data;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
    ll.push(74);
    ll.push(71);
    ll.print();

    cout << "\nMiddle Element of the linked list: ";

    ll.middleElement();

    return 0;
}