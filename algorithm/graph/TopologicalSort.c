#include "TopologicalSort.h"

void topologicalSort(Vertex* v, Node** list)
{
	while(v != NULL && v->Visited == NotVisited)
	{
		dfs(v, list);
		v = v->Next;
	}
}

void dfs(Vertex* v, Node** list)
{
	Node* newHead = NULL;
	Edge* e = NULL;

	v->Visited = Visited;

	e = v->AdjacencyList;
	while(e != NULL)
	{
		if(e->Target != NULL && e->Target->Visited == NotVisited)
			dfs(e->Target, list);

		e = e->Next;
	}
	printf("%c\n", v->Data);

	newHead = createNode(v);
	insertNewHead(list, &newHead);
}