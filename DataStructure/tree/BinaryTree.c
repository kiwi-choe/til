#include "BinaryTree.h"

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

void preorderPrintTree(Node* node)
{
	if(node == NULL)
	{
		printf("\n");
		return;
	}

	printf("%c > ", node->Data);
	preorderPrintTree(node->Left);
	preorderPrintTree(node->Right);
}

void inorderPrintTree(Node* node)
{
	if(node == NULL)
	{
		printf("\n");
		return;
	}

	inorderPrintTree(node->Left);
	printf("%c > ", node->Data);
	inorderPrintTree(node->Right);
}

void postorderPrintTree(Node* node)
{
	if (node == NULL)
	{
		printf("\n");
		return;
	}

	postorderPrintTree(node->Left);
	postorderPrintTree(node->Right);
	printf("%c > ", node->Data);
}

// destroy follwing postorder
void destroyTree(Node* root)
{
	if(root == NULL)
		return;

	destroyTree(root->Left);

	destroyTree(root->Right);

	// root node
	destroyNode(root);
}