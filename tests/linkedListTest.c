#include <stdio.h>

#include "../include/linkedLists/LinkedList.h"

#define TEST_SIZE 3

int main(void) {
	LinkedList *linkedList = initLinkedList();

	Value test;
	test.stringValue = "test";
	Value test2;
	test2.intValue = 2;
	Value test3;
	test3.stringValue = "test3";

	if (insertIntoLinkedList(linkedList, STRING, test) != 0) {
		return -1;
	}

	if (insertIntoLinkedList(linkedList, INT, test2) != 0) {
		return -2;
	}

	if (insertIntoLinkedList(linkedList, STRING, test3) != 0) {
		return -3;
	}

	if (deleteFromLinkedList(linkedList, test) != 0) {
		return -4;
	}



	freeLinkedList(linkedList);

	printf("ALL TESTS PASSED!\n");

	return 0;
}
