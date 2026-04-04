#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_QUEUE_SIZE	10

int cqueue_arr[MAX_QUEUE_SIZE];	
int front = -1, rear = -1;

void display(void);
void insert(int item);
int del(void);
int peek(void);
int isEmpty(void);
int isFull(void);

int main(void) {
	int choice, item;
	while(1) {
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display Element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Input the element for adding in queue : ");
				scanf("%d", &item);
				insert(item);
				break;

			case 2:
				item = del();
				printf("Deleted element is %d\n", item);
				break;

			case 3:
				printf("Element at the front is %d\n", peek());
				break;

			case 4:
				display();
				break;

			case 5:
				exit(1);

			default:
				printf("Wrong choice\n");
		}
	}
}


void insert(int item) {
	if(isFull()) {
		printf("error: queue overflow!\n");
		return;
	}

	if(front == -1) front = 0;
	else if(rear == MAX_QUEUE_SIZE - 1) rear = 0;
	cqueue_arr[++rear] = item;
}

int del(void) {
	if(isEmpty()) {
		printf("error: queue underflow!\n");
		return INT_MIN;
	}

	if(front == MAX_QUEUE_SIZE - 1) front = 0;
	else if(front == rear) front = rear = -1;
	
	return cqueue_arr[front++];
}

int isEmpty(void) {
	return (front == -1);
}

int isFull(void) {
	return ((front == rear + 1) || (front == 0 && rear == MAX_QUEUE_SIZE - 1));
}

int peek(void) {
	if(isEmpty()) {
		printf("error: queue underflow!\n");
		return INT_MIN;
	}

	return cqueue_arr[front];
}

void display(void) {
	int i;
	if(isEmpty()) {
		printf("error: queue is empty!\n");
		return;
	}

	i = front;
	if(front <= rear) {
		while(i <= rear)
			printf( "%d", cqueue_arr[i++]);
	} else {
		while(i < MAX_QUEUE_SIZE)
			printf(" %d", cqueue_arr[i++]);

		i = 0;
		while(i <= rear)
			printf(" %d", cqueue_arr[i++]);
	}

	printf("\n\n");
}

