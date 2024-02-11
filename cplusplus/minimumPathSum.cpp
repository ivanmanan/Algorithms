#include "globals.h"

int minPathSum(vector<vector<int>>& grid) {

	if(grid.empty()) {
		return 0;
	}

	const int maxRow = grid.size();
	const int maxCol = grid[0].size();

	vector<vector<int>> memo(maxRow, vector<int>(maxCol, 0));


	for(int r = 0; r < maxRow; r++) {
		for(int c = 0; c < maxCol; c++) {

			if(r-1 >= 0 && c-1 >= 0) {
				memo[r][c] = min(memo[r-1][c], memo[r][c-1]) + grid[r][c];
			}
			else if(r-1 >= 0) {
				memo[r][c] = memo[r-1][c] + grid[r][c];
			}
			else if(c-1 >= 0) {
				memo[r][c] = memo[r][c-1] + grid[r][c];
			}
			else {
				memo[r][c] = grid[r][c];
			}
		}
	}
	return memo[maxRow-1][maxCol-1];
}