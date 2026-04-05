#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {

	srand((unsigned)time(NULL));

	int iArray[SIZE];

	for (int i = 0; i < SIZE; i++) {
		iArray[i] = rand() % (SIZE + 1);
		printf("%d ", iArray[i]);
	}
	printf("\n");

	for (int i = SIZE - 1; i >= 0; i--) {
		printf("%d ", iArray[i]);
	}
	printf("\n");

	int total = 0;

	for (int i = 0; i < SIZE; i++) {
		total = total + iArray[i];
	}
	printf("total: %d\n", total);

	int max = iArray[0];
	int min = iArray[0];

	for (int i = 1; i < SIZE; i++) {
		if (max < iArray[i]) {
			max = iArray[i];
		}
		if (min > iArray[i]) {
			min = iArray[i];
		}
	}
	printf("max: %d\n", max);
	printf("min: %d\n", min);

	return 0;
}
