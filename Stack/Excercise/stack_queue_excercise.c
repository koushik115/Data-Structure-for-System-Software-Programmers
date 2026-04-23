#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE	100
#define QUEUE_MAX_SIZE	100

typedef struct {
	int stack[STACK_MAX_SIZE];
	int size;
} Stack;

typedef struct {
	int queue[QUEUE_MAX_SIZE];
	int top;
	int rear;
} Queue;

// Initialize stack
void initStack(Stack *s) {
	s->size = 0;
}

// Check Empty
int isEmpty(Stack *s) {
	return s->size == 0;
}

// Check Full
int isFull(Stack *s) {
	return s->size == STACK_MAX_SIZE;
}

// Push (top at index 0)
int push(Stack *s, int data) {
	if(isFull(s)) return -1;

	for(int i = s->size; i > 0; i--)
		s->stack[i] = s->stack[i - 1];

	s->stack[0] = data;
	s->size++;

	return 0;
}

// Pop (remove from index 0)
int pop(Stack *s, int *popped) {
	if(isEmpty(s)) return -1;

	*popped = s->stack[0];

	for(int i = 0; i < s->size; i++)
		s->stack[i] = s->stack[i + 1];

	s->size--;

	return 0;
}

// Peek
int peek(Stack *s, int *topVal) {
	if(isEmpty(s)) return -1;

	*topVal = s->stack[0];

	return 0;
}

// Print Stack
void printStack(Stack *s) {
	printf("Stack (top->bottom): ");
	for(int i = 0; i < s->size; i++)
		printf(" %d", s->stack[i]);
	printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printStack(&s);  // 30 20 10

    int x;
    pop(&s, &x);
    printf("Popped: %d\n", x);

    printStack(&s);  // 20 10

    peek(&s, &x);
    printf("Top: %d\n", x);

    return 0;
}	


