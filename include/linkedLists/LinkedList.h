#include "../dataTypes.h"

typedef struct Node {
	DataType dataType;
	Value value;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
} LinkedList;

LinkedList *initLinkedList(void);
int insertIntoLinkedList(LinkedList *linkedList, DataType dataType, Value value);
int deleteFromLinkedList(LinkedList *linkedList, Value value);
void freeLinkedList(LinkedList *linkedList);
