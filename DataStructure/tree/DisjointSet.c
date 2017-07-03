#include "DisjointSet.h"

void unionSet(DisjointSet* set1, DisjointSet* set2)
{
	set2 = findSet(set2);
	set2->Parent = set1;
}

DisjointSet* findSet(DisjointSet* set)
{
	while(set->Parent != NULL)
	{
		set = set->Parent;
	}
	return set;
}

DisjointSet* makeSet(void* newData)
{
	DisjointSet* newSet = (DisjointSet*)malloc(sizeof(DisjointSet));
	newSet->Data = newData;
	newSet->Parent = NULL;

	return newSet;
}

void destroySet(DisjointSet* set)
{
	free(set);
}