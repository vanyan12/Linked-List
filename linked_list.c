#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void addNode(LinkedList* list, Node* newNode, Node* addBefore, int show) {
	newNode->next = NULL;

	if (list->Head == NULL) {
		newNode->prev = NULL;
		list->Head = newNode;
	}
	else {
		Node* last = list->Head;
		while (last->next != addBefore) {
			last = last->next;
		}

		last->next = newNode;
		newNode->prev = last;

		if (addBefore != NULL) {
			newNode->next = addBefore;
			addBefore->prev = newNode;
		}

	}

	list->len += 1;
	

	if (show) {
		printf("Node is added: ");
		Traverse(list->Head);
	}
	else {
		printf("Node is added!\n");
	}


}

void delNode(LinkedList* list, Node* node, int show) {
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



	if (show) {
		printf("Node is delated: ");
		Traverse(list->Head);
	}
	else {
		printf("Node is delated!\n");
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

void Traverse(Node* p)
{

	while (p != NULL) {
		if (p->next != NULL) {
			printf("%d --> ", p->x);
		}
		else {
			printf("%d\n", p->x);
		}

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

bool Search(Node* p, int data) {

	while (p != NULL) {
		if (p->x == data) {
			printf("%d is in the linked list.\n\n", data);
			return true;
		}

		p = p->next;
	}

	printf("%d is not in the linked list.\n\n", data);
	return false;
}

int main() {

	//Creating emoty Linked List
	LinkedList* list = CreateLinkedList();

	//Creating nodes
	Node a1 = { 1 };
	Node a2 = { 2 };
	Node a3 = { 3 };
	Node a4 = { 4 };

	//Adding nodes. If addBefore is NULL it will automatically add to the tail of list
	addNode(list, &a1, NULL, 0);
	addNode(list, &a2, NULL, 0);
	addNode(list, &a3, NULL, 0);
	addNode(list, &a4, &a3, 0);

	//Printing linked list
	Traverse(list->Head);

	//Reversing linked list
	ReverseLinkedList(list);

	Traverse(list->Head);

	//Searching data in linked list. Node* p is the node from which starts searching
	Search(list->Head, 3);
	Search(list->Head, 8);
	Search(&a4, 3);

	SortLinkedList(list);

	Node a5 = { 2 };

	addNode(list, &a5, NULL, 0);

	Traverse(list->Head);

	SortLinkedList(list);


	freeLinkedList(list);


}