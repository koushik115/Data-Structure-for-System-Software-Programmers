#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
	int info;
	struct node *link;
} *rear = NULL;

void insert(int item);
int del(void);
int peek(void);
void display(void);
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
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	if(tmp == NULL) {
		printf("error: memory allocation failed!\n");
		return;
	}
	
	tmp->info = item;
	if(isEmpty()) {
		rear = tmp;
		tmp->link = rear;
	} else {
		tmp->link = rear->link;
		rear->link = tmp;
		rear = tmp;
	}
}

int del(void) {
	struct node *tmp = NULL;
	int item;

	if(isEmpty()) {
		printf("error: queue is empty!\n");
		return INT_MIN;
	}

	if(rear->link == rear) {
		tmp = rear;
		rear = NULL;
	} else {
		tmp = rear->link;
		rear->link = tmp->link;
	}

	item = tmp->info;
	free(tmp);

	return item;
}

int peek(void) {
	if(isEmpty()) {
		printf("error: queue is empty!\n");
		return INT_MIN;
	}

	return rear->link->info;
}

int isEmpty(void) {
	return(rear == NULL);
}

void display(void) {
	struct node *p = NULL;
	
	if(isEmpty()) {
		printf("error: queue is empty!\n");
		return;
	}

	p = rear->link;
	do {
		printf(" %d", p->info);
		p = p->link;
	} while(p != rear->link);

	printf("\n");
}
