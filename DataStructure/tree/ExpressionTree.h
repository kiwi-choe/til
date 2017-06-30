#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct Node
{
	struct Node* Left;
	struct Node* Right;

	ElementType Data;
} Node;

Node* createNode(ElementType newData);
void destroyNode(Node* node);
void destroyTree(Node* root);

void postorderPrintTree(Node* root);

void buildExpressionTree(char* postfixExpression, Node** node);
double evaluate(Node* tree);

#endif