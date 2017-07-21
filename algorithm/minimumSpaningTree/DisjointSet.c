#include "DisjointSet.h"
#include "Graph.h"

void unionSet( DisjointSet* Set1, DisjointSet* Set2 )
{
    Set2 = findSet(Set2);

    Set2->Parent = Set1;
}

DisjointSet* findSet( DisjointSet* Set )
{
    while ( Set->Parent != NULL )
    {
        Set = Set->Parent;
    }

    return Set;
}

DisjointSet* makeSet( void* NewData )
{
    DisjointSet* NewNode = (DisjointSet*)malloc(sizeof(DisjointSet));
    NewNode->Data   = NewData;
    NewNode->Parent = NULL;

    return NewNode;
}

void destroySet( DisjointSet* Set )
{
    free( Set );
}