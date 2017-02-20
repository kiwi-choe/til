#include "DoublyLinkedList.h"

void displayList(Node* list) {
	int i =0;
	int count = 0;
	Node* current = NULL;

	count = getNodeCount(list);
	for(i=0;i<count; i++) {
		current = getNodeAt(list, i);
		printf("List[%d]: %d\n", i, current->data);
	}
}

int main(void)
{
	int i = 0;
	int count = 0;
	Node* list = NULL;
	Node* current = NULL;
	Node* newNode = NULL;

	// Add 5 nodes
	for(i=0;i<5;i++) {

		newNode = createNode(i);
		appendNode(&list, newNode);
	}

	// Display List
	displayList(list);


	// Insert after 3rd node
	printf("\nInserting 3000 after 3rd node\n");
	current = getNodeAt(list, 2);
	newNode = createNode(3000);
	insertAfter(current, newNode);

	displayList(list);

	printf("\nDestroying list\n");
	count = getNodeCount(list);
	for(i=0; i<count; i++) {
		current = getNodeAt(list, 0);
		if(current != NULL) {
			removeNode(&list, current);
			destroyNode(current);
		}
	}
	
	return 0;
}