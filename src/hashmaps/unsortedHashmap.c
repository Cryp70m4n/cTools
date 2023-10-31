#include <string.h>


#include "../../include/hashFunctions/murmur3.h"
#include "../../include/hashmaps/unsortedHashmap.h"

// structs unsortedHashmap and Node are located insinde unsortedHashmap header file

unsortedHashmap *initHashmap(size_t hashmapSize) {
	unsortedHashmap *hashmap = (unsortedHashmap*)malloc(sizeof(unsortedHashmap));
	
	if (hashmap == NULL) {
		return NULL;
	}

	hashmap->table = (Node**)malloc(sizeof(Node*) * hashmapSize);
	
	if (hashmap->table == NULL) {
		free(hashmap);
		return NULL;
	}


	for(unsigned long int i = 0; i < hashmapSize; i++) {
		hashmap->table[i] = NULL;
	}

	return hashmap;
}


int insertKey(unsortedHashmap *hashmap, size_t hashmapSize, char *key, DataType dataType, Value value, uint32_t hashSeed) {
	uint64_t index = MurmurHash3(key, strlen(key), hashSeed) % hashmapSize;

	Node *newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL) {
		return -1;
	}

	newNode->key = strdup(key);
	newNode->dataType = dataType;
	newNode->value = value;
	newNode->next = NULL;

	Node *current = hashmap->table[index];
	Node *previous = NULL;

	// prevent collision attacks
	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			current->dataType = dataType;
			current->value = value;
			free(newNode->key);
			free(newNode);
			return 0;
		}

		previous = current;
		current = current->next;
	}

	if (previous == NULL) {
		hashmap->table[index] = newNode;
		return 0;
	}

	previous->next = newNode;
	return 0;
}

Node getValue(unsortedHashmap *hashmap, size_t hashmapSize, char *key, uint32_t hashSeed) {
	uint64_t index = MurmurHash3(key, strlen(key), hashSeed) % hashmapSize;

	Node *current = hashmap->table[index];

	// prevent collision attacks
	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			return *current;
		}
		current = current->next;
	}

	Node notFound;
	Value notFoundValue;
	notFoundValue.intValue = -1;

	notFound.key = NULL;
	notFound.dataType = INT;
	notFound.value = notFoundValue;

	return notFound;
}

int deleteValue(unsortedHashmap *hashmap, size_t hashmapSize, char *key, uint32_t hashSeed) {	
	uint64_t index = MurmurHash3(key, strlen(key), hashSeed) % hashmapSize;


	Node *current = hashmap->table[index];
	Node *previous = NULL;

	// prevent collision attacks
	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			if (previous == NULL) {
				hashmap->table[index] = current->next;
			} else {
				previous->next = current->next;
			}
			
			free(current->key);
			free(current);
			
			return 0;
		}
		
		previous = current;
		current = current->next;
	}

	return -1;
}


void freeHashmap(unsortedHashmap *hashmap) {
    free(hashmap->table);
    free(hashmap);
}
