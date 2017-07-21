#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include "Graph.h"
#include "PriorityQueue.h"

#define MAX_WEIGHT 36267

void dijkstra(Graph* g, Vertex* startVertex, Graph* shortestPath);

#endif