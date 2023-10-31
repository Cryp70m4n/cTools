#include <stdio.h>
#include <string.h>

#include "../include/queues/queue.h"


int main() {

    Queue *queue = initQueue(20);

	Value val1;
	val1.stringValue = "test";
	Value val2;
	val2.stringValue = "test2";
	Value val3;
	val3.intValue = 3;

    enqueue(queue, STRING, val1);
    enqueue(queue, STRING, val2);
    enqueue(queue, INT, val3);

	Node item = dequeue(queue);

	char *out;

	if(item.dataType == STRING) {
		out = item.value.stringValue;
		if (strcmp(out, "test") != 0) {
			return -1;
		}
	}


	freeQueue(queue);


	printf("ALL TESTS PASSED!\n");

    return 0;
}
