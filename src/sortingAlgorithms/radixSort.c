#include "../../include/sortingAlgorithms/radixSort.h"


/* countingSort is already implemented in separate header but I did not want to calculate highest and lowest value twice 
 * and make function's timeComplexity bigger. I already have to calculate highest value in array for Radix sort.
*/

// Add warning in the docs that we use int countArray[range] instead of malloc if array has huge value like 444444 it will segfault.

void countingSortForRadixSort(int array[], size_t arraySize, int highestValue, int lowestValue) {

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


void radixSort(int array[], size_t arraySize) {
	int highestValue = array[0];
	int lowestValue = array[0];

	for(unsigned long int i = 1; i < arraySize; i++) {
		if (array[i] > highestValue) {
			highestValue = array[i];
		}

		if (array[i] < lowestValue) {
			lowestValue = array[i];
		}
	}

	for(int exp = 1; highestValue / exp > 0; exp*=10) {
		countingSortForRadixSort(array, arraySize, highestValue, lowestValue);
	}
}

