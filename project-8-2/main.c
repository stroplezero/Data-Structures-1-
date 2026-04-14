#include <stdio.h>
#include <stdlib.h>

// SIZE를 사용해서 N를 정함.
#define N 1000

long long fibo(int n) {

	if (n <= 2) {
		return (1);
	}

	return fibo(n - 1) + fibo(n - 2);
}

int main() {
	for (int i = 1; i <= N; i++) {
		long long n = fibo(i);
		printf("f(%d): %lld ", i, n);
	}
}
