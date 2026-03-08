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


int main()
{
    struct bstNode *rootTreeNode = NULL;
    
    rootTreeNode = insertNode(rootTreeNode, 15);
    rootTreeNode = insertNode(rootTreeNode, 10);
    rootTreeNode = insertNode(rootTreeNode, 20);
    rootTreeNode = insertNode(rootTreeNode, 25);
    rootTreeNode = insertNode(rootTreeNode, 8);
    rootTreeNode = insertNode(rootTreeNode, 12);
    
    displayBST(rootTreeNode);

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
        return true;;
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
