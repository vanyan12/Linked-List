
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int x;
	struct Node* next;
	struct Node* prev;
} Node;


typedef struct LinkedList {
	int len;
	Node* nodes;
	void (*addNode)(LinkedList*, Node);
} LinkedList;


void func(LinkedList* list, Node p) {

	list->len += 1;

	printf("Node is added! %d\n", p.x);
}

LinkedList CreateLinkedList(int len) {

	LinkedList list;
	list.len = 0;
	list.addNode = &func;
	list.nodes = (Node*)malloc(len * sizeof(Node));


	int i = 0;

	while (i < len) {

		list.nodes[i].x = i;
		list.addNode(&list,list.nodes[i]);

		++i;
	}
	return list;
}



void LoopLinkedList(Node* p)
{

	while (p != NULL) {

		printf("%d ", p->x);

		p = p->next;
	}
}

void ReverseLinkedList(Node* p) {

	void* temp;

	while (p != NULL) {

		temp = p->prev;
		p->prev = p->next;
		p->next = temp;


		p = p->prev;
	}

}


int main()
{
	Node a1,a2,a3,a4;
	
	a4.x = 4;
	//a4.prev = &a3;
	//a4.next = NULL;
	//
	a3.x = 3;
	//a3.prev = &a2;
	//a3.next = &a4;

	a2.x = 2;
	//a2.prev = &a1;
	//a2.next = &a3;

	a1.x = 1;
	//a1.next = &a2;
	//a1.prev = NULL;

	LinkedList l = CreateLinkedList(3);

	//l.addNode(l,a1);

	printf("%d\n", l.len);

	//l.addNode = &func;

	//Node a3 = { 3, &a4 };
	//Node a2 = { 2, &a3 };
	//Node a1 = { 1, &a2 };

	//ReverseLinkedList(&a1);
	//LoopLinkedList(&a4);


	return 0;
}


