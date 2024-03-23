// Implement a circular queue data structure using an array. The program should support the following operations:

#include <iostream>
using namespace std;

const int MAX =20;

class CircularQueue {
    private:
    int cqueue_arr[MAX];
    int front,rear;
    
    public:
    CircularQueue() {
        front =-1;
        rear = -1;
    }
    
    void insert(int item) {
        if((front == 0 && rear == MAX - 1) || (front == rear +1)) {
            cout << "Queue Overflow" <<endl;
            return;
        }
        
        if(front ==-1) {
            front =0;
            rear =0;
        } else {
            if(rear == MAX - 1)
            rear =0;
            else 
            rear =rear+1;
        } 
        cqueue_arr[rear] =item;
    }
    
    void del() {
        if(front == -1) {
            cout << "Queue Underflow" << endl;
            return;
        }
        
        cout << cqueue_arr[front] << endl;
        if(front == rear) {
            front =-1;
            rear =-1;
        } else {
            if(front == MAX -1)
            front =0;
            else 
            front =front +1;
        }
    }
    
    void display() {
        int front_pos =front;
        int rear_pos =rear;
        if(front_pos<=rear_pos) {
            while (front_pos <=rear_pos) {
                cout << cqueue_arr[front_pos] << " ";
                front_pos++;
            }
        } else {
            while (front_pos <= MAX-1) {
                cout << cqueue_arr[front_pos] << " ";
                front_pos++;
            } 
            front_pos = 0;
            while(front_pos <=rear_pos) {
                cout << cqueue_arr[front_pos] << " ";
                front_pos++;
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, item;
    do {
        cin >> choice;
        switch (choice) {
            case 1:
            cin >> item;
            cq.insert(item);
            break;
            case 2:
            cq.del();
            break;
            case 3:
            cq.display();
            break;
            case 4:
            break;
            default:
            cout << "Wrong choice" << endl;
        }
    } while (choice !=4);
    return 0;
}
