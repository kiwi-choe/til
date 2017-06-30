#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node
{
	struct Node* Left;
	struct Node* Right;
	ElementType Data;
} Node;

Node* createNode(ElementType newData);
void destroyNode(Node* node);

void preorderPrintTree(Node* node);
void inorderPrintTree(Node* node);
void postorderPrintTree(Node* node);

void destroyTree(Node* root);

#endif