#include <iostream>
#include <vector>

using namespace std;

void printSpiral(vector<vector<int>> matrix) {

	char curr = 'r';
	int r = 0;
	int c = 0;

	int max_rows = matrix.size();
	int max_cols = max_rows;

	bool iterateFlag = true;

	while (iterateFlag) {

		// first, print
		cout << matrix[r][c] << endl;
		matrix[r][c] = -1;

 		// second, figure out where to go next, or if we are done
		// this part must b e correct for the next iteration to be correct

		switch(curr) {
			case ('r'):
				// Valid next step
				if (c+1 < max_cols && matrix[r][c+1] != -1) {
					c++;
				}
				// Reached end of spiral
				else if (r+1 < max_rows && matrix[r+1][c] == -1) {
					iterateFlag = false;
				}
				// Change direction
				else {
					r++;
					curr = 'd';
				}
				break;
			case ('d'):
				if (r+1 < max_rows && matrix[r+1][c] != -1) {
					r++;
				}
				else if (c-1 > 0 && matrix[r][c-1] == -1) {
					iterateFlag = false;
				}
				else {
					c--;
					curr = 'l';
				}
				break;
			case ('l'):
				if (c-1 > 0 && matrix[r][c-1] != -1) {
					c--;
				}
				else if (r-1 > 0 && matrix[r-1][c] == -1) {
					iterateFlag = false;
				}
				else {
					r--;
					curr = 'u';
				}
				break;
			case ('u'):
				if (r-1 > 0 && matrix[r-1][c] != -1) {
					r--;
				}
				else if (c+1 > 0 && matrix[r][c+1] == -1) {
					iterateFlag = false;
				}
				else {
					c++;
					curr = 'r';
				}
				break;
		}
	}
}


int main() {
	vector<vector<int>> matrix;

	vector<int> fill;

	for (int i = 0; i < 3; i++) {
		fill.push_back(i);
	}
	matrix.push_back(fill);
	fill.clear();

	for (int i = 3; i < 6; i++) {
		fill.push_back(i);
	}
	matrix.push_back(fill);
	fill.clear();

	for (int i = 7; i < 10; i++) {
		fill.push_back(i);
	}
	matrix.push_back(fill);
	fill.clear();

	printSpiral(matrix);
}