// You are using GCC
#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
    public:
    Node* head;
    Node* tail;
    
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    void addNode(int data) {
        Node* newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void display() {
        Node* current = head;
        while (current!= nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
    
    static DoublyLinkedList mergeLists(DoublyLinkedList list1, DoublyLinkedList list2) {
        DoublyLinkedList mergedList;
        Node* current1 = list1.head;
        Node* current2 = list2.head;
        
        while (current1 !=nullptr && current2 != nullptr) {
            if (current1->data <current2->data) {
            mergedList.addNode(current1->data);
            current1 = current1->next;
        } else {
            mergedList.addNode(current2->data);
            current2 = current2->next;
        }
    }
    
    while (current1 != nullptr) {
        mergedList.addNode(current1->data);
        current1 = current1->next;
    }
    
    while (current2 != nullptr) {
        mergedList.addNode(current2->data);
        current2 = current2->next;
    }
    
    return mergedList;
    }
};

int main() {
    int N,M;
    cin >> N;
    DoublyLinkedList list1;
    for(int i=0;i<N; ++i) {
        int data;
        cin >> data;
        list1.addNode(data);
    }
    
    cin >> M;
    DoublyLinkedList list2;
    for (int i =0;i<M;++i) {
        int data;
        cin >> data;
        list2.addNode(data);
    }
    
    DoublyLinkedList mergedList = DoublyLinkedList::mergeLists(list1, list2);
    mergedList.display();
    
    return 0;
}