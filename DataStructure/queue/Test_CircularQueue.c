#include "CircularQueue.h"

int main()
{
	int i = 100;
	Queue* Queue;

	create(&Queue, 10);

	enqueue(Queue, 1);
	enqueue(Queue, 2);
	enqueue(Queue, 3);
	enqueue(Queue, 4);

	printf("Deqeue: %d, Front: %d, Rear: %d\n", dequeue(Queue), Queue->Front, Queue->Rear);
	printf("dequeue: %d, Front: %d, Rear: %d\n", dequeue(Queue), Queue->Front, Queue->Rear);
	printf("dequeue: %d, Front: %d, Rear: %d\n", dequeue(Queue), Queue->Front, Queue->Rear);

	while(isFull(Queue) == 0) 
	{
		enqueue(Queue, i++);
	}

	printf("Capacity: %d, Size: %d\n", Queue->Capacity, getSize(Queue));

	while(isEmpty(Queue) == 0)
	{
		int Data = dequeue(Queue);
		printf("Dequeue: %d, Front: %d, Rear: %d\n", Data, Queue->Front, Queue->Rear);
	}
	return 0;
}