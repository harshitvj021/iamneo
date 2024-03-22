#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
    private:
    Node* front;
    Node* rear;
    
    public:
    Queue() : front(nullptr), rear(nullptr) {}
    
    void enqueue(int customerId) {
        Node* newNode = new Node(customerId);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Customer ID " << customerId << " is enqueued" << endl;
    }
    
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        
        int customerId = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        cout << "Dequeued customer ID: " << customerId << endl;
        return customerId;
    }
    
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Customer IDs in the queue are: ";
        Node* current = front;
        while(current!=nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    
    int choice, customerId;
    while(cin >> choice) {
        if(choice == 1) {
            cin >> customerId;
            queue.enqueue(customerId);
        } else if (choice == 2) {
            queue.dequeue();
        } else if (choice == 3) {
            queue.display();
        } else {
            cout << "Invalid option" << endl;
        }
    }
    return 0;
}