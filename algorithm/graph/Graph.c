#include "Graph.h"

Graph* createGraph()
{
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->Vertices = NULL;
	g->VertexCount = 0;

	return g;
}

void destroyGraph(Graph* g)
{
	while(g->Vertices != NULL)
	{
		Vertex* vertices = g->Vertices->Next;
		destroyVertex(g->Vertices);
		g->Vertices = vertices;
	}
	free(g);
}

Vertex* createVertex(ElementType data)
{
	Vertex* v = (Vertex*)malloc(sizeof(Vertex));
	v->Data = data;
	v->Next = NULL;
	v->AdjacencyList = NULL;
	v->Visited = NotVisited;
	v->Index = -1;

	return v;
}

void destroyVertex(Vertex* v)
{
	while(v->AdjacencyList != NULL)
	{
		Edge* edge = v->AdjacencyList->Next;
		destroyEdge(v->AdjacencyList);
		v->AdjacencyList = edge;
	}
	free(v);
}

Edge* createEdge(Vertex* from, Vertex* target, int weigth)
{
	Edge* e = (Edge*)malloc(sizeof(Edge));
	e->From = from;
	e->Target = target;
	e->Next = NULL;
	e->Weight = weigth;

	return e;
}

void destroyEdge(Edge* e)
{
	free(e);
}

void addVertex(Graph* g, Vertex* v)
{
	Vertex* vertexList = g->Vertices;
	if(vertexList == NULL)
		g->Vertices = v;
	else
	{
		while(vertexList->Next != NULL)
			vertexList = vertexList->Next;

		vertexList->Next = v;
	}

	v->Index = g->VertexCount++;
}

void addEdge(Vertex* v, Edge* e)
{
	if(v->AdjacencyList == NULL)
		v->AdjacencyList = e;
	else
	{
		Edge* adjacencyList = v->AdjacencyList;
		while(adjacencyList->Next != NULL)
			adjacencyList = adjacencyList->Next;

		adjacencyList->Next = e;
	}
}

void printGraph(Graph* g)
{
	Vertex* v = NULL;
	Edge* e = NULL;

	v = g->Vertices;
	if(v == NULL)
		return;

	while(v != NULL)
	{
		printf("%c : ", v->Data);

		e = v->AdjacencyList;
		if(e == NULL)
		{
			v = v->Next;
			printf("\n");
			continue;
		}

		while(e != NULL)
		{
			printf("%c[%d] ", e->Target->Data, e->Weight);
			e = e->Next;
		}
		printf("\n");
		v = v->Next;
	}
	printf("\n");
}