//Problem Statement
//Given an integer K and a queue of integers, reverse the order of the first K elements of the queue, leaving the other elements in the same relative order. 

#include <iostream>

using namespace std;

int *queue_array = new int[50];

int rear =-1;
int front =-1;

void enqueue(int n) {
    int add_item;
    for(int j =0;j<n;j++) {
        if(front==-1)
        front =0;
        cin >> add_item;
        rear=rear+1;
        queue_array[rear] =add_item;
    }
}

void reverse(int k) {
    int t=0, kk=k-1;
    for(int i=0;i<k/2;i++) {
        t=queue_array[i];
        queue_array[i] = queue_array[kk];
        queue_array[kk] =t;
        kk--;
    }
}

void display() {
    if(front ==-1)
    cout << "Queue is empty." << endl;
    else {
        cout << "Reversed queue:";
        for(int i=front;i<=rear;i++)
        cout << queue_array[i] << " ";
        cout << endl;
    }
}

int main() {
    int n,k;
    cin >> n>> k;
    enqueue(n);
    reverse(k);
    display();
    
    delete[] queue_array;
    
    return 0;
}
