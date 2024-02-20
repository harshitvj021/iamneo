#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

Node* rotateList(Node* head, int k) {
    if (head == nullptr || k == 0) {
        return head;
    }

    // Find the length of the list
    int len = 0;
    Node* current = head;
    while (current != nullptr) {
        len++;
        current = current->next;
    }

    // Calculate the number of rotations needed
    k %= len;
    if (k == 0) {
        return head;
    }

    // Find the new head and tail nodes
    Node* newTail = head;
    for (int i = 0; i < len - k - 1; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;

    // Update the links
    newHead->prev = nullptr;
    newTail->next = nullptr;
    current = newHead;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = head;
    head->prev = current;

    return newHead;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n;

    // Create doubly linked list
    Node* head = nullptr;
    Node* current = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        Node* node = new Node(data);
        if (head == nullptr) {
            head = node;
            current = node;
        } else {
            current->next = node;
            node->prev = current;
            current = node;
        }
    }

    cin >> k;

    // Rotate the list
    head = rotateList(head, k);

    // Print the rotated list
    printList(head);

    return 0;
}
