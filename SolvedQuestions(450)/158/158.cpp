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
    void deleteSmallNode()
    {

        Node *temp = head;
        Node *prev = NULL;
        Node *next;

        while (temp->next != NULL)
        {
            next = temp->next;

            if (prev != NULL)
            {
                if (next->data > temp->data)
                {
                    prev->next = next;
                }
                else
                {
                    prev = temp;
                }
            }else{
                if (next->data > temp->data)
                {
                    head = next;
                }
                else
                {
                    prev = temp;
                }
            }
            
            
            temp = temp->next;            
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
    ll.push(3);
    ll.push(2);
    ll.push(6);
    ll.push(5);
    ll.push(11);
    ll.push(10);
    ll.push(15);
    ll.push(12);

    ll.print();

    ll.deleteSmallNode();
    cout << "\n";
    ll.print();
    return 0;
}