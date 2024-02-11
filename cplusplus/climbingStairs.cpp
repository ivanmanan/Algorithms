#include "globals.h"

/*
  Input: 3
  Output: 3
  Explanation: There are three ways to climb to the top.
  1. 1 step + 1 step + 1 step
  2. 1 step + 2 steps
  3. 2 steps + 1 step

  NOTE:
  This is just fibonnaci numbers. Optimal solution is the iterative
  method.
*/

// Recursive solution
// climbStairs(i,n) = climbStairs(i+1, n) + climbStairs(i+2,n)
// TIME: O(2^n)
// SPACE: O(N) - depth of recursion tree
int climbStairsRecursive(int i, int n) {

	if(i > n) {
		return 0;
	}

	// Can only do a single step
	if(i == n) {
		return 1;
	}

	return climbStairsRecursive(i+1, n) + climbStairsRecursive(i+2, n);
}

// Dynamic Programming Solution
// TIME: O(N)
// SPACE: O(N)
int climbStairsDP(int n) {
	if(n == 1) {
		return 1;
	}

	vector<int> dp(n+1, 0);
	dp[1] = 1;
	dp[2] = 2;

	for(int i = 3; i <= n; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}


// Controller function
int climbStairs(int n) {
	return climbStairsDP(n);
}

int main() {
	cout << climbStairs(4) << endl;
}