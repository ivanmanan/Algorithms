#include "globals.h"

// SOLUTION 1: BFS
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

    // Do a BFS from each zero spot simultaneously.
    // When two BFS's collide, we already have the minimum.
    // Time: O(M*N)

    const int max_row = mat.size();
    const int max_col = mat[0].size();

    cout << "MAX_ROW: " << max_row << "; MAX_COL: " << max_col << endl;

    queue<pair<int,int>> q;

    vector<vector<int>> res(max_row, vector<int>(max_col, -1));

    for(int r = 0; r < max_row; r++) {
        for(int c = 0; c < max_col; c++) {
            if(mat[r][c] == 0) {
                q.push(make_pair(r,c));
                res[r][c] = 0;
            }
        }
    }

    const vector<int> row_neighbors = {0, 0, 1, -1};
    const vector<int> col_neighbors = {1, -1, 0, 0};

    cout << "REACHED HERE" << endl;
    while(!q.empty()) {
        pair<int,int> m_pair = q.front();
        q.pop();

        const int r = m_pair.first;
        const int c = m_pair.second;
        cout << "(" << r << "," << c << ")" << endl;

        int distance = res[r][c] + 1;

        for(int i = 0; i < row_neighbors.size(); i++) {
            int new_r = r + row_neighbors[i];
            int new_c = c + col_neighbors[i];
            if(new_r >= 0 && new_c >= 0 && new_r < max_row && new_c < max_col && res[new_r][new_c] == -1) {
                cout << "(" << new_r << "," << new_c << ")" << endl;
                // This spot has not been visited yet in the matrix
                res[new_r][new_c] = distance;
                q.push(make_pair(new_r, new_c));
            }
        }
    }
    return res;
}


// SOLUTION 2: O(1) space complexity without a queue
vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));

    //First pass: check for left and top
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0)
                dist[i][j] = 0;
            else {
                if (i > 0)
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                if (j > 0)
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }

    //Second pass: check for bottom and right
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            if (i < rows - 1)
                dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
            if (j < cols - 1)
                dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
        }
    }

    return dist;
}
