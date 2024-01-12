bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    const int max_rows = matrix.size();
    const int max_cols = matrix[0].size();

    for(int r = 0; r < max_rows; r++) {
        for(int c = 0; c < max_cols; c++) {
            if(r-1 >= 0 && c-1 >= 0) {
                if(matrix[r][c] != matrix[r-1][c-1]) {
                    return false;
                }
            }
        }
    }

    return true;
}
