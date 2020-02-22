#include "globals.h"

int tripleStepRecursive(int i, int n) {
	if(i > n) {
		return 0;
	}

	if(i == n) {
		return 1;
	}

	return tripleStepRecursive(i+1, n) + tripleStepRecursive(i+2, n) + tripleStepRecursive(i+3, n);
}

int tripleStepDP(int n) {
	vector<int> memo(n+1);

	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 2;

	for(int i = 3; i <= n; i++) {
		memo[i] = memo[i-3] + memo[i-2] + memo[i-1];
	}
	return memo[n];
}


int tripleStep(int n) {
	return tripleStepDP(n);
	// return tripleStepRecursive(0, n);
}

int main() {
	int input = 4;
	int ans = 7;
	int res = tripleStep(input);

	cout << "Output:   " << res << endl;
	cout << "Expected: " << ans << endl;
}