#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct tagNode
{
    Vertex*         Data;
    struct tagNode* NextNode;
} Node;

Node* createNode(Vertex* NewData);
void  SLL_DestoryNode(Node* Node);
void  SLL_AppendNode(Node** Head, Node* NewNode);
void  SLL_InsertAfter(Node** Current, Node** NewNode);
void  insertNewHead(Node** Head, Node** NewHead);
void  SLL_RemoveNode(Node** Head, Node** Remove);
Node* SLL_GetNodeAt(Node* Head, int Location);
int   SLL_GetNodeCount(Node* Head);

#endif