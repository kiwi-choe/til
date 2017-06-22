#include "LinkedListStack.h"

void createStack(Stack** stack)
{
	(*stack) = (Stack*)malloc(sizeof(Stack));
	(*stack)->List = NULL;
	(*stack)->Top = NULL;
}

void destroyStack(Stack* stack)
{
	// Clear Nodes of Stack first
	while(!isEmpty(stack))
	{
		Node* popped = pop(stack);
		destroyNode(popped);
	}

	free(stack);
}

Node* createNode(char* data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->Data = (char*)malloc(strlen(data) + 1);
	strcpy(newNode->Data, data);
	
	newNode->NextNode = NULL;

	return newNode;
}

void destroyNode(Node* node)
{
	free(node->Data);
	free(node);
}

void push(Stack* stack, Node* newNode)
{
	if(stack->List == NULL)
	{
		stack->List = newNode;
	}
	else
	{
		// Find Top Node
		Node* oldTop = stack->List;
		while(oldTop->NextNode != NULL)
		{
			oldTop = oldTop->NextNode;
		}
		oldTop->NextNode = newNode;
	}
	// Save newNode address to Top field
	stack->Top = newNode;
}

Node* pop(Stack* stack)
{
	Node* topNode = stack->Top;

	if(stack->List == stack->Top)
	{
		stack->List = NULL;
		stack->Top = NULL;
	}
	else
	{
		Node* newTopNode = stack->List;
		while(newTopNode != NULL && newTopNode->NextNode != stack->Top)
		{
			newTopNode = newTopNode->NextNode;
		}
		stack->Top = newTopNode;
		newTopNode->NextNode = NULL;
	}
	
	return topNode;
}

Node* top(Stack* stack)
{
	return stack->Top;
}

int getSize(Stack* stack)
{
	int count = 0;
	Node* current = stack->List;
	while(current != NULL)
	{
		current = current->NextNode;
		count++;
	}
	return count;
}

int isEmpty(Stack* stack)
{
	return (stack->List == NULL);

}