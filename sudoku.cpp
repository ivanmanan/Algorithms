bool isValidSudoku(vector<vector<char>>& board) {

    int checkrow[9][9]={0}; // Every row
    int checkcol[9][9]={0}; // Every column
    int checkbox[9][9]={0}; // 3x3 sub-box
    for(int r = 0; r < 9; r++){
        for(int c = 0; c < 9; c++){
            if(board[r][c] !='.') {
                int num = board[r][c]-'0' - 1;
                int box=(r/3)*3+(c/3);
                if(checkrow[r][num] || checkcol[num][c] || checkbox[box][num]) {
                    //if any of the checker gives true then
                    // the number is already present in that
                    // row/col/sub-box.
                    return false;
                }
                // After checking, we set the values true
                checkrow[r][num] = 1;
                checkcol[num][c] = 1;
                checkbox[box][num] = 1;
            }
        }
    }
    return true;
}
