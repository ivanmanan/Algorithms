// Complexity: O(n)
// We have to iterate through the nums array, but perform an O(1) look-up

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> twoSum(vector<int>& nums, int target) {

	// Must sort array first for O(N log N)

	vector<pair<int, int>> solution;
	unordered_set<int> complement_set; // Map <Key, Value>

	// Construct hash table
	// Element is both key and value
	for (auto it = nums.begin(); it != nums.end(); it++) {
		complement_set.insert(*it);
	}

	// Iterate through entire array
	auto it = nums.begin();
	uint i = 0;
	pair<int, int> temp;
	while (i < nums.size()/2) {
		int complement = target - (*it);

		// Find the complement key in the hash table
		auto got = complement_set.find(complement);

		// If complement key was found
		if (got != complement_set.end() && *got != *it) {
			temp.first = *got;
			temp.second = *it;
			solution.push_back(temp);
		}
		++it;
		++i;
	}
	return solution;
}

int main() {
	vector<int> nums = {1, 2, 3, 4, 5, 6};

	vector<pair<int, int>> solution = twoSum(nums, 6);

	for (auto it = solution.begin(); it != solution.end(); ++it) {
		cout << (*it).first << ", " << (*it).second << endl;
	}
}
