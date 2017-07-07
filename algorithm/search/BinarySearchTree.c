#include "BinarySearchTree.h"

Node* createNode(ElementType newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Left = NULL;
	newNode->Right = NULL;
	newNode->Data = newData;

	return newNode;
}

void destroyNode(Node* node)
{
	free(node);
}

void destroyTree(Node* tree)
{
	if(tree->Right != NULL)
		destroyTree(tree->Right);
	if(tree->Left != NULL)
		destroyTree(tree->Left);

	tree->Left = NULL;
	tree->Right = NULL;
	destroyNode(tree);
}

Node* searchNode(Node* tree, ElementType target)
{
	if(tree == NULL)
		return NULL;

	if(tree->Data > target)
		return searchNode(tree->Left, target);
	else if(tree->Data < target)
		return searchNode(tree->Right, target);
	else
		return tree;
}

Node* searchMinNode(Node* tree)
{
	if(tree == NULL)
		return NULL;

	if(tree->Left == NULL)
		return tree;
	else
		return searchMinNode(tree->Left);
}

void insertNode(Node* tree, Node* child)
{
	if(tree->Data < child->Data)
	{
		if(tree->Right == NULL)
			tree->Right = child;
		else
			insertNode(tree->Right, child);
	}
	else if(tree->Data > child->Data)
	{
		if(tree->Left == NULL)
			tree->Left = child;
		else
			insertNode(tree->Left, child);
	}
}

Node* removeNode(Node* tree, Node* parent, ElementType target)
{
	Node* removed = NULL;

	if(tree == NULL)
		return NULL;

	// Search the removing target
	if(tree->Data > target)
		removed = removeNode(tree->Left, tree, target);
	else if(tree->Data < target)
		removed = removeNode(tree->Right, tree, target);
	else 	// Found the target
	{
		removed = tree;
		// 1. no child
		if(tree->Left == NULL && tree->Right == NULL)
		{
			if(parent->Left == tree)
				parent->Left = NULL;
			else
				parent->Right = NULL;
		}
		else
		{
			// 2. both children
			if(tree->Left != NULL && tree->Right != NULL)
			{
				// Search a min node of the right subtree and place it at the current node
				Node* minNode = searchMinNode(tree->Right);
				minNode = removeNode(tree, NULL, minNode->Data);
				tree->Data = minNode->Data;
			}
			else
			{
				// 3. one child
				Node* temp = NULL;
				if(tree->Left != NULL)
					temp = tree->Left;
				else
					temp = tree->Right;

				if(parent->Left == tree)
					parent->Left = temp;
				else
					parent->Right = temp;
			}
		}
	}
	return removed;
}

void inorderPrintTree(Node* node)
{
	if(node == NULL)
		return;

	inorderPrintTree(node->Left);
	printf("%d ", node->Data);
	inorderPrintTree(node->Right);
}
