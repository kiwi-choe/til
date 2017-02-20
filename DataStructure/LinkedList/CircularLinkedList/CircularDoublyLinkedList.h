#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType data;
	struct tagNode* prev;
	struct tagNode* next;
} Node;

Node* createNode(ElementType data);
void destroyNode(Node* node);
void appendNode(Node** head, Node* newnode);
void insertAfter(Node* current, Node* newnode);
void removeNode(Node** head, Node* remove);
Node* getNodeAt(Node* head, int location);
int getNodeCount(Node* head);
void printNode(Node* node);

#endif