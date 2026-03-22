#include <stdio.h>
#include <stdlib.h>

#include "my_math.h"

my_math get_gcd(my_math i, my_math j) {
	while (j != 0) {
		int temp = i % j;
		i = j;
		j = temp;
	}
	return i;
}

my_math get_lcm(my_math i, my_math j) {
	int gcd = get_gcd(i, j);
	return (i * j) / gcd;
}
