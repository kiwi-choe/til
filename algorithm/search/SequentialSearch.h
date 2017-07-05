#ifndef SEQUENTIAL_SEARCH_H
#define SEQUENTIAL_SEARCH_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node
{
	ElementType Data;
	struct Node* Next;
} Node;

// LinkedList for Sequential search
Node* createNode(ElementType data);
void destroyNode(Node* node);
void removeNode(Node** head, Node* remove);
void appendNode(Node** head, Node* newNode);
Node* getNodeAt(Node* head, int location);
int getNodeCount(Node* head);

// Sequential search
Node* sequentialSearch(Node* head, int targetData);
// Self Organizing Sequential Search
Node* moveToFront(Node** head, int targetData);
Node* transpose(Node** head, int targetData);

#endif