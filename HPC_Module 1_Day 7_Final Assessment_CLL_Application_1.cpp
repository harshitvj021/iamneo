#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    
    if(head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    
    Node* temp = head;
    while (temp->next != head) {
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node * swapNode(Node* head) {
    if(head== NULL || head->next == head) {
        return head;
    }
    
    Node* prev = NULL;
    Node* curr = head;
    while(curr->next !=head) {
        prev = curr;
        curr = curr->next;
    }
    
    curr->next = head->next;
    prev->next = head;
    head->next = curr;
    head= curr;
    return head;
}

void printList(Node* head) {
    if(head == NULL) {
        return;
    }
    
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp!=head);
}

int main() {
    int N;
    cin >> N;
    Node* head = NULL;
    for(int i =0;i<N;i++) {
        int num;
        cin >> num;
        head = insert(head,num);
    }
    
    cout << "Before Swap: ";
    printList(head);
    
    head = swapNode(head);
    
    cout << endl << "After Swap: ";
    printList(head);
    
    return 0;
}