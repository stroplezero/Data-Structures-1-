#include <stdio.h>
#include <stdlib.h>

#include "sparseMatrix.h"

sparseMatrix* createSparseMatrix(int row, int col) {
	sparseMatrix* sm;
	sm = (sparseMatrix*)malloc(sizeof(sparseMatrix));
	sm->row = row;
	sm->col = col;
	sm->value = createArrayList(row * col);

	return sm;
}

int addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value) {
	int size;
	size = sizeArrayList(sm->value);

	insertArrayList(sm->value, size, (elementArrayList) { row, col, value });

	return 1;
}

int printSparseMatrix(sparseMatrix* sm) {
	printf("희소 행렬: \n");

	printArrayList(sm->value);

	return 1;
}

sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2) {
	sparseMatrix* smResult = createSparseMatrix(sm1->row, sm1->col);

	for (int i = 0; i <= sizeArrayList(sm1->value); i++) {
		elementArrayList nonZeroOfSM1 = getItemArrayList(sm1, i);

		int j;
		for (j = 0; j <= sizeArrayList(sm2->value); j++) {
			elementArrayList nonZeroOfSM2 = getItemArrayList(sm2, j);

			if (nonZeroOfSM1.col == nonZeroOfSM2.col && nonZeroOfSM1.row == nonZeroOfSM2.row) {
				insertArrayList(smResult, sizeArrayList(smResult), (elementArrayList) {
					nonZeroOfSM1.row,
					nonZeroOfSM1.col,
					nonZeroOfSM1.value + nonZeroOfSM2.value
				});

				break;
			}
		}

		if (j == sizeArrayList(sm2->value)) {
			insertArrayList(smResult, sizeArrayList(smResult),nonZeroOfSM1);
		}
	}

	return smResult;
}

sparseMatrix* transposeMatrix(sparseMatrix* sm) {

	sparseMatrix* transposeSM = createSparseMatrix(sm->col, sm->row);
	int moveCount = 0;

	if (sm->value->size > 0) {
		for (int i = 0; i < sm->col; i++) {

			for (int j = 0; j < sm->value->size; j++) {
				elementArrayList temp = sm->value->data[j];

				if (temp.col == i) {
					addElementSparseMatrix(transposeSM, temp.col, temp.row, temp.value);

					moveCount++;
				}
			}
		}
	}
	printf("총 데이터 이동 횟수: %d\n", moveCount);

	return transposeSM;
}
