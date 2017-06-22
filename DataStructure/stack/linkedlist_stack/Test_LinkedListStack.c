#include "LinkedListStack.h"

int main(void)
{
	int i = 0;
	int count = 0;
	Node* popped = NULL;

	Stack* stack = NULL;

	createStack(&stack);
	
	push(stack, createNode("abc"));
	push(stack, createNode("def"));
	push(stack, createNode("ghi"));

	count = getSize(stack);
	printf("Size: %d, Top: %s\n", count, top(stack)->Data);

	for(i=0;i<count;i++)
	{
		if(isEmpty(stack))
		{
			break;
		}
		popped = pop(stack);
		printf("popped: %s, ", popped->Data);
		destroyNode(popped);

		if(!isEmpty(stack))
		{
			printf("Current top: %s\n", top(stack)->Data);
		}
		else
		{
			printf("Stack is empty\n");
		}
	}	
	destroyStack(stack);

	return 0;
}