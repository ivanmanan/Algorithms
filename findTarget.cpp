#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {

	int index = 0;

	// Target is greater than last value
	if (target > nums.back()) {
		index = nums.size();
		return index;
	}

	for (auto it = nums.begin(); it != nums.end(); it++) {

		// Target was found
		if (*it == target) {
			index = it - nums.begin();
			return index;
		}

		// Iterator is greater than target
		if (*it > target) {
			index = it - nums.begin();
			return index;
		}
	}
	return index;
}

int main() {


	vector<int> nums = {1, 3, 5, 6};
	int target = 7;

	int index = searchInsert(nums, target);
	cout << index << endl;
}