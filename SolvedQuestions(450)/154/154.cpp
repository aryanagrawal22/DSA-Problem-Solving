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
    void sort012(){
        Node *temp = head;
        int zero = 0;
        int one = 0;
        int two = 0;
        while (temp != NULL){
            if (temp->data == 0){
                zero++;
            }else if(temp ->data == 1){
                one++;
            }else{
                two++;
            }
            temp=temp->next;
        }

        temp = head;

        while(temp!= NULL){
            if (zero != 0){
                temp->data = 0;
                zero--;
            }else if(one != 0){
                temp->data = 1;
                one--;
            }else{
                temp->data = 2;
                two--;
            }

            temp=temp->next;
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
    ll.push(0);
    ll.push(0);
    ll.push(2);
    ll.push(2);
    ll.push(0);
    ll.push(2);
    ll.push(1);
    ll.push(2);
    
    ll.print();

    ll.sort012();

    cout<<"\nSorted Linked list\n";
    
    ll.print();

    return 0;
}