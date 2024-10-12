#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
	int x;
	struct Node* next;
	struct Node* prev;
} Node;


typedef struct {
	int len;
	Node* Head;
} LinkedList;

void addNode(LinkedList* list, Node* newNode);
void delNode(LinkedList* list, Node* node);
void freeLinkedList(LinkedList* list);
LinkedList* CreateLinkedList();
void LoopLinkedList(Node* p);
void ReverseLinkedList(LinkedList* list);

#endif // LINKED_LIST_H