#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int       PriorityType;

typedef struct tagePQNode 
{
    PriorityType Priority;
    void*        Data;
} PQNode;

typedef struct tagPriorityQueue 
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PriorityQueue;

PriorityQueue* createQueue( int InitialSize );
void           destroyQueue( PriorityQueue* PQ );
void           enqueue( PriorityQueue* PQ, PQNode NewData );
void           dequeue( PriorityQueue* PQ, PQNode* Root );
int            PQ_GetParent( int Index );
int            PQ_GetLeftChild( int Index );
void           PQ_SwapNodes( PriorityQueue* PQ, int Index1, int Index2 );
int            isEmpty( PriorityQueue* PQ );

#endif