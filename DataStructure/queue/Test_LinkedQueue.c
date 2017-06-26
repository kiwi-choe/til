#include "LinkedQueue.h"

int main()
{
	Node* popped = NULL;
	LinkedQueue* Queue = NULL;

	createQueue(&Queue);

	enqueue(Queue, createNode("kiwi"));
	enqueue(Queue, createNode("loves"));
	enqueue(Queue, createNode("LA-AMEN"));

	printf("Queue size: %d\n", Queue->Count);

	while(!isEmpty(Queue))
	{
		popped = dequeue(Queue);
		printf("%s\n", popped->Data);

		destroyNode(popped);
	}
	destroyQueue(Queue);

	return 0;
}