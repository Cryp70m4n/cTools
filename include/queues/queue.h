#include <stdlib.h>

#include "../dataTypes.h"

typedef struct Node {
	DataType dataType;
	Value value;
} Node;

typedef struct {
	Node **data;
	int rear;
	int front;
	size_t currentQueueSize;
	size_t queueSize;
} Queue;

Queue *initQueue(size_t queueSize);
int enqueue(Queue *queue, DataType dataType, Value value);
Node dequeue(Queue *queue);
void freeQueue(Queue *queue);
