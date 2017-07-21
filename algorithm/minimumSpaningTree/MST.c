#include "MST.h"

void prim(Graph* g, Vertex* startVertex, Graph* mst)
{
	int i = 0;

	PQNode startNode = {0, startVertex};
	PriorityQueue* pq = createQueue(10);

	Vertex* currentVertex = NULL;
	Edge* currentEdge = NULL;

	int* weights = (int*)malloc(sizeof(int) * g->VertexCount);
	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * g->VertexCount);
	Vertex** fringes = (Vertex**)malloc(sizeof(Vertex*) * g->VertexCount);
	Vertex** precedences = (Vertex**)malloc(sizeof(Vertex*) * g->VertexCount);

	currentVertex = g->Vertices;
	while(currentVertex != NULL)
	{
		Vertex* newVertex = createVertex(currentVertex->Data);
		addVertex(mst, newVertex);

		fringes[i] = NULL;
		precedences[i] = NULL;
		MSTVertices[i] = newVertex;
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
			if(fringes[targetVertex->Index] == NULL && currentEdge->Weight < weights[targetVertex->Index])
			{
				PQNode newNode = {currentEdge->Weight, targetVertex};
				enqueue(pq, newNode);

				precedences[targetVertex->Index] = currentEdge->From;
				weights[targetVertex->Index] = currentEdge->Weight;
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

		addEdge(MSTVertices[fromIndex], 
			createEdge(MSTVertices[fromIndex], MSTVertices[toIndex], 
				weights[i]));

		addEdge(MSTVertices[toIndex], 
			createEdge(MSTVertices[toIndex], MSTVertices[fromIndex], 
				weights[i]));
	}

	free(fringes);
	free(precedences);
	free(MSTVertices);
	free(weights);

	destroyQueue(pq);
}

void kruskal(Graph* g, Graph* mst)
{
	int i = 0;
	Vertex* currentVertex = NULL;
	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * g->VertexCount);
	DisjointSet** vertexSet = (DisjointSet**)malloc(sizeof(Vertex*) * g->VertexCount);

	PriorityQueue* pq = createQueue(10);

	i = 0;
	currentVertex = g->Vertices;
	while(currentVertex != NULL)
	{
		Edge* currentEdge;

		vertexSet[i] = makeSet(currentVertex);
		MSTVertices[i] = createVertex(currentVertex->Data);
		addVertex(mst, MSTVertices[i]);

		currentEdge = currentVertex->AdjacencyList;
		while(currentEdge != NULL)
		{
			PQNode newNode = {currentEdge->Weight, currentEdge};
			enqueue(pq, newNode);

			currentEdge = currentEdge->Next;
		}
		currentVertex = currentVertex->Next;
		i++;
	}

	while(!isEmpty(pq))
	{
		Edge* currentEdge;
		int fromIndex;
		int toIndex;
		PQNode popped;

		dequeue(pq, &popped);
		currentEdge = (Edge*)popped.Data;

		printf("%c - %c : %d\n",
			currentEdge->From->Data,
			currentEdge->Target->Data,
			currentEdge->Weight);
		
		fromIndex = currentEdge->From->Index;
		toIndex = currentEdge->Target->Index;

		if(findSet(vertexSet[fromIndex]) != findSet(vertexSet[toIndex]))
		{
			addEdge(MSTVertices[fromIndex], 
				createEdge(MSTVertices[fromIndex], 
					MSTVertices[toIndex],
					currentEdge->Weight));

			addEdge(MSTVertices[toIndex],
				createEdge(MSTVertices[toIndex],
					MSTVertices[fromIndex],
					currentEdge->Weight));

			unionSet(vertexSet[fromIndex], vertexSet[toIndex]);
		}
	}

	for(i=0; i<g->VertexCount; i++)
	{
		destroySet(vertexSet[i]);
	}

	free(vertexSet);
	free(MSTVertices);
}