/*
  SOLUTION:
  Use DFS
  Use memo

  When using dfs, pass by reference the pathSum
  If memo[r][c] is not null, return that
 */


#include <vector>
#include <iostream>
#include <climits>

using namespace std;


int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>> memo, int& maxValue) {
	if(memo[r][c] != -1) {
		return memo[r][c];
	}
	vector<int> rowNeighbor = {-1, 1, 0,  0};
	vector<int> colNeighbor = { 0, 0, 1, -1};

	int maxPath = 0;

	for(int i = 0; i < rowNeighbor.size(); i++) {
		// Check if position is safe
		const int new_r = r + rowNeighbor[i];
		const int new_c = c + colNeighbor[i];

		if(new_r >= 0 && new_c >= 0 && new_r < grid.size() && new_c < grid[0].size() && grid[r][c] < grid[new_r][new_c]) {
			int temp = grid[r][c] + dfs(new_r, new_c, grid, memo, maxValue);
			if(maxPath < temp) {
				maxPath = temp;
			}
		}
	}
	memo[r][c] = maxPath;
	if(maxValue < memo[r][c]) {
		maxValue = memo[r][c];
	}
	return 0;
}


// Assume all values are either positive integers or zeros
int longestIncreasingPath(vector<vector<int>>& grid) {

	int max_row = grid.size();
	int max_col = grid[0].size();
	vector<vector<int>> memo(max_row, vector<int>(max_col, -1));

	int maxValue = INT_MIN;

	for(int r = 0; r < max_row; r++) {
		for(int c = 0; c < max_col; c++) {
			dfs(r, c, grid, memo, maxValue);
		}
	}
	return maxValue;
}

int main() {
	vector<vector<int>> grid;

	int value = 1;
	for(int r = 0; r < 3; r++) {
		vector<int> row;
		for(int c = 0; c < 3; c++) {
			cout << value << ", ";
			row.push_back(value);
			value++;
		}
		cout << endl;
		grid.push_back(row);
	}

	cout << longestIncreasingPath(grid) << endl;
	cout << "Expected: 29" << endl;
}