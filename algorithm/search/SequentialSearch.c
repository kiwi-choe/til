#include "SequentialSearch.h"

// LinkedList for Sequential search
Node* createNode(ElementType data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->Data = data;
	node->Next = NULL;

	return node;
}

void destroyNode(Node* node)
{
	free(node);
}

void appendNode(Node** head, Node* newNode)
{
	if((*head) == NULL)
	{
		(*head) = newNode;
	}
	else
	{
		Node* tail = (*head);
		while(tail->Next != NULL)
		{
			tail = tail->Next;
		}
		tail->Next = newNode;
	}
}

void removeNode(Node** head, Node* remove)
{
	if(*head == remove)
	{
		*head = remove->Next;
	}
	else
	{
		Node* current = *head;
		while(current != NULL && current->Next != remove)
		{
			current = current->Next;
		}
		if(current!=NULL)
			current->Next = remove->Next;
	}
}

Node* getNodeAt(Node* head, int location)
{
	Node* curNode = head;
	while(curNode != NULL && (--location) > 0)
	{
		curNode = curNode->Next;
	}
	return curNode;
}

int getNodeCount(Node* head)
{
	int count = 0;
	Node* curNode = head;

	while(curNode != NULL)
	{
		curNode = curNode->Next;
		count++;
	}
	return count;
}


// Sequential search
Node* sequentialSearch(Node* head, int targetData)
{
	Node* current = head;
	Node* match = NULL;

	while(current != NULL)
	{
		if(current->Data == targetData)
		{
			match = current;
			break;
		}
		else
			current = current->Next;
	}
	return match;
}

// Self Organizing Sequential Search
Node* moveToFront(Node** head, int targetData)
{
	Node* current = (*head);
	Node* previous = NULL;
	Node* match = NULL;

	while(current != NULL)
	{
		if(current->Data == targetData)
		{
			match = current;
			if(previous != NULL)
			{
				previous->Next = current->Next;

				current->Next = (*head);
				(*head) = current;	
			}
			break;
		}
		else
		{
			previous = current;
			current = current->Next;
		}
	}
	return match;
}

Node* transpose(Node** head, int targetData)
{
	Node* current = (*head);
	Node* pprevious = NULL;
	Node* previous = NULL;
	Node* match = NULL;

	while(current != NULL)
	{
		if(current->Data == targetData)
		{
			match = current;
			// Swap
			if(previous != NULL)
			{
				if(pprevious != NULL)
					pprevious->Next = current;
				else
					(*head) = current;

				previous->Next = current->Next;
				current->Next = previous;
			}
			break;
		}
		else
		{
			if(previous != NULL)
				pprevious = previous;
			previous = current;
			current = current->Next;
		}
	}
	return match;
}

int main()
{
	int i =0;
	int count = 0;
	Node* list = NULL;
	Node* newNode = NULL;
	Node* current = NULL;

	// Create List
	for(i=0;i<100;i++)
	{
		newNode = createNode(i);
		appendNode(&list, newNode);
	}

	// Search using by SequentialSearch
	current = sequentialSearch(list, 55);
	printf("Search using by SequentialSearch: %d \n", current->Data);

	// Search using by transpose
	printf("--------------transpose ----------------\n");
	printf("Next node of the target 55: %d \n", current->Next->Data);
	current = transpose(&list, 55);
	printf("After transpose method, Next node of the target 55: %d \n", current->Next->Data);

	// Search using by moveToFront
	printf("-------------- moveToFront ----------------\n");
	printf("Next node of the target 55: %d \n", current->Next->Data);
	current = moveToFront(&list, 55);
	printf("After moveToFront method, Next node of the target 55: %d \n", current->Next->Data);


	// Destroy List
	for(i=0;i<count;i++)
	{
		current = getNodeAt(list, 0);
		if(current != NULL)
		{
			removeNode(&list, current);
			destroyNode(current);
		}
	}

	return 0;
}