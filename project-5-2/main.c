#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

int main() {
	int iArray[SIZE][SIZE] = {0};

	int r = 0;
	int c = SIZE / 2;

	for (int i = 1; i <= (SIZE * SIZE); i++) {
		iArray[r][c] = i;

		int next_r = r - 1;
		int next_c = c + 1;

		if (next_r < 0) {
			next_r = SIZE - 1;
		}

		if (next_c >= SIZE) {
			next_c = 0;
		}

		if (iArray[next_r][next_c] != 0) {
			r = (r + 1) % SIZE;
		}
		else {
			r = next_r;
			c = next_c;
		}	

	}
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++) {
			printf("%d\t", iArray[i][j]);
		}
		printf("\n");
	}

	int sum_r[SIZE] = { 0 };
	int sum_c[SIZE] = { 0 };
	int sumMainDiagonal = 0, sumAntiDiagonal = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			sum_r[i] = sum_r[i] + iArray[i][j];
		}
		printf("row %d sum: %d\n", i, sum_r[i]);
	}  

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			sum_c[i] = sum_c[i] + iArray[j][i];
		}
		printf("column %d sum_c: %d\n", i, sum_c[i]);
	}

	for (int i = 0; i < SIZE; i++) {
		sumMainDiagonal = sumMainDiagonal + iArray[i][i];
	}
	printf("main diagonal: %d\n", sumMainDiagonal);

	for (int i = 0; i < SIZE; i++) {
		sumAntiDiagonal = sumAntiDiagonal + iArray[i][(SIZE - 1) - i];
	}
	printf("anti diagonal: %d\n", sumAntiDiagonal);

	return 0;
}
