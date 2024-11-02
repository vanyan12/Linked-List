#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

typedef struct Node {
	int x;
	struct Node* next;
	struct Node* prev;
} Node;


typedef struct {
	int len;
	Node* Head;
} LinkedList;

void addNode(LinkedList* list, Node* newNode, Node* addBefore, int show);
void delNode(LinkedList* list, Node* node, int show);
void freeLinkedList(LinkedList* list);
LinkedList* CreateLinkedList();
void Traverse(Node* p);
bool Search(Node* p, int data);
void ReverseLinkedList(LinkedList* list);

#endif // LINKED_LIST_H