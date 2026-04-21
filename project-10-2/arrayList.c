#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

arrayList* createArrayList(int size) {
	arrayList* al;
	al = (arrayList*)malloc(sizeof(arrayList));

	al->data = (elementArrayList*)malloc(sizeof(elementArrayList) * size);
	al->size = 0;
	al->capacity = size;

	return al;
}

void destroyArrayList(arrayList* al) {
	free(al->data);
	free(al);
}

int isEmptyArrayList(arrayList* al) {
	if (al->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFullArrayList(arrayList* al) {
	if (al->size == al->capacity) {
		return 1;
	}
	else {
		return 0;
	}
}

int sizeArrayList(arrayList* al) {
	return al->size;
}

int insertArrayList(arrayList* al, int pos, elementArrayList item) {
	if (pos < 0 || pos > al->size) {

		return 0;
	}

	if (isFullArrayList(al) == 1) {
		elementArrayList* temp = (elementArrayList*)realloc(al->data, (al->capacity * 2) * sizeof(elementArrayList));
		printf("확장 성공!");

		if (temp == NULL) {
			printf("확장 실패");
			return 1;
		}

		al->data = temp;
		al->capacity = al->capacity * 2;
	}

	for (int i = al->size - 1; i >= pos; i--) {
		al->data[i + 1] = al->data[i];
	}

	al->data[pos] = item;
	al->size++;

	return 1;
}

elementArrayList deleteArrayList(arrayList* al, int pos) {
	if (pos < 0 || pos > al->size - 1) {
		elementArrayList errorItem = { -1, -1, 0 };
		return errorItem;
	}

	elementArrayList item = al->data[pos];

	for (int i = pos; i < al->size - 1; i++) {
		al->data[i] = al->data[i + 1];
	}

	al->size--;

	return item;
}

int initArrayList(arrayList* al) {
	for (int i = al->size - 1; i >= 0; i--) {
		deleteArrayList(al, i);
	}

	return 1;
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
	return al->data[pos];
}

int replaceItemArrayList(arrayList* al, int pos, elementArrayList item) {
	if (pos < 0 || pos > al->size - 1) {
		return 0;
	}

	al->data[pos] = item;

	return 1;
}

void printArrayList(arrayList* al) {
	if (al->size == 0) {
		printf("리스트가 비어 있습니다.\n");
		return;
	}

	for (int i = 0; i < al->size; i++) {
		printf("(%d, %d, %d)\n", al->data[i].row, al->data[i].col, al->data[i].value);
	}
}

void clearArrayList(arrayList* al) {
	al->size = 0;
}
