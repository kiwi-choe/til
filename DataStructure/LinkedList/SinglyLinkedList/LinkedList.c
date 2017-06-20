#include "LinkedList.h"

Node* create(ElementType newData) 
{
	Node* newNode = (Node*) malloc(sizeof(Node));

	newNode->Data = newData;
	newNode->Next = NULL;

	return newNode;
}

void destroyNode(Node* node) 
{
	free(node);
}

void insertAfter(Node* current, Node* newNode)
{
	newNode->Next = current->Next;
	current->Next = newNode;
}

Node* getNodeAt(Node* head, int location)
{
	Node* current = head;
	while(current != NULL && (location--) > 0) 
	{
		current = current->Next;
	}
	return current;
}

int getNodeCount(Node* head)
{
	int count = 0;
	Node* current = head;
	while(current != NULL) 
	{
		current = current->Next;
		count++;
	}
	return count;
}

void append(Node** head, Node* newnode)
{
	if((*head) == NULL) 
	{
		*head = newnode;
	}
	else 
	{
		// Find Tail
		Node* tail = (*head);
		while(tail->Next != NULL) 
		{
			tail = tail->Next;
		}
		tail->Next = newnode;
	}
}

void insertNewHead(Node** head, Node* newHead) 
{
	if((*head) == NULL) 
	{
		(*head) = newHead;
	}
	else 
	{
		newHead->Next = (*head);
		(*head) = newHead;
	}
}

void removeNode(Node** head, Node* remove)
{
	if((*head) == remove) 
	{
		(*head) = remove->Next;
	}
	else 
	{
		Node* current = (*head);
		while(current != NULL && current->Next != remove) 
		{
			current = current->Next;
		}
		current->Next = remove->Next;
	}
}

void insertBefore(Node** head, Node* current, Node* newHead) 
{
	if((*head) == NULL) 
	{
		(*head) = newHead;
	}
	else if((*head) == current)
	{
		newHead->Next = (*head);
		(*head) = newHead;
	}
	else 
	{
		Node* currentBefore = (*head);
		while(current != NULL && currentBefore->Next != current)
		{
			currentBefore = currentBefore->Next;
		}
		if(current != NULL) 
		{
			newHead->Next = current;
			currentBefore->Next = newHead;
		}
	}
}

void destroyAllNodes(Node** list) 
{
	Node* tail = (*list);
	while(tail->Next != NULL)
	{
		removeNode(list, tail);
		destroyNode(tail);
		tail = tail->Next;
	}
	removeNode(list, tail);
	destroyNode(tail);
}