#include <stdio.h>
#include <stdlib.h>

// Define the basic unit of the linked list: the Node
struct Node
{
    int data;          // Holds the actual integer value
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
    for (int i = 0; i < 5; i++)
        head = InsertAtBeg(head, i);
    PrintList(head);

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

    // Demonstration of deletion (removing the 2nd node)
    head = DeleteAtPos(head, 2);
    PrintList(head);

    // Demonstration of iterative reversal
    head = ReverseList(head);
    PrintList(head);

    // Demonstration of recursive reversal
    head = ReverseListUsingRecursion(head);
    PrintList(head);
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
    printf("%d ", ptrNode->data);              // Print while returning
}

// Creates a new node and places it at the very start of the list
struct Node *InsertAtBeg(struct Node *head, int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->data = data;
    node->next = head; // Point new node to the old head
    head = node;       // Update head to the new node

    return head;
}

// Inserts a node at a specific 1-based index
struct Node *InsertAtPos(struct Node *head, int data, int pos)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    // Special case: inserting at the first position
    if (pos == 1)
    {
        node->next = head;
        head = node;
        return head;
    }

    // Traverse to the node just before the insertion point
    struct Node *ptrNode = head;
    for (int i = 1; i < pos - 1; i++)
        ptrNode = ptrNode->next;

    // Re-link pointers to include the new node
    node->next = ptrNode->next;
    ptrNode->next = node;

    return head;
}

// Removes a node at a specific 1-based index and frees memory
struct Node *DeleteAtPos(struct Node *head, int pos)
{
    struct Node *ptrNode1 = head;

    // Special case: deleting the first node
    if (pos == 1)
    {
        head = head->next;
        free(ptrNode1);
        return head;
    }

    // Traverse to the node before the one we want to delete
    for (int i = 1; i < pos - 1; i++)
        ptrNode1 = ptrNode1->next;

    struct Node *ptrNode2 = ptrNode1->next; // The node to be deleted
    ptrNode1->next = ptrNode2->next;        // Bypass the deleted node
    free(ptrNode2);                         // Clear memory

    return head;
}

// Reverses the list by flipping the pointers iteratively
struct Node *ReverseList(struct Node *head)
{
    struct Node *prev, *current, *next;
    prev = NULL;
    current = head;

    while (current != NULL)
    {
        next = current->next; // Store the rest of the list
        current->next = prev; // Reverse the current link
        prev = current;       // Move prev forward
        current = next;       // Move current forward
    }
    head = prev; // New head is the last node we processed

    return head;
}

// Reverses the list using the call stack
struct Node *ReverseListUsingRecursion(struct Node *ptrNode)
{
    // Base case: if list is empty or we are at the last node
    if (ptrNode == NULL || ptrNode->next == NULL)
        return ptrNode;

    // Recursive call to find the new head (the original tail)
    struct Node *newHead = ReverseListUsingRecursion(ptrNode->next);

    // After returning, 'ptrNode' is the node before the current 'ptrNode->next'
    // We point the NEXT node back to the current node
    ptrNode->next->next = ptrNode;
    ptrNode->next = NULL; // Break the forward link to prevent cycles

    return newHead;
}