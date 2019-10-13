/*
  Problem Description:
  Given a sorted matrix where the number below and right of  you
  will always be bigger, write an algorithm to find if a particular
  number exist in the matrix. What is the running time of your
  algorithm.


  Solution 1:
  Typecast 2D array into a 1D array. Then sort.
  Then apply binary search.
  Time Complexity: O(N log N) because of sorting

  Solution 2:
  Perform binary search on the middle column until only
  two elements remain or the target element is in the middle
  column. The search is done to skip the rows that are not
  required.

  The two remaining elements must be adjacent.


  Time complexity: O(log N + log M)
 */

#include <iostream>
#include <vector>

using namespace std;

void binarySearch() {
	// Implement Binary Search Here
}

string findInMatrix(vector<vector<int>>& matrix, int target) {

	const int max_rows = matrix.size();
	const int max_cols = matrix[0].size();

	// Perform binary search on middle column
	const int mid_col = max_cols/2;

	return "FALSE";
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

	const int target = 59;
	string answer = findInMatrix(matrix, target);

	for (unsigned int r = 0; r < matrix.size(); r++) {
		cout << "[ ";
		for (unsigned int c = 0; c < matrix[r].size(); c++) {
			cout << matrix[r][c] << " ";
		}
		cout << "]" << endl;
	}

	cout << "Finding Target: " << target << "; Answer: "<< answer << endl;
}