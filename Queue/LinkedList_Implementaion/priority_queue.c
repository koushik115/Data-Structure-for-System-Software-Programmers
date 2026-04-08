#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
	int priority;
	int info;
	struct node *link;
} *front  = NULL;

void insert(int item, int item_priority);
int del(void);
void display(void);
int isEmpty(void);

int main(void) {
	int choice, item, item_priority;
	while(1) {
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter yout choice : \n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Input the item to be added in the queue : ");
				scanf("%d", &item);
				printf("Enter its priority : ");
				scanf("%d", &item_priority);
				insert(item, item_priority);
				break;

			case 2:
				printf("Deleted item is %d\n", del());
				break;

			case 3:
				display();
				break;

			case 4:
				exit(1);

			default:
				printf("Wrong choice!\n");
		}
	}
}

void insert(int item, int item_priority) {
	struct node *tmp, *p;
	tmp = (struct node *)malloc(sizeof(struct node));
	if(tmp == NULL) {
		printf("error: memory allocation failed!\n");
		return;
	}

	tmp->priority = item_priority;
	tmp->info = item;
	if(isEmpty() || item_priority < front->priority) {
		tmp->link = front;
		front = tmp;
	} else {
		p = front;
		while(p->link != NULL && p->link->priority <= item_priority)
			p = p->link;
		tmp->link = p->link;
		p->link = tmp;
	}
}

int del(void) {
	struct node *tmp;
	int item;
	if(isEmpty()) {
		printf("error: queue underflow!\n");
		return INT_MIN;
	} else {
		tmp = front;
		item = tmp->info;
		front = front->link;
		free(tmp);
	}

	return item;
}

int isEmpty(void) {
	return (front == NULL);
}

void display(void) {
	struct node *ptr;
	ptr = front;

	if(isEmpty()) {
		printf("error: queue is empty!\n");
		return;
	}

	printf("Queue is :\n");
	while(ptr != NULL) {
		printf(" %d", ptr->info);
		ptr = ptr->link;
	}
}
