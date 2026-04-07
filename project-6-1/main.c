#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {

	srand((unsigned)time(NULL));

	int *iPtr = (int*)malloc(sizeof(int)*SIZE);
	if (iPtr == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	int *ptr = iPtr;

	for (int i = 0; i < SIZE; i++) {
		*ptr = rand() % (SIZE + 1);
		printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");

	for (int i = SIZE; i > 0; i--) {
		ptr--;
		printf("%d ", *ptr);
	}
	printf("\n");
	
	int total = 0;
	ptr = iPtr;

	for (int i = 0; i < SIZE; i++) {
		total = total + *ptr;
		ptr++;
	}
	printf("total: %d\n", total);


	int max = *iPtr;
	int min = *iPtr;
    ptr = iPtr;

	for (int i = 1; i < SIZE; i++) {
		if (max < *(ptr + i)) {
			max = *(ptr + i);
		}
		if (min > *(ptr + i)) {
			min = *(ptr + i);
		}
	}
	printf("max: %d\n", max);
	printf("min: %d\n", min);

	free(iPtr);
	iPtr = NULL;

	return 0;
}
