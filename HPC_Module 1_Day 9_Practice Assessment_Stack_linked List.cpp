#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node*link;
    Node(int data) {
        this->data=data;
        this->link = NULL;
    }
};

class Stack {
    Node* top;
    int count =0;
    public:
    Stack() {
        top=NULL;
    }
    
    void push(int data,int n){
        Node* temp=new Node(data);
        if(count ==n) {
            cout << "Stack OverFlow" << endl;
            return;
        }
        count++;
        temp->link =top;
        top= temp;
    }
    int pop() {
        if(top==NULL) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int data = top->data;
        Node* temp =top;
        top =top->link;
        delete temp;
        return data;
    }
    
    void display() {
        if(top==NULL) {
            cout << "Stack UnderFlow" <<endl;
            return;
        }
        Node* temp=top;
        while(temp!=NULL){
            cout <<temp->data<< " ";
            temp=temp->link;
        }
        cout <<endl;
        int ans=pop();
        cout << ans <<endl;
    }
};

int main() {
    Stack s;
    int num;
    cin >> num;
   // while(num--1) {
    // int ans;
    // cin>>ans;
    // }
    if(num==0) {
        cout<< "Stack Underflow" << endl;
    } else {
        for (int i=0;i<num;i++) {
            int ans;
            cin >>ans;
            s.push(ans,num);
        }
        s.display();
        s.display();
    }
    return 0;
}