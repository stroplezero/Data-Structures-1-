#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "my_fraction.h"

int main() {

	char f1[10], f2[10], sign = 0;
	int num1 = 0, num2 = 0, den1 = 0, den2 = 0;

	printf("입력: ");
	scanf("%s %c %s", f1, &sign, f2);

	change_from_f(f1, &num1, &den1);
	change_from_f(f2, &num2, &den2);
	
	int temp[2] = {0, 1};
	char out[20] = { 0 };

	switch (sign) {
	case '+':
		add(num1, den1, num2, den2, &temp[0], &temp[1]);
		break;
	case '-':
		minus(num1, den1, num2, den2, &temp[0], &temp[1]);
		break;
	case '*':
		mult(num1, den1, num2, den2, &temp[0], &temp[1]);
		break;
	case '/':
		divid(num1, den1, num2, den2, &temp[0], &temp[1]);
		break;
	default:
		printf("sign error");
	}

	simplify(&temp[0], &temp[1]);

	change_from_ab(temp, out);

	printf("출력: %s", out);

	return 0;
}
