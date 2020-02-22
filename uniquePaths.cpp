#include "globals.h"

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// Unique Paths I
int uniquePaths(int m, int n) {

	vector<vector<int>> memo(m, vector<int>(n, 0));

	for(int r = 0; r < m; r++) {
		for(int c = 0; c < n; c++) {

			// Base case
			if(r == 0 || c == 0) {
				memo[r][c] = 1;
			}
			else {
				memo[r][c] = memo[r-1][c] + memo[r][c-1];
			}
		}
	}
	return memo[m-1][n-1];
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// Unique Paths II

/*
  There are now obstacles

  Same DP method as above but must be able to detect obstacles if
  blocking the final path
 */

