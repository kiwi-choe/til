#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H value

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct RBTNode
{
	struct RBTNode* Parent;
	struct RBTNode* Left;
	struct RBTNode* Right;

	enum { RED, BLACK } Color;

	ElementType Data;
} RBTNode;

void destroyTree(RBTNode* tree);

RBTNode* createNode(ElementType newData);
void destroyNode(RBTNode* node);

RBTNode* searchNode(RBTNode* tree, ElementType target);
RBTNode* searchMinNode(RBTNode* tree);

void insertNode(RBTNode** tree, RBTNode* newNode);
void insertNodeHelper(RBTNode** tree, RBTNode* newNode);
void rebuildAfterInsert(RBTNode** tree, RBTNode* newNode);

RBTNode* removeNode(RBTNode** root, ElementType target);
void rebuildAfterRemove(RBTNode** root, RBTNode* x);

void printTree(RBTNode* node, int depth, int blackCount);
void rotateLeft(RBTNode** root, RBTNode* parent);
void rotateRight(RBTNode** root, RBTNode* parent);

#endif