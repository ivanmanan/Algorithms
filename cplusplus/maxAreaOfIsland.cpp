int dfs(int r, int c, const int max_row, const int max_col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    if(r < 0 || c < 0 || r >= max_row || c >= max_col || visited[r][c] || grid[r][c] == 0) {
        return 0;
    }

    int current_area = 1;
    visited[r][c] = true;

    const vector<int> row_neighbors = {1, -1, 0, 0};
    const vector<int> col_neighbors = {0, 0, 1, -1};


    for(int i = 0; i < row_neighbors.size(); i++) {
        current_area += dfs(r+row_neighbors[i], c+col_neighbors[i], max_row, max_col, grid, visited);
    }
    return current_area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    const int max_row = grid.size();
    const int max_col = grid[0].size();

    vector<vector<bool>> visited(max_row, vector<bool>(max_col, false));

    int res = 0;
    for(int r = 0; r < max_row; r++) {
        for(int c = 0; c < max_col; c++) {
            if(grid[r][c] == 1 && !visited[r][c]) {
                int area = dfs(r, c, max_row, max_col, grid, visited);
                res = max(res, area);
            }
        }
    }

    return res;
}
