#include "globals.h"


/*
  We are given an array with infinite elements.
  The array is in sorted order.
  Find the target element.

  TIME COMPLEXITY
  O(log N)
 */

int binarySearch(vector<int>& nums, int l, int r, int target) {

	if(l > r) {
		return -1;
	}
	else {
		int mid = l + (r - 2)/2;
		if(nums[mid] == target) {
			return mid;
		}
		else if(nums[mid] > target) {
			return binarySearch(nums, l, mid-1, target);
		}
		else {
			return binarySearch(nums, mid+1, r, target);
		}
	}
}

bool findElement(vector<int> nums, int target) {

	int l = 0; // low
	int h = 1; // high

	int val = nums[0];

	// Find the high boundary
	while(val < target) {
		l = h; // Update lower boundary
		h = 2*h; // Double high boundary
		val = nums[h]; // Update value
	}

	return binarySearch(nums, l, h, target);
}