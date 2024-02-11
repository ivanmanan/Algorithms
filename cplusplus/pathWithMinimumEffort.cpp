#include <globals.h>


typedef pair<int, pair<int,int>> pi;
int minimumEffortPath(vector<vector<int>>& heights) {

    int max_row = heights.size();
    int max_col = heights[0].size();

    // min heap
    priority_queue <pi, vector<pi>, greater<pi>> pq;

    // Store distances from (0,0)
    vector<vector<int>> memo(max_row, vector<int>(max_col, INT_MAX));

    memo[0][0] = 0;
    pq.push(make_pair(0, make_pair(0,0)));

    const vector<int> row_neighbors = {1, -1, 0, 0};
    const vector<int> col_neighbors = {0, 0, 1, -1};

    // Dijkstra's algorithm
    while(!pq.empty()) {
        pi curr = pq.top();
        pq.pop();

        int distance = curr.first;
        int r = curr.second.first;
        int c = curr.second.second;

        if(r == max_row-1 && c == max_col-1) {
            // We reached bottom right position
            return distance;
        }

        for(int i = 0; i < row_neighbors.size(); i++) {
            int new_r = r + row_neighbors[i];
            int new_c = c + col_neighbors[i];

            // Check if new position is invalid
            if(new_r < 0 || new_c < 0 || new_r >= max_row || new_c >= max_col) {
                continue;
            }

            int new_distance = max(distance, abs(heights[new_r][new_c] - heights[r][c]));
            if(new_distance < memo[new_r][new_c]) {
                memo[new_r][new_c] = new_distance;
                pq.push(make_pair(new_distance, make_pair(new_r, new_c)));
            }
        }
    }
    return 0;
}
