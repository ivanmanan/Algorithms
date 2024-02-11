void dfs(int r, int c, const int max_row, const int max_col, int& count, int prev_value, vector<vector<int>>& memo, vector<vector<int>>& grid) {
    if(r < 0 || c < 0 || r >= max_row || c >= max_col || prev_value >= grid[r][c]) {
        return;
    }
    else {
        if(memo[r][c] != 0) {
            count += memo[r][c];
        }
        else {
            count++;
            const vector<int> row_neighbors = {1, -1, 0, 0};
            const vector<int> col_neighbors = {0, 0, 1, -1};
            for(int i = 0; i < row_neighbors.size(); i++) {
                dfs(r+row_neighbors[i], c+col_neighbors[i], max_row, max_col, count, grid[r][c], memo, grid);
            }
        }
    }
}

int countPaths(vector<vector<int>>& grid) {
    const int max_row = grid.size();
    const int max_col = grid[0].size();
    vector<vector<int>> memo(max_row, vector<int>(max_col, 0));

    int res = 0;
    for(int r = 0; r < max_row; r++) {
        for(int c = 0; c < max_col; c++) {
            int count = 0;
            int prev_value = INT_MIN;
            dfs(r, c, max_row, max_col, count, prev_value, memo, grid);
            memo[r][c] = count;
            res += count;
        }
    }
    return res;
}
