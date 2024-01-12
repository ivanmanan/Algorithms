int dfs(int r, int c, const int max_rows, const int max_cols, vector<vector<int>>& grid, vector<vector<bool>>& visited) {

    if(r < 0 || c < 0 || r >= max_rows || c >= max_cols) {
        return 1;
    }
    if(grid[r][c] == 0) {
        return 1;
    }
    if(visited[r][c]) {
        return 0;
    }
    visited[r][c] = true;

    vector<int> row_neighbors = {1, -1, 0, 0};
    vector<int> col_neighbors = {0, 0, 1, -1};
    int res = 0;
    for(int i = 0; i < row_neighbors.size(); i++) {
        int new_r = r+row_neighbors[i];
        int new_c = c+col_neighbors[i];
        res += dfs(new_r, new_c, max_rows, max_cols, grid, visited);
    }
    cout << res << endl;
    return res;
}


int islandPerimeter(vector<vector<int>>& grid) {
    const int max_rows = grid.size();
    const int max_cols = grid[0].size();
    vector<vector<bool>> visited(max_rows, vector<bool>(max_cols, false));
    for(int r = 0; r < max_rows; r++) {
        for(int c = 0; c < max_cols; c++) {
            if(grid[r][c] == 1) {
                return dfs(r, c, max_rows, max_cols, grid, visited);
            }
        }
    }
    return 0;
}
