#include "CircularDoublyLinkedList.h"

Node* create(ElementType data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = data;
	newNode->PreNode = NULL;
	newNode->NextNode = NULL;

	return newNode;
}

void destroyNode(Node* node)
{
	free(node);
}

void append(Node** head, Node* newNode)
{
	if((*head) == NULL)
	{
		(*head) = newNode;
		(*head)->NextNode = (*head);
		(*head)->PreNode = (*head);
	}
	else
	{
		// Insert between head and tail
		Node* tail = (*head)->PreNode;
		(*head)->PreNode = newNode;
		tail->NextNode = newNode;

		newNode->NextNode = (*head);
		newNode->PreNode = tail;
	}
}

void insertAfter(Node* current, Node* newNode)
{
	newNode->NextNode = current->NextNode;
	current->NextNode->PreNode = newNode;

	newNode->PreNode = current;
	current->NextNode = newNode;
}

void removeNode(Node** head, Node* remove)
{
	if((*head) == remove)
	{
		(*head)->PreNode->NextNode = remove->NextNode;
		(*head)->NextNode->PreNode = remove->PreNode;

		(*head) = remove->NextNode;
	}
	else
	{
		Node* temp = remove;
		remove->PreNode->NextNode = remove->NextNode;
		remove->NextNode->PreNode = remove->PreNode;
	}

	remove->PreNode = NULL;
	remove->NextNode = NULL;
}

Node* getNodeAt(Node* head, int location)
{
	Node* current = head;
	while(current != NULL && (location--) > 0)
	{
		current = current->NextNode;
	}
	return current;
}

int getNodeCount(Node* head)
{
	Node* current = head;
	int count = 0;
	while(current != NULL)
	{
		current = current->NextNode;
		count++;
		if(current == head)
			break;
	}
	return count;
}

void printNode(Node* node)
{
	if(node->PreNode == NULL)
	{
		printf("PreNode: NULL\n");
	}
	else
	{
		printf("PreNode: %d\n", node->PreNode->Data);
	}
	printf("current: %d\n", node->Data);
	if(node->NextNode == NULL)
	{
		printf("NextNode: NULL\n");
	}
	else
	{
		printf("NextNode: %d\n", node->NextNode->Data);
	}
}

// Node* getNodeAt(Node* head, int location) {
// 	Node* current = head;
// 	while(current != NULL && (--location) >= 0) {
// 		current = current->next;
// 	}
// 	return current;
// }