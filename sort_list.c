#include "linked_list.h"
#include <stdio.h>

Node* Merge(Node* Left, Node* Right) {
	// If one of the parts is empty, merged list will be another
	if (Left == NULL) return Right;
	if (Right == NULL) return Left;

	// Using Dummy for getting head in the end
	Node Dummy;
	Node* tail = &Dummy;

	while (Left != NULL && Right != NULL) {
		if (Left->x < Right->x) {

			tail->next = Left;
			Left->prev = tail;

			Left = Left->next;
		}
		else {
			tail->next = Right;
			Right->prev = tail;

			Right = Right->next;
		}

		tail = tail->next;
	}

	if (Left != NULL) {
		tail->next = Left;
		Left->prev = tail;
	}

	if (Right != NULL) {
		tail->next = Right;
		Right->prev = tail;
	}

	// Closing First Node, making it as head
	Dummy.next->prev = NULL;
	return Dummy.next;



}

void Split_List(Node* head, Node** Left, Node** Right) {

	Node* slow = head;
	Node* fast = head->next;

	while (fast != NULL) {

		fast = fast->next;

		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	*Right = slow->next;
	(*Right)->prev = NULL;

	slow->next = NULL;
	*Left = head;
}



Node* MergeSort(Node* head) {

	if (head == NULL || head->next == NULL) {
		return;
	}
	
	Node* LeftHalf;
	Node* RightHalf;

	Split_List(head, &LeftHalf, &RightHalf);

	LeftHalf = MergeSort(LeftHalf);
	RightHalf = MergeSort(RightHalf);

	return Merge(LeftHalf, RightHalf);

}

void SortLinkedList(LinkedList* list) {
	if (list->Head == NULL || list->len < 2) {
		return;
	}

	list->Head = MergeSort(list->Head);
	
	printf("Sorted Linked List: ");
	Traverse(list->Head);
}
