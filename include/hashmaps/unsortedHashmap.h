#include <stdlib.h>
#include <stdint.h>

#include "../dataTypes.h"


typedef struct Node {
	char *key;
	DataType dataType;
	Value value;
	struct Node *next;
} Node;

typedef struct {
	Node **table;
	size_t hashmapSize;
} unsortedHashmap;


unsortedHashmap* initHashmap(size_t hashmapSize);
int insertKey(unsortedHashmap *hashmap, size_t hashmapSize, char *key, DataType dataType, Value value, uint32_t hashSeed);
Node getValue(unsortedHashmap *hashmap, size_t hashmapSize, char *key, uint32_t hashSeed);
int deleteValue(unsortedHashmap *hashmap, size_t hashmapSize, char *key, uint32_t hashSeed);
void freeHashmap(unsortedHashmap *hashmap);
