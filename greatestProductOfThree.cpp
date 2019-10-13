#include <iostream>
#include <vector>

using namespace std;

// Given an array, find the triplet that forms the greatest product

/*
  Edge cases: duplicate numbers, all negative values

  Trivial solution: Merge sort
  O(N log N) time, O(N) space

  Five for-loops
  Three for-loops to find the three greatest positive elements
  Two for-loops to find the two least negative elements

  Compare the products of triplets
  (-,-,+) OR (+,+,+)

  If all negative values in array, then the triplet will be
  (-,-,-)

*/

// Can be solved in O(N) time
vector<int> greatestProductOfThree(vector<int> numbers) {
	vector<int> triplet;



	return triplet;
}


int main() {

	// Answer: -5, -6, 6
	vector<int> nums = {1, 2, 3, 4, 5, 6, -1, -2, -3, -4, -5, -6};
	vector<int> ans = greatestProductOfThree(nums);
	for(uint i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}