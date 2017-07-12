#include "PriorityQueue.h"

void printNode(PQNode* Node)
{
	printf("task name: %s (priority: %d) \n", (char*)Node->Data, Node->Priority);
}

int main()
{
	PQueue* pq = createQueue(3);
	PQNode popped;

	PQNode Nodes[7] =
	{
		{34, (void*)"coding"},
		{12, (void*)"meeting"},
		{87, (void*)"take coffee"},
		{45, (void*)"make documents"},
		{35, (void*)"debugging"},
		{66, (void*)"bruch my teeth"}
	};

	enqueue(pq, Nodes[0]);
	enqueue(pq, Nodes[1]);
	enqueue(pq, Nodes[2]);
	enqueue(pq, Nodes[3]);
	enqueue(pq, Nodes[4]);
	enqueue(pq, Nodes[5]);

	printf("number of tasks in queue: %d\n", pq->UsedSize);

	while(!isEmpty(pq))
	{
		dequeue(pq, &popped);
		printNode(&popped);
	}

	return 0;
}