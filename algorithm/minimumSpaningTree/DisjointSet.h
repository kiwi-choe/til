#include <stdio.h>
#include <stdlib.h>

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

typedef struct tagDisjointSet
{
    struct tagDisjointSet* Parent;
    void*                  Data;
} DisjointSet;

void unionSet( DisjointSet* Set1, DisjointSet* Set2 );
DisjointSet* findSet( DisjointSet* Set );
DisjointSet* makeSet( void* NewData );
void destroySet( DisjointSet* Set );

#endif