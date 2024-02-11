#include "globals.h"

void setZeroes(vector<vector<int>>& matrix) {

	bool first_row_zeros = false;
	bool first_col_zeros = false;
	for(int r = 0; r < matrix.size(); r++) {
		for(int c = 0; c < matrix[0].size(); c++) {
			if(r == 0 && matrix[r][c] == 0) {
				first_row_zeros = true;
			}
			if(c == 0 && matrix[r][c] == 0) {
				first_col_zeros = true;
			}
			if(matrix[r][c] == 0) {
				matrix[r][0] = 0;
				matrix[0][c] = 0;
			}
		}
	}

	for(int r = 1; r < matrix.size(); r++) {
		for(int c = 1; c < matrix[0].size(); c++) {

			if(matrix[r][0] == 0 || matrix[0][c] == 0) {
				matrix[r][c] = 0;

			}
		}
	}

	// Check if first row or column needs to be set to zero
	if(first_row_zeros) {
		for(int c = 0; c < matrix[0].size(); c++) {
			matrix[0][c] = 0;
		}
	}
	if(first_col_zeros) {
		for(int r = 0; r < matrix.size(); r++) {
			matrix[r][0] = 0;
		}
	}

}
