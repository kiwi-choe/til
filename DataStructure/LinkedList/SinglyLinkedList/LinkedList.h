#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node 
{
	ElementType Data;
	struct Node* Next;
} Node;

Node* create(ElementType newData);
void destroyNode(Node* node);
void insertAfter(Node* current, Node* newNode);
Node* getNodeAt(Node* head, int location);
int getNodeCount(Node* head);

void append(Node** head, Node* newnode);
void insertNewHead(Node** head, Node* newHead);
void removeNode(Node** head, Node* remove);

void insertBefore(Node** head, Node* current, Node* newHead);
void destroyAllNodes(Node** list);

#endif