#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *link;
};

struct node *create_list(struct node *start);
struct node *insert_s(struct node *start, int data);
struct node *insert(struct node *start, int data);
void display(struct node *start);
struct node *merge(struct node *p1, struct node *p2);

int main(void) {
	struct node *start1 = NULL, *start2 = NULL, *start3 = NULL;
	start1 = create_list(start1);
	start2 = create_list(start2);
	display(start1);
	display(start2);
	start3 = merge(start1, start2);
	display(start3);

	return 0;
}

struct node *create_list(struct node *start) {
	int i, n, data;

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	start = NULL;
	for(i = 1; i <= n; i++) {
		printf("Enter the element to be inserted : ");
		scanf("%d", &data);
		start = insert_s(start, data);
	}

	return start;
}

struct node *insert_s(struct node *start, int data) {
	struct node *p, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;

	if(start == NULL || data < start->info) {
		tmp->link = start;
		start = tmp;
		return start;
	}

	p = start;
	while(p->link != NULL && data > p->link->info)
		p = p->link;
	tmp->link = p->link;
	p->link = tmp;

	return start;
}

struct node *insert(struct node *start, int data) {
	struct node *p, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	if(tmp == NULL) return NULL;
	tmp->info = data;

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
		printf("error: list is empty!\n");
		return;
	}

	p = start;
	while(p != NULL) {
		printf("%d ", p->info);
		p = p->link;
	}
	printf("\n");
}

struct node *merge(struct node *p1, struct node *p2) {
	struct node *start3;
	start3 = NULL;
	while(p1 != NULL && p2 != NULL) {
		if(p1->info < p2->info) {
			start3 = insert(start3, p1->info);
			p1 = p1->link;
		} else if(p2->info < p1->info) {
			start3 = insert(start3, p2->info);
			p2 = p2->link;
		} else {
			start3 = insert(start3, p1->info);
			p1 = p1->link;
			p2 = p2->link;
		}
	}

	while(p1 != NULL) {
		start3 = insert(start3, p1->info);
		p1 = p1->link;
	}

	while(p2 != NULL) {
		start3 = insert(start3, p2->info);
		p2 = p2->link;
	}

	return start3;
}
