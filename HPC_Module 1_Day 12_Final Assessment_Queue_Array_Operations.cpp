// You are using GCC
#include <iostream>
#define MAX_SIZE 5

using namespace std;

char orders[MAX_SIZE];
int front = -1;
int rear = -1;

void initializeQueue() {
    front = -1;
    rear = -1;
}

bool isempty() {
    return front == -1;
}

bool isFull() {
    return(rear +1) % MAX_SIZE == front;
}

bool enqueue(char order) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue more orders." << endl;
        return false;
    }
    
    if (isempty()) {
        front = rear =0;
    } else {
        rear =(rear +1) % MAX_SIZE;
    }
    
    orders[rear] = order;
    cout << "Order for " << order << " is enqueued." <<endl;
    return true;
}

bool dequeue(char& order) {
    if (isempty()) {
        return false;
    }
    
    order = orders[front];
    
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front +1) % MAX_SIZE;
    }
    
    return true;
}

void display() {
    if (isempty()) {
        cout << "Queue is empty.No orders available." << endl;
    } else {
        cout << "Orders in the queue are: ";
        int i =front;
        while (i!=rear) {
            cout << orders[i] << " ";
            i =(i+1) % MAX_SIZE;
        }
        cout << orders[rear] << endl;
    }
}

int main() {
    char order;
    int option;
    
    initializeQueue();
    
    while (true) {
        if (!(cin>>option)) {
            break;
        }
        
        switch (option) {
            case 1:
            if(!(cin >> order)) {
                break;
            }
            if (enqueue(order)) {
                // Order enqueued
            }
            break;
            
            case 2:
            if(dequeue(order)) {
                cout << "Dequeued Order: " << order << endl;
            } else {
                cout << "No orders in the queue." << endl;
            }
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            cout << "Exiting program";
            return 0;
            
            default: 
            cout << "Invalid option." << endl;
            break;
        }
    }
    return 0;
}