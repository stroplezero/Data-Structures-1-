#include <stdio.h>
#include <stdlib.h>

#include "my_math.h"

// SIZE를 사용해서 횟수를 정하여 반복했습니다.
#define SIZE 50

int main() {

	int n = 5;

	int gcd = 0;

	for (int i = 0; i < SIZE; i++) {
		
		gcd = get_gcd(F(n), F(n - 1));

		printf("GCD: %d\n", gcd);

		n++;

	}
	return 0; 
}
