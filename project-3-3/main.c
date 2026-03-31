#include <stdio.h>
#include <stdlib.h>

#include "my_math.h"
#include "my_fraction.h"

int main(int c, char** v) {
	if (c != 3) {
		printf("Usage: %s <num1> <num2>\n", v[0]);
		return 1;
	}

	int num1 = 0, num2 = 0, den1 = 0, den2 = 0;

	change_from_f(v[1], &num1, &den1);
	change_from_f(v[2], &num2, &den2);

	int temp1[2] = { 0, 1 }, temp2[2] = { 0,1 };
	char perimeter[10] = { 0 }, area[10] = { 0 };

	add(num1, den1, num2, den2, &temp1[0], &temp1[1]);
	mult(temp1[0], temp1[1], 2, 1, &temp1[0], &temp1[1]);
	simplify(&temp1[0], &temp1[1]);
	change_from_ab(temp1, perimeter);

	mult(num1, den1, num2, den2, &temp2[0], &temp2[1]);
	simplify(&temp2[0], &temp2[1]);
	change_from_ab(temp2, area);
	

	printf("Perimeter: %s, Area: %s", perimeter, area);

	return 0;
}
