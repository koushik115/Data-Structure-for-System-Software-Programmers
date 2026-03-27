#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *link;
};

struct node *create_list(struct node *head);
void display(struct node *head);
struct node *addatend(struct node *head, int data);
struct node *addbefore(struct node *head, int data, int item);
struct node *addatpos(struct node *head, int data, int pos);
struct node *del(struct node *head, int data);
struct node *reverse(struct node *head);

int main() {
  int choice, data, item, pos;
  struct node *head;

  head = (struct node *)malloc(sizeof(struct node));
  head->info = 0;
  head->link = NULL;

  head = create_list(head);

  while (1) {
    printf("1.Display\n");
    printf("2.Add at end\n");
    printf("3.Add before node\n");
    printf("4.Add at position\n");
    printf("5.Delete\n");
    printf("6.Reverse\n");
    printf("7.Quit\n\n");

    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      display(head);
      break;

    case 2:
      printf("Enter the element to be inserted : ");
      scanf("%d", &data);
      head = addatend(head, data);
      break;

    case 3:
      printf("Enter the element to be inserted : ");
      scanf("%d", &data);
      printf("Enter the element before which to insert : ");
      scanf("%d", &item);
      head = addbefore(head, data, item);
      break;

    case 4:
      printf("Enter the element to be inserted : ");
      scanf("%d", &data);
      printf("Enter the position at which to insert : ");
      scanf("%d", &pos);
      head = addatpos(head, data, pos);
      break;

    case 5:
      printf("Enter the element to be deleted : ");
      scanf("%d", &data);
      head = del(head, data);
      break;

    case 6:
      head = reverse(head);
      break;

    case 7:
      exit(1);

    default:
      printf("Wrong choice\n\n");
    }
  }
}

/* End of main */

struct node *create_list(struct node *head) {
  int i, n, data;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    head = addatend(head, data);
  }

  return head;
}

void display(struct node *head) {
  if (head->link == NULL) {
    printf("error: list is empty!\n");
    return;
  }

  struct node *p;
  p = head->link;

  while (p != NULL) {
    printf("%d ", p->info);
    p = p->link;
  }
  printf("\n");
}

struct node *addatend(struct node *head, int data) {
  struct node *p, *tmp;

  p = head;
  while (p->link != NULL)
    p = p->link;

  tmp = (struct node *)malloc(sizeof(struct node));
  tmp->info = data;
  p->link = tmp;
  tmp->link = NULL;

  return head;
}

struct node *addbefore(struct node *head, int data, int item) {
  struct node *p, *tmp;
  if (head->link == NULL)
    return NULL;

  p = head;
  while (p->link != NULL) {
    if (p->link->info == item) {
      tmp = (struct node *)malloc(sizeof(struct node));
      tmp->info = data;
      tmp->link = p->link;
      p->link = tmp;

      return head;
    }
    p = p->link;
  }

  printf("error: %d not present in the list\n", item);
  return head;
}

struct node *addatpos(struct node *head, int data, int pos) {
  struct node *p, *tmp;
  if (head->link == NULL)
    return NULL;

  p = head;
  for (int i = 1; p != NULL && i <= pos - 1; i++)
    p = p->link;

  if (p == NULL) {
    printf("error: there are less than %d elements\n", pos);
    return head;
  }

  tmp = (struct node *)malloc(sizeof(struct node));
  tmp->info = data;
  tmp->link = p->link;
  p->link = tmp;

  return head;
}

struct node *del(struct node *head, int data) {
  struct node *p, *tmp;
  if (head->link == NULL)
    return NULL;

  p = head;
  while (p->link != NULL) {
    if (p->link->info == data) {
      tmp = p->link;
      p->link = tmp->link;
      free(tmp);
      return head;
    }
    p = p->link;
  }

  printf("error: element %d not found in the list\n", data);
  return head;
}

struct node *reverse(struct node *head) {
  struct node *prev, *current, *next;
  if (head->link == NULL)
    return NULL;

  prev = NULL;
  current = head->link;

  while (current != NULL) {
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
  }

  head->link = prev;
  return head;
}
