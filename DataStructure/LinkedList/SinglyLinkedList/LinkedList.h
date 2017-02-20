#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
} Node;

// Definition functions
Node*	createNode(ElementType newData);
void	destroyNode(Node* node);
void	appendNode(Node** head, Node* newnode);	 
void	insertAfter(Node* current, Node* newnode);
void	insertNewHead(Node** head, Node* newhead);
void	removeNode(Node** head, Node* remove);
Node*	getNodeAt(Node* head, int location);
int 	getNodeCount(Node* head);

#endif