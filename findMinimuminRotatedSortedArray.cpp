#include "globals.h"

/*
  Input: [3,4,5,1,2]
  Output: 1

*/

int findMin(vector<int>& nums) {

	int L = 0;
	int R = nums.size() - 1;

	// Array size 1 or was not rotated
	if(nums.size() == 1 || nums[R] > nums[L]) {
		return nums[0];
	}

	// Binary Search
	while(R > L) {
		int mid = L + (R - L) / 2;

		// Ex. ... 3 4 5 1 2 ... --> mid is at 5 --> (5 > 1)
		if(nums[mid] > nums[mid+1]) {
			return nums[mid+1];
		}
		// Ex. ... 3 4 5 1 2 ... --> mid is at 1 --> (5 > 1)
		if(nums[mid-1] > nums[mid]) {
			return nums[mid];
		}

		// If mid element is greater than the 0th element, then least value is to the right
		if(nums[mid] > nums[0]) {
			L = mid + 1;
		}
		else {
            // If mid element is less than the 0th element, then least value is to the left
			R = mid - 1;
		}
	}
	return - 1;
}