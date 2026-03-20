/* Program of doubly linked list based on Data Structures through C in Depth */
#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *prev;
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addtoempty(struct node *start, int data);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);

int main()
{
    int choice, data, item;
    struct node *start = NULL;

    while (1)
    {
        printf("\n");
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Add to empty list\n");
        printf("4. Add at beginning\n");
        printf("5. Add at end\n");
        printf("6. Add after\n");
        printf("7. Add before\n");
        printf("8. Delete\n");
        printf("9. Reverse\n");
        printf("10. Exit\n");

        printf("Enter your choice : ");
        (void)scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                start = create_list(start);
                break;

            case 2:
                display(start);
                break;

            case 3:
                printf("Enter the element to be inserted : ");
                (void)scanf("%d", &data);
                start = addtoempty(start, data);
                break;

            case 4:
                printf("Enter the element to be inserted : ");
                (void)scanf("%d", &data);
                start = addatbeg(start, data);
                break;

            case 5:
                printf("Enter the element to be inserted : ");
                (void)scanf("%d", &data);
                start = addatend(start, data);
                break;

            case 6:
                printf("Enter the element to be inserted : ");
                (void)scanf("%d", &data);
                printf("Enter the element after which to insert : ");
                (void)scanf("%d", &item);
                start = addafter(start, data, item);
                break;

            case 7:
                printf("Enter the element to be inserted : ");
                (void)scanf("%d", &data);
                printf("Enter the element before which to insert : ");
                (void)scanf("%d", &item);
                start = addbefore(start, data, item);
                break;

            case 8:
                printf("Enter the element to be deleted : ");
                (void)scanf("%d", &data);
                start = del(start, data);
                break;

            case 9:
                start = reverse(start);
                break;

            case 10:
                exit(1);

            default:
                printf("Wrong choice\n");
        }
    }
}

struct node *create_list(struct node *start) {
	int i, n, data;
	printf("Enter the number of nodes: ");
	(void)scanf("%d", &n);
	start = NULL;

	if(n == 0) return start;

	printf("Enter the element to be inserted: ");
	(void)scanf("%d", &data);

	start = addtoempty(start, data);
	for(i = 2; i <= n; i++) {
		printf("Enter the element to be inserted: ");
		(void)scanf("%d", &data);
		start = addatend(start, data);
	}

	return start;
}

void display(struct node *start) {
	struct node *p = start;
	if(p == NULL) {
		printf("error: list is empty!\n");
		return;
	}

	while(p != NULL) {
		printf("%d\t", p->info);
		p = p->next;
	}

	printf("\n\n");
}


struct node *addtoempty(struct node *start, int data) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	if(tmp == NULL) return NULL;

	tmp->prev = NULL;
	tmp->info = data;
	tmp->next = NULL;
	start = tmp;

	return start;
}

struct node *addatbeg(struct node *start, int data) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	if(tmp == NULL) return NULL;

	tmp->prev = NULL;
	tmp->info = data;
	tmp->next = start;
	start->prev = tmp;
	start = tmp;

	return start;
}

struct node *addatend(struct node *start, int data) {
	struct node *p, *tmp;
	if(start == NULL) return NULL;
	
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->prev = NULL;
	tmp->info = data;
	tmp->next = NULL;

	p = start;
	while(p->next != NULL) p = p->next;
	p->next = tmp;
	tmp->prev = p;

	return start;
}

struct node *addafter(struct node *start, int data, int item) {
	struct node *tmp, *p;
	if(start == NULL) return NULL;

	p = start;
	while(p != NULL) {
		if(p->info == item) {
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp->info = data;
			tmp->next = p->next;
			if(p->next != NULL)
				p->next->prev = tmp;
			p->next = tmp;
			tmp->prev = p;

			return start;
		}

		p = p->next;
	}

	printf("error: %d not found in the list\n", item);
	return start;

}

struct node *addbefore(struct node *start, int data, int item) {
	struct node *p, *tmp;
	if(start == NULL) return NULL;

	if(start->info == item) {
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->prev = NULL;
		tmp->info = data;
		tmp->next = start;
		start->prev = tmp;
		start = tmp;

		return start;
	}

	p = start;
	while(p->next != NULL) {
		if(p->next->info == item) {
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp->info = data;
			tmp->next = p->next;
			p->next->prev= tmp;
			p->next = tmp;
			tmp->prev = p;

			return start;
		}

		p = p->next;
	}

	printf("error: %d not found in the list\n", item);
	return start;
}


struct node *del(struct node *start, int data) {
	struct node *p, *tmp;

	if(start == NULL) {
		printf("error: List is empty!\n");
		return NULL;
	}

	if(start->info == data) {
		tmp = start;
		start = start->next;
		if(start != NULL)
			start->prev = NULL;
		free(tmp);

		return start;
	}

	p = start;
	while(p->next != NULL) {
		if(p->next->info == data) {
			tmp = p->next;
			p->next = tmp->next;
			if(tmp->next != NULL)
				tmp->next->prev = p;
			free(tmp);

			return start;
		}

		p = p->next;
	}

	printf("error: %d not found in the list\n", data);
	return start;
}


struct node *reverse(struct node *start) {
	struct node *p1, *p2;
	if(start == NULL) return NULL;

	p1 = start;
	p2 = p1->next;
	p1->next = NULL;
	p1->prev = p2;

	while(p2 != NULL) {
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}

	start = p1;
	printf("list reversed\n");
	return start;
}
