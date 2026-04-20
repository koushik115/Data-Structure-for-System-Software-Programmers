#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

int top = -1;
char stack[MAX];
char pop(void);
void push(char c);

int check(char expr[]);
int match(char a, char b);

int main(void) {
	/*
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
	*/

	char expr[MAX];
	int valid;
	printf("Enter an algebriac expression : ");
	scanf("%s", expr);
	valid = check(expr);
	if(valid) 
		printf("status: valid expression!\n");
	else
		printf("status: invalid expression!\n");

	return 0;
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

int check(char expr[]) {
	int i;
	char tmp;

	for(i = 0; i < strlen(expr); i++) {
		if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
			push(expr[i]);

		if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
			if(top == -1) {
				printf("error: right paranthesis are more than left\n");
				return 0;
			} else {
				tmp = pop();
				if(!match(tmp, expr[i])) {
					printf("error: mismatched parenthesis\n");
					return 0;
				}
			}
		
		}
	}

	if(top == -1) {
		printf("status: balanced parenthesis\n");
		return 1;
	} else {
		printf("error: left parenthesis is more than right parenthesis!\n");
		return 0;
	}
}

int match(char a, char b) {
	if(a == '(' && b == ')')
		return 1;
	else if(a == '[' && b == ']')
		return 1;
	else if(a == '{' && b == '}')
		return 1;
}	
