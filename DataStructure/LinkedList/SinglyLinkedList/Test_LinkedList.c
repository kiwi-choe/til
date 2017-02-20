#include "LinkedList.h"

int main(void) {
	int i = 0;
	int count = 0;
	Node* list = NULL;
	Node* current = NULL;
	Node* newnode = NULL;

	// Add 5 nodes
	for(i=0; i<5; i++) {
		newnode = createNode(i);
		appendNode(&list, newnode);
	}

	newnode = createNode(-1);
	insertNewHead(&list, newnode);

	newnode = createNode(-2);
	insertNewHead(&list, newnode);

	// Display list	
	count = getNodeCount(list);
	for(i=0; i<count; i++) {
		current = getNodeAt(list, i);
		printf("list[%d]: %d\n", i, current->Data);
	}

	// Insert after 3rd node
	printf("\nInserting 3000 After [2]... \n\n");
	current = getNodeAt(list, 2);
	newnode = createNode(3000);

	insertAfter(current, newnode);

	// Display list	
	count = getNodeCount(list);
	for(i=0; i<count; i++) {
		current = getNodeAt(list, i);
		printf("list[%d]: %d\n", i, current->Data);
	}


	// Remove all nodes from memmory
	printf("\nDestroying list...\n");
	for(i=0; i<count; i++) {
		current = getNodeAt(list, 0);
		if(current != NULL) {
			removeNode(&list, current);
			destroyNode(current);
		}
	}

	return 0;
}