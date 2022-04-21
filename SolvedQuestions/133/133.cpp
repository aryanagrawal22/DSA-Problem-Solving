#include <iostream>
using namespace std;
  
/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
  
struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }
  
    /* Function to reverse the linked list */
    void lastToFirst()
    {
        Node *last, *sclast;
        sclast = head;
        last = head->next;
        while(last->next!=NULL){
            sclast = last;
            last = last->next;
        }
        last->next= head;
        sclast->next=NULL;
        head = last;
    }
  
    /* Function to print linked list */
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
  
    void push(int data)
    {
        Node* temp = new Node(data);
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
    ll.push(2);
    ll.push(5);
    ll.push(1);
    ll.push(5);
    cout << "Given linked list\n";
    ll.print();
  
    ll.lastToFirst();
  
    cout << "\nNew linked list \n";
    ll.print();
    return 0;
}