#include "ArrayStack.h"

int main() {
	int i =0;
	ArrayStack* stack = NULL;
	int capacity = 10;

	createStack(&stack, capacity);

	// push(stack, 0);
	// push(stack, 1);
	// push(stack, 2);
	// push(stack, 3);
	// push(stack, 4);

	// printf("capacity: %d, size: %d, top: %d\n",
	// 	stack->capacity, getSize(stack), top(stack));

	// for(i=0; i<5; i++) {
	// 	if(isEmpty(stack)) {
	// 		break;
	// 	}

	// 	printf("popped: %d, ", pop(stack));

	// 	if(!isEmpty(stack)) {
	// 		printf("current top: %d\n", top(stack));
	// 	}
	// 	else {
	// 		printf("Stack is empty\n");
	// 	}
	// }

	// test isFull
	for(i=0; i<capacity; i++) {
		if(isFull(stack)) {
			break;
		}
		push(stack, i);
	}
	printf("capacity: %d, size: %d, top: %d\n",
		stack->capacity, getSize(stack), top(stack));
	for(i=0; i<capacity; i++) {
		if(isEmpty(stack)) {
			break;
		}

		printf("popped: %d, ", pop(stack));

		if(!isEmpty(stack)) {
			printf("current top: %d\n", top(stack));
		}
		else {
			printf("Stack is empty\n");
		}
	}	

	destroyStack(stack);
	return 0;
}