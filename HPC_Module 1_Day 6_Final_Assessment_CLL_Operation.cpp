// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    if( head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* curr =head;
        while (curr->next != head) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    cout << "Node with data " << data << " inserted." << endl;
}

void beginDelete() {
    if(head == NULL) {
        cout << "Circular Linked List is empty." <<endl;
        return;
    }
    
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* curr = head;
        while (curr->next !=head) {
            curr = curr->next;
        }
        curr->next = head->next;
        delete head; 
        head = curr->next;
    }
    
    cout << "Node at the beginning deleted." <<endl;
}

void lastDelete() {
    if (head == NULL) {
        cout << "Circular Linked List is empty." <<endl;
        return;
    }
    
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        while (curr->next !=head) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = head;
        delete curr;
    }
    
    cout << "Node at the end deleted." << endl;
}

void randomDelete(int data) {
    if (head == NULL) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }
    
    if(head->data == data) {
        beginDelete();
        return;
    }
    
    Node* curr = head;
    Node* prev = NULL;
    do {
        if (curr->data == data) {
            prev->next = curr->next;
            delete curr;
            cout << "Node with data " << data << " deleted." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    
    cout << "Node with data " << data << " not found." << endl;
}

void search(int data) {
    if(head == NULL) {
        cout << "Circular Linked List is empty." <<endl;
        return;
    }
    
    Node* curr = head;
    int position = 1;
    do {
        if (curr->data == data) {
            cout << "Node with data " << data << " found at position " << position << "." << endl;
            return;
        }
        curr = curr->next;
        position++;
    } while (curr != head);
    
    cout << "Node with data " << data << " not found." << endl;
}

void display() {
    if (head == NULL) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }
    
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr !=head);
    cout << endl;
}

int main() {
    int choice,data;
    
    while (true) {
        cin >> choice;
        
        switch (choice) {
            case 1: 
            cin >> data;
            insert(data);
            break;
            case 2:
            beginDelete();
            break;
            case 3:
            lastDelete();
            break;
            case 4:
            cin >> data;
            randomDelete(data);
            break;
            case 5:
            cin >> data;
            search(data);
            break;
            case 6:
            display();
            break;
            case 7:
            return 0;
            default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}