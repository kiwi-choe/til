#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int PriorityType;
typedef struct PQNode
{
	PriorityType Priority;
	void* Data;
} PQNode;

typedef struct PriorityQueue
{
	PQNode* Nodes;
	int Capacity;
	int UsedSize;
} PQueue;

PQueue* createQueue(int initialSize);
void destroyQueue(PQueue* pq);
void enqueue(PQueue* pq, PQNode newData);
void dequeue(PQueue* pq, PQNode* root);

int getParent(int index);
int getLeftChild(int index);
void swapNodes(PQueue* pq, int index1, int index2);
int isEmpty(PQueue* pq);

#endif