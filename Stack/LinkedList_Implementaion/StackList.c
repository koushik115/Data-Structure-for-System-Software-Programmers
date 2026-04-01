#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *link;
}*top = NULL;

void push(int item);
int pop(void);
int peek(void);
int isEmpty(void);
void display(void);

int main(void) {
	int choice, item;
	while(1) {
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display item at the top\n");
		printf("4.Display all items of the stack\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter the element to be pushed : ");
				scanf("%d", &item);
				push(item);
				break;

			case 2:
				item = pop();
				printf("Popped item is : %d\n", item);
				break;

			case 3:
				printf("Item at the top is %d\n", peek());
				break;

			case 4:
				display();
				break;

			case 5: 
				exit(1);

			default:
				printf("Wrong choice\n");
				break;
		}
	}
}

void push(int item) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	if(tmp == NULL) {
		printf("error: stack overflow!....\nmemory allocation failed!\n");
		return;
	}

	tmp->info = item;
	tmp->link = top;
	top = tmp;
}

int pop(void) {
	struct node *tmp;
	int item;

	if(isEmpty()) {
		printf("error: stack underflow\n");
		exit(1);
	}

	tmp = top;
	item = tmp->info;
	top = top->link;
	free(tmp);

	return item;
}

int peek(void) {
	if(isEmpty()) {
		printf("error: stack underflow\n");
		exit(1);
	}

	return top->info;
}

int isEmpty(void) {
	return (top == NULL);
}

void display(void) {
	struct node *p;
	
	if(isEmpty()) {
		printf("Stack is empty\n");
		return;
	}

	p = top;
	printf("Stack elements : \n");
	while(p != NULL) {
		printf( "%d\n", p->info);
		p = p->link;
	}

	printf("\n");
}
