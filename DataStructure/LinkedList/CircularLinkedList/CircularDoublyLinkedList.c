#include "CircularDoublyLinkedList.h"

Node* createNode(ElementType data) {
	Node* newnode = (Node*)malloc(sizeof(Node));

	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

void destroyNode(Node* node) {
	free(node);
}

void appendNode(Node** head, Node* newnode) {
	if((*head) == NULL) {
		*head = newnode;
		(*head)->next = *head;
		(*head)->prev = *head;
	}
	else {
		// Inserting between head and tail
		Node* tail = (*head)->prev;

		tail->next->prev = newnode;
		tail->next = newnode;

		newnode->next = *head;
		newnode->prev = tail;
	}
}

void insertAfter(Node* current, Node* newnode) {
	newnode->next = current->next;
	newnode->prev = current;

	current->next->prev = newnode;
	current->next = newnode;
}

void removeNode(Node** head, Node* remove) {
	if((*head) == remove) {
		(*head)->prev->next = remove->next;
		(*head)->next->prev = remove->prev;

		*head = remove->next;
	} 
	else {
		Node* tmp = remove;
		remove->prev->next = tmp->next;
		remove->next->prev = tmp->prev;
	}

	// Set pointer to NULL
	remove->prev = NULL;
	remove->next = NULL;
}

Node* getNodeAt(Node* head, int location) {
	Node* current = head;
	while(current != NULL && (--location) >= 0) {
		current = current->next;
	}
	return current;
}

int getNodeCount(Node* head) {
	int count = 0;
	Node* current = head;
	while(current != NULL) {
		current = current->next;
		count++;
		// Coz it's circular Linked List
		if(current == head) {
			break;
		}
	}
	return count;
}

void printNode(Node* node) {

	if(node->prev == NULL) {
		printf("prev: NULL\n");
	}
	else {
		printf("prev: %d\n", node->prev->data);
	}
	printf(" current: %d\n", node->data);

	if(node->next == NULL) {
		printf("next: NULL\n");
	}
	else {
		printf("next: %d\n", node->next->data);
	}
}