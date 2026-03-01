#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int enqueue(struct node **front, struct node **rear, int x);
int dequeue(struct node **front, struct node **rear, int *x);
int isQueueEmpty(struct node *front, struct node *rear);

int main(void) {
    struct node *front = NULL, *rear = NULL;
    int value;

    printf("---- Queue Test ----\n");

    if(!enqueue(&front, &rear, 10)) return 1;
    if(!enqueue(&front, &rear, 20)) return 1;
    if(!enqueue(&front, &rear, 30)) return 1;

    while (dequeue(&front, &rear, &value)) {
        printf("Dequeued: %d\n", value);
    }

    return 0;
}

int enqueue(struct node **front, struct node **rear, int x) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL) return 0;
    
    tmp->data = x;
    tmp->next = NULL;
    if(isQueueEmpty(*front, *rear)) {
        *front = *rear = tmp;
    } else {
        (*rear)->next = tmp;
        *rear = tmp;
    }
    
    return 1;
}

int dequeue(struct node **front, struct node **rear, int *x) {
    struct node *tmp = *front;
    
    if(isQueueEmpty(*front, *rear)) {
        return 0;
    } else if(*front == *rear) {
        *x = (*front)->data;
        free(*front);
        *front = *rear = NULL;
    } else {
        *x = (*front)->data;
        *front = (*front)->next;
        free(tmp);
        tmp = NULL;
    }
    
    return 1;
}

int isQueueEmpty(struct node *front, struct node *rear) {
    return (front == NULL && rear == NULL);
}
