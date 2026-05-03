#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"

int main() {
	polynomial* p1;
	p1 = createPolynomial(100);

	printf("첫번째 다항식을 입력하세요. (ex: 3X^2+2X^1+1X^0): ");
	inputPolynomial(p1);

	polynomial* p2;
	p2 = createPolynomial(100);

	printf("두번째 다항식을 입력하세요. (ex: 3X^2+2X^1+1X^0): ");
	inputPolynomial(p2);

	polynomial* p3 = multiPolynomial(p1, p2);
	printPolynomial(p3);
}
