#ifndef LCRCTREE_H
#define LCRCTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct LCRSNode
{
	ElementType Data;
	struct LCRSNode* LeftChild;
	struct LCRSNode* RightSibling;
} LCRSNode;

LCRSNode* createNode(ElementType newData);
void destroyNode(LCRSNode* node);
void destroyTree(LCRSNode* root);

void addChildNode(LCRSNode* parent, LCRSNode* child);
void printTree(LCRSNode* node, int depth);

void printNodesAtLevel(LCRSNode* root, int level);

#endif