#include "PriorityQueue.h"

PQueue* createQueue(int initialSize)
{
	PQueue* newPQ = (PQueue*)malloc(sizeof(PQueue));
	newPQ->Capacity = initialSize;
	newPQ->UsedSize = 0;
	newPQ->Nodes = (PQNode*)malloc(sizeof(PQNode)*newPQ->Capacity);

	return newPQ;
}

void destroyQueue(PQueue* pq)
{
	free(pq->Nodes);
	free(pq);
}

void enqueue(PQueue* pq, PQNode newNode)
{
	int currentPosition = pq->UsedSize;
	int parentPosition = getParent(currentPosition);

	if(pq->UsedSize == pq->Capacity)
	{
		if(pq->Capacity == 0)
			pq->Capacity = 1;

		pq->Capacity *= 2;
		pq->Nodes = (PQNode*)realloc(pq->Nodes, sizeof(PQNode)*pq->Capacity);
	}
	pq->Nodes[currentPosition] = newNode;

	while(currentPosition > 0
		&& pq->Nodes[currentPosition].Priority < pq->Nodes[parentPosition].Priority)
	{
		swapNodes(pq, currentPosition, parentPosition);
		currentPosition = parentPosition;
		parentPosition = getParent(currentPosition);
	}
	pq->UsedSize++;
}

void dequeue(PQueue* pq, PQNode* root)
{
	int parentPosition = 0;
	int leftPosition = 0;
	int rightPosition = 0;

	memcpy(root, &pq->Nodes[0], sizeof(PQNode));
	memset(&pq->Nodes[0], 0, sizeof(PQNode));
	pq->UsedSize--;
	swapNodes(pq, 0, pq->UsedSize);

	leftPosition = getLeftChild(0);
	rightPosition = leftPosition+1;

	while(1)
	{
		int selectedChild = 0;

		if(leftPosition >= pq->UsedSize)
			break;

		if(rightPosition >= pq->UsedSize)
		{
			selectedChild = leftPosition;
		}
		else
		{
			if(pq->Nodes[leftPosition].Priority > pq->Nodes[rightPosition].Priority)
				selectedChild = rightPosition;
			else
				selectedChild = leftPosition;
		}

		if(pq->Nodes[selectedChild].Priority < pq->Nodes[parentPosition].Priority)
		{
			swapNodes(pq, parentPosition, selectedChild);
			parentPosition = selectedChild;
		}
		else
			break;

		leftPosition = getLeftChild(parentPosition);
		rightPosition = leftPosition+1;
	}

	if(pq->UsedSize < (pq->Capacity / 2))
	{
		pq->Capacity /= 2;
		pq->Nodes =
		(PQNode*)realloc(pq->Nodes, sizeof(PQNode)*pq->Capacity);
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

void swapNodes(PQueue* pq, int index1, int index2)
{
	int copySize = sizeof(PQNode);
	PQNode* temp = (PQNode*)malloc(sizeof(copySize));

	memcpy(temp, &pq->Nodes[index1], copySize);
	memcpy(&pq->Nodes[index1], &pq->Nodes[index2], copySize);
	memcpy(&pq->Nodes[index2], temp, copySize);

	free(temp);
}

int isEmpty(PQueue* pq)
{
	return (pq->UsedSize == 0);
}