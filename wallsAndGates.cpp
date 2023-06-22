#include "../Algorithms/globals.h"
/*
    -1 A wall or an obstacle.
    0 A gate.
    INT_MAX means an empty room
*/

// Time: O(M*N)

vector<vector<int>> distancesToGate(vector<vector<int>>& grid) {

	const int max_row = grid.size();
	const int max_col = grid[0].size();

	vector<vector<int>> res = grid;
    queue<pair<int,int>> q;

	for(int r = 0; r < max_row; r++) {
		for(int c = 0; c < max_col; c++) {
			if(grid[r][c] == 0) {
				q.push_back(make_pair(r,c));
			}
		}
	}

    const vector<int> row_neighbors = {1, -1, 0, 0};
    const vector<int> col_neighobrs = {0, 0, 1, -1};

    // BFS from each gate
    while(!q.empty()) {
        pair<int,int> m_pair = q.front();
        q.pop();
        int r = m_pair.first;
        int c = m_pair.second;

        for(int i = 0; i < row_neighbors.size(); i++) {
            // Check next step is valid
            int new_r = r + row_neighbors[i];
            int new_c = c + col_neighbors[i];
            if(new_r < 0 || new_c < 0 || new_r >= max_row || new_c >= max_col || res[new_r][new_c] == -1 || res[new_r][new_c] != INT_MAX) {
                continue;
            }
            else {
                res[new_r][new_c] = res[r][c] + 1;
                q.push(make_pair(new_r, new_c));
            }
        }
    }
	return res;
}
