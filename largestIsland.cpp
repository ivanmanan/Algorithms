// Return area
int dfs(int r, int c, const int max_rows, const int max_cols, vector<vector<int>>& grid, vector<vector<int>>& groups, int group_id) {
    int res = 0;
    if(r < 0 || c < 0 || r >= max_rows || c >= max_cols || grid[r][c] == 0 || groups[r][c] != -1) {
        return res;
    }
    res = 1;
    groups[r][c] = group_id;

    const vector<int> row_neighbors = {1, -1, 0, 0};
    const vector<int> col_neighbors = {0, 0, 1, -1};

    for(int i = 0; i < row_neighbors.size(); i++) {
        int new_r = r + row_neighbors[i];
        int new_c = c + col_neighbors[i];

        res += dfs(new_r, new_c, max_rows, max_cols, grid, groups, group_id);
    }
    return res;
}

int connectAreas(int r, int c, const int max_rows, const int max_cols, vector<vector<int>>& grid, vector<vector<int>>& groups, unordered_map<int,int>& ma) {
    const vector<int> row_neighbors = {1, -1, 0, 0};
    const vector<int> col_neighbors = {0, 0, 1, -1};

    int res = 1; // The flipping of 0 to 1 is a carry
    // Avoid duplicate groups
    unordered_set<int> groups_already;
    for(int i = 0; i < row_neighbors.size(); i++) {
        int new_r = r + row_neighbors[i];
        int new_c = c +  col_neighbors[i];

        if(new_r >= 0 && new_c >= 0 && new_r < max_rows && new_c < max_cols && grid[new_r][new_c] == 1) {
            int group_id = groups[new_r][new_c];

            cout << "GROUP ID: " << group_id << endl;
            if(groups_already.find(group_id) == groups_already.end()) {
                res += ma[groups[new_r][new_c]];
                groups_already.insert(groups[new_r][new_c]);
            }
        }
    }
    return res;
}

int largestIsland(vector<vector<int>>& grid) {
    // Create group IDs
    // Each 1 is associated with a group ID
    // For the 4-directionally connected land masses,
    // sum the group ID areas

    const int max_rows = grid.size();
    const int max_cols = grid[0].size();

    // key: group_id, value: area
    unordered_map<int,int> ma;
    vector<vector<int>> groups(max_rows, vector<int>(max_cols, -1));

    int group = 1;
    int res = 0;
    for(int r = 0; r < max_rows; r++) {
        for(int c = 0; c < max_cols; c++) {
            if(grid[r][c] == 1 && groups[r][c] == -1) {
                int area = dfs(r, c, max_rows, max_cols, grid, groups, group);
                res = max(res, area);
                ma[group] = area;
                group++;
            }
        }
    }

    for(int r = 0; r < max_rows; r++) {
        for(int c = 0; c < max_cols; c++) {
            // cout << "r: " << r << ", c: " << c << "; GROUP: " << groups[r][c];
            // if(groups[r][c] != -1) {
            //     cout << "; AREA: " << ma[groups[r][c]] << endl;
            // }
            // cout << endl;
            if(grid[r][c] == 0) {
                int new_area = connectAreas(r, c, max_rows, max_cols, grid, groups, ma);
                res = max(res, new_area);
            }
        }
    }
    return res;
}
