#include "../../include/sortingAlgorithms/countingSort.h"


void countingSort(int array[], size_t arraySize) {
	int highestValue= array[0];
	int lowestValue = array[0];

	for(unsigned long int i = 0; i < arraySize; i++) {
		if(array[i] > highestValue) {
			highestValue = array[i];
		}

		if (array[i] < lowestValue) {
			lowestValue = array[i];
		}
	}

	int range = highestValue - lowestValue + 1;

	int countArray[range];

	for(int i = 0; i < range; i++) {
		countArray[i] = 0;
	}

	for(int i = 0; i < arraySize; i++) {
		countArray[array[i] - lowestValue]++;
	}

	int index = 0;

	for(int i = 0; i < range; i++) {
		while (countArray[i] > 0) {
			array[index] = i + lowestValue;
			index++;
			countArray[i]--;
		}
	}
}
