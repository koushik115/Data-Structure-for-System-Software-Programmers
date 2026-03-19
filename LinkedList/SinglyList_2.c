/* Program of Single Linked List from Data Structures Through C in Depth */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int data);
struct node *addbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
struct node *addatpos(struct node *start, int data, int pos);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);

int main()
{
    struct node *start = NULL;
    int choice, data, item, pos;

    while(1)
    {
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Search\n");
        printf("5. Add to empty list / Add at beginning\n");
        printf("6. Add at end\n");
        printf("7. Add after node\n");
        printf("8. Add before node\n");
        printf("9. Add at position\n");
        printf("10. Delete\n");
        printf("11. Reverse\n");
        printf("12. Quit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                start = create_list(start);
                break;

            case 2:
                display(start);
                break;

            case 3:
                count(start);
                break;

            case 4:
                printf("Enter the element to be searched : ");
                scanf("%d", &data);
                search(start, data);
                break;

            case 5:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                start = addbeg(start, data);
                break;

            case 6:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                start = addatend(start, data);
                break;

            case 7:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                printf("Enter the element after which to insert : ");
                scanf("%d", &item);
                start = addafter(start, data, item);
                break;

            case 8:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                printf("Enter the element before which to insert : ");
                scanf("%d", &item);
                start = addbefore(start, data, item);
                break;

            case 9:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                printf("Enter the position at which to insert : ");
                scanf("%d", &pos);
                start = addatpos(start, data, pos);
                break;

            case 10:
                printf("Enter the element to be deleted : ");
                scanf("%d", &data);
                start = del(start, data);
                break;

            case 11:
                start = reverse(start);
                break;

            case 12:
                exit(1);

            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}

struct node *create_list(struct node *start) {
    int i, n, data;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    start = NULL;
    if(n == 0) 
        return start;
        
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    
    start = addbeg(start, data);
    for(i = 1; i < n; i++) {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    
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
        printf("%d\t", p->info);
        p = p->link;
    }
    
    printf("\n\n");
}

void count(struct node *start) {
    struct node *p = start;
    int nodecount = 0;
    
    while(p != NULL) {
        nodecount++;
        p = p->link;
    }
    
    printf("count: no of elements are %d\n", nodecount);
}

void search(struct node *start, int data) {
    struct node *p = start;
    int pos = 1;
    
    while(p != NULL) {
        if(p->info == data) {
            printf("search: data %d is found at position %d\n", data, pos);
            return;
        }
        
        pos++;
        p = p->link;
    }
    
    printf("error: data %d is not found in the list\n", data);
}

/* Inserting at the beginning or at the empty list */
struct node *addbeg(struct node *start, int data) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL) return NULL;
    
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    
    return start;
}

struct node *addatend(struct node *start, int data) {
    if(start == NULL)  return NULL;
    
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL) return NULL;
    
    tmp->info = data;
    tmp->link = NULL;
    
    p = start;
    while(p->link != NULL)
        p = p->link;
        
    p->link = tmp;
    
    return start;
}

struct node *addafter(struct node *start, int data, int item) {
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node *));
    if(tmp == NULL) return NULL;
    
    p = start;
    while(p != NULL) {
        if(p->info == item) {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            
            return start;
        }
        
        p = p->link;
    }
    
    printf("error: %d not present in the list\n", item);
    return start;
}

struct node *addbefore(struct node *start, int data, int item) {
    struct node *p, *tmp;
    if(start == NULL) return NULL;
    
    if(start->info == item) {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;   
        tmp->link = start;
        start = tmp;
        
        return start;
    }
    
    p = start;
    while(p->link != NULL) {
        if(p->link->info == item) {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        
        p = p->link;
    }
    
    printf("error: %d not present in the list\n", item);
    return start;
}

struct node *addatpos(struct node *start, int data, int pos) {
    struct node *p, *tmp;
    if(start == NULL) return NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL) return NULL;
    tmp->info = data;
    
    if(pos == 1) {
        tmp->link = start;
        start = tmp;
        return start;
    }
    
    p = start;
    for(int i = 1; i < pos - 1 && p != NULL; i++)
        p = p->link;
        
    if(p == NULL) {
        printf("error: there are less than %d elements\n", pos);
    } else {
        tmp->link = p->link;
        p->link = tmp;
    }
    
    return start;
}

struct node *del(struct node *start, int data) {
    struct node *p, *tmp;
    
    if(start == NULL) {
        printf("error: list is empty!\n");
        return NULL;
    }
    
    if(start->info == data) {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    
    p = start;
    while(p->link != NULL) {
        if(p->link->info == data) {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        
        p = p->link;
    }
    
    printf("error: element %d not found\n", data);
    return start;
}

struct node *reverse(struct node *start) {
    struct node *prev, *current, *next;
    if(start == NULL) {
        printf("error: list is empty!\n");
        return start;
    }
    
    prev = NULL;
    current = start;
    while(current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    
    start = prev;
    return start;
}
