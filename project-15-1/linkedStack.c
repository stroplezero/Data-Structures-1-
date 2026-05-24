#define _CRT_SECURE_NO_WARNINGS

#include <string.h>

#include "linkedStack.h"

LinkedStack* createLinkedStack() {
	LinkedStack* re = (LinkedStack*)malloc(sizeof(LinkedStack));
	re->head = NULL;
	re->size = 0;

	return re;
}

int destroyLinkedStack(LinkedStack* s) {
	Node* nptr, * mptr;

	for (nptr = s->head; nptr != NULL; nptr = mptr) {
		mptr = nptr->next;
		free(nptr);
	}

	free(s);

	return 1;
}


int emptyLinkedStack(LinkedStack* s) {
	return s->size == 0;
}

int fullLinkedStack(LinkedStack* s) {
	return 0;
}

int pushLinkedStack(LinkedStack* s, stackElement item) {
	Node* temp = (Node*)malloc(sizeof(Node));
	strcpy(temp->data, item);
	temp->next = s->head;
	s->head = temp;

	s->size++;

	return 1;
}

stackElement* popLinkedStack(LinkedStack* s) {
	if (s->size != 0) {
		Node* nPtr = s->head;
		s->head = nPtr->next;

		stackElement* temp = (stackElement*)malloc(sizeof(stackElement));
		strcpy(temp, nPtr->data);
		free(nPtr);

		s->size--;

		return temp;
	}
	else {
		return NULL;
	}
}

stackElement* peekLinkedStack(LinkedStack* s) {
	if (s->head == NULL) {
		return (stackElement*)NULL;
	}
	else {
		stackElement* temp = s->head->data;
		return temp;
	}
}

void printLinkedStack(LinkedStack* s) {
	printf("Stack:\n");
	printf("Size: %d\n", s->size);
	Node* temp = s->head;
	while (temp != NULL) {
		printf("%s\n", temp->data);
		temp = temp->next;
	}
}
