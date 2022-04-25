#include <bits/stdc++.h>
using namespace std;

#define MAX 6

class Queue
{
    int front, rear;

public:
    int a[MAX]; //Max size of queue

    Queue(){
        front = -1;
        rear = -1;
    };
    bool isEmpty();
    bool isFull();
    void enQueue(int n);
    int deQueue();
    void displayQueue();

};

bool Queue::isEmpty(){
    if (front == -1 && rear == -1){
        return true;
    }else{
        return false;
    }
}

bool Queue::isFull(){
    if((rear+1) % MAX == front){
        return true;
    }else{
        return false;
    }
}

void Queue::enQueue(int n){
    if (isEmpty()){
        front = rear = 0;
        a[rear] = n;
    }else if (isFull()){
        cout<<"Queue Full";
    }else{
        rear = (rear + 1) % MAX;
        a[rear] = n;
    }
    
}

int Queue::deQueue(){
    int value;
    if (isEmpty()){
        cout<<"Queue is Empty";
        return 0;
    }else{
        value = a[front];
        front = (front+1) % MAX;
        return value;
    }
}

void Queue::displayQueue(){
    int i = front;
    if (isEmpty()){
        cout<<"Empty Queue";
    }else{
        while(i<=rear)  
        {  
            cout<<a[i]<<"\n";
            i=(i+1) % MAX;  
        }
    }
}


int main()
{
    Queue obj;
    cout << "Please select one of the following options:  \n";

    cout << "0: Exit\n"
            "1: Add to Circular Queue\n"
            "2: Delete from Circular Queue\n"
            "3: Display Queue\n";
    
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
            cout<<"Enter the number to add: \n";
            cin>>x;
            obj.enQueue(x);
            break;
        }

        case 2:
        {
            cout<<obj.deQueue()<<" was dropped \n";
            break;
        }

        case 3:
        {
            obj.displayQueue();
            break;
        }
        }
    } while (choice != 0);
    
    return 0;
}