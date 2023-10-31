#include <stdio.h>
#include <stdint.h>

#include "../include/hashmaps/unsortedHashmap.h"



int main(void) {

    uint32_t hashSeed = 42;

	size_t hashmapSize = 17;

    unsortedHashmap *hashmap = initHashmap(hashmapSize);


	char *key = "stringTestKey";
    Value value;
	value.stringValue = "testValue";
	Value newValue;
	newValue.stringValue= "newTestValue";
	char *invalidKey = "randomKey";

	char *keyTwo = "intTestKey";
	Value valueTwo;
	valueTwo.intValue = 4;

    if (insertKey(hashmap, hashmapSize, key, STRING, value, hashSeed) != 0) {
		return -1;
	}
    
    if (insertKey(hashmap, hashmapSize, key, STRING, newValue, hashSeed) != 0) {
		return -2;
	}

	if (insertKey(hashmap, hashmapSize, keyTwo, INT, valueTwo, hashSeed) != 0 ) {
		return -3;
	}

	Node result = getValue(hashmap, hashmapSize, key, hashSeed);
	
	if (result.dataType != STRING) {
		return -4;
	}

	if (deleteValue(hashmap, hashmapSize, key, hashSeed) != 0) {
		return -5;
	}

	Node result2 = getValue(hashmap, hashmapSize, key, hashSeed);

	if (result2.dataType != INT) {
		return -6;
	}

	Node result3 = getValue(hashmap, hashmapSize, invalidKey, hashSeed);

	if (result3.dataType != VOID) {
		return -7;
	}



	freeHashmap(hashmap);

	printf("ALL TESTS PASSED\n");

    return 0;
}
