#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited };

typedef int ElementType;

typedef struct tagVertex
{
    ElementType       Data;
    int               Visited;
    int               Index;

    struct tagVertex* Next;
    struct tagEdge*   AdjacencyList;
} Vertex;

typedef struct tagEdge
{
    int    Weight;
    struct tagEdge* Next;
    Vertex* From;
    Vertex* Target;
} Edge;

typedef struct tagGraph
{
    Vertex* Vertices;
    int     VertexCount;
} Graph;

Graph* createGraph();
void   destroyGraph( Graph* G );

Vertex* createVertex( ElementType Data );
void    destroyVertex( Vertex* V );

Edge*   createEdge( Vertex* From, Vertex* Target, int Weight );
void    destroyEdge( Edge* E );

void   addVertex( Graph* G, Vertex* V );
void   addEdge( Vertex* V, Edge* E );
void   printGraph ( Graph* G );

#endif