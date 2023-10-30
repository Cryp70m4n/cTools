#include <stdlib.h>
#include <stdint.h>


typedef struct Node {
	char *key;
	char *value;
	struct Node *next;
} Node;

typedef struct {
	Node **table;
	size_t hashmapSize;
} unsortedHashmap;


unsortedHashmap* initHashmap(size_t hashmapSize);
int insertKey(unsortedHashmap *hashmap, size_t hashmapSize, char *key, char *value, uint32_t hashSeed);
char *getValue(unsortedHashmap *hashmap, size_t hashmapSize, char *key, uint32_t hashSeed);
int deleteKey(unsortedHashmap *hashmap, size_t hashmapSize, char *key, uint32_t hashSeed);
void freeHashmap(unsortedHashmap *hashmap);
