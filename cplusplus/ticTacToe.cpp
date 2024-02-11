class TicTacToe {
public:
    /*
        anti-diagonal: column=n-row-1

        Use data structures to track the frequency
    */
    TicTacToe(int n) {
        dimension_size = n;
        rows = vector<vector<int>>(2, vector<int>(n,0));
        cols = vector<vector<int>>(2, vector<int>(n,0));
    }

    int move(int row, int col, int player) {
        /*
            0 = no winner
            1 = player 1 wins
            2 = player 2 wins
        */
        int n = dimension_size;
        rows[player-1][row]++;
        cols[player-1][col]++;
        if(rows[player-1][row] == n || cols[player-1][col] == n) {
            return player;
        }

        if(row == col) {
            diagonals[player-1]++;
            if(diagonals[player-1] == n) {
                return player;
            }
        }
        if(col == n-row-1) {
            antidiagonals[player-1]++;
            if(antidiagonals[player-1] == n) {
                return player;
            }
        }
        return 0;
    }
private:
    int dimension_size;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<int> diagonals = vector<int>(2, 0);
    vector<int> antidiagonals = vector<int>(2, 0);
};
