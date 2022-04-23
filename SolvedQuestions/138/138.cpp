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

    /* Function to reverse the linked list */
    void mergeSort(Node **begin,Node **end)
    {
        Node *head = *begin;
        Node *last = *end;
        if (head->next = NULL)
        {
            return; // Returns recursively
        }
        
        // Calculate middle
        Node *temp = head;
        int n = 1;
        while (temp->next != last){
            
            temp = temp->next;
            
            n++;
            cout<<n;
        };
        cout<<last->data;
        n = n/2;
        temp=head;
        for (int i =0; i< n; i++){
            temp = temp->next;
        }

        Node *mid = temp;
        cout<<mid->data;
        // mergeSort(begin, mid);
        // mergeSort(mid->next, end);
        // merge(begin, mid, end);
    }

    // Node *midCalculate(Node *begin, Node *end)
    // {
        
    //     cout<<temp->data;
    //     return temp;
    // };

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
    ll.push(98);

    cout << "Given linked list\n";
    ll.print();

    Node *temp = ll.head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    ll.mergeSort(&ll.head, &temp);

    return 0;
}