#include "GraphTraversal.h"

void DFS(Vertex* v)
{
	Edge* e = NULL;

	printf("%d ", v->Data);

	v->Visited = Visited;

	e = v->AdjacencyList;
	while(e != NULL)
	{
		if(e->Target != NULL && e->Target->Visited == NotVisited)
			DFS(e->Target);

		e = e->Next;
	}
}

void BFS(Vertex* v, LinkedQueue* q)
{
	Edge* e = NULL;

	printf("%d ", v->Data);
	v->Visited = Visited;

	enqueue(&q, createNode(v));
	while(!isEmpty(q))
	{
		Node* popped = dequeue(&q);
		v = popped->Data;
		
		e = v->AdjacencyList;
		while(e != NULL)
		{
			v = e->Target;
			if(v != NULL && v->Visited == NotVisited)
			{
				printf("%d ", v->Data);
				v->Visited = Visited;
				enqueue(&q, createNode(v));
			}
			e = e->Next;
		}
	}
}