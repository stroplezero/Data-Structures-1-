#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

LinkedList* createLinkedList() {
	LinkedList* r;
	r = (LinkedList*)malloc(sizeof(LinkedList)); //malloc으로 가져온 메모리는 시스템에 남아있어서 이후에도 지속적으로 사용 가능

	r->head = (PointType*)NULL;
	r->size = 0;

	return r;
}

int destroyLinkedList(LinkedList* li) {
	PointType* nptr, * mptr;

	for (nptr = li->head; nptr != NULL; nptr = mptr) {
		mptr = nptr->next;
		free(nptr);
	}

	free(li);

	return 1;
}

int isEmptyLinkedList(LinkedList* li) {
	return (li->size == 0);
}

int sizeLinkedList(LinkedList* li) {
	return li->size;
}

LinkedList* insertFirstLinkedList(LinkedList* li, PointType item) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	*ptr = item;

	ptr->next = li->head;
	li->head = ptr;
	li->size++;

	return li;
}

int printLinkedList(LinkedList* li) {
	PointType* current = li->head;
	printf("LinkedList:\n");
	for (int i = 0; i < li->size; i++) {
		printf("x: %d, y: %d, next: %x\n", current->x, current->y, current->next);

		current = current->next;
	}
}

LinkedList* insertLastLinkedLikst(LinkedList* li, PointType item) {
	PointType* ptr = li->head;

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	nPtr->next = NULL;

	ptr->next = nPtr;

	li->size++;

	return li;
}

LinkedList* deleteAtLinkedList(LinkedList* li, int at) {
	if (at >= 0 && at < li->size) {
		PointType* nPtr = li->head;
    
		for (int i = 0; i < at - 1; i++) {
			nPtr = nPtr->next;
		}

		if (at == 0) {
			PointType* fPtr = li->head;
			li->head = fPtr->next;
			free(fPtr);
		}
		else {
			PointType* fPtr = nPtr->next;
			nPtr->next = fPtr->next;
			free(fPtr);
		}

		li->size--;
	}

	return li;
}
