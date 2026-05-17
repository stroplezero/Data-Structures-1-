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

LinkedList* insertFirstLinkedList(LinkedList* li, int item) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	ptr->num = item;

	ptr->next = li->head;
	li->head = ptr;
	li->size++;

	return li;
}

int printLinkedList(LinkedList* li) {
	PointType* current = li->head;
	printf("LinkedList:\n");

	for (int i = 0; i < li->size; i++) {
		printf("num: %d, next: %x\n", current->num, current->next);

		current = current->next;
	}

	return 1;
}

LinkedList* insertLastLinkedList(LinkedList* li, int item) {
	PointType* ptr = li->head;

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	nPtr->num = item;
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

LinkedList* insertItemLinkedList(LinkedList* li, PointType* pre, int item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	nPtr->num = item;

	if (pre != NULL) {
		nPtr->next = pre->next;
		pre->next = nPtr;

		li->size++;
	}
	else {
		nPtr->next = li->head;
		li->head = nPtr;

		li->size++;
	}

	return li;
}

PointType deleteFirstLinkedList(LinkedList* li) {
	if (li->size != 0) {
		PointType* tPtr = li->head;
		li->head = tPtr->next;

		PointType temp = *tPtr;
		free(tPtr);

		li->size--;

		return temp;
	}
	else {
		return (PointType) { 0, 0 };
	}
}

PointType deleteLastLinkedList(LinkedList* li) {
	PointType* pre;
	PointType* iPtr;

	pre = li->head;

	if (pre == NULL) {
		return (PointType) { 0, 0 };
	}

	iPtr = pre->next;

	if (iPtr == NULL) {
		li->head = NULL;

		PointType temp;
		temp = *pre;
		free(pre);

		li->size--;

		return temp;
	}
	else {
		while (iPtr->next != NULL) {
			pre = iPtr;
			iPtr = iPtr->next;
		}

		PointType temp;
		temp = *iPtr;

		pre->next = NULL;
		free(iPtr);

		li->size--;

		return temp;
	}
}

PointType deleteItemLinkedList(LinkedList* li,int pos) {
	PointType* pre;
	PointType* iPtr;

	pre = NULL;
	iPtr = li->head;

	if (iPtr == NULL) {
		return (PointType) { 0, 0 };
	}

	if (iPtr->num == pos) {
		PointType temp = *iPtr;
		deleteFirstLinkedList(li);
		return temp;
	}

	while (iPtr != NULL && iPtr->num != pos) {
		pre = iPtr;
		iPtr = iPtr->next;
	}

	if (iPtr == NULL) {
		printf("삭제할 아이템을 찾지 못했습니다.\n");
		return (PointType) { 0, 0 };
	}
	
	PointType temp;
	temp = *iPtr;

	pre->next = iPtr->next;
	free(iPtr);

	li->size--;

	return temp;
}

LinkedList* insertAtlinkedList(LinkedList* li, int at, int item) {
	PointType* iPtr = (PointType*)malloc(sizeof(PointType));
	iPtr->num = item;

	if (at >= 0 && at < li->size) {
		PointType* nPtr = li->head;

		for (int i = 0; i < at - 1; i++) {
			nPtr = nPtr->next;
		}

		if (at == 0) {
			iPtr->next = li->head;
			li->head = iPtr;
		}
		else {
			iPtr->next = nPtr->next;
			nPtr->next = iPtr;
		}

		li->size++;
	}

	return li;
}

PointType getItemLinkedList(LinkedList* li, PointType* pos) {

	if (pos == NULL) {
		return (PointType) { 0, 0 };
	}

	PointType temp = *pos;

	return temp;
}

void replaceItemLinkedList(LinkedList* li, PointType* pos, int item) {

	if (pos == NULL) {
		return;
	}

	pos->num = item;
}

PointType nextItemLinkedList(LinkedList* li, PointType* pre) {
	PointType temp;

	if (pre == NULL) {
		return (PointType) { 0, 0 };
	}

	temp = *pre->next;

	return temp;
}
