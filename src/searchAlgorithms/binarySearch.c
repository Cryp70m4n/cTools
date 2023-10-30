#include "../../include/searchAlgorithms/binarySearch.h"

int binarySearch(int array[], size_t arrayLength, int target) {
		int high = arrayLength;
		int low = 0;

		while (high >= low) {
			int index = (low+high) / 2;

			if (array[index] == target) {
				return index;
			} else if (array[index] > target) {
				high = index - 1;
			} else {
				low = index + 1;
			}
		}

		return -1;
}
