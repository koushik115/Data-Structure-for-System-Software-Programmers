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

// ================= PROBLEM 3 =================
// Check if two linked lists are identical

int areIdentical(Node* head1, Node* head2) {
    // TODO: Write your logic here
    Node *p1 = head1, *p2 = head2;

    while(p1 != NULL && p2 != NULL) {
	    if(p1->data != p2-> data) return 0;

	    p1 = p1->next; p2 = p2->next;
    }

    return (p1 == NULL && p2 == NULL);
}

// ================= PROBLEM 2 =================
// Find smallest and largest element in singly linked list

void findMinMax(Node* head, int* min, int* max) {
    // TODO: Write your logic here
    Node *p = head;

    if(p == NULL) {
	    *min = *max = -1;
	    return;
    }

	*min = *max = p->data;
    while(p != NULL) {
	    if(p->data < *min) *min = p->data;
	    if(p->data > *max) *max = p->data;
	    p = p->next;
    }

}

// ================= PROBLEM 4 =================
// Create a copy of a singly linked list

Node* copyList(Node* head) {
    // TODO: Write your logic here
    Node *prev = NULL, *tmp = NULL, *p = NULL, *copyHead = NULL;
    p = head;
    
    if(p == NULL) return NULL;

    tmp = (Node *)malloc(sizeof(Node));
    if(tmp == NULL) return NULL;
    tmp->data = p->data;
    tmp->next = NULL;
    copyHead = prev = tmp;
    p = p->next;


    while(p != NULL) {
	    tmp = (Node *)malloc(sizeof(Node));
	    if(tmp == NULL) return NULL;
	    tmp->data = p->data;
	    tmp->next = NULL;
	    prev->next = tmp;
	    prev = tmp;
	    p = p->next;
    }

    return copyHead;

}

// ================= PROBLEM 5 =================
// Create a new list which is reverse of given list (original unchanged)

Node* reverseCopy(Node* head) {
    // TODO: Write your logic here
    Node *tmp = NULL, *p = NULL, *newHead = NULL;
    p = head;

    if(p == NULL) return NULL;

    while(p != NULL) {
	    tmp = (Node *)malloc(sizeof(Node));
	    if(tmp == NULL) return NULL;
	    tmp->data = p->data;
	    tmp->next = newHead;
	    newHead = tmp;
	    p = p->next;
    }

    return newHead;
}

int main() {
/*
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
*/
/*
    Node* head = NULL;

    // List: 7 -> 2 -> 9 -> 1 -> 5
    head = insertEnd(head, 7);
    head = insertEnd(head, 2);
    head = insertEnd(head, 9);
    head = insertEnd(head, 1);
    head = insertEnd(head, 5);

    printf("List:\n");
    printList(head);

    int min, max;
    findMinMax(head, &min, &max);

    printf("Min = %d, Max = %d\n", min, max);
    // Expected: Min = 1, Max = 9

    // ================= EDGE CASES =================

    // Case 2: Single node
    Node* single = createNode(10);
    findMinMax(single, &min, &max);
    printf("Single node -> Min = %d, Max = %d\n", min, max);
    // Expected: 10, 10

    // Case 3: All elements same
    Node* same = NULL;
    same = insertEnd(same, 4);
    same = insertEnd(same, 4);
    same = insertEnd(same, 4);

    findMinMax(same, &min, &max);
    printf("All same -> Min = %d, Max = %d\n", min, max);
    // Expected: 4, 4

    // Case 4: Empty list
    Node* empty = NULL;
    findMinMax(empty, &min, &max);
    printf("Empty list handled\n"); 
    // Decide how you want to handle this (important!)
*/
/*
    // -------- Case 1: Identical lists --------
    Node* list1 = NULL;
    Node* list2 = NULL;

    // List: 1 -> 2 -> 3 -> 4
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 2);
    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 4);

    list2 = insertEnd(list2, 1);
    list2 = insertEnd(list2, 2);
    list2 = insertEnd(list2, 3);
    list2 = insertEnd(list2, 4);

    printf("List1:\n");
    printList(list1);
    printf("List2:\n");
    printList(list2);

    printf("Are identical? %d\n", areIdentical(list1, list2));
    // Expected: 1


    // -------- Case 2: Same size, different elements --------
    Node* list3 = NULL;
    list3 = insertEnd(list3, 1);
    list3 = insertEnd(list3, 2);
    list3 = insertEnd(list3, 9);
    list3 = insertEnd(list3, 4);

    printf("Are identical? %d\n", areIdentical(list1, list3));
    // Expected: 0


    // -------- Case 3: Different lengths --------
    Node* list4 = NULL;
    list4 = insertEnd(list4, 1);
    list4 = insertEnd(list4, 2);

    printf("Are identical? %d\n", areIdentical(list1, list4));
    // Expected: 0


    // -------- Case 4: Both empty --------
    Node* empty1 = NULL;
    Node* empty2 = NULL;

    printf("Both empty: %d\n", areIdentical(empty1, empty2));
    // Expected: 1


    // -------- Case 5: One empty, one not --------
    printf("One empty: %d\n", areIdentical(list1, NULL));
    // Expected: 0
*/
/*	
    // -------- Case 1: Normal list --------
    Node* head = NULL;

    // List: 1 -> 2 -> 3 -> 4
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);

    printf("Original List:\n");
    printList(head);

    Node* copied = copyList(head);

    printf("Copied List:\n");
    printList(copied);
    // Expected: same as original


    // -------- Case 2: Modify original, copy should not change --------
    head->data = 100;

    printf("After modifying original:\n");
    printf("Original:\n");
    printList(head);

    printf("Copied:\n");
    printList(copied);
    // Expected: copied list unchanged


    // -------- Case 3: Empty list --------
    Node* empty = NULL;
    Node* copyEmpty = copyList(empty);

    printf("Empty copy:\n");
    printList(copyEmpty);
    // Expected: NULL


    // -------- Case 4: Single node --------
    Node* single = createNode(42);
    Node* copySingle = copyList(single);

    printf("Single original:\n");
    printList(single);

    printf("Single copy:\n");
    printList(copySingle);
    // Expected: 42 -> NULL
*/

    // -------- Case 1: Normal list --------
    Node* head = NULL;

    // List: 1 -> 2 -> 3 -> 4 -> 5
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    printf("Original List:\n");
    printList(head);

    Node* reversed = reverseCopy(head);

    printf("Reversed Copy:\n");
    printList(reversed);
    // Expected: 5 -> 4 -> 3 -> 2 -> 1

    printf("Original Again (should be unchanged):\n");
    printList(head);


    // -------- Case 2: Single node --------
    Node* single = createNode(10);
    Node* revSingle = reverseCopy(single);

    printf("Single original:\n");
    printList(single);

    printf("Single reversed copy:\n");
    printList(revSingle);
    // Expected: 10 -> NULL


    // -------- Case 3: Empty list --------
    Node* empty = NULL;
    Node* revEmpty = reverseCopy(empty);

    printf("Empty reversed copy:\n");
    printList(revEmpty);
    // Expected: NULL

    return 0;
}
