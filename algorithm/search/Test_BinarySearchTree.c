#include "BinarySearchTree.h"

int main()
{
	Node* tree = createNode(123);
	Node* node = NULL;

	insertNode(tree, createNode(22));
	insertNode(tree, createNode(9918));
	insertNode(tree, createNode(424));
	insertNode(tree, createNode(17));
	insertNode(tree, createNode(3));

	insertNode(tree, createNode(98));
	insertNode(tree, createNode(34));

	insertNode(tree, createNode(760));
	insertNode(tree, createNode(317));
	insertNode(tree, createNode(1));

	inorderPrintTree(tree);
	printf("\n");

	printf("Removing 98 ------\n");
	node = removeNode(tree, NULL, 98);
	destroyNode(node);

	inorderPrintTree(tree);
	printf("\n");

	printf("Inserting 111 --------\n");
	insertNode(tree, createNode(111));
	inorderPrintTree(tree);
	printf("\n");

	destroyTree(tree);
	
	return 0;
}