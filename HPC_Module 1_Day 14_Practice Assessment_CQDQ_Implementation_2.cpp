
// Write a program to implement a deque (double-ended queue) using an array. The program should provide the following functionality:

#include <iostream>
using namespace std;

const int MAX = 20;

class Deque {
private:
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    Deque(int size) {
        front = -1;
        rear = 0;
        this->size = size;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int key) {
        if (isFull()) {
            cout << "Overflow" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0)
            front = size - 1;
        else
            front = front - 1;

        arr[front] = key;
        cout << key << endl;
    }

    void insertRear(int key) {
        if (isFull()) {
            cout << "Overflow" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1)
            rear = 0;
        else
            rear = rear + 1;

        arr[rear] = key;
        cout << key << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0)
            rear = size - 1;
        else
            rear = rear - 1;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty() || rear < 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    void printDeque() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cin >> size;

    Deque dq(size);
    int choice;
    int front, rear;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> front;
                dq.insertFront(front);
                break;
            case 2:
                cin >> rear;
                dq.insertRear(rear);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                front = dq.getFront();
                if (front != -1) {
                    cout << front << endl;
                }
                break;
            case 6:
                rear = dq.getRear();
                if (rear != -1) {
                    cout << rear << endl;
                }
                break;
            case 7:
                dq.printDeque();
                break;
            case 8:
                cout << "Exiting" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
