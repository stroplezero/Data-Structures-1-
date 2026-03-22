#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "my_fraction.h"

my_fraction change_from_f(const char *str, int *num, int *den) {
	if (sscanf(str, "%d/%d", num, den) == 1) {
		*den = 1;
	}
}

void change_from_ab(const int *temp, char *out) {
	if (temp == NULL || out == NULL) return;

	if (temp[1] == 1) sprintf(out, "%d", temp[0]);
	else sprintf(out, "%d/%d", temp[0], temp[1]);
}

void add(int num1, int den1, int num2, int den2, int *temp1, int *temp2) {
	*temp1 = (num1 * den2) + (num2 * den1);
	*temp2 = den1 * den2;
}
void minus(int num1, int den1, int num2, int den2, int *temp1, int *temp2) {
	*temp1 = (num1 * den2) - (num2 * den1);
	*temp2 = den1 * den2;
}
void mult(int num1, int den1, int num2, int den2, int *temp1, int *temp2) {
	*temp1 = num1 * num2;
	*temp2 = den1 * den2;
}
void divid(int num1, int den1, int num2, int den2, int *temp1, int *temp2) {
	*temp1 = num1 * den2;
	*temp2 = den1 * num2;
}

int get_gcd(int a, int b) {
	if (a < 0) a = - a; 
	if (b < 0) b = - b;

	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

void simplify(int* temp1, int* temp2) {
	int gcd = get_gcd(*temp1, *temp2);

	if (gcd != 0) {
		*temp1 = *temp1 / gcd;
		*temp2 = *temp2 / gcd;	
	}

}
