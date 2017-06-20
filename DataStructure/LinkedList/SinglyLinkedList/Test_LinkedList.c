#include "LinkedList.h"

void displayList(Node* list) 
{
	int count = 0;
	int i = 0;
	Node* current = NULL;

	count = getNodeCount(list);
	for(i=0;i<count;i++)
	{
		current = getNodeAt(list, i);
		printf("List[%d]: %d\n", i, current->Data);
	}
}

int main(void) 
{
	int i = 0;
	int count = 0;
	Node* list = NULL;
	Node* current = NULL;
	Node* newNode = NULL;

	// create 5 new nodes
	for(i=0;i<5;i++) 
	{
		newNode = create(i);
		append(&list, newNode);
	}

	newNode = create(-1);
	insertNewHead(&list, newNode);

	newNode = create(-2);
	insertNewHead(&list, newNode);

	displayList(list);

	printf("\nInserting 5000 after [2] ...\n");
	current = getNodeAt(list, 2);
	newNode = create(5000);
	insertAfter(current, newNode);

	displayList(list);

	printf("sizeof(Node): %lu, sizeof(Node*): %lu\n", sizeof(Node), sizeof(Node*));

	printf("insertBefore [1]\n");
	current = getNodeAt(list, 1);
	newNode = create(-555);
	insertBefore(&list, current, newNode);
	displayList(list);

	printf("\nDestroying ... \n");
	destroyAllNodes(&list);
	displayList(list);
	// count = getNodeCount(list);
	// for(i=0;i<count;i++)
	// {
	// 	current = getNodeAt(list, 0);
	// 	if(current != NULL) 
	// 	{
	// 		removeNode(&list, current);
	// 		destroyNode(current);
	// 	}
	// }
	return 0;
}