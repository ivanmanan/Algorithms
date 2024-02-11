#include "globals.h"

vector<int> twoSum(vector<int>& nums, int target) {

	vector<int> indices;

	// number_value:index
	unordered_map<int,int> ma;

	for(int i = 0; i < nums.size(); i++) {
		int complement = target - nums[i];
		auto got = ma.find(complement);
		if(got != ma.end()) {
			indices.push_back(i);
			indices.push_back(got->second);
		}
		else {
			ma.insert({nums[i], i});
		}
	}
	return indices;
}

// Two Sum with the input being a sorted array
vector<int> twoSum(vector<int>& numbers, int target) {

	vector<int> res;
	int i = 0;
	int j = numbers.size()-1;
	while(i < j) {
		int sum = numbers[i] + numbers[j];
		if(sum == target) {
			res.push_back(i+1);
			res.push_back(j+1);
			return res;
		}
		else if(sum < target) {
			i++;
		}
		else {
			// sum > target
			j--;
		}
	}
	return res;
}
