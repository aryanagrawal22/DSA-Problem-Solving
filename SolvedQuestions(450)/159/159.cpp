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
    void sortEvenOdd(){
        Node* even= new Node(-1);
        Node* odd= new Node(-1);
        Node* evenptr=even;
        Node* oddptr=odd;
        
        Node* temp=head;
        
        while(temp!=NULL){
            if((temp->data)%2==0){
                evenptr->next=temp;
                evenptr=evenptr->next;
            }
            else{
                oddptr->next=temp;
                oddptr=oddptr->next;
            }
            temp=temp->next;
        }
        if(even->next!=NULL){
            evenptr->next=odd->next;
            oddptr->next=NULL;
            head = even->next;
        }else{
            head = odd->next;
        }
        
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
    ll.push(6);
    ll.push(4);
    ll.push(2);
    ll.push(9);
    ll.push(8);
    ll.push(15);
    ll.push(17);
    
    ll.print();

    ll.sortEvenOdd();
    cout<<"\n";
    ll.print();
    return 0;
}