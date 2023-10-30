#include <stdio.h>

#include "../include/searchAlgorithms/binarySearch.h"

#define ARRAY_SIZE 5

int main(void) {
	int array[ARRAY_SIZE] = {1, 2, 3, 4, 5};

	if(binarySearch(array, ARRAY_SIZE, 1) != 0) {
		return -1;
	}

	if(binarySearch(array, ARRAY_SIZE, 2) != 1) {
		return -2;
	}

	if(binarySearch(array, ARRAY_SIZE, 3) != 2) {
		return -3;
	}

	if(binarySearch(array, ARRAY_SIZE, 4) != 3) {
		return -4;
	}

	if(binarySearch(array, ARRAY_SIZE, 5) != 4) {
		return -5;
	}

	if(binarySearch(array, ARRAY_SIZE, 6) != -1) {
		return -6;
	}

	printf("ALL TESTS PASSED!\n");

	return 0;
}
