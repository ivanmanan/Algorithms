#include "globals.h"

int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& memo, int parentValue) {

	// Check bounds
	if(r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size() || parentValue >= matrix[r][c]) {
		return 0;
	}

	if(memo[r][c]) {
		return memo[r][c];
	}

	vector<int> rowNeighbors = {0,  0, 1, -1};
	vector<int> colNeighbors = {1, -1, 0,  0};

	int maxLocalPath = 0;
	for(int i = 0; i < rowNeighbors.size(); i++) {
		maxLocalPath = max(maxLocalPath, dfs(r+rowNeighbors[i], c+colNeighbors[i], matrix, memo, matrix[r][c]) + 1);
	}
	memo[r][c] = maxLocalPath;
	return memo[r][c];
}



int longestIncreasingPath(vector<vector<int>>& matrix) {

	if(matrix.empty()) {
		return 0;
	}

	int maxRow = matrix.size();
	int maxCol = matrix[0].size();

	// Each element in grid contains the longest increasing path
	vector<vector<int>> memo(maxRow, vector<int>(maxCol, 0));

	int maxPath = 0;

	int parentValue = INT_MIN;

	for(int r = 0; r < maxRow; r++) {
		for(int c = 0; c < maxCol; c++) {
			maxPath = max(maxPath, dfs(r, c, matrix, memo, parentValue));
		}
	}
	return maxPath;
}




int main() {
	const int ans = 4;
	vector<vector<int>> grid(3, vector<int>(3, 0));

	vector<int> row1 = {9, 9, 4};
	vector<int> row2 = {6, 6, 8};
	vector<int> row3 = {2, 1, 1};

	grid.push_back(row1);
	grid.push_back(row2);
	grid.push_back(row3);

	cout << "Output:   " << longestIncreasingPath(grid) << endl;
	cout << "Expected: " << ans << endl;
}