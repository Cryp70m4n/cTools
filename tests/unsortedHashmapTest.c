#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "../include/hashmaps/unsortedHashmap.h"



int main(void) {

    uint32_t hashSeed = 42;

	size_t hashmapSize = 17;

    unsortedHashmap *hashmap = initHashmap(hashmapSize);


	char *key = "testKey";
    char *value = "testValue";
	char *newValue = "newTestValue";
	char *invalidKey = "randomKey";

    if (insertKey(hashmap, hashmapSize, key, value, hashSeed) != 0) {
		return -1;
	}
    
    if(getValue(hashmap, hashmapSize, key, hashSeed) == NULL) {
		return -2;
	}

    if (insertKey(hashmap, hashmapSize, key, newValue, hashSeed) != 0) {
		return -3;
	}

    if(strcmp(getValue(hashmap, hashmapSize, key, hashSeed), newValue) != 0) {
		return -4;
	}

	if(getValue(hashmap, hashmapSize, invalidKey, hashSeed) != NULL) {
		return -5;
	}


	freeHashmap(hashmap);

	printf("ALL TESTS PASSED\n");

    return 0;
}
