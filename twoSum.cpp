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