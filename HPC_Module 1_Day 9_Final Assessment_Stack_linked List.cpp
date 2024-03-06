#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

Node* top = nullptr;

void push(int x) {
    Node* temp = new Node();
    if(temp == nullptr) {
        return;
    }
    temp->data=x;
    temp->link=top;
    top=temp;
}

bool isEmpty() {
    return top == nullptr;
}

int peek() {
    if(!isEmpty()) {
        return top->data;
    } 
    else {
        return -1;
    }
}

void pop() {
    if(top == nullptr) {
        cout << "Stack Underflow" << endl;
        return;
    }
    top=top->link;
}

void display() {
    if(top==nullptr) {
        cout << "Stack Underflow" << endl;
        exit(1);
    }
    else {
        Node* temp=top;
        while(temp!=nullptr) {
            cout << temp->data << " ";
            temp=temp->link;
        }
    }
}

int main() {
    int ele;
    while (true) {
        cin >> ele;
        if(ele >=0) {
            push(ele);
        }
        else {
            break;
        }
    }
    if(isEmpty()) {
        cout << "Stack Underflow";
    } else {
        display();
    }
    return 0;
}