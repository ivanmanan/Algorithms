#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
  Solution is to use preprocessing to create hash tables
  Then take the row,column pair and subtract from the corners
 */

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

    const int row_size = matrix.size();
    const int col_size = matrix[0].size();


    // Queue with cell (row, col)
    queue<pair<int,int>> q;
    pair<int,int> temp;

    // Insert 0 cells into queue
    for (int r = 0; r < row_size; r++) {
        for (int c = 0; c < col_size; c++) {
            if (matrix[r][c] == 0) {
                temp.first = r;
                temp.second = c;
                q.push(temp);
            }
        }
    }


    // For each cell in queue, perform BFS
    while (!q.empty()) {

    }

    return matrix;

}
