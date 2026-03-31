#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_STACK_SIZE	100

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int item);
int pop(void);
int isEmpty(void);
int isFull(void);
int peek(void);
void display(void);

int main(void) {
	int choice, item;
	while(1) {
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display top element\n");
		printf("4.Display all stack elements\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter the item to be pushed : ");
				scanf("%d", &item);
				push(item);
				break;

			case 2:
				item = pop();
				printf("Popped element is : %d\n", item);
				break;

			case 3: 
				printf("Item at the top is : %d\n", peek());
				break;

			case 4:
				display();
				break;

			case 5:
				exit(1);
			
			default:
				printf("Wrong choice!\n");
		}
	}
}

void push(int item) {
	if(isFull()) {
		printf("error: stack overflow!\n");
		return;
	}

	stack[++top] = item;
}

int pop(void) {
	int item;
	if(isEmpty()) {
		printf("error: stack underflow!");
		return INT_MIN;
	}

	return stack[top--];
}

int peek(void) {
	if(isEmpty()) {
		printf("error: stack underflow!\n");
		return INT_MIN;
	}

	return stack[top];
}

int isEmpty(void) {
	return (top == -1);
}

int isFull(void) {
	return (top == MAX_STACK_SIZE - 1);
}

void display(void) {
	int i;
	if(isEmpty()) {
		printf("error: stack is empty!\n");
		return;
	}

	printf("Stack elements :\n\n");
	for(i = top; i >= 0; i--) 
		printf(" %d\n", stack[i]);
	printf("\n");
}



