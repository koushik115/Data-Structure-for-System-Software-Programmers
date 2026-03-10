#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

struct bstNode {
  int data;
  struct bstNode *lchildNode;
  struct bstNode *rchildNode;
};

static inline struct bstNode *createNewNode(int data);
struct bstNode *insertNode(struct bstNode *root, int data);
bool isNodePresent(struct bstNode *root, int data);
struct bstNode *deleteNode(struct bstNode *root, int data);
void displayBST(struct bstNode *root);
int findMinimum(struct bstNode *root, int *minimum);
int findMaximum(struct bstNode *root, int *maximum);
int findHeight(struct bstNode *root);

int queueFront = -1, queueRear = -1;
struct bstNode *queueArray[QUEUE_SIZE];
int enqueue(struct bstNode *node);
int dequeue(struct bstNode *node);
int isQueueFull(void);
int isQueueEmpty(void);
struct bstNode *getTopQueue(void);
void levelOrderTraversal(struct bstNode *root);
void preOrderTraversal(struct bstNode *root);
void inOrderTraversal(struct bstNode *root);
void postOrderTraversal(struct bstNode *root);

int main() {
  struct bstNode *rootTreeNode = NULL;
  int minimum = -1, maximum = -1;

  rootTreeNode = insertNode(rootTreeNode, 15);
  rootTreeNode = insertNode(rootTreeNode, 10);
  rootTreeNode = insertNode(rootTreeNode, 20);
  rootTreeNode = insertNode(rootTreeNode, 25);
  rootTreeNode = insertNode(rootTreeNode, 8);
  rootTreeNode = insertNode(rootTreeNode, 12);

  displayBST(rootTreeNode);
  printf("\n\n");

  levelOrderTraversal(rootTreeNode);
  printf("\n\n");
  preOrderTraversal(rootTreeNode);
  printf("\n\n");
  inOrderTraversal(rootTreeNode);
  printf("\n\n");
  postOrderTraversal(rootTreeNode);
  printf("\n\n");
  /*
  if(findMinimum(rootTreeNode, &minimum)) {
          printf("Minimum element in the tree is %d\n", minimum);
  } else {
          printf("error: empty tree!\n");
  }

  if(findMaximum(rootTreeNode, &maximum)) {
          printf("Maximum element in the tree is %d\n", maximum);
  } else {
          printf("error: empty tree!\n");
  }

  printf("Height of the tree is %d\n", findHeight(rootTreeNode));
  */

  return 0;
}

static inline struct bstNode *createNewNode(int data) {
  struct bstNode *rootNode = (struct bstNode *)malloc(sizeof(struct bstNode));
  if (rootNode == NULL)
    return NULL;
  rootNode->data = data;
  rootNode->lchildNode = rootNode->rchildNode = NULL;
  return rootNode;
}

struct bstNode *insertNode(struct bstNode *root, int data) {
  if (root == NULL) {
    root = createNewNode(data);
  } else if (root->data >= data) {
    root->lchildNode = insertNode(root->lchildNode, data);
  } else {
    root->rchildNode = insertNode(root->rchildNode, data);
  }

  return root;
}

bool isNodePresent(struct bstNode *root, int data) {
  if (root == NULL) {
    return false;
  } else if (root->data == data) {
    return true;
  } else if (root->data > data) {
    return isNodePresent(root->lchildNode, data);
  } else {
    return isNodePresent(root->rchildNode, data);
  }
}

void displayBST(struct bstNode *root) {
  if (root == NULL) {
    return;
  }

  displayBST(root->lchildNode);

  printf("%d\t", root->data);

  displayBST(root->rchildNode);
}

int findMinimum(struct bstNode *root, int *minimum) {
  if (root == NULL) {
    return 0;
  } else if (root->lchildNode == NULL) {
    *minimum = root->data;
    return 1;
  }

  return findMinimum(root->lchildNode, minimum);
}

int findMaximum(struct bstNode *root, int *maximum) {
  if (root == NULL) {
    return 0;
  } else if (root->rchildNode == NULL) {
    *maximum = root->data;
    return 1;
  }

  return findMaximum(root->rchildNode, maximum);
}

/*
int findMinimum(struct bstNode *root) {
        if(root == NULL) {
                return -1;
        }

        while(root->lchildNode != NULL)
                root = root->lchildNode;

        return root->data;
}

int findMaximum(struct bstNode *root) {
        if(root == NULL) {
                return 0;
        }

        while(root->rchildNode != NULL)
                root = root->rchildNode;

        return root->data;
}
*/

int findHeight(struct bstNode *root) {
  if (root == NULL)
    return -1;

  int lHeight = findHeight(root->lchildNode);
  int rHeight = findHeight(root->rchildNode);

  return 1 + (lHeight > rHeight ? lHeight : rHeight);
}

int isQueueFull(void) { return (queueFront == ((queueRear + 1) % QUEUE_SIZE)); }

int isQueueEmpty(void) { return (queueFront == -1 && queueRear == -1); }

struct bstNode *getTopQueue(void) {
  if (isQueueEmpty()) {
    return NULL;
  } else {
    return queueArray[queueFront];
  }
}

int enqueue(struct bstNode *node) {
  if (isQueueFull()) {
    return 0;
  } else if (isQueueEmpty()) {
    queueFront = queueRear = 0;
  } else {
    queueRear = (queueRear + 1) % QUEUE_SIZE;
  }

  queueArray[queueRear] = node;

  return 1;
}

int dequeue(struct bstNode *node) {
  if (isQueueEmpty()) {
    return 0;
  } else if (queueFront == queueRear) {
    node = queueArray[queueFront];
    queueFront = queueRear = -1;
  } else {
    node = queueArray[queueFront];
    queueFront = (queueFront + 1) % QUEUE_SIZE;
  }

  return 1;
}

void levelOrderTraversal(struct bstNode *root) {
  if (root == NULL)
    return;
  if (!enqueue(root)) {
    printf("error: in queuing the root!\nexiting...");
    return;
  }

  while (!isQueueEmpty()) {
    struct bstNode *currentNode = getTopQueue();
    printf("%d\t", currentNode->data);

    if (currentNode->lchildNode != NULL) {
      enqueue(currentNode->lchildNode);
    }

    if (currentNode->rchildNode != NULL) {
      enqueue(currentNode->rchildNode);
    }

    if (!dequeue(currentNode)) {
      printf("error: in dequeuing the root!\nexiting...");
      return;
    }
  }
}

void preOrderTraversal(struct bstNode *root) {
  if (root == NULL)
    return;

  printf("%d\t", root->data);
  preOrderTraversal(root->lchildNode);
  preOrderTraversal(root->rchildNode);
}

void inOrderTraversal(struct bstNode *root) {
  if (root == NULL)
    return;

  inOrderTraversal(root->lchildNode);
  printf("%d\t", root->data);
  inOrderTraversal(root->rchildNode);
}

void postOrderTraversal(struct bstNode *root) {
  if (root == NULL)
    return;

  postOrderTraversal(root->lchildNode);
  postOrderTraversal(root->rchildNode);
  printf("%d\t", root->data);
}
