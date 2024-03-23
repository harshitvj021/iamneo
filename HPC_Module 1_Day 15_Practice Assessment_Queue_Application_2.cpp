//Problem Statement

//Write a program that sorts the elements in a queue in non-decreasing order. The program should read integers from the user and store them in a queue using an array. Once all the elements are added, the program should sort the queue in a non-decreasing order and display the sorted elements.

#include <iostream>
#include <vector>
#include <algorithm>

void enqueue(int n);
void display();
void sort(int n);
std::vector<int> queue_array(20);
int rear =-1;int front =-1;

int main() {
    int n;
    std::cin>>n;
    enqueue(n);
    sort(n);
    display();
    return 0;
}

void enqueue(int n)
{
    int add_item,j;
    for(j=0;j<n;j++) {
        if(front==-1)
        front=0;
        rear=(rear+1) % 20;
        std::cin >> add_item;
        queue_array[rear] =add_item;
    }
}

void sort(int n) {
    std::sort(queue_array.begin() + front,queue_array.begin() +rear +1);
}

void display() {
    if(front ==-1)
    std::cout << "Queue is empty." << std::endl;
    else {
        for (int i=front;i!=rear; i= (i+1) % 20)
        std::cout<<queue_array[i] << " ";
        std::cout << queue_array[rear] << std::endl;
    }
}