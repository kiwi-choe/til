#include "DoublyLinkedList.h"

Node* createNode(ElementType newData) {
	Node* newnode = (Node*)malloc(sizeof(Node));

	newnode->data = newData;
	newnode->preNode = NULL;
	newnode->nextNode = NULL;

	return newnode;
}

void destroyNode(Node* node) {
	free(node);
}

void appendNode(Node** head, Node* newnode) {
	if((*head) == NULL) {
		*head = newnode;
	}
	else {
		Node* tail = *head;
		while(tail->nextNode != NULL) {
			tail = tail->nextNode;
		}
		tail->nextNode = newnode;
		tail = newnode->preNode;
	}
}

void insertAfter(Node* current, Node* newnode) {
	newnode->preNode = current;
	newnode->nextNode = current->nextNode;
	if(current->nextNode != NULL) {
		current->nextNode->preNode = newnode;
	}
	current->nextNode = newnode;
}

void removeNode(Node** head, Node* remove) {
	if((*head) == remove) {
		*head = remove->nextNode;
		if((*head) != NULL) {
			(*head)->preNode = NULL;
		}
	}
	else {
		// Node* tmp = remove;	// why store remove's address into tmp 
		if(remove->preNode != NULL) {
			// remove->preNode->nextNode = tmp->nextNode;
			remove->preNode->nextNode = remove->nextNode;
		}
		if(remove->nextNode != NULL) {
			// remove->nextNode->preNode = tmp->preNode;
			remove->nextNode->preNode = remove->preNode;
		}
	}

	remove->preNode = NULL;
	remove->nextNode = NULL;
}

Node* getNodeAt(Node* head, int location) {
	Node* current = head;
	while(current != NULL && (--location) >= 0) {
		current = current->nextNode;
	}
	return current;
}

int getNodeCount(Node* head) {
	int count = 0;
	Node* current = head;
	while(current != NULL) {
		current = current->nextNode;
		count++;
	}
	return count;
}
