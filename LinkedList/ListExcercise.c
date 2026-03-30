#include <stdio.h>
#include <stdlib.h>

// ================= NODE DEFINITION =================
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ================= HELPER FUNCTIONS =================

// Create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    
    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ================= PROBLEM 1 =================
// Count occurrences of a given element in singly linked list

int countOccurrences(Node* head, int key) {
    // TODO: Write your logic here
    if(head == NULL)
	    return 0;

    Node *p = head;
    int count = 0;

    while(p != NULL) {
	if(p->data == key)
		count++;
	p = p->next;
    }

    return count;
}

int main() {
    Node* head = NULL;

    // List: 1 -> 2 -> 3 -> 2 -> 4 -> 2 -> 5
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 2);
    head = insertEnd(head, 4);
    head = insertEnd(head, 2);
    head = insertEnd(head, 5);

    printf("List:\n");
    printList(head);

    int key = 2;
    int count = countOccurrences(head, key);

    printf("Occurrences of %d = %d\n", key, count);
    // Expected: 3

    // ================= EDGE CASES =================

    // Case 2: Element not present
    key = 10;
    count = countOccurrences(head, key);
    printf("Occurrences of %d = %d\n", key, count);
    // Expected: 0

    // Case 3: Empty list
    Node* empty = NULL;
    count = countOccurrences(empty, 1);
    printf("Occurrences in empty list = %d\n", count);
    // Expected: 0

    // Case 4: Single node
    Node* single = createNode(5);
    count = countOccurrences(single, 5);
    printf("Single node match = %d\n", count);
    // Expected: 1

    count = countOccurrences(single, 2);
    printf("Single node no match = %d\n", count);
    // Expected: 0

    return 0;
}
