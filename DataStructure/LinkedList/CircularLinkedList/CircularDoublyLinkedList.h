#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
	struct tagNode* PreNode;
	struct tagNode* NextNode;
} Node;

Node* create(ElementType data);
void destroyNode(Node* node);
void append(Node** head, Node* newnode);
void insertAfter(Node* current, Node* newnode);
void removeNode(Node** head, Node* remove);
Node* getNodeAt(Node* head, int location);
int getNodeCount(Node* head);
void printNode(Node* node);

#endif