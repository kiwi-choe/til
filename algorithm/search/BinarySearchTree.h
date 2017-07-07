#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node
{
	struct Node* Left;
	struct Node* Right;

	ElementType Data;
} Node;

Node* createNode(ElementType newData);
void destroyNode(Node* node);
void destroyTree(Node* tree);

Node* searchNode(Node* tree, ElementType target);
Node* searchMinNode(Node* tree);
void insertNode(Node* tree, Node* child);
Node* removeNode(Node* tree, Node* parent, ElementType target);

void inorderPrintTree(Node* node);

#endif