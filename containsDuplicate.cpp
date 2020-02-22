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