#include "LCRSTree.h"

LCRSNode* createNode(ElementType newData)
{
	LCRSNode* newNode = (LCRSNode*)malloc(sizeof(LCRSNode));

	newNode->Data = newData;
	newNode->LeftChild = NULL;
	newNode->RightSibling = NULL;

	return newNode;
}

void destroyNode(LCRSNode* node)
{
	free(node);
}

// Destroy from Left Child Right Silbing
void destroyTree(LCRSNode* root)
{
	if(root->RightSibling != NULL)
		destroyTree(root->RightSibling);
	if(root->LeftChild != NULL)
		destroyTree(root->LeftChild);

	root->LeftChild = NULL;
	root->RightSibling = NULL;

	printf("Deleted: %c\n", root->Data);
	destroyNode(root);
}

void addChildNode(LCRSNode* parent, LCRSNode* child)
{
	if(parent->LeftChild == NULL)
	{
		parent->LeftChild = child;
	}
	else
	{
		LCRSNode* Sibling = parent->LeftChild;
		while(Sibling->RightSibling != NULL)
		{
			Sibling = Sibling->RightSibling;
		}
		Sibling->RightSibling = child;
	}
}

void printTree(LCRSNode* node, int depth)
{
	// Print space as much as depth
	int i = 0;
	for(i=0; i<depth; i++)
	{
		printf("-");
	}
	printf("%c\n", node->Data);

	if(node->LeftChild != NULL)
	{
		printTree(node->LeftChild, depth+1);
	}

	if(node->RightSibling != NULL)
	{
		printTree(node->RightSibling, depth);
	}
}

// try it again...
void printNodesAtLevel(LCRSNode* root, int level)
{
	// go to level first node
	while(root->LeftChild != NULL && level > 0)
	{
		printNodesAtLevel(root->LeftChild, level-1);
	}
	if(root->RightSibling != NULL)
	{
		printNodesAtLevel(root->RightSibling, level);
	}

	if(level == 0)
	{
		printf("%d: %c\n", level, root->Data);
	}
}