#include <stdio.h>
#include <stdlib.h>

struct node {
	float coefficient;
	int exponent;
	struct node *link;
};

struct node *create(struct node *start);
struct node *insert_s(struct node *start, float coef, int expo);
struct node *insert(struct node *start, float coef, int expo);
void display(struct node *start);
void poly_add(struct node *start1, struct node *start2);
void poly_mul(struct node *start1, struct node *start2);

int main(void) {
	struct node *start1 = NULL, *start2 = NULL;
	printf("Enter polynomial 1 : \n"); start1 = create(start1);
	printf("Enter polynomial 2 : \n"); start2 = create(start2);
	printf("Polynomial 1 is : "); display(start1);
	printf("Polynomial 2 is : "); display(start2);
	poly_add(start1, start2);
	poly_mul(start1, start2);

	return 0;
}

struct node *create(struct node *start) {
	int i, n, expo;
	float coef;

	printf("Enter the number of terms: ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		printf("Enter the coefficient for term %d : ", i);
		scanf("%f", &coef);
		printf("Enter the exponent for term %d : ", i);
		scanf("%d", &expo);
		start = insert_s(start, coef, expo);
	}

	return start;
}

struct node *insert_s(struct node *start, float coef, int expo) {
	struct node *p, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->coefficient = coef;
	tmp->exponent = expo;

	if(start == NULL || expo > start->exponent) {
		tmp->link = start;
		start = tmp;
		return start;
	} 

	p = start;
	while(p->link != NULL && expo <= p->link->exponent)
		p = p->link;
	
	tmp->link = p->link;
	p->link = tmp;

	return start;
}

struct node *insert(struct node *start, float coef, int expo) {
	struct node *p, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->coefficient = coef;
	tmp->exponent = expo;

	if(start == NULL) {
		tmp->link = start;
		start = tmp;
		return start;
	}

	p = start;
	while(p->link != NULL)
		p = p->link;

	tmp->link = p->link;
	p->link = tmp;

	return start;
}

void display(struct node *start) {
	struct node *p;

	if(start == NULL) {
		printf("error: list is empty\n");
		return;
	}

	p = start;
	while(p != NULL) {
		printf("(%.1fx^%d)", p->coefficient, p->exponent);
		p = p->link;
		if(p != NULL) printf(" + ");
		else printf("\n");
	}

	printf("\n\n");
}

void poly_add(struct node *p1, struct node *p2) {
	struct node *start3 = NULL;

	while(p1 != NULL && p2 != NULL) {
		if(p1->exponent > p2->exponent) {
			start3 = insert(start3, p1->coefficient, p1->exponent);
			p1 = p1->link;
		} else if(p2->exponent > p1->exponent) {
			start3 = insert(start3, p2->coefficient, p2->exponent);
			p2 = p2->link;
		} else {
			start3 = insert(start3, (p2->coefficient + p1->coefficient), p1->exponent);
			p1 = p1->link; p2 = p2->link;
		}
	}

	while(p1 != NULL) {
		start3 = insert(start3, p1->coefficient, p1->exponent);
		p1 = p1->link;
	}

	while(p2 != NULL) {
		start3 = insert(start3, p2->coefficient, p2->exponent);
		p2 = p2->link;
	}
	printf("Added Polynomial is : ");
	display(start3);
}

void poly_mul(struct node *p1, struct node *p2) {
	struct node *start3 = NULL;
	struct node *p2_beg = p2;

	if(p1 == NULL || p2 == NULL) {
		printf("error: multiplied polynomial is zero polynomial\n");
		return;
	}

	while(p1 != NULL) {
		p2 = p2_beg;
		while(p2 != NULL) {
			start3 = insert(start3, p1->coefficient * p2->coefficient, p1->exponent + p2->exponent);
			p2 = p2->link;
		}

		p1 = p1->link;
	}
	printf("Multiplied polynomial is : ");
	display(start3);
}
