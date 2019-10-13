#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        const int max_rows = grid.size();
        const int max_cols = grid[0].size();

        // Initialize memorized table
        int memo[max_rows][max_cols] = {-1};
        memo[0][0] = grid[0][0];

        // At position (r,c):
        // 1. Check current position
        // 2. Check bounds
        // 3. Fill-in with min
        for (int r = 0; r < max_rows; r++) {
            for (int c = 0; c < max_cols; c++) {

                // Check from up and left direction
                if (r-1 >= 0 && c-1 >= 0) {
                    memo[r][c] = grid[r][c] + min(memo[r-1][c], memo[r][c-1]);
                }
                // Otherwise, check only if single directions are valid
                else if (r-1 >= 0) {
                    memo[r][c] = grid[r][c] + memo[r-1][c];
                }

                else if (c-1 >= 0) {
                    memo[r][c] = grid[r][c] + memo[r][c-1];
                }
            }
        }
        return memo[max_rows-1][max_cols-1];
    }
};