#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "my_math.h"

int main() {

	int i = 0, j = 0;

	printf("입력: ");
	scanf("%d %d", &i, &j);

	int gcd = 0, lcm = 0;

	gcd = get_gcd(i, j);
	lcm = get_lcm(i, j);

	printf("GCD: %d, LCM: %d", gcd, lcm);

	return 0;
}
