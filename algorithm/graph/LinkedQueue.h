#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "Graph.h"
#include <string.h>

typedef struct Node 
{
	Vertex* Data;
	struct Node* NextNode;
} Node;

typedef struct LinkedQueue
{
	Node* Front;
	Node* Rear;
	int Count;
} LinkedQueue;

LinkedQueue* createQueue();
void destroyQueue(LinkedQueue* queue);

Node* createNode(Vertex* Data);
void destroyNode(Node* node);

void enqueue(LinkedQueue** queue, Node* node);
Node* dequeue(LinkedQueue** queue);
int isEmpty(LinkedQueue* queue);

#endif