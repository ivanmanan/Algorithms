#include "globals.h"


// Constraint: Select a position n, and all other elements are incremented by 1
int minMoves(vector<int>& nums) {

	int minimum = INT_MAX;
	int sum = 0;
	for(auto it = nums.begin(); it != nums.end(); it++) {
		minimum = minimum > *it ? *it : minimum;
		sum += *it;
	}

	int res = sum - nums.size() * minimum;
	return res;
}

// Constraint: Select a desired element and increment/decrement by 1
// SOLUTION: Sort the elements, and have all elements equivalent to the median

// Ex. Given { 1 2 3 6 6 }
// Output:   { 3 3 3 3 3 }
int minMoves2(vector<int>& nums) {
	int res = 0;
	if(nums.size() <= 1) {
		return res;
	}
	sort(nums.begin(), nums.end());

	int median = nums[nums.size() / 2];

	for(int i = 0; i < nums.size(); i++){
		res += abs(nums[i] - median);
	}
	return res;
}
