#include "DoublyLinkedList.h"

void printReverse(Node* head) {

	Node* tail = NULL;
	int i = 0;
	int count = 0;

	tail = head;
	// find tail
	count = getNodeCount(head);
	printf("count: %d\n", count);

	// find tail
	while(tail->nextNode != NULL) {
		tail = tail->nextNode;
	}

	// while tail->prev != NULL, print
	// for(i=0;i<count;i++) {
		// printf("%d\n", tail->data);
		// tail = tail->preNode;
	// }
	while(tail != NULL){
		printf("%d <-> ",tail->data);
		tail = tail->preNode;
	}
}

int main() 
{
	Node* list = NULL;
	Node* newnode = NULL;
	Node* current = NULL;
	int i = 0;
	int count = 0;

	for(i=0;i<5;i++) {
		newnode = createNode(i);
		appendNode(&list, newnode);
	}

	// Display list
	count = getNodeCount(list);
	for(i=0;i<count;i++) {
		current = getNodeAt(list, i);
		printf("List[%d]: %d\n", i, current->data);
	}

	printf("list: %d\n", list->data);
	// printf("list->preNode: %d\n", list->preNode->data);
	current = getNodeAt(list, 1);
	printf("list[1]: %d\n", current->data);

	// printReverse(list);

	return 0;
}