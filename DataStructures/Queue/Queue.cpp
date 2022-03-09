#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

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
    if (front == -1){
        return true;
    }else{
        return false;
    }
}

bool Queue::isFull(){
    if(front == 0 && rear == MAX - 1){
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
        rear = rear + 1;
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
        front++;
        return value;
    }
}

void Queue::displayQueue(){
    if (isEmpty()){
        cout<<"Empty Queue";
    }else{
        for (int i = front; i<=rear; i++){
            cout<<a[i]<<"\n";
        }
    }
}


int main()
{
    Queue obj;
    cout << "Please select one of the following options:  \n";

    cout << "0: Exit\n"
            "1: Add to Queue\n"
            "2: Delete from Queue\n"
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