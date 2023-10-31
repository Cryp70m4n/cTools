#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

int insertIntoLinkedList(LinkedList *linkedList, DataType dataType, Value value) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	if (newNode == NULL) {
		return -1;
	}

	newNode->dataType = dataType;
	newNode->value = value;
	newNode->next = NULL;
	
	if(linkedList->head == NULL) {
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

int deleteFromLinkedList(LinkedList *linkedList, Value value) {
	bool found = false;

	switch (linkedList->head->dataType) {
		case INT:
			if (linkedList->head->value.intValue == value.intValue) {
				found = true;
			}
			break;

		case LONG:
			if (linkedList->head->value.longValue == value.longValue) {
				found = true;
			}
			break;

		case FLOAT:
			if (linkedList->head->value.floatValue == value.floatValue) {
				found = true;
			}
			break;

		case STRING:
			if (strcmp(linkedList->head->value.stringValue, value.stringValue) == 0) {
				found = true;
			}
			break;

		default:
			break;
	}

		if (found == true) {
			Node *head = linkedList->head;
			linkedList->head = linkedList->head->next;
			free(head);
			return 0;
		}

	Node *current = linkedList->head;
	Node *previous = NULL;
	

	while (current != NULL) {
		switch (current->dataType) {
			case INT:
				if (current->value.intValue == value.intValue) {
					found = true;
				}
				break;

			case LONG:
				if (current->value.longValue == value.longValue) {
					found = true;
				}
				break;

			case FLOAT:
				if (current->value.floatValue == value.floatValue) {
					found = true;
				}
				break;

			case STRING:
				if (strcmp(current->value.stringValue, value.stringValue) == 0) {
					found = true;
				}
				break;

			default:
				break;
		}

		if (found == true) {
			previous->next = current->next;
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
