#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node *next;
} Node;

long int fact(int n) {
	if(n == 0)
		return 1;

	return n * fact(n -1);
}

int summation(int n) {
	if(n == 0)
		return 0;

	return n + summation(n - 1);
}

void display1(int n) {
	if(n == 0)
		return;

	printf("%d ", n);
	display1(n - 1);
}

void display2(int n) {
	if(n == 0) 
		return;

	display2(n - 1);
	printf("%d ", n);
}

int rseries(int n) {
	int sum;
	if(n == 0)
		return 0;
	sum = n + rseries(n - 1);
	printf("%d + ", n);
	return sum;
}

void convert(int num, int base) {
	if(num == 0)
		return;

	int rem = num % base;

	convert(num / base, base);

	if(rem < 10)
		printf("%d", rem);
	else
		printf("%c", rem - 10 + 'A');
}

int sumdigits(int n) {
	if(n == 0)
		return 0;

	return (n % 10) + sumdigits(n / 10);
}

float power(int a, int n) {
	if(n == 0)
		return 1;

	return a * power(a, n - 1);
}

void PFactors(int num) {
	int i = 2;

	if(num == 0 || num == 1)
		return;

	while(num % i != 0)
		i++;

	printf("%d ", i);
	PFactors(num / i);
}

int gcd(int a, int b) {
	if(b == 0)
		return a;

	return gcd(b, a % b);
}

int fib(int n) {
	if(n == 0 || n == 1)
		return 1;

	return fib(n - 1) + fib(n - 2);
}

int divisibleBy9(long int n) {
	if(n == 9)
		return 1;
	else if(n < 9)
		return 0;

	int sumDigits = 0;
	while(n > 0) {
		sumDigits = sumDigits + n % 10;
		n = n / 10;
	}

	return divisibleBy9(sumDigits);
}

int divisibleBy11(long int n) {
	int s1 = 0, s2 = 0, diff = 0;
	if(n == 0)
		return 1;
	else if(n < 10)
		return 0;

	while(n > 0) {
		s1 += n % 10;
		n /= 10;
		s2 += n % 10;
		n /= 10;
	}

	diff = (s1 > s2) ? (s1 - s2) : (s2 - s1);
	return divisibleBy11(diff);
}

void towerOfHanoi(int ndisk, char source, char temp, char dest) {
	if(ndisk == 1) {
		printf("Move Disk %d from %c ---> %c\n", ndisk, source, dest);
		return;
	}

	towerOfHanoi(ndisk - 1, source, dest, temp);
	printf("Move Disk %d from %c --> %c\n", ndisk, source, dest);
	towerOfHanoi(ndisk - 1, temp, source, dest);
}

int length(Node *ptr) {
	if(ptr == NULL)
		return 0;

	return 1 + length(pre->next);
}

int sum(Node *ptr) {
	if(ptr == NULL)
		return 0;

	return ptr->data + sum(ptr->next);
}

void display(Node *ptr) {
	if(ptr == NULL)
		return;

	printf("%d ", ptr->data);
	display(ptr->next);
}

void Rdisplay(Node *ptr) {
	if(ptr == NULL)
		return;

	Rdisplay(ptr->next);
	printf(" %d", ptr->data);
}

int search(Node *ptr, int item) {
	if(ptr == NULL)
		return 0;
	
	if(ptr->data == item)
		return 1;

	return search(ptr->next, item);
}

Node *insertLast(Node *ptr, int item) {
	Node *tmp = NULL;
	if(ptr == NULL) {
		tmp = (Node *)malloc(sizeof(Node));
		tmp->data = item;
		tmp->next = NULL;
		return tmp;
	}

	ptr->next = insertLast(ptr->next, item);
	return ptr;
}

Node *delLast(Node *ptr) {
	if(ptr->next == NULL) {
		free(ptr);
		return NULL;
	}

	ptr->next = delLast(ptr->next);
	return ptr;
}

Node *reverse(Node *ptr) {
	Node *tmp;

	if(ptr->next == NULL)
		return ptr;

	tmp = reverse(ptr->next);
	tmp->next = ptr;
	ptr->next = NULL;

	return tmp;
}

int main(void) {
/*
	printf("%ld ", fact(3));
	printf("\n");

	printf("%d", summation(4));
	printf("\n");

	display1(5);
	printf("\n");

	display2(5);
	printf("\n");

	printf("\b\b = %d\n", rseries(5));

	printf("%d\n", sumdigits(45329));

	convert(15, 16);
	printf("\n");

	printf("%0.f\n", power(2, 11));

	PFactors(84);
	printf("\n");

	printf("%d\n", fib(5));

	printf("%d\n", divisibleBy9(1469358));

	printf("%d\n", divisibleBy11(62938194));
*/
	towerOfHanoi(3, 'A', 'B', 'C');

	return 0;
}


