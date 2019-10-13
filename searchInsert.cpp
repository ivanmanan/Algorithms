#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {

	int L = 0;
	int R = nums.size()-1;
	int mid = 0;

	// Iterative binary search - O(log N)
	while(L <= R) {

		// Prevent integer overflow
		mid = L + (R-L)/2;

		if(nums[mid] == target) {
			return mid;
		}
		else {
			if(nums[mid] >= target) {
				R = mid-1;
			}
			else {
				L = mid+1;
			}
		}
	}
	mid = L + (R-L)/2;
	// No element was found
	return mid;
}