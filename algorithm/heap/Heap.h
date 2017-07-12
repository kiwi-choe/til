#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct HeapNode 
{
	ElementType Data;
} HeapNode;

typedef struct Heap
{
	HeapNode* Nodes;
	int Capacity;
	int UsedSize;
} Heap;

Heap* createHeap(int initialSize);
void destroyHeap(Heap* h);
void insert(Heap* h, ElementType newData);
void deleteMin(Heap* h, HeapNode* root);

int getParent(int index);
int getLeftChild(int index);
void swapNodes(Heap* h, int index1, int index2);
void printNodes(Heap* h);

#endif