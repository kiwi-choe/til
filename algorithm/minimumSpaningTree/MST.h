#ifndef MST_H
#define MST_H

#include "Graph.h"
#include "PriorityQueue.h"
#include "DisjointSet.h"

#define MAX_WEIGHT 36267

void prim(Graph* g, Vertex* startVertex, Graph* mst);
void kruskal(Graph* g, Graph* mst);

#endif