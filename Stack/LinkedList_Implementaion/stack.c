#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *push(struct Node *top, int element);
int pop(struct Node **top, int *popElement);
int topElement(struct Node *top);


int main(void) {
	int choice, x, popElement = 0, topelement;
	struct Node *top = NULL;

	while(1) {
		printf("Which operation need to be performed?\n1. Push\n2. Pop\n3. Get top element\n4. Quit\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter the element: ");
			scanf("%d", &x);
			top = push(top, x);
			if (top == NULL) {
				printf("error: dynamic allocation failed!\n");
				break;
			}
			printf("Element %d is pushed into the stack\n", x);
			break;

		case 2:
			if(pop(&top, &popElement) == 0) {
				printf("error: stack is empty!\n");
				break;
			}
			printf("Popped element is %d\n", popElement);
			popElement = 0;
			break;

		case 3:
			topelement = topElement(top);
			if (topelement == INT_MIN) break;
			printf("Top element is %d\n", topelement);
			break;

		case 4:
			printf("Quitting.....");
			exit(0);

		}
	}

	return 0;
}

struct Node *push(struct Node *top, int element) {
	
	struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
	if (tmp == NULL) return NULL;
	tmp->data = element;

	if (top == NULL) {
		tmp->next = NULL;
	} else {
		tmp->next = top;
	}

	top = tmp;
	return top;
}

int pop(struct Node **top, int *popElement) {
	struct Node *tmp = *top;

	if (*top == NULL) return 0;
	
	*top = tmp->next;
	*popElement = tmp->data;

	free(tmp);
	tmp = NULL;

	return 1;
}

int topElement(struct Node *top) {
	return (top == NULL) ? INT_MIN : top->data;
}
