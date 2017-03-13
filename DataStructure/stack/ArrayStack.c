#include "ArrayStack.h"

void createStack(ArrayStack** stack, int capacity) 
{
	// create stack in heap
	(*stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	// create nodes as many as capacity in heap
	(*stack)->nodes = (Node*)malloc(sizeof(Node) * capacity);

	(*stack)->capacity = capacity;
	(*stack)->top = 0;
}

void destroyStack(ArrayStack* stack) 
{
	free(stack->nodes);
	free(stack);
}

void push(ArrayStack* stack, ElementType data)
{
	int position = stack->top;

	stack->nodes[position].data = data;
	stack->top++;
}

ElementType pop(ArrayStack* stack) 
{
	int position = --(stack->top);
	return stack->nodes[position].data;
}

ElementType top(ArrayStack* stack) 
{
	int position = stack->top -1;
	return stack->nodes[position].data;
}

int getSize(ArrayStack* stack)
{
	return stack->top;
}

int isEmpty(ArrayStack* stack)
{
	return (stack->top == 0);
}

int isFull(ArrayStack* stack) 
{
	return (stack->capacity == stack->top);
}