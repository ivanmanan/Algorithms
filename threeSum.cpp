#include "globals.h"

vector<vector<int>> threeSum(vector<int>& nums) {

	vector<vector<int>> triplets;

	for(int i = 0; i < nums.size()-1; i++) {

		// Do Two Sum here
		unordered_set<int> seen;
		for(int j = i+1; j < nums.size(); j++) {
			int complement = -(nums[i] + nums[j]);
			auto got = seen.find(complement);

			// Exists in hash table
			if(got != seen.end()) {
				vector<int> triplet = {nums[i], nums[j], complement};
				triplets.push_back(triplet);
			}
			else {
				seen.insert(nums[j]);
			}
		}
	}
	return triplets;
}

vector<int> threeSumWithTarget(vector<int>& numbers, int target) {
	vector<int> solution;
	int sum;

	for (uint i = 0; i < numbers.size() - 2; i++) {

		unordered_set<int> s;
		sum = target - numbers[i];

		for (uint j = i+1; j < numbers.size(); j++) {

			// Complement found in hash table
			if (s.find(sum - numbers[j]) != s.end()) {
				solution.push_back(numbers[i]);
				solution.push_back(numbers[j]);
				solution.push_back(sum - numbers[j]);
				return solution;
			}
			s.insert(numbers[j]);
		}
	}
	return solution;
}

int main() {
	const int target = 27;
	vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> ans = threeSumWithTarget(numbers, target);

	int sum = 0;
	cout << "Answer is: ";
	for (auto it = ans.begin(); it != ans.end(); it++) {
		sum += *it;
		cout << *it << " ";
	}
	cout << endl << "Does Sum Equal " << target << "? ";
	if (sum == target) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}