#include <stdio.h>
#include <string.h>

#include "../include/queues/queue.h"


int main() {

    Queue *queue = initQueue(20);

	char *val1 = "test";
	char *val2 = "test2";
	char *val3 = "test3";

    enqueue(queue, val1);
    enqueue(queue, val2);
    enqueue(queue, val3);


	if (strcmp(dequeue(queue), val1) != 0) { return -1; }
	if (strcmp(dequeue(queue), val2) != 0) { return -2; }
	if (strcmp(dequeue(queue), val3) != 0) { return -3; }

	freeQueue(queue);


	printf("ALL TESTS PASSED!\n");

    return 0;
}
