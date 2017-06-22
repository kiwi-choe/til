#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node 
{
	char* Data;
	struct Node* NextNode;
} Node;

typedef struct Stack
{
	Node* List;
	Node* Top;
} Stack;

void createStack(Stack** stack);
void destroyStack(Stack* stack);

Node* createNode(char* data);
void destroyNode(Node* node);

void push(Stack* stack, Node* newNode);
Node* pop(Stack* stack);

Node* top(Stack* stack);
int getSize(Stack* stack);
int isEmpty(Stack* stack);

#endif