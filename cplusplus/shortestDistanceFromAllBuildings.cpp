int shortestDistance(vector<vector<int>>& grid) {
    const int max_rows = grid.size();
    const int max_cols = grid[0].size();

    vector<pair<int,int>> buildings;
    for(int r = 0; r < max_rows; r++) {
        for(int c = 0; c < max_cols; c++) {
            if(grid[r][c] == 1) {
                buildings.push_back({r,c});
            }
        }
    }
    vector<int> row_neighbors = {1, -1, 0, 0};
    vector<int> col_neighbors = {0, 0, 1, -1};
    vector<vector<int>> distances(max_rows, vector<int>(max_cols, 0));
    // Track number of houses reached
    vector<vector<int>> houses_reached(max_rows, vector<int>(max_cols, 0));
    // BFS for each building
    for(auto& p: buildings) {
        int start_r = p.first;
        int start_c = p.second;
        vector<vector<bool>> visited(max_rows, vector<bool>(max_cols, false));
        // r,c,dist
        queue<vector<int>> q;
        q.push({start_r,start_c, 0});
        visited[start_r][start_c] = true;
        houses_reached[start_r][start_c]++;
        while(!q.empty()) {
            int r = q.front()[0];
            int c = q.front()[1];
            int dist = q.front()[2];
            q.pop();
            distances[r][c] += dist;
            for(int i = 0; i < row_neighbors.size(); i++) {
                int new_r = r+row_neighbors[i];
                int new_c = c+col_neighbors[i];
                if(new_r >= 0 && new_c >= 0 && new_r < max_rows && new_c < max_cols && grid[new_r][new_c] == 0 && !visited[new_r][new_c]) {
                    visited[new_r][new_c] = true;
                    houses_reached[new_r][new_c]++;
                    q.push({new_r,new_c, dist+1});
                }
            }
        }
    }
    int res = INT_MAX;
    for(int r = 0; r < max_rows; r++) {
        for(int c = 0; c < max_cols; c++) {
            if(grid[r][c] == 0 && houses_reached[r][c] == buildings.size()) {
                res = min(res, distances[r][c]);
            }
        }
    }
    if(res == INT_MAX) {
        return -1; // No way found
    }
    return res;
}
