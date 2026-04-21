#include <stdio.h>
#include <stdlib.h>

#include "sparseMatrix.h"

int main() {

	int row = 10;
	int col = 10;

	sparseMatrix* sm = createSparseMatrix(row, col);

	int k = 0; 

	for (int i = 0; i < row && k < 20; i++) {
		for (int j = 0; j < col && k < 20; j++) {
			addElementSparseMatrix(sm, i, j, (i + j + 1) % 10);

			k++;
		}
	}

	printSparseMatrix(sm);
	printf("\n");

	sparseMatrix* transposeSM = transposeMatrix(sm);

	printf("전치 ");
	printSparseMatrix(transposeSM);
	printf("\n");
	
	return 0;
}
