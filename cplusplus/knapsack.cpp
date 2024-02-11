/*
Problem Description:
Given n items, each with specific weights, put these items in a
knapsack of capacity W to get the maximum total value.

val[0, 1, ..., n-1]
w[0, 1, ..., n-1]
W = knapsack capacity

Arrays represent values and weights associated with n items

Find maximum value subset of val[] such that the sum of the weights
of this subset is smaller than or equal to W.

Ex. Solution
val[] = [60, 100, 120]
w[]   = [10, 20, 30]
W = 50

Output: 220

*/

#include <iostream>
using namespace std;

int w[] = {1, 2, 4, 2, 5};
int v[] = {5, 3, 5, 3, 2};

// Auxilliary function
int max(int a, int b) { return (a > b)? a : b; }

// Time Complexity: O(2^n)
int recursiveKS(int n, int C) {
	// Base Case
	if (n == 0 || C == 0) {
		return 0;
	}

	// If weight of the nth item is more than Knapsack capacity C,
	// then this item cannot be included in the optimal solution
	else if (w[n-1] > C) {
		return recursiveKS(n-1, C);
	}

	// Return the maximum of two cases
	// 1. nth item is not included
	// 2. nth item is included
	else {
		int tmp1 = recursiveKS(n-1, C);
		int tmp2 = v[n-1] + recursiveKS(n-1, C-w[n-1]);
		return max(tmp1, tmp2);
	}
}

/*
  Initialize memoization array memo[n][C]
  Ex. n=5; C=10, then there are 50 combinations

  w[] = {1, 2, 4, 2, 5}
  v[] = {5, 3, 5, 3, 2}

  n rows
  C columns

Walkthrough:
Walk through row 1
If I can add item onto knapsack, then add it

Walk through row 2
If I can add item 2 onto knapsack, then compare max of previous row without the added item to the newly added item value
Otherwise, take the value from the previous row, same column

+----+---+---+---+---+---+---+---+---+---+---+---+
|    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| Column = Capacity
+----+---+---+---+---+---+---+---+---+---+---+---+
| 1  | 0 | 5 | 5 | 5 | 5 | 5 | 5 | 5 | 5 | 5 | 5 |
+----+---+---+---+---+---+---+---+---+---+---+---+
| 2  | 0 | 5 | 5 | 8 | 8 | 8 | 8 | 8 | 8 | 8 | 8 |
+----+---+---+---+---+---+---+---+---+---+---+---+
| 4  | 0 | 5 | 5 | 8 | 8 | 10| 10| 10| 10| 10| 10|
+----+---+---+---+---+---+---+---+---+---+---+---+
| 2  | 0 | 5 | 5 | 8 | 8 | 11| 11| 11| 11| 16| 16|
+----+---+---+---+---+---+---+---+---+---+---+---+
| 5  | 0 | 5 | 5 | 8 | 8 | 11| 11| 11| 11| 16| 16|
+----+---+---+---+---+---+---+---+---+---+---+---+

Row = items from w[] being added onto knapsack
*/


// Time Complexity: O(n*C)
int KS(int n, int C) {

	int memo[n+1][C+1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= C; j++) {

			// Base Case
			if (i == 0 || j == 0) {
				memo[i][j] = 0;
			}

			// Attempt to add item onto knapsack
			else if (w[i-1] <= C) {
				int temp1 = memo[i-1][j];
				int temp2 = v[i-1] + memo[i-1][j-w[i-1]];
				memo[i][j] = max(temp1, temp2);
			}

			// Capacity exceeded, so return previous value
			// without the item
			else {
				memo[i][j] = memo[i-1][j];
			}
		}
	}

	return memo[n][C];
}

int main() {
    int C = 10;
    int n = sizeof(v)/sizeof(v[0]);
    cout <<  KS(n, C) << endl;;
    return 0;
}