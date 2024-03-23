#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* deleteKthNode(Node* head, int k) {
    if( head == nullptr) return nullptr;
    if( k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node* prev = nullptr;
    Node* curr = head;
    int count = 1;
    
    while (curr != nullptr && count < k) {
        prev = curr;
        curr = curr->next;
        count++;
    }
    
    if(curr == nullptr) return head;
    
    prev->next = curr->next;
    delete curr;
    
    return head;
}

void printLinkedList(Node* head) {
    while( head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n,k;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    cin >> k;
    
    head = deleteKthNode(head, k);
    
    printLinkedList(head);
    
    return 0;
}