#include <stdio.h>

#include "../include/linkedLists/LinkedList.h"

#define TEST_SIZE 3

int main(void) {
	LinkedList *linkedList = initLinkedList();

	char *values[TEST_SIZE] = {"test", "test2", "test3"};

	int currentElement = -1;
	for(int i = 0; i < TEST_SIZE; i++) {
		if (insertIntoLinkedList(linkedList, values[i])) {
			return currentElement;
		}
		currentElement--;
	}

	if (deleteFromLinkedList(linkedList, "test") != 0) {
		return -4;
	}

	if (deleteFromLinkedList(linkedList, "test5") == 0) {
		return -5;
	}

	freeLinkedList(linkedList);

	printf("ALL TESTS PASSED!\n");

	return 0;
}
