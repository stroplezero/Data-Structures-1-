#define _CRT_SECURE_NO_WARNINGS
#include "polynomial.h"

polynomial* createPolynomial(int capacity) {
	polynomial* po = (polynomial*)createArrayList(capacity);
	return po;
}

polynomial* addItemPolynomial(polynomial* po, elementType item) {
	int i;
	for (i = 0; i < sizeArrayList(po); i++) {
		if (po->data[i].expo <= item.expo) {
			break;
		}
	}

	if (i == sizeArrayList(po)) {
		insertArrayList(po, i, item);
	}
	else if (po->data[i].expo == item.expo) {
		po->data[i].coef += item.coef;
	}
	else {
		insertArrayList(po, i, item);
	}

	return po;
}

polynomial* addPolynomial(polynomial* p1, polynomial* p2) {
	polynomial* r = createPolynomial(100);

	int i = 0, j = 0;

	while (i < sizeArrayList(p1) && j < sizeArrayList(p2)) {
		if (p1->data[i].expo < p2->data[j].expo) {
			addItemPolynomial(r, p2->data[j]);
			j++;
		}
		else if (p1->data[i].expo > p2->data[j].expo) {
			addItemPolynomial(r, p1->data[i]);
			i++;
		}
		else {
			int sumCoef = p1->data[i].coef + p2->data[j].coef;

			if (sumCoef != 0) {
				addItemPolynomial(r, (elementType) { sumCoef, p1->data[i].expo });
			}

			i++;
			j++;
		}
	}

	while (i < p1->size) {
		addItemPolynomial(r, p1->data[i]);
		i++;
	}

	while (j < p2->size) {
		addItemPolynomial(r, p2->data[j]);
		j++;
	}

	return r;
}

void printPolynomial(polynomial* po) {
	printf("Polynomial: \n");

	printArrayList(po);

	printf("\n");
}

polynomial* inputPolynomial(polynomial* po) {
	char op = '+';

	while (po->size < 100) {
		int c;
		int e;

		if (scanf("%dX^%d", &c, &e) == 2) {
			if (op == '-') {
				c = -c;
			}

			po->data[po->size].coef = c;
			po->data[po->size].expo = e;
			po->size++;
		}
		if (scanf("%c", &op) != 1 || (op != '+' && op != '-')) {
			break;
		}
	}
	return po;
}

polynomial* multiPolynomial(polynomial* p1, polynomial* p2) {
	polynomial* r = createPolynomial(100);

	int i = 0, j = 0;

	while (i < sizeArrayList(p1) && j < sizeArrayList(p2)) {
		if (p1->data[i].expo < p2->data[j].expo) {
			addItemPolynomial(r, p2->data[j]);
			j++;
		}
		else if (p1->data[i].expo > p2->data[j].expo) {
			addItemPolynomial(r, p1->data[i]);
			i++;
		}
		else {
			addItemPolynomial(r, (elementType) {p1->data[i].coef * p2->data[j].coef, p1->data[i].expo});

			i++;
			j++;
		}
	}

	while (i < p1->size) {
		addItemPolynomial(r, p1->data[i]);
		i++;
	}

	while (j < p2->size) {
		addItemPolynomial(r, p2->data[j]);
		j++;
	}

	return r;
}
