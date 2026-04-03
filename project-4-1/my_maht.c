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

my_math F(my_math n) {
	if (n <= 2) {
		return(1);
	}
	else
		return (F(n - 1) + F(n - 2));

}
