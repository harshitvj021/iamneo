#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    Node* lastNode;

    LinkedList() : head(nullptr), lastNode(nullptr) {}

    void append(int data) {
        if (lastNode == nullptr) {
            head = new Node(data);
            lastNode = head;
        } else {
            lastNode->next = new Node(data);
            lastNode = lastNode->next;
        }
    }

    Node* getNode(int index) {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                return nullptr;
            }
            current = current->next;
        }
        return current;
    }

    Node* getPrevNode(Node* refNode) {
        Node* current = head;
        while (current != nullptr && current->next != refNode) {
            current = current->next;
        }
        return current;
    }

    void insertAtBeginning(Node* newNode) {
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void remove(Node* node) {
        Node* prevNode = getPrevNode(node);
        if (prevNode == nullptr) {
            head = head->next;
        } else {
            prevNode->next = node->next;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

void moveEvenBeforeOdd(LinkedList& list) {
    Node* current = list.head;
    while (current != nullptr) {
        Node* temp = current->next;
        if (current->data % 2 == 0) {
            list.remove(current);
            list.insertAtBeginning(current);
        }
        current = temp;
    }
}

int main() {
    LinkedList linkedList;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        linkedList.append(data);
    }

    moveEvenBeforeOdd(linkedList);

    linkedList.display();
    return 0;
}
