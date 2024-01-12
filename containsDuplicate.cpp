#include "globals.h"

bool containsDuplicate(vector<int>& nums) {
	unordered_set<int> st;
	for(int i = 0; i < nums.size(); i++) {
		auto got = st.find(nums[i]);

		// Exists in hash table
		if(got != st.end()) {
			return true;
		}
		else {
			st.insert(nums[i]);
		}
	}
	return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	// int:index
	unordered_map<int,int> ma;
	for(int i = 0; i < nums.size(); i++) {
		auto got = ma.find(nums[i]);
		if(got != ma.end()) {
			int j = got->second;
			if(abs(i-j) <= k) {
				return true;
			}
		}
		ma[nums[i]] = i;
		continue;
	}
	return false;
}
