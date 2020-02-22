#include "globals.h"

void sort(vector<int>& nums) {

	for(int i = 0; i < nums.size()-1; i++) {
		for(int j = 0; j < nums.size()-i-1; j++) {
			if(nums[j] > nums[j+1]) {
				swap(nums[j], nums[j+1]);
			}
		}
	}
}

int main() {
	vector<int> nums = {4, 3, 1, 2, 9, 5, 8, 6, 7, 10, 12, 11};
	sort(nums);
	for(auto it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}