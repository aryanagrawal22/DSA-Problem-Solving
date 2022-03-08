#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack
{
    int top;

public:
    int a[MAX]; // Max Stack Size

    Stack()
    { // Constructor
        top = -1;
    };
    bool push(int x);
    int pop();
    int peep();
    bool isEmpty();
    bool isFull();
};

bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull()
{
    if (top >= (MAX - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << "Pushed into Stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

int Stack::peep()
{
    if (isEmpty())
    {
        cout << "Stack Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

int main()
{
    Stack obj;
    cout << "Please select one of the following options:  \n";

    cout << "0: Exit\n"
            "1: Push to Stack\n"
            "2: Peep Stack\n"
            "3: Pop from Stack\n";
    
    int choice;

    do
    {
        cout << "Enter your selection: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int x;
            cout<<"Enter the number to push: \n";
            cin>>x;
            obj.push(x);
            break;
        }

        case 2:
        {
            cout<<obj.peep()<<" is at top \n";
            break;
        }

        case 3:
        {
            cout<<obj.pop()<<" was popped \n";
            break;
        }
        }
    } while (choice != 0);
    
    return 0;
}