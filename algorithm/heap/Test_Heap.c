#include "Heap.h"

int main()
{
	Heap* h = createHeap(3);
	HeapNode minNode;

	insert(h, 12);
	insert(h, 87);
	insert(h, 111);
	insert(h, 34);
	insert(h, 16);
	insert(h, 75);
	printNodes(h);

	deleteMin(h, &minNode);
	printNodes(h);

	deleteMin(h, &minNode);
	printNodes(h);

	deleteMin(h, &minNode);
	printNodes(h);

	deleteMin(h, &minNode);
	printNodes(h);

	deleteMin(h, &minNode);
	printNodes(h);

	deleteMin(h, &minNode);
	printNodes(h);
	
	return 0;
}