#include "DoublyLinkedList.h"


void printReverse(Node* head)
{
	if(head == NULL) 
	{
		return;
	}

	// Find tail
	Node* tail = head;
	while(tail->NextNode != NULL)
	{
		tail = tail->NextNode;
	}

	// Start from tail to head
	while(tail->PreNode != NULL)
	{
		printf("%d\n", tail->Data);
		tail = tail->PreNode;
	}
	// tail == head location
	printf("%d\n", tail->Data);
}

int main() 
{
	Node* list = NULL;
	Node* newnode = NULL;
	Node* current = NULL;
	int i = 0;
	int count = 0;

	for(i=0;i<5;i++) {
		newnode = create(i);
		append(&list, newnode);
	}

	// Display list
	count = getNodeCount(list);
	for(i=0;i<count;i++) {
		current = getNodeAt(list, i);
		printf("List[%d]: %d\n", i, current->Data);
	}

	printReverse(list);

	return 0;
}