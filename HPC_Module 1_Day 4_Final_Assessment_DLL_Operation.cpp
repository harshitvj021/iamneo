#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Node*& head, Node*& tail, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << "Node with data " << data << " inserted at the end." << endl;
}

void deleteFirst(Node*& head, Node*& tail) {
    if (head == nullptr) {
        cout << "Doubly Linked List is empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    cout << "Node with data " << temp->data << " deleted from the beginning." << endl;
    delete temp;
}

void deleteEnd(Node*& head, Node*& tail) {
    if (tail == nullptr) {
        cout << "Doubly Linked List is empty." << endl;
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    cout << "Node with data " << temp->data << " deleted from the end." << endl;
    delete temp;
}

void deletePosition(Node*& head, Node*& tail, int position) {
    if (head == nullptr || position <= 0) {
        cout << "Invalid position or Doubly Linked List is empty." << endl;
        return;
    }
    Node* curr = head;
    int count = 1;
    while (count < position && curr != nullptr) {
        curr = curr->next;
        count++;
    }
    if (curr == nullptr) {
        cout << "Invalid position." << endl;
        return;
    }
    if (curr == head) {
        deleteFirst(head, tail);
    } else if (curr == tail) {
        deleteEnd(head, tail);
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        cout << "Node with data " << curr->data << " deleted from position " << position << "." << endl;
        delete curr;
    }
}

void traverse(Node* head) {
    if (head == nullptr) {
        cout << "Doubly Linked List is empty." << endl;
        return;
    }
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int choice, data, position;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> data;
                insertEnd(head, tail, data);
                break;
            case 2:
                deleteFirst(head, tail);
                break;
            case 3:
                deleteEnd(head, tail);
                break;
            case 4:
                cin >> position;
                deletePosition(head, tail, position);
                break;
            case 5:
                traverse(head);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}
