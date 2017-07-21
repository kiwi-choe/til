#include "ShortestPath.h"

void dijkstra(Graph* g, Vertex* startVertex, Graph* shortestPath)
{
	int i =0;
	PQNode startNode = {0, startVertex};
	PriorityQueue* pq = createQueue(10);

	Vertex* currentVertex = NULL;
	Edge* currentEdge = NULL;
	
	int* weights = (int*)malloc(sizeof(int) * g->VertexCount);
	Vertex** shortestPathVertices =
		(Vertex**)malloc(sizeof(Vertex*) * g->VertexCount);
	Vertex** fringes = (Vertex**)malloc(sizeof(Vertex*) * g->VertexCount);
	Vertex** precedences = (Vertex**)malloc(sizeof(Vertex*) * g->VertexCount);

	currentVertex = g->Vertices;
	while(currentVertex != NULL)
	{
		Vertex* newVertex = createVertex(currentVertex->Data);
		addVertex(shortestPath, newVertex);

		fringes[i] = NULL;
		precedences[i] = NULL;
		shortestPathVertices[i] = newVertex;
		weights[i] = MAX_WEIGHT;
		currentVertex = currentVertex->Next;
		i++;
	}

	enqueue(pq, startNode);
	weights[startVertex->Index] = 0;

	while(!isEmpty(pq))
	{
		PQNode popped;

		dequeue(pq, &popped);
		currentVertex = (Vertex*)popped.Data;

		fringes[currentVertex->Index] = currentVertex;

		currentEdge = currentVertex->AdjacencyList;
		while(currentEdge != NULL)
		{
			Vertex* targetVertex = currentEdge->Target;
			if(fringes[targetVertex->Index] == NULL && 
				weights[currentVertex->Index] + currentEdge->Weight < weights[targetVertex->Index])
			{
				PQNode newNode = {currentEdge->Weight, targetVertex};
				enqueue(pq, newNode);

				precedences[targetVertex->Index] = currentEdge->From;
				weights[targetVertex->Index] = 
					weights[currentVertex->Index] + currentEdge->Weight;
			}
			currentEdge = currentEdge->Next;
		}
	}

	for(i=0; i<g->VertexCount; i++)
	{
		int fromIndex, toIndex;

		if(precedences[i] == NULL)
			continue;

		fromIndex = precedences[i]->Index;
		toIndex = i;

		addEdge(shortestPathVertices[fromIndex],
			createEdge(
				shortestPathVertices[fromIndex],
				shortestPathVertices[toIndex],
				weights[i]));
	}

	free(fringes);
	free(precedences);
	free(shortestPathVertices);
	free(weights);

	destroyQueue(pq);
}