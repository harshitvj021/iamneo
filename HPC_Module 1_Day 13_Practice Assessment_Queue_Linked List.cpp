#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    private:
    Node* front;
    Node* rear;
    public:
    Queue() {
        front = rear = nullptr;
    }
    
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if(rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    void dequeue() {
        if (front == nullptr) {
            return;
        }
        
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }
    
    void displayFrontRear() {
        if (front!= nullptr && rear!= nullptr) {
            cout << "Front: " << front->data << ", Rear: " << rear->data << endl;
        }
    }
};

int main() {
    int N;
    cin >> N;
    
    Queue queue;
    
    for (int i = 0;i<N; ++i) {
        int customerId;
        cin >> customerId;
        queue.enqueue(customerId);
    }
    
    queue.dequeue();
    
    queue.displayFrontRear();
    
    return 0;
}
