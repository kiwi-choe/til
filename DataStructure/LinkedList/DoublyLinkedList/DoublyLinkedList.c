#include "DoublyLinkedList.h"

Node* create(ElementType newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = newData;
	newNode->PreNode = NULL;
	newNode->NextNode = NULL;

	return newNode;
}

void destroy(Node* node)
{
	free(node);
}

void append(Node** head, Node* newNode)
{
	if((*head) == NULL)
	{
		(*head) = newNode;
	}
	else
	{
		Node* tail = (*head);
		while(tail->NextNode != NULL) 
		{
			tail = tail->NextNode;
		}
		tail->NextNode = newNode;
		newNode->PreNode = tail;
	}
}

void insertAfter(Node* current, Node* newNode)
{
	newNode->PreNode = current;
	newNode->NextNode = current->NextNode;
	if(current->NextNode != NULL) 
	{
		current->NextNode->PreNode = newNode;
	}
	current->NextNode = newNode;
}

void removeNode(Node** head, Node* remove)
{
	if((*head) == remove) 
	{
		(*head) = remove->NextNode;
		if((*head) != NULL)
		{
			(*head)->PreNode = NULL;
		}
	}
	else
	{
		Node* temp = remove;
		if(remove->PreNode != NULL)
		{
			remove->PreNode->NextNode = temp->NextNode;
		}
		if(remove->NextNode != NULL)
		{
			remove->NextNode->PreNode = temp->PreNode;
		}
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
	int count = 0;
	Node* current = head;
	while(current != NULL)
	{
		current = current->NextNode;
		count++;
	}
	return count;
}