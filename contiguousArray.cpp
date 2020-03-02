#include "globals.h"

/*
  Given a binary array, find the maximum length of a contiguous subarray
  with equal number of 0 and 1.
*/

int findMaxLength(vector<int>& nums) {
	unordered_map<int, int> ma;
	ma[0] = -1;
	int res = 0;
	int curr = 0;
	for(uint i = 0; i < nums.size(); ++i) {
		curr += nums[i] ? 1 : -1;
		if (ma.count(curr))
			res = max(res, i - ma[curr]);
		else
			ma[curr] = i;
	}
	return res;
}
