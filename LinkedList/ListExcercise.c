#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// ================= NODE DEFINITION =================
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// ================= DOUBLY NODE =================
typedef struct DNode {
  int data;
  struct DNode *next;
  struct DNode *prev;
} DNode;

// ================= HELPER FUNCTIONS =================

// Create new node
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Insert at end
Node *insertEnd(Node *head, int data) {
  Node *newNode = createNode(data);

  if (head == NULL)
    return newNode;

  Node *temp = head;
  while (temp->next)
    temp = temp->next;

  temp->next = newNode;
  return head;
}

// Print list
void printList(Node *head) {
  Node *temp = head;
  while (temp) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Create node
DNode *createDNode(int data) {
  DNode *newNode = (DNode *)malloc(sizeof(DNode));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// Insert at end
DNode *insertEndD(DNode *head, int data) {
  DNode *newNode = createDNode(data);

  if (head == NULL)
    return newNode;

  DNode *temp = head;
  while (temp->next)
    temp = temp->next;

  temp->next = newNode;
  newNode->prev = temp;

  return head;
}

// Print forward
void printDList(DNode *head) {
  DNode *temp = head;
  while (temp) {
    printf("%d <-> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// ================= PROBLEM 1 =================
// Count occurrences of a given element in singly linked list

int countOccurrences(Node *head, int key) {
  // TODO: Write your logic here
  if (head == NULL)
    return 0;

  Node *p = head;
  int count = 0;

  while (p != NULL) {
    if (p->data == key)
      count++;
    p = p->next;
  }

  return count;
}

// ================= PROBLEM 3 =================
// Check if two linked lists are identical

int areIdentical(Node *head1, Node *head2) {
  // TODO: Write your logic here
  Node *p1 = head1, *p2 = head2;

  while (p1 != NULL && p2 != NULL) {
    if (p1->data != p2->data)
      return 0;

    p1 = p1->next;
    p2 = p2->next;
  }

  return (p1 == NULL && p2 == NULL);
}

// ================= PROBLEM 2 =================
// Find smallest and largest element in singly linked list

void findMinMax(Node *head, int *min, int *max) {
  // TODO: Write your logic here
  Node *p = head;

  if (p == NULL) {
    *min = *max = -1;
    return;
  }

  *min = *max = p->data;
  while (p != NULL) {
    if (p->data < *min)
      *min = p->data;
    if (p->data > *max)
      *max = p->data;
    p = p->next;
  }
}

// ================= PROBLEM 4 =================
// Create a copy of a singly linked list

Node *copyList(Node *head) {
  // TODO: Write your logic here
  Node *prev = NULL, *tmp = NULL, *p = NULL, *copyHead = NULL;
  p = head;

  if (p == NULL)
    return NULL;

  tmp = (Node *)malloc(sizeof(Node));
  if (tmp == NULL)
    return NULL;
  tmp->data = p->data;
  tmp->next = NULL;
  copyHead = prev = tmp;
  p = p->next;

  while (p != NULL) {
    tmp = (Node *)malloc(sizeof(Node));
    if (tmp == NULL)
      return NULL;
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

Node *reverseCopy(Node *head) {
  // TODO: Write your logic here
  Node *tmp = NULL, *p = NULL, *newHead = NULL;
  p = head;

  if (p == NULL)
    return NULL;

  while (p != NULL) {
    tmp = (Node *)malloc(sizeof(Node));
    if (tmp == NULL)
      return NULL;
    tmp->data = p->data;
    tmp->next = newHead;
    newHead = tmp;
    p = p->next;
  }

  return newHead;
}

// ================= PROBLEM 6(a) =================
// Swap adjacent nodes by exchanging data

Node *swapData(Node *head) {
  // TODO: Write your logic here
  Node *tmp = head;
  int currentData = -1, nextData = -1;
  if (tmp == NULL)
    return NULL;

  while (tmp != NULL && tmp->next != NULL) {
    currentData = tmp->data;
    nextData = tmp->next->data;
    tmp->data = nextData;
    tmp->next->data = currentData;
    tmp = tmp->next->next;
  }

  return head;
}

// ================= PROBLEM 6(b) =================
// Swap adjacent nodes by rearranging links

Node *swapLinks(Node *head) {
  if (head == NULL || head->next == NULL)
    return head;

  Node *prev = NULL;
  Node *current = head;
  Node *next = NULL;
  Node *nextPair = NULL;

  Node *newHead = head->next;

  while (current != NULL && current->next != NULL) {
    next = current->next;
    nextPair = next->next;

    // swap
    next->next = current;
    current->next = nextPair;

    // connect with previous pair
    if (prev != NULL)
      prev->next = next;

    // move forward
    prev = current;
    current = nextPair;
  }

  return newHead;
}

// ================= PROBLEM 7 =================
// Swap adjacent nodes in doubly linked list by rearranging links

DNode *swapAdjacentDLL(DNode *head) {
  // TODO: Write your logic here
  DNode *prev, *current, *next, *nextPair, *newHead;
  if (head == NULL || head->next == NULL)
    return head;

  prev = NULL;
  current = head;
  next = NULL;
  nextPair = NULL;
  newHead = current->next;
  newHead->prev = NULL;

  while (current != NULL && current->next != NULL) {
    next = current->next;
    nextPair = next->next;

    next->next = current;
    next->prev = prev;

    current->prev = next;
    current->next = nextPair;

    if (prev != NULL)
      prev->next = next;

    if (nextPair != NULL)
      nextPair->prev = current;

    prev = current;
    current = nextPair;
  }

  return newHead;
}

// ================= PROBLEM 8(a) =================
// Swap first and last node by exchanging data

Node *swapFirstLastData(Node *head) {
  // TODO: Write your logic here
  int firstInfo = INT_MIN;
  int lastInfo = INT_MIN;
  Node *p = head;

  if (head == NULL)
    return NULL;

  firstInfo = head->data;

  while (p->next != NULL)
    p = p->next;

  lastInfo = p->data;

  head->data = lastInfo;
  p->data = firstInfo;

  return head;
}

// ================= PROBLEM 8(b) =================
// Swap first and last node by rearranging links

Node *swapFirstLastLinks(Node *head) {
  // TODO: Write your logic here
  Node *p1 = NULL, *p2 = NULL;

  if (head == NULL)
    return NULL;

  p1 = head;
  p2 = head->next;

  if (p2 == NULL) {
    return head;
  } else if (p2->next == NULL) {
    p2->next = p1;
    p1->next = NULL;
    head = p2;

    return head;
  }

  while (p2 != NULL && p2->next != NULL) {
    p1 = p2;
    p2 = p2->next;
  }

  p2->next = head->next;
  head->next = NULL;
  p1->next = head;
  head = p2;

  return head;
}

// ================= PROBLEM 9 =================
// Move the largest element to the end of the list

Node *moveMaxToEnd(Node *head) {
  // TODO: Write your logic here
  Node *p = NULL, *p1 = NULL, *p2 = NULL;
  int max = INT_MAX;

  if (head == NULL || head->next == NULL)
    return head;
  max = head->data;

  p = head;
  while (p != NULL && p->next != NULL) {
    if (p->next->data > max) {
      p1 = p;
      p2 = p1->next;
      max = p->next->data;
    }

    p = p->next;
  }

  if (p1 == NULL && p2 == NULL) {
    p1 = head;
    head = head->next;
    p1->next = NULL;
    p->next = p1;

    return head;
  }

  if (p2->next != NULL)
    p1->next = p2->next;
  p2->next = NULL;
  if (p != p2)
    p->next = p2;

  return head;
}

// ================= PROBLEM 10 =================
// Move smallest element to beginning of list

Node *moveMinToFront(Node *head) {
  // TODO: Write your logic here
  Node *p = NULL, *p1 = NULL, *p2 = NULL;
  int min = INT_MIN;

  if (head == NULL || head->next == NULL)
    return head;
  p = head;
  min = p->data;

  while (p != NULL && p->next != NULL) {
    if (p->next->data < min) {
      min = p->next->data;
      p1 = p;
      p2 = p1->next;
    }

    p = p->next;
  }

  if (p1 == NULL && p2 == NULL)
    return head;
  p1->next = p2->next;
  p2->next = head;
  head = p2;

  return head;
}

// ================= PROBLEM 11 =================
// Delete all nodes with value N

Node *deleteAllOccurrences(Node *head, int key) {
  // TODO: Write your logic here
  Node *prev = NULL, *current = NULL, *p;

  if (head == NULL)
    return NULL;

  if (head->data == key) {
    p = head;
    head = head->next;
    free(p);
  }

  current = head;
  while (current != NULL) {
    if (current->data == key) {
      p = current;
      if (prev != NULL)
        prev->next = current->next;
      if (prev != NULL)
        current = prev->next;
      if (current == head) {
        head = head->next;
        current = head;
      }

      free(p);
    } else {
      prev = current;
      current = current->next;
    }
  }

  return head;
}

// ================= PROBLEM 12 =================
// Print elements of L2 at positions given by L1

void printByPositions(Node *l1, Node *l2) {
  // TODO: Write your logic here
  Node *p1 = NULL, *p2 = NULL;

  if (l1 == NULL)
    return;

  p1 = l1;
  p2 = l2;

  while (p1 != NULL) {
    int pos = p1->data;
    while (p2 != NULL && --pos > 0)
      p2 = p2->next;
    if (p2 != NULL)
      printf("%d ", p2->data);
    p2 = l2;
    p1 = p1->next;
  }

  printf("\n");
}

// ================= PROBLEM 13 =================
// Move first node to end of list

Node *moveFirstToEnd(Node *head) {
  // TODO: Write your logic here
  Node *start = NULL, *p = NULL;

  if (head == NULL || head->next == NULL)
    return head;

  p = start = head;
  while (p != NULL && p->next != NULL)
    p = p->next;

  head = head->next;
  start->next = p->next;
  p->next = start;

  return head;
}

// ================= PROBLEM 14 =================
// Move last node to beginning of list

Node *moveLastToFront(Node *head) {
  // TODO: Write your logic here
  Node *p = NULL;
  if (head == NULL || head->next == NULL)
    return head;

  p = head;
  while (p != NULL && p->next != NULL && p->next->next != NULL)
    p = p->next;

  p->next->next = head;
  head = p->next;
  p->next = NULL;

  return head;
}

// ================= PROBLEM 15 =================
// Move node at position 'pos' n steps forward (towards head)
/*
Node* moveNodeForward(Node* head, int pos, int n) {
    // TODO: Write your logic here
    Node *p = NULL, *q = NULL, *r = NULL, *s = NULL;

    if(head == NULL || head->next == NULL || n == 0) return head;

    p = head;
    while(p != NULL && p->next != NULL && --pos > 0) {
            q = p;
            p = p->next;
    }

    r = head;
    while(--count > 0 && r != NULL) {
        s = r;
        r = r->next;
    }


    return head;
}
*/

// ================= PROBLEM 16 =================
// Delete given node (only pointer to that node is provided)

void deleteNode(Node *node) {
  // TODO: Write your logic here
  Node *tmp = NULL;
  if (node == NULL || node->next == NULL)
    return;

  tmp = node->next;
  node->data = tmp->data;
  node->next = tmp->next;
  free(tmp);
  tmp = NULL;
}

// ================= PROBLEM 17 =================

// Insert AFTER node p
void insertAfter(Node *p, int data) {
  // TODO
  Node *tmp = NULL;

  if (p == NULL)
    return;

  tmp = (Node *)malloc(sizeof(Node));
  if (tmp == NULL)
    return;

  tmp->data = data;
  tmp->next = p->next;
  p->next = tmp;
}

// Insert BEFORE node p
void insertBefore(Node *p, int data) {
  // TODO
  Node *tmp = NULL;

  if (p == NULL)
    return;

  tmp = (Node *)malloc(sizeof(Node));
  if (tmp == NULL)
    return;

  tmp->data = p->data;
  p->data = data;
  tmp->next = p->next;
  p->next = tmp;
}

// ================= PROBLEM 18 =================
// Free all nodes in the list

Node *destroy(Node *head) {
  // TODO: Write your logic here
  Node *p = NULL, *q = NULL;

  if (head == NULL)
    return NULL;

  p = head;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }

  head = NULL;
  return head;
}

// ================= PROBLEM 19 =================
// Remove duplicates from sorted linked list
Node *removeDuplicates(Node *head) {
  Node *p = head, *q = NULL;

  while (p != NULL && p->next != NULL) {
    if (p->data == p->next->data) {
      q = p->next;
      p->next = p->next->next;
      free(q);
    } else
      p = p->next;
  }

  return head;
}

// ================= PROBLEM 20 =================
// Remove duplicates from unsorted linked list

Node *removeDuplicatesUnsorted(Node *head) {
  // TODO: Write your logic here
  Node *p = NULL, *q = NULL, *r = NULL;

  if (head == NULL || head->next == NULL)
    return head;

  p = head;
  while (p != NULL && p->next != NULL) {
    q = p;
    while (q != NULL && q->next != NULL) {
      if (p->data == q->next->data) {
        r = q->next;
        q->next = r->next;
        free(r);
      } else
        q = q->next;
    }

    p = p->next;
  }

  return head;
}

// ================= PROBLEM 21 =================
// Create intersection list (common elements)

Node *intersectionList(Node *l1, Node *l2) {
  // TODO: Write your logic here
  Node *p = NULL, *q = NULL, *r = NULL, *tmp = NULL, *head = NULL;
  Node *free_p = NULL, *free_q = NULL;
  if (l1 == NULL || l2 == NULL)
    return NULL;

  p = l1;
  while (p != NULL) {
    q = l2;
    while (q != NULL) {
      if (p->data == q->data) {
        tmp = (Node *)malloc(sizeof(Node));
        if (tmp == NULL) {
          if (head != NULL) {
            free_p = head;
            while (free_p != NULL) {
              free_q = free_p;
              free_p = free_p->next;
              free(free_q);
            }

            return NULL;
          }
        }

        tmp->data = p->data;
        if (head == NULL)
          head = tmp;
        if (r != NULL)
          r->next = tmp;
        r = tmp;
        tmp->next = NULL;
        break;
      } else
        q = q->next;
    }

    p = p->next;
  }

  return head;
}

// ================= PROBLEM 22 =================
// Create union list (unique elements from both lists)

Node *unionList(Node *l1, Node *l2) {
  // TODO: Write your logic here
  Node *p = NULL, *q = NULL, *r = NULL, *tmp = NULL, *head = NULL;
  Node *free_p = NULL, *free_q = NULL;
  int isRepeat = 0;

  if (l1 == NULL && l2 == NULL)
    return NULL;

  if (l1 == NULL)
    p = l2;
  else
    p = l1;

  while (p != NULL) {
    q = head;
    while (q != NULL && p->data != q->data) {
      q = q->next;
    }
    if (q == NULL) {
      tmp = (Node *)malloc(sizeof(Node));
      if (tmp == NULL) {
        free_p = head;
        while (free_p != NULL) {
          free_q = free_p;
          free_p = free_p->next;
          free(free_q);
        }

        return NULL;
      }

      tmp->data = p->data;
      if (head == NULL) {
        head = r = tmp;
      } else {
        r->next = tmp;
        r = tmp;
      }

      tmp->next = NULL;
    }

    p = p->next;
    if (l1 != NULL && p == NULL && !isRepeat) {
      p = l2;
      isRepeat = 1;
    }
  }

  return head;
}

// ================= PROBLEM 23 =================
// Split l1 into l2 (negative) and l3 (positive)

void splitList(Node *l1, Node **l2, Node **l3) {
  // TODO: Write your logic here
  Node *p = l1, *l2_prev = NULL, *l3_prev = NULL, *next = NULL;

  if (p == NULL)
    return;

  while (p != NULL) {
    if (p->data >= 0) {
      if (*l3 == NULL)
        *l3 = p;
      if (l3_prev != NULL)
        l3_prev->next = p;
      l3_prev = p;
    } else {
      if (*l2 == NULL)
        *l2 = p;
      if (l2_prev != NULL)
        l2_prev->next = p;
      l2_prev = p;
    }

    next = p->next;
    p->next = NULL;
    p = next;
  }

  if (l2_prev != NULL)
    l2_prev->next = NULL;

  if (l3_prev != NULL)
    l3_prev->next = NULL;
}

// ================= PROBLEM 24 =================
// Split into even and odd lists (do NOT modify l1)

void splitEvenOdd(Node *l1, Node **l2, Node **l3) {
  // TODO: Write your logic here
  Node *p = NULL, *odd_prev = NULL, *even_prev = NULL, *tmp = NULL;
  Node *free_p = NULL, *free_q = NULL;

  if (l1 == NULL)
    return;

  p = l1;
  while (p != NULL) {
    if (p->data % 2 == 0) {
      tmp = (Node *)malloc(sizeof(Node));
      if (tmp == NULL) {
        if (*l2 != NULL) {
          free_p = *l2;
          while (free_p != NULL) {
            free_q = free_p;
            free_p = free_p->next;
            free(free_q);
          }
        }

        if (*l3 != NULL) {
          free_p = *l3;
          while (free_p != NULL) {
            free_q = free_p;
            free_p = free_p->next;
            free(free_q);
          }
        }

        *l2 = NULL;
        *l3 = NULL;
        return;
      }

      tmp->data = p->data;
      tmp->next = NULL;

      if (*l2 == NULL)
        *l2 = even_prev = tmp;
      else {
        even_prev->next = tmp;
        even_prev = tmp;
      }
    } else {
      tmp = (Node *)malloc(sizeof(Node));
      if (tmp == NULL) {
        if (*l2 != NULL) {
          free_p = *l2;
          while (free_p != NULL) {
            free_q = free_p;
            free_p = free_p->next;
            free(free_q);
          }
        }

        if (*l3 != NULL) {
          free_p = *l3;
          while (free_p != NULL) {
            free_q = free_p;
            free_p = free_p->next;
            free(free_q);
          }
        }

        *l2 = NULL;
        *l3 = NULL;
        return;
      }

      tmp->data = p->data;
      tmp->next = NULL;

      if (*l3 == NULL)
        *l3 = odd_prev = tmp;
      else {
        odd_prev->next = tmp;
        odd_prev = tmp;
      }
    }

    p = p->next;
  }
}

// ================= PROBLEM 26 =================
// Delete alternate (even-positioned) nodes

Node* deleteAlternate(Node* head) {
    // TODO: Write your logic here
    Node *p = NULL, *q = NULL;

    if(head == NULL || head->next == NULL) return head;

    p = head;
    while(p != NULL && p->next != NULL) {
	    q = p->next;
	    p->next = q->next;
	    free(q);
	    p = p->next;
    }

    return head;
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
      // -------- Case 1 --------
      Node* head = NULL;

      // 1 -> 2 -> 3 -> 4 -> 5
      for(int i = 1; i <= 5; i++)
          head = insertEnd(head, i);

      printf("Original:\n");
      printList(head);

      head = moveNodeForward(head, 4, 2);

      printf("After move:\n");
      printList(head);
      // Expected: 1 -> 4 -> 2 -> 3 -> 5


      // -------- Case 2: Move beyond head --------
      head = moveNodeForward(head, 3, 5);
      printList(head);
      // Expected: node moves to head


      // -------- Case 3: n = 0 --------
      head = moveNodeForward(head, 2, 0);
      printList(head);
      // Expected: unchanged


      // -------- Case 4: Invalid position --------
      head = moveNodeForward(head, 10, 2);
      printList(head);
      // Expected: unchanged


      // -------- Case 5: Single node --------
      Node* single = createNode(10);
      single = moveNodeForward(single, 1, 3);
      printList(single);
      // Expected: 10
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
  /*
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
  */
  /*
      // -------- Case 1: Even number of nodes --------
      Node* head1 = NULL;

      // List: 1 -> 2 -> 3 -> 4 -> 5 -> 6
      for (int i = 1; i <= 6; i++)
          head1 = insertEnd(head1, i);

      printf("Original List:\n");
      printList(head1);

      Node* dataSwap = swapData(head1);
      printf("After swap (data):\n");
      printList(dataSwap);
      // Expected: 2 -> 1 -> 4 -> 3 -> 6 -> 5


      // Recreate list (IMPORTANT for second test)
      Node* head2 = NULL;
      for (int i = 1; i <= 6; i++)
          head2 = insertEnd(head2, i);

      Node* linkSwap = swapLinks(head2);
      printf("After swap (links):\n");
      printList(linkSwap);
      // Expected: 2 -> 1 -> 4 -> 3 -> 6 -> 5


      // -------- Case 2: Odd number of nodes --------
      Node* odd = NULL;
      for (int i = 1; i <= 5; i++)
          odd = insertEnd(odd, i);

      printf("Odd List:\n");
      printList(odd);

      odd = swapLinks(odd);
      printf("After swap (links):\n");
      printList(odd);
      // Expected: 2 -> 1 -> 4 -> 3 -> 5


      // -------- Case 3: Single node --------
      Node* single = createNode(10);
      single = swapLinks(single);

      printf("Single node:\n");
      printList(single);
      // Expected: 10


      // -------- Case 4: Empty list --------
      Node* empty = NULL;
      empty = swapLinks(empty);

      printf("Empty list:\n");
      printList(empty);
      // Expected: NULL
  */
  /*
      // -------- Case 1: Even nodes --------
      DNode* head = NULL;

      // 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
      for (int i = 1; i <= 6; i++)
          head = insertEndD(head, i);

      printf("Original DLL:\n");
      printDList(head);

      head = swapAdjacentDLL(head);

      printf("After swap:\n");
      printDList(head);
      // Expected: 2 <-> 1 <-> 4 <-> 3 <-> 6 <-> 5


      // -------- Case 2: Odd nodes --------
      DNode* odd = NULL;
      for (int i = 1; i <= 5; i++)
          odd = insertEndD(odd, i);

      printf("Odd DLL:\n");
      printDList(odd);

      odd = swapAdjacentDLL(odd);

      printf("After swap:\n");
      printDList(odd);
      // Expected: 2 <-> 1 <-> 4 <-> 3 <-> 5


      // -------- Case 3: Single node --------
      DNode* single = createDNode(10);
      single = swapAdjacentDLL(single);

      printDList(single);
      // Expected: 10


      // -------- Case 4: Empty --------
      DNode* empty = NULL;
      empty = swapAdjacentDLL(empty);

      printDList(empty);
      // Expected: NULL
  */
  /*
      // -------- Case 1: Normal list --------
      Node* head = NULL;

      // 1 -> 2 -> 3 -> 4 -> 5
      for(int i = 1; i <= 5; i++)
          head = insertEnd(head, i);

      printf("Original List:\n");
      printList(head);

      Node* dataSwap = swapFirstLastData(head);
      printf("After swap (data):\n");
      printList(dataSwap);
      // Expected: 5 -> 2 -> 3 -> 4 -> 1


      // Recreate for link swap
      Node* head2 = NULL;
      for(int i = 1; i <= 5; i++)
          head2 = insertEnd(head2, i);

      Node* linkSwap = swapFirstLastLinks(head2);
      printf("After swap (links):\n");
      printList(linkSwap);
      // Expected: 5 -> 2 -> 3 -> 4 -> 1


      // -------- Case 2: Two nodes --------
      Node* two = NULL;
      two = insertEnd(two, 10);
      two = insertEnd(two, 20);

      two = swapFirstLastLinks(two);
      printList(two);
      // Expected: 20 -> 10


      // -------- Case 3: Single node --------
      Node* single = createNode(7);
      single = swapFirstLastLinks(single);
      printList(single);
      // Expected: 7


      // -------- Case 4: Empty --------
      Node* empty = NULL;
      empty = swapFirstLastLinks(empty);
      printList(empty);
      // Expected: NULL
      */

  // -------- Case 1: Normal list --------
  /*  Node* head = NULL;

    // 3 -> 1 -> 5 -> 2 -> 4
    head = insertEnd(head, 3);
    head = insertEnd(head, 1);
    head = insertEnd(head, 5);
    head = insertEnd(head, 2);
    head = insertEnd(head, 4);

    printf("Original List:\n");
    printList(head);

    head = moveMaxToEnd(head);

    printf("After moving max to end:\n");
    printList(head);
    // Expected: 3 -> 1 -> 2 -> 4 -> 5


    // -------- Case 2: Max already at end --------
    Node* head2 = NULL;
    head2 = insertEnd(head2, 1);
    head2 = insertEnd(head2, 2);
    head2 = insertEnd(head2, 3);

    head2 = moveMaxToEnd(head2);
    printList(head2);
    // Expected: unchanged


    // -------- Case 3: Max at head --------
    Node* head3 = NULL;
    head3 = insertEnd(head3, 9);
    head3 = insertEnd(head3, 2);
    head3 = insertEnd(head3, 3);

    head3 = moveMaxToEnd(head3);
    printList(head3);
    // Expected: 2 -> 3 -> 9


    // -------- Case 4: Single node --------
    Node* single = createNode(10);
    single = moveMaxToEnd(single);
    printList(single);
    // Expected: 10


    // -------- Case 5: Empty --------
    Node* empty = NULL;
    empty = moveMaxToEnd(empty);
    printList(empty);
    // Expected: NULL
*/
  /*
      // -------- Case 1: Normal list --------
      Node* head = NULL;

      // 3 -> 1 -> 5 -> 2 -> 4
      head = insertEnd(head, 3);
      head = insertEnd(head, 1);
      head = insertEnd(head, 5);
      head = insertEnd(head, 2);
      head = insertEnd(head, 4);

      printf("Original List:\n");
      printList(head);

      head = moveMinToFront(head);

      printf("After moving min to front:\n");
      printList(head);
      // Expected: 1 -> 3 -> 5 -> 2 -> 4


      // -------- Case 2: Min already at head --------
      Node* head2 = NULL;
      head2 = insertEnd(head2, 1);
      head2 = insertEnd(head2, 2);
      head2 = insertEnd(head2, 3);

      head2 = moveMinToFront(head2);
      printList(head2);
      // Expected: unchanged


      // -------- Case 3: Min at end --------
      Node* head3 = NULL;
      head3 = insertEnd(head3, 5);
      head3 = insertEnd(head3, 4);
      head3 = insertEnd(head3, 3);
      head3 = insertEnd(head3, 1);

      head3 = moveMinToFront(head3);
      printList(head3);
      // Expected: 1 -> 5 -> 4 -> 3


      // -------- Case 4: Single node --------
      Node* single = createNode(10);
      single = moveMinToFront(single);
      printList(single);
      // Expected: 10


      // -------- Case 5: Empty --------
      Node* empty = NULL;
      empty = moveMinToFront(empty);
      printList(empty);
      // Expected: NULL
   */
  /*
      // -------- Case 1: Multiple occurrences --------
      Node* head = NULL;

      // 1 -> 2 -> 3 -> 2 -> 4 -> 2 -> 5
      head = insertEnd(head, 1);
      head = insertEnd(head, 2);
      head = insertEnd(head, 3);
      head = insertEnd(head, 2);
      head = insertEnd(head, 4);
      head = insertEnd(head, 2);
      head = insertEnd(head, 5);

      printf("Original:\n");
      printList(head);

      head = deleteAllOccurrences(head, 2);

      printf("After deleting 2:\n");
      printList(head);
      // Expected: 1 -> 3 -> 4 -> 5


      // -------- Case 2: All nodes match --------
      Node* all = NULL;
      all = insertEnd(all, 7);
      all = insertEnd(all, 7);
      all = insertEnd(all, 7);

      all = deleteAllOccurrences(all, 7);
      printList(all);
      // Expected: NULL


      // -------- Case 3: No match --------
      Node* noMatch = NULL;
      noMatch = insertEnd(noMatch, 1);
      noMatch = insertEnd(noMatch, 2);
      noMatch = insertEnd(noMatch, 3);

      noMatch = deleteAllOccurrences(noMatch, 9);
      printList(noMatch);
      // Expected: unchanged


      // -------- Case 4: Key at head --------
      Node* headCase = NULL;
      headCase = insertEnd(headCase, 5);
      headCase = insertEnd(headCase, 5);
      headCase = insertEnd(headCase, 1);
      headCase = insertEnd(headCase, 2);

      headCase = deleteAllOccurrences(headCase, 5);
      printList(headCase);
      // Expected: 1 -> 2


      // -------- Case 5: Single node --------
      Node* single = createNode(10);
      single = deleteAllOccurrences(single, 10);
      printList(single);
      // Expected: NULL
  */
  /*
      // L2: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 70 -> 80
      Node* l2 = NULL;
      for(int i = 1; i <= 8; i++)
          l2 = insertEnd(l2, i * 10);

      printf("L2:\n");
      printList(l2);

      // -------- Case 1 --------
      Node* l1 = NULL;
      l1 = insertEnd(l1, 1);
      l1 = insertEnd(l1, 2);
      l1 = insertEnd(l1, 5);
      l1 = insertEnd(l1, 7);
      l1 = insertEnd(l1, 8);

      printf("Positio    // -------- Case 1 --------
    Node* head = NULL;

    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    for(int i = 1; i <= 7; i++)
        head = insertEnd(head, i);

    printf("Original:\n");
    printList(head);
    // -------- Case 1 --------
    Node* head = NULL;

    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    for(int i = 1; i <= 7; i++)
        head = insertEnd(head, i);

    printf("Original:\n");
    printList(head);

    head = deleteAlternate(head);

    printf("After:\n");
    printList(head);
    // Expected: 1 -> 3 -> 5 -> 7


    // -------- Case 2: Even count --------
    Node* even = NULL;
    for(int i = 1; i <= 6; i++)
        even = insertEnd(even, i);

    even = deleteAlternate(even);
    printList(even);
    // Expected: 1 -> 3 -> 5


    // -------- Case 3: Single --------
    Node* single = createNode(10);
    single = deleteAlternate(single);
    printList(single);
    // Expected: 10


    // -------- Case 4: Empty --------
    Node* empty = NULL;
    empty = deleteAlternate(empty);
    printList(empty);
    // Expected: NULL    // -------- Case 1 --------
    Node* head = NULL;

    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    for(int i = 1; i <= 7; i++)
        head = insertEnd(head, i);

    printf("Original:\n");
    printList(head);

    head = deleteAlternate(head);

    printf("After:\n");
    printList(head);
    // Expected: 1 -> 3 -> 5 -> 7


    // -------- Case 2: Even count --------
    Node* even = NULL;
    for(int i = 1; i <= 6; i++)
        even = insertEnd(even, i);

    even = deleteAlternate(even);
    printList(even);
    // Expected: 1 -> 3 -> 5


    // -------- Case 3: Single --------
    Node* single = createNode(10);
    single = deleteAlternate(single);
    printList(single);
    // Expected: 10


    // -------- Case 4: Empty --------
    Node* empty = NULL;
    empty = deleteAlternate(empty);
    printList(empty);
    // Expected: NULL
    head = deleteAlternate(head);

    printf("After:\n");
    printList(head);
    // Expected: 1 -> 3 -> 5 -> 7


    // -------- Case 2: Even count --------
    Node* even = NULL;
    for(int i = 1; i <= 6; i++)
        even = insertEnd(even, i);

    even = deleteAlternate(even);
    printList(even);
    // Expected: 1 -> 3 -> 5


    // -------- Case 3: Single --------
    Node* single = createNode(10);
    single = deleteAlternate(single);
    printList(single);
    // Expected: 10


    // -------- Case 4: Empty --------
    Node* empty = NULL;
    empty = deleteAlternate(empty);
    printList(empty);
    // Expected: NULLns (L1):\n");
      printList(l1);

      printf("Output:\n");
      printByPositions(l1, l2);
      // Expected: 10 20 50 70 80


      // -------- Case 2: Positions out of range --------
      Node* l1_2 = NULL;
      l1_2 = insertEnd(l1_2, 2);
      l1_2 = insertEnd(l1_2, 10); // out of range
      l1_2 = insertEnd(l1_2, 3);

      printf("Output:\n");
      printByPositions(l1_2, l2);
      // Expected: 20 30


      // -------- Case 3: Empty L1 --------
      Node* empty = NULL;
      printByPositions(empty, l2);
      // Expected: nothing


      // -------- Case 4: Empty L2 --------
      printByPositions(l1, NULL);
      // Expected: nothing
  */
  /*
      // -------- Case 1: Normal list --------
      Node* head = NULL;

      // 1 -> 2 -> 3 -> 4 -> 5
      for(int i = 1; i <= 5; i++)
          head = insertEnd(head, i);

      printf("Original List:\n");
      printList(head);

      head = moveFirstToEnd(head);

      printf("After moving first to end:\n");
      printList(head);
      // Expected: 2 -> 3 -> 4 -> 5 -> 1


      // -------- Case 2: Two nodes --------
      Node* two = NULL;
      two = insertEnd(two, 10);
      two = insertEnd(two, 20);

      two = moveFirstToEnd(two);
      printList(two);
      // Expected: 20 -> 10


      // -------- Case 3: Single node --------
      Node* single = createNode(7);
      single = moveFirstToEnd(single);
      printList(single);
      // Expected: 7


      // -------- Case 4: Empty --------
      Node* empty = NULL;
      empty = moveFirstToEnd(empty);
      printList(empty);
      // Expected: NULL
  */
  /*
      // -------- Case 1: Normal list --------
      Node* head = NULL;

      // 1 -> 2 -> 3 -> 4 -> 5
      for(int i = 1; i <= 5; i++)
          head = insertEnd(head, i);

      printf("Original List:\n");
      printList(head);

      head = moveLastToFront(head);

      printf("After moving last to front:\n");
      printList(head);
      // Expected: 5 -> 1 -> 2 -> 3 -> 4


      // -------- Case 2: Two nodes --------
      Node* two = NULL;
      two = insertEnd(two, 10);
      two = insertEnd(two, 20);

      two = moveLastToFront(two);
      printList(two);
      // Expected: 20 -> 10


      // -------- Case 3: Single node --------
      Node* single = createNode(7);
      single = moveLastToFront(single);
      printList(single);
      // Expected: 7


      // -------- Case 4: Empty --------
      Node* empty = NULL;
      empty = moveLastToFront(empty);
      printList(empty);
      // Expected: NULL
  */
  /*
      // -------- Case 1 --------
      Node* head = NULL;

      // 1 -> 2 -> 3 -> 4 -> 5
      for(int i = 1; i <= 5; i++)
          head = insertEnd(head, i);

      printf("Original:\n");
      printList(head);

      head = moveNodeForward(head, 4, 2);

      printf("After move:\n");
      printList(head);
      // Expected: 1 -> 4 -> 2 -> 3 -> 5


      // -------- Case 2: Move beyond head --------
      head = moveNodeForward(head, 3, 5);
      printList(head);
      // Expected: node moves to head


      // -------- Case 3: n = 0 --------
      head = moveNodeForward(head, 2, 0);
      printList(head);
      // Expected: unchanged


      // -------- Case 4: Invalid position --------
      head = moveNodeForward(head, 10, 2);
      printList(head);
      // Expected: unchanged


      // -------- Case 5: Single node --------
      Node* single = createNode(10);
      single = moveNodeForward(single, 1, 3);
      printList(single);
      // Expected: 10
  */
  /*
      Node* head = NULL;

      // 1 -> 2 -> 3 -> 4 -> 5
      for(int i = 1; i <= 5; i++)
          head = insertEnd(head, i);

      printf("Original:\n");
      printList(head);

      // Suppose we want to delete node with value 3
      Node* temp = head->next->next; // node with data = 3

      deleteNode(temp);

      printf("After deleting node 3:\n");
      printList(head);
      // Expected: 1 -> 2 -> 4 -> 5
  */
  /*
      Node* head = NULL;

      // 1 -> 2 -> 3 -> 4
      for(int i = 1; i <= 4; i++)
          head = insertEnd(head, i);

      printf("Original:\n");
      printList(head);

      Node* p = head->next->next; // node with value 3

      insertAfter(p, 99);
      printf("After insertAfter (3):\n");
      printList(head);
      // Expected: 1 -> 2 -> 3 -> 99 -> 4

      insertBefore(p, 77);
      printf("After insertBefore (3):\n");
      printList(head);
      // Expected: 1 -> 2 -> 77 -> 3 -> 99 -> 4
  */
  /*
      // -------- Case 1: Normal list --------
      Node* head = NULL;

      // 1 -> 2 -> 3 -> 4 -> 5
      for(int i = 1; i <= 5; i++)
          head = insertEnd(head, i);

      printf("Before destroy:\n");
      printList(head);

      head = destroy(head);

      printf("After destroy:\n");
      printList(head);
      // Expected: NULL


      // -------- Case 2: Already empty --------
      Node* empty = NULL;
      empty = destroy(empty);
      printList(empty);
      // Expected: NULL
  */
  /*
          // -------- Case 1 --------
      Node* head = NULL;

      // 1 -> 1 -> 2 -> 3 -> 3 -> 3 -> 4 -> 5 -> 5
      head = insertEnd(head, 1);
      head = insertEnd(head, 1);
      head = insertEnd(head, 2);
      head = insertEnd(head, 3);
      head = insertEnd(head, 3);
      head = insertEnd(head, 3);
      head = insertEnd(head, 4);
      head = insertEnd(head, 5);
      head = insertEnd(head, 5);

      printf("Before:\n");
      printList(head);

      head = removeDuplicates(head);

      printf("After:\n");
      printList(head);
      // Expected: 1 -> 2 -> 3 -> 4 -> 5


      // -------- Case 2: All same --------
      Node* same = NULL;
      same = insertEnd(same, 7);
      same = insertEnd(same, 7);
      same = insertEnd(same, 7);

      same = removeDuplicates(same);
      printList(same);
      // Expected: 7


      // -------- Case 3: No duplicates --------
      Node* unique = NULL;
      unique = insertEnd(unique, 1);
      unique = insertEnd(unique, 2);
      unique = insertEnd(unique, 3);

      unique = removeDuplicates(unique);
      printList(unique);
      // Expected: unchanged


      // -------- Case 4: Single node --------
      Node* single = createNode(10);
      single = removeDuplicates(single);
      printList(single);
      // Expected: 10


      // -------- Case 5: Empty --------
      Node* empty = NULL;
      empty = removeDuplicates(empty);
      printList(empty);
      // Expected: NULL
  */
  /*
      // -------- Case 1 --------
      Node* head = NULL;

      // 1 -> 3 -> 2 -> 3 -> 4 -> 1 -> 5 -> 2
      head = insertEnd(head, 1);
      head = insertEnd(head, 3);
      head = insertEnd(head, 2);
      head = insertEnd(head, 3);
      head = insertEnd(head, 4);
      head = insertEnd(head, 1);
      head = insertEnd(head, 5);
      head = insertEnd(head, 2);

      printf("Before:\n");
      printList(head);

      head = removeDuplicatesUnsorted(head);

      printf("After:\n");
      printList(head);
      // Expected: 1 -> 3 -> 2 -> 4 -> 5


      // -------- Case 2: All same --------
      Node* same = NULL;
      same = insertEnd(same, 7);
      same = insertEnd(same, 7);
      same = insertEnd(same, 7);

      same = removeDuplicatesUnsorted(same);
      printList(same);
      // Expected: 7


      // -------- Case 3: No duplicates --------
      Node* unique = NULL;
      unique = insertEnd(unique, 1);
      unique = insertEnd(unique, 2);
      unique = insertEnd(unique, 3);

      unique = removeDuplicatesUnsorted(unique);
      printList(unique);
      // Expected: unchanged


      // -------- Case 4: Single --------
      Node* single = createNode(10);
      single = removeDuplicatesUnsorted(single);
      printList(single);
      // Expected: 10
  */
  /*
          // -------- Case 1 --------
      Node* l1 = NULL;
      Node* l2 = NULL;

      // l1: 1 -> 2 -> 3 -> 4 -> 5
      for(int i = 1; i <= 5; i++)
          l1 = insertEnd(l1, i);

      // l2: 3 -> 4 -> 5 -> 6 -> 7
      l2 = insertEnd(l2, 3);
      l2 = insertEnd(l2, 4);
      l2 = insertEnd(l2, 5);
      l2 = insertEnd(l2, 6);
      l2 = insertEnd(l2, 7);

      printf("L1:\n");
      printList(l1);
      printf("L2:\n");
      printList(l2);

      Node* inter = intersectionList(l1, l2);

      printf("Intersection:\n");
      printList(inter);
      // Expected: 3 -> 4 -> 5


      // -------- Case 2: No common --------
      Node* a = NULL;
      Node* b = NULL;

      a = insertEnd(a, 1);
      a = insertEnd(a, 2);

      b = insertEnd(b, 3);
      b = insertEnd(b, 4);

      Node* res = intersectionList(a, b);
      printList(res);
      // Expected: NULL


      // -------- Case 3: With duplicates --------
      Node* d1 = NULL;
      Node* d2 = NULL;

      // d1: 1 -> 2 -> 2 -> 3
      d1 = insertEnd(d1, 1);
      d1 = insertEnd(d1, 2);
      d1 = insertEnd(d1, 2);
      d1 = insertEnd(d1, 3);

      // d2: 2 -> 2 -> 4
      d2 = insertEnd(d2, 2);
      d2 = insertEnd(d2, 2);
      d2 = insertEnd(d2, 4);

      Node* res2 = intersectionList(d1, d2);
      printList(res2);
      // Expected: depends (usually 2 -> 2 OR just 2)
  */
  /*
    // -------- Case 1 --------
    Node *l1 = NULL;
    Node *l2 = NULL;

    // l1: 1 -> 2 -> 3 -> 4
    for (int i = 1; i <= 4; i++)
      l1 = insertEnd(l1, i);

    // l2: 3 -> 4 -> 5 -> 6
    l2 = insertEnd(l2, 3);
    l2 = insertEnd(l2, 4);
    l2 = insertEnd(l2, 5);
    l2 = insertEnd(l2, 6);

    printf("L1:\n");
    printList(l1);
    printf("L2:\n");
    printList(l2);

    Node *uni = unionList(l1, l2);

    printf("Union:\n");
    printList(uni);
    // Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6

    // -------- Case 2: No overlap --------
    Node *a = NULL;
    Node *b = NULL;

    a = insertEnd(a, 1);
    a = insertEnd(a, 2);

    b = insertEnd(b, 3);
    b = insertEnd(b, 4);

    Node *res = unionList(a, b);
    printList(res);
    // Expected: 1 -> 2 -> 3 -> 4

    // -------- Case 3: With duplicates --------
    Node *d1 = NULL;
    Node *d2 = NULL;

    // d1: 1 -> 2 -> 2 -> 3
    d1 = insertEnd(d1, 1);
    d1 = insertEnd(d1, 2);
    d1 = insertEnd(d1, 2);
    d1 = insertEnd(d1, 3);

    // d2: 2 -> 3 -> 3 -> 4
    d2 = insertEnd(d2, 2);
    d2 = insertEnd(d2, 3);
    d2 = insertEnd(d2, 3);
    d2 = insertEnd(d2, 4);

    Node *res2 = unionList(d1, d2);
    printList(res2);
    // Expected: 1 -> 2 -> 3 -> 4
  */
  /*
    Node *l1 = NULL;

    // 3 -> -1 -> 5 -> -2 -> 0 -> 4 -> -3
    l1 = insertEnd(l1, 3);
    l1 = insertEnd(l1, -1);
    l1 = insertEnd(l1, 5);
    l1 = insertEnd(l1, -2);
    l1 = insertEnd(l1, 0);
    l1 = insertEnd(l1, 4);
    l1 = insertEnd(l1, -3);

    Node *l2 = NULL, *l3 = NULL;

    printf("Original L1:\n");
    printList(l1);

    splitList(l1, &l2, &l3);

    printf("Negative (L2):\n");
    printList(l2);
    // Expected: -1 -> -2 -> -3

    printf("Positive (L3):\n");
    printList(l3);
    // Expected: 3 -> 5 -> 4 (depending on definition, 0 handling)
  */
/*
  Node *l1 = NULL;

  // 1 -> 2 -> 3 -> 4 -> 5 -> 6
  for (int i = 1; i <= 6; i++)
    l1 = insertEnd(l1, i);

  Node *l2 = NULL, *l3 = NULL;

  printf("Original L1:\n");
  printList(l1);

  splitEvenOdd(l1, &l2, &l3);

  printf("Even (L2):\n");
  printList(l2);
  // Expected: 2 -> 4 -> 6

  printf("Odd (L3):\n");
  printList(l3);
  // Expected: 1 -> 3 -> 5

  printf("Original again (should be unchanged):\n");
  printList(l1);
*/

	     // -------- Case 1 --------
    Node* head = NULL;

    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    for(int i = 1; i <= 7; i++)
        head = insertEnd(head, i);

    printf("Original:\n");
    printList(head);

    head = deleteAlternate(head);

    printf("After:\n");
    printList(head);
    // Expected: 1 -> 3 -> 5 -> 7


    // -------- Case 2: Even count --------
    Node* even = NULL;
    for(int i = 1; i <= 6; i++)
        even = insertEnd(even, i);

    even = deleteAlternate(even);
    printList(even);
    // Expected: 1 -> 3 -> 5


    // -------- Case 3: Single --------
    Node* single = createNode(10);
    single = deleteAlternate(single);
    printList(single);
    // Expected: 10


    // -------- Case 4: Empty --------
    Node* empty = NULL;
    empty = deleteAlternate(empty);
    printList(empty);
    // Expected: NULL 

  return 0;
}
