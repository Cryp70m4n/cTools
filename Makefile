CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
INCLUDES = -Iinclude/hashFunctions -Iinclude

HASHMAP_SOURCES = tests/unsortedHashmapTest.c src/hashmaps/unsortedHashmap.c src/hashFunctions/murmur3.c
QUEUE_SOURCES = tests/queueTest.c src/queues/queue.c
LINKEDLIST_SOURCES = tests/linkedListTest.c src/linkedLists/linkedList.c
BINARYSEARCH_SOURCES = tests/binarySearchTest.c src/searchAlgorithms/binarySearch.c

HASHMAP_TARGET = unsortedHashmapTest
QUEUE_TARGET = queueTest
LINKEDLIST_TARGET = linkedListTest
BINARYSEARCH_TARGET = binarySearchTest

.PHONY: all clean

all: $(HASHMAP_TARGET) $(QUEUE_TARGET) $(LINKEDLIST_TARGET) $(BINARYSEARCH_TARGET)

$(HASHMAP_TARGET): $(HASHMAP_SOURCES)
	$(CC) $(CFLAGS) -o $(HASHMAP_TARGET) $(HASHMAP_SOURCES) $(INCLUDES)

$(QUEUE_TARGET): $(QUEUE_SOURCES)
	$(CC) $(CFLAGS) -o $(QUEUE_TARGET) $(QUEUE_SOURCES)

$(LINKEDLIST_TARGET): $(LINKEDLIST_SOURCES)
	$(CC) $(CFLAGS) -o $(LINKEDLIST_TARGET) $(LINKEDLIST_SOURCES)

$(BINARYSEARCH_TARGET): $(BINARYSEARCH_SOURCES)
	$(CC) $(CFLAGS) -o $(BINARYSEARCH_TARGET) $(BINARYSEARCH_SOURCES)

clean:
	rm -f $(HASHMAP_TARGET) $(QUEUE_TARGET) $(LINKEDLIST_TARGET) $(BINARYSEARCH_TARGET)
