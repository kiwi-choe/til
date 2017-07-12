#include "Heap.h"

Heap* createHeap(int initialSize)
{
	Heap* newHeap = (Heap*)malloc(sizeof(Heap));
	newHeap->Capacity = initialSize;
	newHeap->UsedSize = 0;
	newHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode)*newHeap->Capacity);

	printf("size: %ld\n", sizeof(HeapNode));

	return newHeap;
}

void destroyHeap(Heap* h)
{
	free(h->Nodes);
	free(h);
}

void insert(Heap* h, ElementType newData)
{
	int currentPosition = h->UsedSize;
	int parentPosition = getParent(currentPosition);

	if(h->UsedSize == h->Capacity)
	{
		h->Capacity *= 2;
		h->Nodes = (HeapNode*)realloc(h->Nodes, sizeof(HeapNode)*h->Capacity);
	}
	h->Nodes[currentPosition].Data = newData;

	while(currentPosition>0 
		&& h->Nodes[currentPosition].Data < h->Nodes[parentPosition].Data)
	{
		swapNodes(h, currentPosition, parentPosition);

		currentPosition = parentPosition;
		parentPosition = getParent(currentPosition);
	}
	h->UsedSize++;
}

void deleteMin(Heap* h, HeapNode* root)
{
	int parentPosition = 0;
	int leftPosition = 0;
	int rightPosition = 0;

	memcpy(root, &h->Nodes[0], sizeof(HeapNode));
	// initialize root node(nodes[0])
	memset(&h->Nodes[0], 0, sizeof(HeapNode));
	h->UsedSize--;
	swapNodes(h, 0, h->UsedSize);

	leftPosition = getLeftChild(0);
	rightPosition = leftPosition+1;

	while(1)
	{
		int selectedChild = 0;
		
		if(leftPosition >= h->UsedSize)
			break;

		// ????
		if(rightPosition >= h->UsedSize)
		{
			 selectedChild = leftPosition;
		}
		else
		{
			if(h->Nodes[leftPosition].Data > h->Nodes[rightPosition].Data)
				selectedChild = rightPosition;
			else
				selectedChild = leftPosition;
		}

		if(h->Nodes[selectedChild].Data < h->Nodes[parentPosition].Data)
		{
			swapNodes(h, parentPosition, selectedChild);
			parentPosition = selectedChild;
		}
		else
			break;

		leftPosition = getLeftChild(parentPosition);
		rightPosition = leftPosition + 1;
	}

	if(h->UsedSize < (h->Capacity /2))
	{
		h->Capacity /= 2;
		h->Nodes = 
		(HeapNode*) realloc(h->Nodes, sizeof(HeapNode)*h->Capacity);
	}
}

int getParent(int index)
{
	return (int)((index-1)/2);
}

int getLeftChild(int index)
{
	return (2*index)+1;
}

void swapNodes(Heap* h, int index1, int index2)
{
	int copySize = sizeof(HeapNode);
	HeapNode* temp = (HeapNode*)malloc(copySize);

	memcpy(temp, &h->Nodes[index1], copySize);
	memcpy(&h->Nodes[index1], &h->Nodes[index2], copySize);
	memcpy(&h->Nodes[index2], temp, copySize);

	free(temp);
}

void printNodes(Heap* h)
{
	int i =0;
	for(i=0;i<h->UsedSize;i++)
	{
		printf("%d ", h->Nodes[i].Data);
	}
	printf("\n");
}