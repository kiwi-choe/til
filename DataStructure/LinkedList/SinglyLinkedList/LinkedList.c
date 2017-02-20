#include "LinkedList.h"

// Create node
Node*	createNode(ElementType newData) {
	Node* newnode = (Node*)malloc(sizeof(Node));

	// Save data
	newnode->Data = newData;
	// Initialize pointer of nextNode to NULL
	newnode->NextNode = NULL;
	// Return node address
	return newnode;
}

void	destroyNode(Node* node) {
	free(node);
}

void	appendNode(Node** head, Node* newnode) {
	// if headnode is null, newnode become head
	if( (*head) == NULL ) {
		*head = newnode;
	}
	else {
		// find tail and connect newnode
		Node* tail = (*head);
		while(tail->NextNode != NULL) {
			tail = tail->NextNode;
		}

		tail->NextNode = newnode;
	}
}

void	insertAfter(Node* current, Node* newnode) {
	newnode->NextNode = current->NextNode;
	current->NextNode = newnode;
}

void	insertNewHead(Node** head, Node* newhead) {
	if(*head == NULL) {
		(*head) = newhead;
	}
	else {
		newhead->NextNode = (*head);
		(*head) = newhead;
	}
}

// with Drawing again
void	removeNode(Node** head, Node* remove) {
	if(*head == remove) {
		*head = remove->NextNode;
	}
	else {
		Node* node = *head;
		while(node != NULL && node->NextNode != remove) {
			node = node->NextNode;
		}
		if(node != NULL) {
			node->NextNode = remove->NextNode;	
		}
	}
}

Node*	getNodeAt(Node* head, int location) {

	Node* current = head;
	// Memorize (--location)>=0
	while(current!=NULL && (--location) >= 0) {
		current = current->NextNode;
	}
	return current;
}

int 	getNodeCount(Node* head) {
	
	int count = 0;
	Node* node = head;
	while(node!=NULL) {
		node = node->NextNode;
		count++;
	}
	return 	count;
}
