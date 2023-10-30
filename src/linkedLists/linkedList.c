#include <string.h>
#include <stdlib.h>

#include "../../include/linkedLists/LinkedList.h"

// structs LinkedList and Node are located inside LinkedList header file

LinkedList *initLinkedList(void) {
	LinkedList *linkedList = (LinkedList*)malloc(sizeof(LinkedList));
	
	if(linkedList == NULL) {
		return NULL;
	}

	linkedList->head = NULL;

	return linkedList;
}

int insertIntoLinkedList(LinkedList *linkedList, char *value) {
	Node *newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL) {
		return -1;
	}

	newNode->data = strdup(value);
	newNode->next = NULL;

	if (linkedList->head == NULL) {
		linkedList->head = newNode;
		return 0;
	}

	Node *current = linkedList->head;

	while(current->next != NULL) {
		current = current->next;
	}

	current->next = newNode;

	return 0;
}

int deleteFromLinkedList(LinkedList *linkedList, char *value) {
	if (strcmp(linkedList->head->data, value) == 0) {
		Node *head = linkedList->head;
		linkedList->head = linkedList->head->next;
		free(head);
		return 0;
	}

	Node *current = linkedList->head;
	Node *previous = NULL;

	while (current != NULL) {
		if (strcmp(current->data, value) == 0) {
			previous->next = current->next;
			free(current->data);
			free(current);
			return 0;
		}
		previous = current;
		current = current->next;
	}

	return -1;
}


void freeLinkedList(LinkedList *linkedList) {
	Node *current = linkedList->head;

	while (current != NULL) {
		Node *element = current;
		current = current->next;
		free(element);
	}

	free (linkedList);
}
