#include "globals.h"

string tictactoe(vector<vector<int>>& moves) {
	vector<vector<string>> grid(3,vector<string>(3));
	string winner;
	int r, c;

	for(int i = 0; i < moves.size(); i++){
		if(i % 2 == 0){
			r = moves[i][0];
			c = moves[i][1];
			grid[r][c] = "X";
			if(grid[r][0]=="X" && grid[r][1]=="X" && grid[r][2]=="X")
				return "A";
			else if(grid[0][c]=="X" && grid[1][c]=="X" && grid[2][c]=="X")
				return "A";
			else if(grid[0][0]=="X" && grid[1][1]=="X" && grid[2][2]=="X")
				return "A";
			else if(grid[0][2]=="X" && grid[1][1]=="X" && grid[2][0]=="X")
				return "A";
		}
		else{
			r = moves[i][0];
			c = moves[i][1];
			grid[r][c] = "O";
			if(grid[r][0]=="O" && grid[r][1]=="O" && grid[r][2]=="O")
				return "B";
			else if(grid[0][c]=="O" && grid[1][c]=="O" && grid[2][c]=="O")
				return "B";
			else if(grid[0][0]=="O" && grid[1][1]=="O" && grid[2][2]=="O")
				return "B";
			else if(grid[0][2]=="O" && grid[1][1]=="O" && grid[2][0]=="O")
				return "B";
		}
	}

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(grid[i][j]=="")
				return "Pending";
		}
	}
	return "Draw";
}