/*
  Problem:
  Given an array, find the number of distinct pairs
  (A[i], A[j]), but i < j strictly

  Must be done in O(N) time

  Ex. A = { 1, 2, 1, 1, 4, 5 }

  1,1
  2,1
  1,1
  1,4
  2,4
  1,5
  2,5
  4,5

  Answer: 8

  H{1:3} -- key = 1; value = 3
  Use a hash table to count the number of pairs that distinct element already
  has. Note this was from a Google interview.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int distinctPairs(vector<int>& A) {

	unordered_map<int, int> pair_map;
	int distinctElements = 0;
	int ans = 0;
	for (auto it = A.begin(); it != A.end(); it++) {

		auto got = pair_map.find(*it);

		// Element not found in hash table
		if (got == pair_map.end()) {
			distinctElements++;
			ans += distinctElements;
		}
		// Element has been used before
		else if (got->second == 1) {
			// Change got->second to 2
			ans += distinctElements - 1;
		}
		else if (got->second == 2) {
			// Change got->second to 3

		}
		else if (got->second >= 3){
			// Do nothing
			continue;
		}
	}
	return ans;
}

int main() {
	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(1);
	A.push_back(1);
	A.push_back(4);
	A.push_back(5);

	int ans = distinctPairs(A);

	cout << "Answer: " << ans << endl;
}