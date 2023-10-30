typedef struct Node {
	char *data;
	struct Node *next;
} Node;

typedef struct {
	struct Node *head;
} LinkedList;

LinkedList *initLinkedList(void);
int insertIntoLinkedList(LinkedList *linkedList, char *value);
int deleteFromLinkedList(LinkedList *linkedList, char *value);
void freeLinkedList(LinkedList *linkedList);
