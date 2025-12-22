#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void PrintList(struct Node *head);
void PrintUsingRecursion(struct Node *ptrNode);
void ReversePrintUsingRecursion(struct Node *ptrNode);

struct Node *InsertAtBeg(struct Node *head, int data);
struct Node *InsertAtPos(struct Node *head, int data, int pos);
struct Node *DeleteAtPos(struct Node *head, int pos);
struct Node *ReverseList(struct Node *head);
struct Node *ReverseListUsingRecursion(struct Node *ptrNode);

int main(void)
{
    struct Node *head = NULL;
    int x, data, pos;

    for (int i = 0; i < 5; i++)
        head = InsertAtBeg(head, i);
    PrintList(head);

    printf("Enter the number of nodes to be added on the list: ");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        printf("Enter the position of element to be added on the list: ");
        scanf("%d", &pos);
        printf("Enter the element to be added on the position %d: ", pos);
        scanf("%d", &data);

        head = InsertAtPos(head, data, pos);
    }
    PrintList(head);

    head = DeleteAtPos(head, 2);
    PrintList(head);

    head = ReverseList(head);
    PrintList(head);

    head = ReverseListUsingRecursion(head);
    PrintList(head);
}

void PrintList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

void PrintUsingRecursion(struct Node *ptrNode)
{
    if (ptrNode == NULL)
        return;

    printf("%d ", ptrNode->data);
    PrintUsingRecursion(ptrNode->next);
}

void ReversePrintUsingRecursion(struct Node *ptrNode)
{
    if (ptrNode == NULL)
        return;

    ReversePrintUsingRecursion(ptrNode->next);
    printf("%d ", ptrNode->data);
}

struct Node *InsertAtBeg(struct Node *head, int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->data = data;
    node->next = head;
    head = node;

    return head;
}

struct Node *InsertAtPos(struct Node *head, int data, int pos)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node *));
    node->data = data;
    node->next = NULL;

    if (pos == 1)
    {
        node->next = head;
        head = node;
        return head;
    }

    struct Node *ptrNode = head;
    for (int i = 1; i < pos - 1; i++)
        ptrNode = ptrNode->next;

    node->next = ptrNode->next;
    ptrNode->next = node;

    return head;
}

struct Node *DeleteAtPos(struct Node *head, int pos)
{
    struct Node *ptrNode1 = head;

    if (pos == 1)
    {
        head = head->next;
        free(ptrNode1);
        return head;
    }

    struct Node *ptrNode2 = NULL;
    for (int i = 1; i < pos - 1; i++)
        ptrNode1 = ptrNode1->next;

    ptrNode2 = ptrNode1->next;
    ptrNode1->next = ptrNode2->next;
    free(ptrNode2);

    return head;
}

struct Node *ReverseList(struct Node *head)
{
    struct Node *prev, *current, *next;
    prev = NULL;
    current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    return head;
}

struct Node *ReverseListUsingRecursion(struct Node *ptrNode)
{
    if (ptrNode->next == NULL)
        return ptrNode;

    struct Node *newHead = ReverseListUsingRecursion(ptrNode->next);
    ptrNode->next->next = ptrNode;
    ptrNode->next = NULL;

    return newHead;
}