#include "CircularDoublyLinkedList.h"

void displayList(Node* list) 
{
	int count = 0;
	int i = 0;
	Node* current = NULL;

	count = getNodeCount(list);
	for(i=0;i<count;i++) {
		current = getNodeAt(list, i);
		printf("List[%d]: %d\n", i, current->data);
	}
}

int main() 
{
	int count = 0;
	int i = 0;

	Node* list = NULL;
	Node* newnode = NULL;
	Node* current = NULL;

	// Append 5 nodes
	for(i=0;i<5; i++) {
		newnode = createNode(i);
		appendNode(&list, newnode);
	}

	// Check if it is Circular?
	count = getNodeCount(list);
	for(i=0;i<count*2;i++) {
		current = getNodeAt(list, i);
		printf("List[%d]: %d\n", i, current->data);
	}

	printf("Inserting 3000 after 3rd node\n");
	newnode = createNode(3000);
	current = getNodeAt(list, 2);
	insertAfter(current, newnode);

	displayList(list);

	printf("Destroying List.....\n");
	count = getNodeCount(list);
	for(i=0;i<count;i++) {
		current = getNodeAt(list, i);
		if(current != NULL) {
			removeNode(&list, current);
			destroyNode(current);
		}
	}

	return 0;
}