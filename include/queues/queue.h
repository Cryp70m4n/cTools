#include <stdlib.h>

#include "../dataTypes.h"

typedef struct Node {
	DataType dataType;
	Value value;
} Node;


// UPDATE QUEUE TO USE DATA TYPES
typedef struct {
	char **data;
	int rear;
	int front;
	size_t currentQueueSize;
	size_t queueSize;
} Queue;

Queue *initQueue(size_t queueSize);
int enqueue(Queue *queue, char *value);
char *dequeue(Queue *queue);
void freeQueue(Queue *queue);
