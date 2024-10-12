
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>


void addNode(LinkedList* list, Node* newNode) {
	newNode->next = NULL;

	if (list->Head == NULL) {
		newNode->prev = NULL;
		list->Head = newNode;
	}
	else {
		Node* last = list->Head;
		while (last->next != NULL) {
			last = last->next;
		}

		last->next = newNode;
		newNode->prev = last;
	}

	list->len += 1;

	printf("Node is added!\n");
}

void delNode(LinkedList* list, Node* node) {
	Node* current = list->Head;

	if (current == node) {
		node->next->prev = NULL;
		list->Head = node->next;
		return;
	}
	
	while (current->next != node) {
		current = current->next;
	}

	current->next = node->next;
	if (node->next != NULL) {
		node->next->prev = current;
	}

}


void freeLinkedList(LinkedList* list) {
	free(list);
}


LinkedList* CreateLinkedList() {

	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	list->len = 0;
	list->Head = NULL;

	return list;
}



void LoopLinkedList(Node* p)
{

	while (p != NULL) {

		printf("%d ", p->x);

		p = p->next;
	}
	printf("\n");

}

void ReverseLinkedList(LinkedList* list) {
	Node* current = list->Head;
	Node* temp = NULL;

	while (current != NULL) {

		temp = current->prev;
		current->prev = current->next;
		current->next = temp;

		current = current->prev;
	}

	if (temp != NULL) {
		list->Head = temp->prev;
	}


}



