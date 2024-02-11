bool isValidSudoku(vector<vector<char>>& board) {

    vector<vector<char>> rows(9, vector<char>(9, '.'));
    vector<vector<char>> cols(9, vector<char>(9, '.'));

    vector<vector<char>> subboxes(9, vector<char>(9, '.'));

    for(int r = 0; r < board.size(); r++) {
        for(int c = 0; c < board[0].size(); c++) {

            int value = board[r][c] - '0';
            value = value - 1;
            cout << r << ", " << c << " -- " << value << endl;
            int subbox_index = (r/3)*3+c/3;

            if(board[r][c] != '.') {
                if(rows[r][value] != '.' || cols[c][value] != '.' || subboxes[subbox_index][value] != '.') {
                    return false;
                }
                else {
                    rows[r][value] = '*';
                    cols[c][value] = '*';
                    subboxes[subbox_index][value] = '*';
                }
            }
        }
    }
    return true;

}
