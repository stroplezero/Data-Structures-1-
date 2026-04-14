#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// SIZE를 사용해서 최대 N를 정함.
#define N 1000

long long fibo(int n) {
	long long f1 = 1;
	long long f2 = 1;

	if (n == 1){
		return f1;
	}
	else if (n == 2) {
		return f2;
	}
	else {
		long long fn;

		for (int i = 3; i <= n; i++)
		{
			fn = f1 + f2;

			f1 = f2;
			f2 = fn;
		} 
		return fn;
	}
}

int main() {

	for (int i = 1; i <= N; i++) {
		long long n = fibo(i);
		printf("f(%d): %lld ", i, n);
	}
}
