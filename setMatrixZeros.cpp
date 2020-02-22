#include "globals.h"

void setZeroes(vector<vector<int>>& matrix) {

	int maxRow = matrix.size();
	int maxCol = matrix[0].size();

	// We must have an additional flag to check on the very first row and column
	bool setColAsZero = false;

	// Set the first cell of a row/column as a flag
	for(int r = 0; r < maxRow; r++) {

		if(matrix[r][0] == 0) {
			setColAsZero = true;
		}

		for(int c = 1; c < maxCol; c++) {
			if(matrix[r][c] == 0) {
				matrix[0][c] = 0;
				matrix[r][0] = 0;
			}

		}
	}

	// Start with the interior of the matrix in order to avoid the flags
	for(int r = 1; r < maxRow; r++) {
		for(int c = 1; c < maxCol; c++) {
			if(matrix[0][c] == 0 || matrix[r][0] == 0) {
				matrix[r][c] = 0;
			}
		}
	}

	// Now check if first row needs to be set as zero
	if(matrix[0][0] == 0) {
		for(int c = 0; c < maxCol; c++) {
			matrix[0][c] = 0;
		}
	}

	// Now check if first column needs to be set as zero
	if(setColAsZero) {
		for(int r = 0; r < maxRow; r++) {
			matrix[r][0] = 0;
		}
	}
}