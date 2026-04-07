#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

int main() {
	int *iPtr = (int*)malloc(sizeof(int) * SIZE * SIZE);
	if (iPtr == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}
	memset(iPtr, 0, sizeof(int) * SIZE * SIZE);

	int *ptr = iPtr + (SIZE / 2);

	for (int i = 1; i <= (SIZE * SIZE); i++) {
		*ptr = i;

		int* next_p = ptr - SIZE;

		if (next_p < iPtr) {
			next_p = next_p + (SIZE * SIZE);
		}

		int* row_start = iPtr + ((next_p - iPtr) / SIZE) * SIZE;
		int* row_end = row_start + SIZE;

		next_p = next_p + 1;

		if (next_p >= row_end) {
			next_p = row_start;
		}

		if (*next_p != 0) {
			ptr = ptr + SIZE;
			if (ptr >= iPtr + (SIZE * SIZE)) {
				ptr = ptr - (SIZE * SIZE);
			}
		}
		else {
			ptr = next_p;
		}
	}

	ptr = iPtr;

	for (int i = 0; i < (SIZE * SIZE); i++) {
		printf("%d\t", *(ptr + i));

		if ((i + 1) % SIZE == 0) {
			printf("\n");
		}

	}

	int sum_r[SIZE] = { 0 };
	int sum_c[SIZE] = { 0 };
	int sumMainDiagonal = 0, sumAntiDiagonal = 0;

	int* sum_rPtr = sum_r;
	int* sum_cPtr = sum_c;

	for (int i = 0; i < (SIZE); i++) {
		sum_rPtr = sum_r + i;

		for (int j = 0; j < SIZE; j++) {
			*sum_rPtr = *sum_rPtr + *(ptr + (i * SIZE) + j);
		}
		printf("row %d sum: %d\n", i, *sum_rPtr);
	}

	for (int i = 0; i < SIZE; i++) {
		sum_cPtr = sum_c + i;

		for (int j = 0; j < SIZE; j++) {
			*sum_cPtr = *sum_cPtr + *(ptr + (j * SIZE) + i);
		}
		printf("column %d sum_c: %d\n", i, *sum_cPtr);
	}

	for (int i = 0; i < SIZE; i++) {
		sumMainDiagonal = sumMainDiagonal + *(iPtr + (i * SIZE) + i);
	}
	printf("main diagonal: %d\n", sumMainDiagonal);

	for (int i = 0; i < SIZE; i++) {
		sumAntiDiagonal = sumAntiDiagonal + *(iPtr + ((SIZE - 1 - i) * SIZE) + i);
	}
	printf("anti diagonal: %d\n", sumAntiDiagonal);

	free(iPtr);
	iPtr = NULL;
	return 0;
}
