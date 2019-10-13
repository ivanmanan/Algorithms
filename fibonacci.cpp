#include <iostream>

using namespace std;

int fibonacciDP(int n) {

	int *fib = new int[n];
	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i < n; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}
	int solution = fib[n-1];
	delete []fib;
	return solution;
}

int fibonacciIterative(int n) {

	int solution = 0;
	int a = 0;
	int b = 1;

	for (int i = 2; i < n; i++) {
		solution = a + b;
		a = b;
		b = solution;
	}

	return solution;
}


int main() {

	int ans1 = fibonacciDP(10);
	int ans2 = fibonacciIterative(10);
	if (ans1 == ans2) {
		cout << ans2 << endl;
	}
}