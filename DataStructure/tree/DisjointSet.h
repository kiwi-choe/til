#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct DisjointSet
{
	struct DisjointSet* Parent;
	void* Data;
} DisjointSet;

void unionSet(DisjointSet* set1, DisjointSet* set2);
DisjointSet* findSet(DisjointSet* set);
DisjointSet* makeSet(void* newData);
void destroySet(DisjointSet* set);

#endif