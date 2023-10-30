#include <stdlib.h>

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
