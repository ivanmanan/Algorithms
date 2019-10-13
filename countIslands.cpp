#include <iostream>
#include <vector>

using namespace std;


void DFS(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited) {

	// Check if position is safe
	if(r < 0 || c < 0 || r >= visited.size() || c >= visited[0].size() || visited[r][c] || grid[r][c] == '0') {
		return;
	}

	// NOTE: Can be expanded to include diagonals if desired
	vector<int> rowNeighbor = {-1, 1, 0,  0};
	vector<int> colNeighbor = { 0, 0, 1, -1};

	visited[r][c] = true;

	// Visit children nodes
	for(uint i = 0; i < rowNeighbor.size(); i++) {
			DFS(r + rowNeighbor[i], c + colNeighbor[i], grid, visited);
	}
}

int numIslands(vector<vector<char>>& grid) {

	const int max_row = grid.size();
	const int max_col = grid[0].size();

	int countIslands = 0;

	// SIZE first, then INSERTION of actual element
	vector<vector<bool>> visited(max_row, vector<bool>(max_col, false));


	// Perform DFS for each element in the grid
	for(int r = 0; r < max_row; r++) {
		for(int c = 0; c < max_col; c++) {

			if(grid[r][c] == '1' && !visited[r][c]) {
				DFS(r, c, grid, visited);
				countIslands++;
			}
		}
	}
	return countIslands;
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