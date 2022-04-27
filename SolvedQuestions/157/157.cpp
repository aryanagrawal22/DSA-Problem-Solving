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
    void multiplyLL(Node *head1, Node *head2)
    {

        Node *temp1 = head1;
        Node *temp2 = head2;
        int num1 = 0;
        int num2 = 0;
        int multiplier;
        multiplier = 1;
        while (temp1 != NULL)
        {
            num1 += (temp1->data) * multiplier;
            temp1 = temp1->next;
            multiplier = multiplier * 10;
        }

        multiplier = 1;
        while (temp2 != NULL)
        {
            num2 += (temp2->data) * multiplier;
            temp2 = temp2->next;
            multiplier = multiplier * 10;
        }

        int rev_num1 = 0;
        while (num1 > 0)
        {
            rev_num1 = rev_num1 * 10 + num1 % 10;
            num1 = num1 / 10;
        }

        int rev_num2 = 0;
        while (num2 > 0)
        {
            rev_num2 = rev_num2 * 10 + num2 % 10;
            num2 = num2 / 10;
        }

        long int final = rev_num1 * rev_num2;
        cout<<"\n"<<rev_num1;
        cout<<"\n"<<rev_num2;
        cout<<"\n"<<final;
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

    Node *push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        return head;
    }
};

/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll1;
    ll1.push(2);
    ll1.push(3);
    Node *head1 = ll1.push(1);

    LinkedList ll2;
    Node *head2 = ll2.push(2);


    cout<<"\nFirst LL:";
    ll1.print();

    cout<<"\nSecond LL:";
    ll2.print();

    LinkedList ll;

    ll.multiplyLL(head1, head2);

    return 0;
}