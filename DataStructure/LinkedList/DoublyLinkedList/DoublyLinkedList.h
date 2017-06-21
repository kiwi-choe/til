#ifndef	DOUBLE_LINKEDLIST_H
#define DOUBLE_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node
{
	ElementType Data;
	struct Node* PreNode;
	struct Node* NextNode;
} Node;

Node* create(ElementType newData);
void destroy(Node* node);
void append(Node** head, Node* newNode);
void insertAfter(Node* current, Node* newNode);
void removeNode(Node** head, Node* remove);
Node* getNodeAt(Node* head, int location);
int getNodeCount(Node* head);

#endif