#include "Graph.h"
#include "LinkedList.h"

#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

void topologicalSort(Vertex* v, Node** list);
void dfs(Vertex* v, Node** list);

#endif