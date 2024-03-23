//Problem Statement

//Write a program to interleave the first half of the queue with the second half.

#include <iostream>
using namespace std;

struct Queue {
    int front,rear;
    unsigned capacity;
    int* array;
};

Queue* createQueue(unsigned capacity) {
    Queue* queue = new Queue;
    queue->capacity =capacity;
    queue->front =queue->rear=-1;
    queue->array =new int[queue->capacity];
    return queue;
}

bool isFull(Queue* queue) {
    return (queue->rear+1) % queue->capacity == queue->front;
}

bool isEmpty(Queue* queue) {
    return queue->front ==-1;
}

void enqueue(Queue* queue,int item) {
    if(isFull(queue))
    return;
    
    if(isEmpty(queue))
    queue->front =0;
    
    queue->rear =(queue->rear+1) % queue->capacity;
    queue->array[queue->rear] =item;
}

int dequeue(Queue* queue) {
    if(isEmpty(queue))
    return -1;
    
    int item =queue->array[queue->front];
    
    if(queue->front ==queue->rear)
    queue->front = queue->rear = -1;
    else 
    queue->front =(queue->front+ 1) % queue->capacity;
    
    return item;
}

void interleave(Queue* q) {
    Queue q1,q2;
    q1.capacity = q2.capacity = q->capacity/2;
    q1.front = q1.rear = q2.front = q2.rear = -1;
    q1.array = new int[q1.capacity];
    q2.array = new int[q2.capacity];
    
    int n= q->rear - q->front +1;
    int i;
    
    for(i=0;i<n/2;i++) {
        enqueue(&q1, dequeue(q));
    }
    
    for(;i<n;i++) {
        enqueue(&q2,dequeue(q));
    }
    
    while(!isEmpty(&q1) && !isEmpty(&q2)) {
        enqueue(q, dequeue(&q1));
        enqueue(q, dequeue(&q2));
    }
    
    while (!isEmpty(&q1)) {
        enqueue(q, dequeue(&q1));
    }
    
    while(!isEmpty(&q2)) {
        enqueue(q, dequeue(&q2));
    }
}

int main() {
    Queue* q;
    int n1;
    cin >> n1;
    
    q=createQueue(n1);
    
    for(int i =1 ; i<=n1 ; i++) 
    enqueue(q,i);
    
    interleave(q);
    
    while(!isEmpty(q)) {
        cout << dequeue(q) << " ";
    }
    cout << endl;
    
    delete[] q->array;
    delete q;
    
    return 0;
}

