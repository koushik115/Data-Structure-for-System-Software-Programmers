#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_SIZE	101

int stack[MAX_SIZE];
int stackp = -1;

void push(int stackElement);
int pop(void);
int top(void);
int isEmpty(void);
int isFull(void);

int main(void) {
	int choice, x, popElement, topElement;

	while(1) {
		printf("Which operation need to be performed?\n1. Push\n2. Pop\n3. Get top element\n4. Quit\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter the element: ");
			scanf("%d", &x);
			push(x);
			printf("Element %d is pushed into the stack\n", x);
			break;

		case 2:
			popElement = pop();
			if (popElement == INT_MIN) break;
			printf("Popped element is %d\n", popElement);
			break;

		case 3:
			topElement = top();
			if (topElement == INT_MIN) break;
			printf("Top element is %d\n", topElement);
			break;

		case 4:
			printf("Quitting.....");
			exit(0);

		}
	}

	return 0;
}

void push(int x) {
	if (isFull()) {
		printf("error: stack overflow!\n");
		return;
	}

	stack[++stackp] = x;
}

int pop(void) {
	if (isEmpty()) {
		printf("error: stack underflow!\n");
		return INT_MIN;
	}

	return stack[stackp--];
}

int top(void) {
	if (isEmpty()) {
		printf("error: stack underflow!\n");
		return INT_MIN;
	}

	return stack[stackp];
}

int isEmpty(void) {
	return (stackp == -1);
}


int isFull(void) {
	return (stackp == MAX_SIZE - 1);
}
