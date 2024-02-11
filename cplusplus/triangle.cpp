/*
  Solution to get O(N) space:

  1. Create a vector of maximum rows of the triangle
  2. A triangle is essentially a n x n matrix
  3. Compute all possible paths to the bottom of the triangle
  4. Return minimum element

int minimumTotal1(vector<vector<int>>& triangle) {
    vector<int> res(triangle.size(), triangle[0][0]);
    for (unsigned int i = 1; i < triangle.size(); i++)
        for (int j = i; j >= 0; j--) {
            if (j == 0)
                res[0] += triangle[i][j];
            else if (j == i)
                res[j] = triangle[i][j] + res[j-1];
            else
                res[j] = triangle[i][j] + min(res[j-1], res[j]);
        }
    return *min_element(res.begin(), res.end());
}

// bottom-up
int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> res = triangle.back();
    for (int i = triangle.size()-2; i >= 0; i--)
        for (unsigned int j = 0; j <= i; j++)
            res[j] = triangle[i][j] + min(res[j], res[j+1]);
    return res[0];
}
*/


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int max_rows = triangle.size();
        const int max_cols = triangle[max_rows-1].size();

        // Initialize memorized table
        int memo[max_rows][max_cols] = {-1};

        for (int r = 0; r < max_rows; r++) {
            for (int c = 0; c < triangle[r].size(); c++) {

                if (r-1 >= 0 && c-1 >= 0) {
                    // This is the middle element of the triangle row
                    if (c < triangle[r-1].size()) {
                        int temp1 = memo[r-1][c-1];
                        int temp2 = memo[r-1][c];
                        memo[r][c] = std::min(temp1, temp2) + triangle[r][c];
                    }
                    // Otherwise, this is the rightmost element of the triangle row
                    else {
                        memo[r][c] = memo[r-1][c-1] + triangle[r][c];
                    }
                }
                else if (r-1 >= 0) {
                    // This is the leftmost element of the triangle row
                    memo[r][c] = memo[r-1][c] + triangle[r][c];

                }
                else {
                    // Initialize memo[0][0]
                    memo[r][c] = triangle[r][c];
                }
            }
        }

        // Loop through last row of matrix to find mininum element
        int solution = memo[max_rows-1][0];
        for (int c = 0; c < max_cols; c++) {
            int temp = memo[max_rows-1][c];
            if (temp < solution) {
                solution = temp;
            }
        }
        return solution;
    }
};