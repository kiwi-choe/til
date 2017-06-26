#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node 
{
	char* Data;
	struct Node* NextNode;
} Node;

typedef struct LinkedQueue
{
	Node* Front;
	Node* Rear;
	int Count;
} LinkedQueue;

void createQueue(LinkedQueue** queue);
void destroyQueue(LinkedQueue* queue);

Node* createNode(char* Data);
void destroyNode(Node* node);

void enqueue(LinkedQueue* queue, Node* node);
Node* dequeue(LinkedQueue* queue);
int isEmpty(LinkedQueue* queue);

#endif