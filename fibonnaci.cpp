#include "globals.h"

// F(0) = 0
// F(1) = 1
// F(N) = F(N-1) + F(N-2)

int fibRecursive(int N) {
	if(N <= 1) {
		return N;
	}
	return fib(N-1) + fib(N-2);
}

int fibIterative(int N) {

	int a = 0;
	int b = 1;

	if(N <= 1) {
		return N;
	}

	int c = a + b;

	for(int i = 2; i <= N; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}