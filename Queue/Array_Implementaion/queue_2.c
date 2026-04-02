#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUE_MAX_SIZE	100

int queue_arr[QUEUE_MAX_SIZE];
int front = -1;
int rear = -1;

void insert(int item);
int del(void);
int peek(void);
void display(void);
int isFull(void);
int isEmpty(void);

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
	queue_arr[++rear] = item;
}

int del(void) {
	if(isEmpty()) {
		printf("error: queue underflow!\n");
		return INT_MIN;
	}

	return queue_arr[front++];
}

int peek(void) {
	if(isEmpty()) {
		printf("error: queue underflow!\n");
		return INT_MIN;
	}

	return queue_arr[front];
}

int isEmpty(void) {
	return (front == -1 || front == rear + 1);
}

int isFull(void) {
	return (rear == QUEUE_MAX_SIZE - 1);
}

void display(void) {
	if(isEmpty()) {
		printf("error: queue is empty!\n");
		return;
	}

	printf("Queue is : \n\n");
	for(int i = front; i <= rear; i++)
		printf("%d ", queue_arr[i]);
	printf("\n\n");
}
