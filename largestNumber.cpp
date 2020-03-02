#include "globals.h"

/*
  Given a list of non negative integers, arrange them such that they
  form the largest number.

  Input: [10,2]
  Output: "210"
*/

string largestNumber(vector<int>& nums) {
	vector<string> strs(nums.size());
	for (auto i = 0; i < nums.size(); ++ i) {
		strs[i] = to_string(nums[i]);
	}
	auto cmp = [](const string& s1, const string& s2) {
		return s1 + s2 > s2 + s1;
	};
	sort(strs.begin(), strs.end(), cmp);
	if (!strs.empty() && strs[0] == "0") {
		return "0";
	}
	string result;
	for (const auto& str : strs) {
		result += str;
	}
	return result;
}