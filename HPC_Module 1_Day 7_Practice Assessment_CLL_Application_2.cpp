#include <iostream>
using namespace std;

struct Node {
    int processId;
    Node* next;
};

Node* head = NULL;

void addToEmpty(int processId) {
    if (head != NULL) {
        return;
    }

    Node* newNode = new Node;
    newNode->processId = processId;
    head = newNode;
    head->next = head;
}

void addToEnd(int processId) {
    if (head == NULL) {
        addToEmpty(processId);
        return;
    }

    Node* newNode = new Node;
    newNode->processId = processId;
    newNode->next = head->next;
    head->next = newNode;
    head = newNode;
}

void deleteNode(int processId) {
    if (head == NULL) {
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    do {
        if (curr->processId == processId) {
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    if (curr == head && curr->processId != processId) {
        return;
    }

    if (curr == head && curr->next == head) {
        delete head;
        head = NULL;
        return;
    }

    if (curr == head) {
        prev = head;
        while (prev->next != head) {
            prev = prev->next;
        }
        head = curr->next;
        prev->next = head;
        delete curr;
    } else if (curr->next == head) {
        prev->next = head;
        delete curr;
    } else {
        prev->next = curr->next;
        delete curr;
    }
}

void printList() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->processId << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int choice, processId;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                // Enter the process ID
                cin >> processId;
                addToEnd(processId);
                break;

            case 2:
                // Enter the process ID to delete
                cin >> processId;
                deleteNode(processId);
                cout << "Deleted process ID: " << processId << endl;
                break;

            case 3:
                cout << "Current processes: ";
                printList();
                break;

            case 4:
                // Exiting the program
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
