#include "LinkedQueue.h"

LinkedQueue* createQueue()
{
	LinkedQueue* q = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	q->Front = NULL;
	q->Rear = NULL;
	q->Count = 0;

	return q;
}

void destroyQueue(LinkedQueue* queue)
{
	while(!isEmpty(queue))
	{
		destroyNode(dequeue(&queue));
	}
	free(queue);
}

Node* createNode(Vertex* data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->Data = data;
	newNode->NextNode = NULL;

	return newNode;
}

void destroyNode(Node* node)
{
	free(node->Data);
	free(node);
}

void enqueue(LinkedQueue** queue, Node* newNode)
{
	if((*queue)->Front == NULL)
	{
		(*queue)->Front = newNode;
		(*queue)->Rear = newNode;
	}
	else
	{
		(*queue)->Rear->NextNode = newNode;
		(*queue)->Rear = newNode;
	}
	(*queue)->Count++;
}

Node* dequeue(LinkedQueue** queue)
{
	// Save old front 
	Node* oldFront = (*queue)->Front;
	// set new front
	if((*queue)->Front->NextNode == NULL)
	{
		(*queue)->Front = NULL;
		(*queue)->Rear = NULL;
	}
	else
	{
		(*queue)->Front = oldFront->NextNode;	
	}
	(*queue)->Count--;

	return oldFront;
}

int isEmpty(LinkedQueue* queue)
{
	// return (queue->Count == 0);
	return (queue->Front == NULL);
}