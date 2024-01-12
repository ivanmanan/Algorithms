int shortestPath(vector<vector<int>>& grid, int k) {

    const int max_rows = grid.size();
    const int max_cols = grid[0].size();
    // Create a visited matrix with the state level
    // We do not want infinite loop of visiting the same state
    unordered_set<string> seen; //"r-c-k"

    // Vector: [r, c, k, distance]
    queue<vector<int>> q;
    q.push({0, 0, k, 0});
    string first_state = "0-0-" + to_string(k);
    seen.insert(first_state);


    vector<int> row_neighbors = {0, 0, 1, -1};
    vector<int> col_neighbors = {1, -1, 0 ,0};

    while(!q.empty()) {
        vector<int> points = q.front();
        q.pop();
        int r = points[0];
        int c = points[1];
        int obstacles = points[2];
        int distance = points[3];

        if(r == max_rows-1 && c == max_cols-1) {
            return distance;
        }


        // Check new element is valid
        for(int i = 0; i < row_neighbors.size(); i++) {
            int new_r = r + row_neighbors[i];
            int new_c = c + col_neighbors[i];
            if(new_r >= 0 && new_c >= 0 && new_r < max_rows && new_c < max_cols) {
                int new_obstacles = obstacles;
                if(grid[new_r][new_c] == 1) {
                    if(obstacles <= 0) {
                        continue;
                    }
                    new_obstacles = obstacles - 1;
                }
                int new_distance = distance + 1;
                string new_state = to_string(new_r) + "-" + to_string(new_c) + "-" + to_string(new_obstacles);
                if(seen.find(new_state) == seen.end()) {
                    q.push({new_r, new_c, new_obstacles, distance+1});
                    seen.insert(new_state);
                }
            }
        }
    }
    return -1;
}
