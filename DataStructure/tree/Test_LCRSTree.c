#include "LCRSTree.h"

int main()
{
	LCRSNode* root = createNode('a');

	LCRSNode* b = createNode('b');
	LCRSNode* c = createNode('c');
	LCRSNode* d = createNode('d');
	LCRSNode* e = createNode('e');
	LCRSNode* f = createNode('f');

	LCRSNode* g = createNode('g');
	LCRSNode* h = createNode('h');

	LCRSNode* i = createNode('i');
	LCRSNode* j = createNode('j');
	LCRSNode* k = createNode('k');

	addChildNode(root, b);
	addChildNode(root, g);
	addChildNode(root, i);

	addChildNode(b, c);
	addChildNode(b, d);

	addChildNode(d, e);
	addChildNode(d, f);

	addChildNode(g, h);

	addChildNode(i, j);

	addChildNode(j, k);

	printf("TREE - from root\n");
	printTree(root, 0);

	printf("TREE - from b\n");
	printTree(b, 1);

	printf("TREE - from c\n");
	printTree(c, 2);

	printf("TREE - at level 2\n");
	// printNodesAtLevel(root, 2);

	destroyTree(root);
	return 0;
}