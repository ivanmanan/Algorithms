#include "globals.h"

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// Search a 2D Matrix I

// Time Complexity:
// O(log M + log N)
// Binary search M rows, then binary search N colunms
bool searchMatrix(vector<vector<int>>& matrix, int target) {

	const int maxRow = matrix.size();
	const int maxCol = matrix[0].size();


	// Do binary search on first column
	// Determine the pivot point where the column value is
	// greater than the target value

	int l = 0;
	int r = maxRow-1;
	int targetRow = 0;
	while(l <= r) {
		int mid = (l+r)/2;

		if(matrix[mid][0] == target) {
			return true;
		}

		// Base case for last row
		if(mid+1 == maxRow) {
			if(matrix[mid][0] < target) {
				targetRow = mid;
				break;
			}
			else {
				return false;
			}
		}

		if(matrix[mid][0] < target && matrix[mid+1][0] > target) {
			targetRow = mid;
			break;
		}

		// Update high end
		if(matrix[mid][0] > target) {
			r = mid - 1;
		}
		else {// if(matrix[mid][0] < target) {
			l = mid + 1;
		}
	}

	// Perform a normal binary search on the targeted row
	l = 0;
	r = maxCol - 1;

	while(l <= r) {
		int mid = (l+r)/2;

		if(matrix[targetRow][mid] == target) {
			return true;
		}
		else if(matrix[targetRow][mid] < target) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return false;
}

int main() {
	vector<vector<int>> matrix;

	vector<int> fill;

	// Fill first row
	fill.push_back(10);
	fill.push_back(11);
	fill.push_back(15);
	fill.push_back(20);
	matrix.push_back(fill);
	fill.clear();

	// Fill second row
	fill.push_back(12);
	fill.push_back(13);
	fill.push_back(17);
	fill.push_back(22);
	matrix.push_back(fill);
	fill.clear();

	// Fill third row
	fill.push_back(24);
	fill.push_back(27);
	fill.push_back(29);
	fill.push_back(31);
	matrix.push_back(fill);
	fill.clear();

	// Fill fourth row
	fill.push_back(32);
	fill.push_back(48);
	fill.push_back(59);
	fill.push_back(99);
	matrix.push_back(fill);
	fill.clear();

	const int target = 11;
	string answer = searchMatrix(matrix, target) ? "true" : "false";

	for (unsigned int r = 0; r < matrix.size(); r++) {
		cout << "[ ";
		for (unsigned int c = 0; c < matrix[r].size(); c++) {
			cout << matrix[r][c] << " ";
		}
		cout << "]" << endl;
	}

	cout << "Finding Target: " << target << "; Answer: "<< answer << endl;

}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// Search a 2D Matrix I

/*
  CONSTRAINT:
  MxN matrix
  Integers are sorted left-to-right per row
  Integers are sorted up-to-down per column

  [1    4   7  11  15]
  [2    5   8  12  19]
  [3    6   9  16  22]
  [10  13  14  17  24]
  [18  21  23  26  30]

  SOLUTION:
  TIME: O(M + N), where M = rows, N = columns

  WALKTHROUGH
  Suppose we want to search for 12 in the above matrix. compare 12
  with the top-right element nums[0][4] = 15. Since 12 < 15, 12
  cannot appear in the column of 15 since all elements in that column
  are greater than or equal to 15. Now we reduce the search space by
  one column (the last column).

  We further compare 12 with the top-right element of the remaining
  matrix, which is nums[0][3] = 11. Since 12 > 11, 12 cannot appear
  in the row of 11 since all elements in this row are less than or
  equal to 11 (the last column has been discarded). Now we reduce the
  search space by one row (the first row).

  We move on to compare 12 with the top-right element of the
  remaining matrix, which is nums[1][3] = 12. Since it is equal to
  12, we return true.

 */

bool searchMatrixII(vector<vector<int>>& matrix, int target) {
	int maxRow = matrix.size();
	int maxCol = matrix[0].size();
	int r = 0;
	int c = maxCol - 1;

	while (r < maxRow && c >= 0) {
		if (matrix[r][c] == target) {
			return true;
		}
		matrix[r][c] > target ? c-- : r++;
	}
	return false;
}
