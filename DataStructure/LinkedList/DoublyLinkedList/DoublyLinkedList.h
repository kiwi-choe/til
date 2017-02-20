#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType data;
	struct tagNode* preNode;
	struct tagNode* nextNode;
} Node;

Node* createNode(ElementType newData);
void destroyNode(Node* node);
void appendNode(Node** head, Node* newnode);
void insertAfter(Node* current, Node* newnode);
void removeNode(Node** head, Node* remove);
Node* getNodeAt(Node* head, int location);
int getNodeCount(Node* head);

#endif