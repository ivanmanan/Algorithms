/*
DFS: slide through each consecutively-rolled cell until hit wall
Add to visited array that we reached this cell before
*/

void dfs(int r, int c, const int max_rows, const int max_cols, vector<vector<int>>& maze, vector<vector<bool>>& visited, const int goal_r, const int goal_c) {
    visited[r][c] = true;
    if(r == goal_r && c == goal_c) {
        // We finish!
        return;
    }
    // We make sure parameters are valid BEFORE calling this function
    const vector<int> row_neighbors = {1, -1, 0, 0};
    const vector<int> col_neighbors = {0, 0, 1, -1};

    for(int i = 0; i < row_neighbors.size(); i++) {
        // Continuously go up or down, so r is constant
        if(row_neighbors[i] == 0) {
            int new_c = c;
            while(new_c + col_neighbors[i] >= 0 && new_c + col_neighbors[i] < max_cols && maze[r][new_c + + col_neighbors[i]] == 0) {
                new_c += col_neighbors[i];
            }
            if(!visited[r][new_c]) {
                dfs(r, new_c, max_rows, max_cols, maze, visited, goal_r, goal_c);
            }
        }
        // Continously go left or right, so c is constant
        else {
            int new_r = r;
            while(new_r + row_neighbors[i] >= 0 && new_r + row_neighbors[i] < max_rows && maze[new_r + row_neighbors[i]][c] == 0) {
                new_r += row_neighbors[i];
            }
            if(!visited[new_r][c]) {
                dfs(new_r, c, max_rows, max_cols, maze, visited, goal_r, goal_c);
            }
        }
    }
}


bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    const int max_rows = maze.size();
    const int max_cols = maze[0].size();

    vector<vector<bool>> visited(max_rows, vector<bool>(max_cols, false));

    visited[start[0]][start[1]] = true;
    dfs(start[0], start[1], max_rows, max_cols, maze, visited, destination[0], destination[1]);
    return visited[destination[0]][destination[1]];
}
