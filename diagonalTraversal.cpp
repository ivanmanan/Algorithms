/*
    [1 2 3]
    [4 5 6]
    [7 8 9]

    Output: [1 2 4 3 5 7 6 8 9]

    Notice the heads are all in the first row and last column
    Iterate from each element in first row or last column
    and go down-left until out of bounds

    Then reverse elements in even-numbered indexes
*/

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    vector<int> res;
    vector<vector<int>> store;
    const int max_rows = mat.size();
    const int max_cols = mat[0].size();

    // Iterate the 0th row
    for(int c = 0; c < max_cols; c++) {
        int diag_r = 0;
        int diag_c = c;
        vector<int> temp;
        while(diag_r < max_rows && diag_c >= 0) {
            temp.push_back(mat[diag_r][diag_c]);
            diag_r++;
            diag_c--;
        }
        store.push_back(temp);
    }
    // Iterate the last column
    for(int r = 1; r < max_rows; r++) {
        int diag_r = r;
        int diag_c = max_cols-1;
        vector<int> temp;
        while(diag_r < max_rows && diag_c >= 0) {
            temp.push_back(mat[diag_r][diag_c]);
            diag_r++;
            diag_c--;
        }
        store.push_back(temp);
    }
    // Reverse elements in even-numbered arrays
    for(int i = 0; i < store.size(); i+=2) {
        reverse(store[i].begin(), store[i].end());
    }
    for(auto& v:store) {
        for(auto& it: v) {
            res.push_back(it);
        }
    }
    return res;
}
