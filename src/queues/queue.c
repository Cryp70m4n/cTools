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
	queue->data = (Node**)malloc(queueSize * sizeof(Node*));

	if(queue->data == NULL) {
		free(queue);
		return NULL;
	}

	for(unsigned long int i = 0; i < queueSize; i++) {
		queue->data[i] = NULL;
	}

	return queue;
}


int enqueue(Queue *queue, DataType dataType, Value value) {
	if (queue->currentQueueSize >= queue->queueSize) {
		return -1;
	}

	if (queue->currentQueueSize == 0) {
		queue->front = 0;
		queue->rear = 0;
	} else {
		queue->rear = (queue->rear+1) % queue->queueSize;
	}

	Node *newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL) {
		return -2;
	}

	newNode->dataType = dataType;
	newNode->value = value;

	queue->data[queue->rear] = newNode;
	queue->currentQueueSize++;

	return 0;
}

Node dequeue(Queue *queue) {
	if(queue->currentQueueSize == 0) {
		Node notFound;
		Value notFoundValue;
		notFoundValue.voidValue = NULL;

		notFound.dataType = VOID;
		notFound.value = notFoundValue;

		return notFound;
	}

	Node *node = queue->data[queue->front];

	if(queue->front == queue->rear) {
		queue->front = -1;
		queue->rear = -1;
	} else {
		queue->front = (queue->front+1) % queue->queueSize;
	}

	queue->currentQueueSize++;


	return *node;
}


void freeQueue(Queue *queue) {
	free(queue->data);
	free(queue);
}

