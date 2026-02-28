#include <stdio.h>

#define MAXSIZE 100

int queueArray[MAXSIZE];
int front = -1, rear = -1;

void enqueue(int x);
void enqueueCircular(int x);
int dequeue(int *x);
int dequeueCircular(int *x);
int isEmptyQueue(void);
int isFullQueue(void);
int isFullQueueCircular(void);

int main(void) {
    int value;

    printf("---- Linear Queue Test ----\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);

    while (dequeue(&value)) {
        printf("Dequeued (Linear): %d\n", value);
    }

    printf("\n---- Circular Queue Test ----\n");

    enqueueCircular(100);
    enqueueCircular(200);
    enqueueCircular(300);

    dequeueCircular(&value);
    printf("Dequeued (Circular): %d\n", value);

    enqueueCircular(400);  // Tests wrap-around behavior

    while (dequeueCircular(&value)) {
        printf("Dequeued (Circular): %d\n", value);
    }

    return 0;
}

void enqueue(int x) {
    if(isFullQueue()) 
        return;
    else if(isEmptyQueue())
        front = rear = 0;
    else 
        rear++;
        
    queueArray[rear] = x;
}

void enqueueCircular(int x) {
    if(isFullQueueCircular())
        return;
    else if(isEmptyQueue())
        front = rear = 0;
    else
        rear = (rear + 1) % MAXSIZE;
        
    queueArray[rear] = x;
}

int dequeue(int *x) {
    if(isEmptyQueue()) 
        return 0;    
    else if(front == rear) {
        *x = queueArray[front];
        front = rear = - 1;
    } else {
        *x = queueArray[front];
        front++;
    }
    
    return 1;
}

int dequeueCircular(int *x) {
    if(isEmptyQueue()) 
        return 0;    
    else if(front == rear) {
        *x = queueArray[front];
        front = rear = - 1;
    } else {
        *x = queueArray[front];
        front = (front + 1) % MAXSIZE;
    }
    
    return 1;
}

int isEmptyQueue(void) {
    return (front == -1 && rear == -1);
}

int isFullQueue(void) {
    return (rear == (MAXSIZE - 1));
}

int isFullQueueCircular(void) {
    return (((rear + 1) % MAXSIZE) == front); 
}
