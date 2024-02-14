#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* current_i = head;
    while (current_i != nullptr) {
        Node* current_j = current_i->next;
        while (current_j != nullptr) {
            if (current_i->data > current_j->data) {
                swap(current_i->data, current_j->data);
            }
            current_j = current_j->next;
        }
        current_i = current_i->next;
    }

    cout << "[";

    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << ", ";
        }
        current = current->next;
    }

    cout << "]" << endl;

    Node* lastNode = tail;
    cout << lastNode->data << endl;

    // Free memory
    current = head;
    while (current != nullptr) {
        Node* temp = current->next;
        delete current;
        current = temp;
    }

    return 0;
}
