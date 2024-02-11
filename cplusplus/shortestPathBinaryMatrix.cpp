int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    const int max_rows = grid.size();
    const int max_cols = grid[0].size();

    vector<vector<int>> visited(max_rows, vector<int>(max_cols, -1));

    if(grid[0][0] == 1) {
        return -1;
    }

    // (r,c)
    queue<pair<int,int>> q;
    visited[0][0] = 1;
    q.push({0,0});

    const vector<int> row_neighbors = {0, 0, 1, 1, 1, -1, -1, -1};
    const vector<int> col_neighbors = {1, -1, 1, 0, -1, 1, 0, -1};

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if(r == max_rows-1 && c == max_cols-1) {
            return visited[max_rows-1][max_cols-1];
        }

        for(int i = 0; i < row_neighbors.size(); i++) {
            int new_r = r + row_neighbors[i];
            int new_c = c + col_neighbors[i];
            if(new_r >= 0 && new_c >= 0 && new_r < max_rows && new_c < max_cols && visited[new_r][new_c] == -1 && grid[new_r][new_c] == 0) {
                visited[new_r][new_c] = visited[r][c] + 1;
                q.push({new_r, new_c});
            }
        }
    }
    return -1;
}
