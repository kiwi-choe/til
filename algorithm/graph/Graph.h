#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited };

typedef int ElementType;

typedef struct Vertex
{
	ElementType Data;
	int Visited;
	int Index;

	struct Vertex* Next;
	struct Edge* AdjacencyList;
} Vertex;

typedef struct Edge
{
	int Weight;
	struct Edge* Next;
	Vertex* From;
	Vertex* Target;
} Edge;

typedef struct Graph
{
	Vertex* Vertices;
	int VertexCount;
} Graph;

Graph* createGraph();
void destroyGraph(Graph* g);

Vertex* createVertex(ElementType data);
void destroyVertex(Vertex* v);

Edge* createEdge(Vertex* from, Vertex* target, int weigth);
void destroyEdge(Edge* e);

void addVertex(Graph* g, Vertex* v);
void addEdge(Vertex* v, Edge* e);
void printGraph(Graph* g);

#endif