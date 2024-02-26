#include <iostream>
#include <string>

using namespace std;

struct Node {
    string appName;
    Node* next;
    Node(const string& name) : appName(name), next(nullptr) {}
};

class CircularLinkedList {
    private:
    Node* head;
    
    public:
    CircularLinkedList() : head(nullptr) {}
    
    ~CircularLinkedList() {
        if(head == nullptr) return;
        Node* current = head->next;
        while(current !=head) {
            Node* temp=current;
            current = current->next;
            delete temp;
        }
        delete head;
    }
    
    void insertApplication(const string& appName) {
        Node* newNode = new Node(appName);
        if(head ==nullptr) {
            head =newNode;
            head->next = head;
        } else {
            Node* temp =head;
            while (temp->next !=head) {
                temp=temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    
    void displayApplication() const {
        if(head ==nullptr) {
            cout << "Circular Linked List - Running Applications\n\n";
            cout << "No applications to iterate.\n";
            return;
        }
        cout << "Circular Linked List - Running Applications\n\n";
        cout << "Running Applications:\n";
        Node* temp=head;
        do {
            cout << temp->appName << endl;
            temp= temp->next;
        } while (temp!=head);
    }
};

int main() {
    CircularLinkedList runningApps;
    string appName;
    while (true) {
        getline(cin,appName);
        if(appName == "exit") break;
        runningApps.insertApplication(appName);
    }
    runningApps.displayApplication();
    return 0;
}