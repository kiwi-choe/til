#include "CircularQueue.h"

void create(Queue** queue, int capacity)
{
	(*queue)  = (Queue*)malloc(sizeof(Queue));

	(*queue)->Nodes = (Node*)malloc(sizeof(Node) * (capacity+1));
	(*queue)->Capacity = capacity;
	(*queue)->Front = 0;
	(*queue)->Rear = 0;
}

void destroyQueue(Queue* queue)
{
	free(queue->Nodes);
	free(queue);
}

void enqueue(Queue* queue, ElementType data)
{
	int position = 0;
	// isEmpty
	if(queue->Rear == queue->Capacity+1)
	{
		queue->Rear = 0;
		position = 0;
	} 
	else 
	{
		position= queue->Rear++;
	}
	queue->Nodes[position].Data = data;
}

ElementType dequeue(Queue* queue)
{
	int position = queue->Front;
	if(queue->Front == queue->Capacity)
	{
		queue->Front = 0;
	}
	else
	{
		queue->Front++;
	}
	return queue->Nodes[position].Data;
}

int getSize(Queue* queue)
{
	return queue->Capacity-1;
}

int isEmpty(Queue* queue)
{
	return (queue->Front == queue->Rear);
}

int isFull(Queue* queue)
{
	if(queue->Front < queue->Rear)
	{
		return (queue->Rear - queue->Front) == queue->Capacity;
	}
	else
	{
		return (queue->Rear + 1) == queue->Front;
	}
}