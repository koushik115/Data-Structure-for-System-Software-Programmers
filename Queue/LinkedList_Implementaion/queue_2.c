#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
	int info;
	struct node *link;
} *front = NULL, *rear = NULL;

void insert(int item);
int del(void);
int peek(void);
int isEmpty(void);
void display(void);

int main(void) {
	int choice, item;
	while(1) {
		int choice, item;
		while(1) {
			printf("1.Insert\n");
			printf("2.Delete\n");
			printf("3.Display the element at the front\n");
			printf("4.Display all elements of the queue\n");
			printf("5.Quit\n");
			printf("Enter your choice : ");
			scanf("%d", &choice);
			switch(choice) {
				case 1: 
					printf("Input the element for adding in the queue : ");
					scanf("%d", &item);
					insert(item);
					break;

				case 2:
					printf("Deleted element is %d\n", del());
					break;

				case 3:
					printf("Element at the front of the queue is %d\n", peek());
					break;

				case 4:
					display();
					break;

				case 5:
					exit(1);

				default:
					printf("Wrong choice!\n");
					break;
			}
		}
	}
}

void insert(int item) {
	struct node *tmp;

	tmp = (struct node *)malloc(sizeof(struct node));
	if(tmp == NULL) {
		printf("error: memory allocation failed\n");
		return;
	}

	tmp->info = item;
	tmp->link = NULL;
	if(front == NULL) front = rear = tmp;
	else rear->link = tmp;

	rear = tmp;
}

int del(void) {
	struct node *tmp;
	int item;

	if(isEmpty()) {
		printf("error: queue underflow!");
		return INT_MIN;
	}

	tmp = front;
	item = front->info;
	front = front->link;
	free(tmp);

	return item;
}

int peek(void) {
	if(isEmpty()) {
		printf("queue underflow\n");
		return INT_MIN;
	}

	return front->info;
}

int isEmpty(void) {
	return (front == NULL);
}

void display(void) {
	struct node *p = NULL;
	if(isEmpty()) {
		printf("error: queue is empry!\n");
		return;
	}

	p = front;
	while(p != NULL) {
		printf(" %d", p->info);
		p = p->link;
	}

	printf("\n\n");
}


