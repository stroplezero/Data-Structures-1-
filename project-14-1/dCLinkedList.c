#include "dCLinkedList.h"

DCLinkedList* createDCLinkedList() {
	DCLinkedList* d;
	d = (DCLinkedList*)malloc(sizeof(DCLinkedList)); //malloc으로 가져온 메모리는 시스템에 남아있어서 이후에도 지속적으로 사용 가능
	d->head = (PointType*)malloc(sizeof(PointType));

	d->head->prev = d->head;
	d->head->next = d->head;
	d->head->num = (int)NULL;
	d->size = 0;

	return d;
}

int destroyDCLinkedList(DCLinkedList* li) {
	PointType* nptr, * mptr;

	for (nptr = li->head->next; nptr != li->head; nptr = mptr) {
		mptr = nptr->next;
		free(nptr);
	}

	free(li);

	return 1;
}

int isEmptyDCLinkedList(DCLinkedList* li) {
	return (li->size == 0);
}

int sizeDCLinkedList(DCLinkedList* li) {
	return li->size;
}

DCLinkedList* insertFirstDCLinkedList(DCLinkedList* li, int item) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	ptr->num = item;

	ptr->next = li->head->next;
	ptr->next->prev = ptr;
	li->head->next = ptr;
	ptr->prev = li->head;

	li->size++;

	return li;
}

DCLinkedList* insertLastDCLinkedList(DCLinkedList* li, int item) {
	PointType* ptr = li->head;

	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	nPtr->num = item;

	ptr->prev->next = nPtr;
	nPtr->prev = ptr->prev;
	ptr->prev = nPtr;
	nPtr->next = ptr;

	li->size++;

	return li;
}

DCLinkedList* insertItemDCLinkedList(DCLinkedList* li, PointType* pre, int item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	nPtr->num = item;

	pre->next->prev = nPtr;
	nPtr->next = pre->next;
	pre->next = nPtr;
	nPtr->prev = pre;


	li->size++;

	return li;
}

PointType deleteFirstDCLinkedList(DCLinkedList* li) {
	if (li->size != 0) {
		PointType* tPtr = li->head->next;

		li->head->next = tPtr->next;
		tPtr->next->prev = tPtr->prev;

		PointType temp = *tPtr;
		free(tPtr);

		li->size--;

		return temp;
	}
	else {
		return (PointType) { 0, 0, 0 };
	}
}

PointType deleteLastDCLinkedList(DCLinkedList* li) {
	if (li->size != 0) {
		PointType* tPtr = li->head->prev;

		li->head->prev = tPtr->prev;
		tPtr->prev->next = tPtr->next;

		PointType temp = *tPtr;
		free(tPtr);

		li->size--;

		return temp;
	}
	else {
		return (PointType) { 0, 0, 0 };
	}
}

PointType deleteItemDCLinkedList(DCLinkedList* li, int pos) {
	PointType* iPtr;

	iPtr = li->head;

	if (li->size == 0) {
		return (PointType) { 0, 0, 0 };
	}

	while (iPtr->next != li->head && iPtr->num != pos) {
		iPtr = iPtr->next;
	}

	if (iPtr == li->head) {
		printf("삭제할 아이템을 찾지 못했습니다.\n");
		return (PointType) { 0, 0, 0 };
	}

	PointType temp;
	temp = *iPtr;

	iPtr->prev->next = iPtr->next;
	iPtr->next->prev = iPtr->prev;
	free(iPtr);

	li->size--;

	return temp;
}


DCLinkedList* insertAtDCLinkedList(DCLinkedList* li, int at, int item) {
	PointType* iPtr = (PointType*)malloc(sizeof(PointType));
	iPtr->num = item;

	if (at >= 0 && at < li->size) {
		PointType* nPtr = li->head;

		for (int i = 0; i <= at; i++) {
			nPtr = nPtr->next;
		}

		nPtr->prev->next = iPtr;
		iPtr->prev = nPtr->prev;
		iPtr->next = nPtr;
		nPtr->prev = iPtr;

		li->size++;
	}

	return li;
}

DCLinkedList* deleteAtDCLinkedList(DCLinkedList* li, int at) {
	if (at >= 0 && at < li->size) {
		PointType* nPtr = li->head;

		for (int i = 0; i <= at; i++) {
			nPtr = nPtr->next;
		}

		nPtr->prev->next = nPtr->next;
		nPtr->next->prev = nPtr->prev;

		free(nPtr);
		li->size--;
	}

	return li;
}

PointType getItemDCLinkedList(DCLinkedList* li, PointType* pos) {
	PointType temp;

	if (pos == NULL) {
		temp = *li->head;
		return temp;
	}

	temp = *pos;

	return temp;
}

void replaceItemDCLinkedList(DCLinkedList* li, PointType* pos, int item) {
	if (pos == NULL) {
		return;
	}

	pos->num = item;
}

PointType nextItemDCLinkedList(DCLinkedList* li, PointType* pre) {
	PointType temp;

	if (pre == NULL) {
		temp = *li->head->next;
		return temp;
	}

	temp = *pre->next;

	return temp;
}

int printDCLinkedList(DCLinkedList* li) {
	PointType* current = li->head->next;
	printf("Doubly Circular LinkedList:\n");
	printf("head: prev: %x, num: %d, next: %x\n", li->head->prev, li->head->num, li->head->next);
	printf("size: %d\n", li->size);

	for (int i = 0; i < li->size; i++) {
		printf("[%d] prev: %x, num: %d, next: %x\n", i, current->prev, current->num, current->next);

		current = current->next;
	}

	return 1;
}
