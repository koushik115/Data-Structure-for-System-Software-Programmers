#include <stdio.h>
#include <stdlib.h>

// Define the basic unit of the linked list: the Node
struct Node
{
    int data;          // Holds the actual integer value
    struct Node *prev; // Pointer the previous node in the sequence
    struct Node *next; // Pointer to the next node in the sequence
};

// Function Prototypes
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
    struct Node *head = NULL; // Initialize an empty list
    int x, data, pos;

    // Fill the list initially by inserting 0 through 4 at the beginning
    // for (int i = 0; i < 5; i++)
    //     head = InsertAtBeg(head, i);
    // PrintList(head);

    head = InsertAtBeg(head, 1);
    // User input for custom insertions
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

    // // Demonstration of deletion (removing the 2nd node)
    // head = DeleteAtPos(head, 2);
    // PrintList(head);

    // // Demonstration of iterative reversal
    // head = ReverseList(head);
    // PrintList(head);

    // // Demonstration of recursive reversal
    // head = ReverseListUsingRecursion(head);
    // PrintList(head);
}

// Traverses the list and prints data until it hits NULL
void PrintList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Prints list elements in order using recursion
void PrintUsingRecursion(struct Node *ptrNode)
{
    if (ptrNode == NULL)
        return; // Base case

    printf("%d ", ptrNode->data);       // Print current
    PrintUsingRecursion(ptrNode->next); // Move to next
}

// Prints list elements in reverse order using recursion (backtracking)
void ReversePrintUsingRecursion(struct Node *ptrNode)
{
    if (ptrNode == NULL)
        return;

    ReversePrintUsingRecursion(ptrNode->next); // Go to the end first
    printf(" %d", ptrNode->data);              // Print while returning
}

// Creates a new node and places it at the very start of the list
struct Node *InsertAtBeg(struct Node *head, int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
        return NULL;

    node->data = data;
    node->prev = NULL;
    node->next = head; // Point new node to the old head
    if (head != NULL)
        head->prev = node; // Point the old previous node to the new node
    head = node;           // Update head to the new node

    return head;
}

// Inserts a node at a specific 1-based index
struct Node *InsertAtPos(struct Node *head, int data, int pos)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
        return NULL;

    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    if (pos == 1)
    {
        node->next = head;
        if (head != NULL)
            head->prev = node;
        head = node;

        return head;
    }

    struct Node *ptrNode = head;
    for (int i = 1; i < pos - 1 && ptrNode->next != NULL; i++)
        ptrNode = ptrNode->next;

    node->next = ptrNode->next;
    if (ptrNode->next != NULL)
        ptrNode->next->prev = node;
    node->prev = ptrNode;
    ptrNode->next = node;

    return head;
}