// You are using GCC
#include <iostream>
using namespace std;

class Queue {
    private:
    int front , rear, capacity;
    int* array;
    public:
    Queue(int size) {
        capacity = size;
        front = rear = -1;
        array = new int[capacity];
    }
    
    ~Queue() {
        delete[] array;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        rear = (rear +1)% capacity;
        array[rear] = item;
        if (front == -1){
            front = rear;
        }
        cout << "Order ID " << item << " is inserted in the queue." << endl;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int item = array[front];
        if (front == rear) {
            front = rear = -1;
        } else { 
            front = (front+1) % capacity;
        }
        cout << "Processed Order ID: " << item  << endl;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        cout << "Order IDs in the queue are: ";
        while (i!=rear) {
            cout << array[i] << " ";
            i = (i+1) % capacity;
        }
        cout << array[rear] << endl;
    }
};

int main() {
    Queue q(5);
    int option,orderID;
    while (cin >> option) {
        switch (option) {
            case 1:
            cin >> orderID;
            q.enqueue(orderID);
            break;
            case 2:
            q.dequeue();
            break;
            case 3:
            q.display();
            break;
            default:
            cout << "Invalid option." << endl;
        }
    }
    return 0;
}