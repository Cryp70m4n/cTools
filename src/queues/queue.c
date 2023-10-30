#include <string.h>

#include "../../include/queues/queue.h"


// struct Queue is located inside header file

Queue *initQueue(size_t queueSize) {
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	
	if(queue == NULL) {
		return NULL;
	}

	queue->front = -1;
	queue->rear = -1;
	queue->currentQueueSize = 0;
	queue->queueSize = queueSize;
	queue->data = (char **)malloc(queueSize * sizeof(char *));

	if(queue->data == NULL) {
		free(queue);
		return NULL;
	}

	for(unsigned long int i = 0; i < queueSize; i++) {
		queue->data[i] = NULL;
	}

	return queue;
}


int enqueue(Queue *queue, char *value) {
	if (queue->currentQueueSize >= queue->queueSize) {
		return -1;
	}

	if (queue->currentQueueSize == 0) {
		queue->front = 0;
		queue->rear = 0;
	} else {
		queue->rear = (queue->rear+1) % queue->queueSize;
	}

	queue->data[queue->rear] = strdup(value);
	queue->currentQueueSize++;

	return 0;
}

char *dequeue(Queue *queue) {
	if(queue->currentQueueSize == 0) {
		return NULL;
	}

	char *value = queue->data[queue->front];

	if(queue->front == queue->rear) {
		queue->front = -1;
		queue->rear = -1;
	} else {
		queue->front = (queue->front+1) % queue->queueSize;
	}

	queue->currentQueueSize++;

	return value;
}


void freeQueue(Queue *queue) {
	free(queue->data);
	free(queue);
}
