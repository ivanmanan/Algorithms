#include "globals.h"

void dfs(int r, int c, int maxRow, int maxCol, vector<vector<char>>& grid, vector<vector<bool>>& visited) {

	// Check if position is safe
	if(r < 0 || c < 0 || r >= maxRow || c >= maxCol || grid[r][c] == '0' || visited[r][c]) {
		return;
	}
	visited[r][c] = true;

	// NOTE: Can be expanded to include diagonals if desired
	vector<int> rowNeighbors = {0,  0, -1, 1};
	vector<int> colNeighbors = {1, -1,  0, 0};

	for(int i = 0; i < rowNeighbors.size(); i++) {
		dfs(r+rowNeighbors[i], c+colNeighbors[i], maxRow, maxCol, grid, visited);
	}
}

int numIslands(vector<vector<char>>& grid) {

	const int maxRow = grid.size();
	const int maxCol = grid[0].size();

	// SIZE first, then INSERTION of actual element
	vector<vector<bool>> visited(maxRow, vector<bool>(maxCol, false));

	// Perform DFS for each element in the grid
	int count = 0;
	for(int r = 0; r < maxRow; r++) {
		for(int c = 0; c < maxCol; c++) {
			if(grid[r][c] == '1' && !visited[r][c]) {
				dfs(r, c, maxRow, maxCol, grid, visited);
				count++;
			}
		}
	}
	return count;
}

int main() {

	vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
								 {'1', '1', '0', '0', '0'},
								 {'0', '0', '1', '0', '0'},
								 {'0', '0', '0', '1', '1'}};

	int ans = numIslands(grid);
	cout << "Expected Answer: 3" << endl;
	cout << "Real Answer: " << ans << endl;
}