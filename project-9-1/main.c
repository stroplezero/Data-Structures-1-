#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

int main() {
	arrayList* myArrayList;
	myArrayList = createArrayList(2);

	if (sizeArrayList(myArrayList) == 0) {
		printf("Create ok\n");
	}

	printf("할당된 크기: %d 바이트\n", myArrayList->capacity);

	// Insert test
	insertArrayList(myArrayList, 0, 10); 
	insertArrayList(myArrayList, 1, 20);
	insertArrayList(myArrayList, 2, 30);
	insertArrayList(myArrayList, 0, 5);
	insertArrayList(myArrayList, 0, 5);
	insertArrayList(myArrayList, 0, 5);
	
	printArrayList(myArrayList);

	// Delete test
	deleteArrayList(myArrayList, 0);
	deleteArrayList(myArrayList, 1);
	deleteArrayList(myArrayList, 2);

	printArrayList(myArrayList);
}
