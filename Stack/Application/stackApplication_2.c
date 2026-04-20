#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

int top = -1;
char stack[MAX];
char pop(void);
void push(char c);

int main(void) {
	char str[20];
	unsigned int i;

	printf("Enter the string : ");
	scanf("%s", str);

	for(i = 0; i < strlen(str); i++)
		push(str[i]);

	for(i = 0; i < strlen(str); i++)
		str[i] = pop();

	printf("Reversed string is : ");
	printf("%s\n", str);
}

void push(char c) {
	if(top == MAX - 1) {
		printf("error: stack overflow!\n");
		return;
	}

	stack[++top] = c;
}

char pop(void) {
	if(top == -1) {
		printf("error: stack underflow!\n");
		exit(1);
	}

	return stack[top--];
}
