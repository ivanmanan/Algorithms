void wallsAndGates(vector<vector<int>> &rooms) {
    // Take all coordinates containing the value 0
    // Do BFS
    // If encounter a visited coordinate, can stop b/c that's already the min

    const int max_rows = rooms.size();
    const int max_cols = rooms[0].size();

    queue<pair<int, pair<int,int>>> q;

    for(int r = 0; r < max_rows; r++) {
        for(int c = 0; c < max_cols; c++) {
            if(rooms[r][c] == 0) {
                q.push(make_pair(0, make_pair(r,c)));
            }
        }
    }

    vector<int> row_neighbors = {1, -1, 0, 0};
    vector<int> col_neighbors = {0, 0, 1, -1};

    while(!q.empty()) {
        int curr = q.top().first;
        int r = q.top().second.first;
        int c = q.top().second.second;
        q.pop();

        for(int i = 0; i < row_neighbors.size(); i++) {
            int new_r = r + row_neighbors[i];
            int new_c = c + col_neighbors[i];
            // Check position is valid
            if(new_r < 0 || new_c < 0 || new_r >= max_rows || new_c >= max_rows || rooms[new_r][new_c] == -1 || rooms[new_r][new_c] != MAX_INT) {
                continue;
            }
            else {
                rooms[r][c] = curr;
                q.push(make_pair<curr+1, make_pair(new_r, new_c));
            }
        }
    }
}
