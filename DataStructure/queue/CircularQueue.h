#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node
{
	ElementType Data;
} Node;

typedef struct Queue
{
	int Capacity;
	int Front;
	int Rear;
	Node* Nodes;
} Queue;

void create(Queue** queue, int capacity);
void destroyQueue(Queue* queue);
void enqueue(Queue* queue, ElementType data);
ElementType dequeue(Queue* queue);
int getSize(Queue* queue);
int isEmpty(Queue* queue);
int isFull(Queue* queue);

#endif