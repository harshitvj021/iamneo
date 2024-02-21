// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* head = nullptr;

void insertLeft(int data) {
    Node* newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* curr = head;
            while (curr->next !=head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Node with data " << data << " inserted at the beginning." << endl;
}

void insertRight(int data) {
    Node* newNode = new Node(data);
    if(head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* curr = head;
        while (curr->next != head) {
            curr = curr->next;
        }
        curr->next =newNode;
        newNode->next = head;
    }
    cout << "Node with data " << data << " inserted at the end." <<endl;
}

void insertPos(int data, int position) {
    if (position <= 0) {
        cout << "Invalid position." << endl;;
        return;
    }
    
    Node* newNode = new Node(data);
    
    if(position ==  1){
        newNode->next = head;
        Node* curr = head;
        while (curr->next != head) {
            curr = curr->next;
        }
        curr->next = newNode;
        head = newNode; 
    } else {
        Node* curr = head;
        int count = 1;
        while (count < position - 1 && curr->next != head) {
            curr = curr->next;
            count++;
        }
        if (count < position - 1) {
            cout << "Invalid position." << endl;
            delete newNode;
            return;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    cout << "Node with data" << data << " inserted at position " << position << "." << endl;
}

void display() {
    if (head == nullptr) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }
    Node* curr = head;
    do{
        cout << curr->data << " ";
        curr = curr->next;
        } while (curr != head);
        cout << endl;
}

int main() {
    int choice,data,position;
    
    while (true) {
        cin >> choice;
        
        switch (choice) {
            case 1:
            cin >> data;
            insertLeft(data);
            break;
            case 2:
            cin >> data;
            insertRight(data);
            break;
            case 3:
            cin >> data >> position;
            insertPos(data, position);
            break;
            case 4:
            display();
            break;
            case 5:
            exit(0);
            default:
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}