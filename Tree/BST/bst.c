#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int main()
{
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

    return 0;
}

static inline struct bstNode *createNewNode(int data) {
    struct bstNode *rootNode = (struct bstNode *)malloc(sizeof(struct bstNode));
    if(rootNode == NULL) return NULL;
    rootNode->data = data;
    rootNode->lchildNode = rootNode->rchildNode = NULL;
    return rootNode;
}

struct bstNode *insertNode(struct bstNode *root, int data) {
    if(root == NULL) {
        root = createNewNode(data);
    } else if(root->data >= data) {
        root->lchildNode = insertNode(root->lchildNode, data);
    } else {
        root->rchildNode = insertNode(root->rchildNode, data);
    }
    
    return root;
}

bool isNodePresent(struct bstNode *root, int data) {
    if(root == NULL) {
        return false;
    } else if(root->data == data) {
        return true;
    } else if(root->data > data) {
        return isNodePresent(root->lchildNode, data);
    } else {
        return isNodePresent(root->rchildNode, data);
    }
}


void displayBST(struct bstNode *root) {
    if(root == NULL) {
        return;
    }
    
    displayBST(root->lchildNode);
    
    printf("%d\t", root->data);
    
    displayBST(root->rchildNode);
    
}

int findMinimum(struct bstNode *root, int *minimum) {
	if(root == NULL) {
		return 0;
	} else if(root->lchildNode == NULL) {
		*minimum = root->data;
		return 1;
	}

	return findMinimum(root->lchildNode, minimum);
}

int findMaximum(struct bstNode *root, int *maximum) {
	if(root == NULL) {
		return 0;
	} else if(root->rchildNode == NULL) {
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
	if(root == NULL)
		return -1;

	int lHeight = findHeight(root->lchildNode);
	int rHeight = findHeight(root->rchildNode);

	return 1 + (lHeight > rHeight ? lHeight : rHeight);
}
