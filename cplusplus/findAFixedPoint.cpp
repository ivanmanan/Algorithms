#include "globals.h"

/*
  Fixed Point in an array is an index i such that arr[i] is equal to i

  SOLUTION
  Binary search with comparing fixed point

  WALKTHROUGH

           0    1  2  3  4
  Given  {-10, -5, 0, 3, 7}

  1. mid = 2
     nums[mid] = 0

	 mid > nums[mid]
	  2  >  0

	 Therefore, go right

 */

int binarySearch(vector<int>& nums, int l, int r) {

	if(l > r) {
		return -1;
	}

	int mid = (l + r)/2;

	if(mid == nums[mid]) {
		return mid;
	}
	//
	else if(mid > nums[mid]) {
		return binarySearch(nums, mid+1, r);
	}
	else {
		return binarySearch(nums, l, mid-1);
	}
}


int findFixedPoint(vector<int>& nums) {
	int l = 0;
	int r = nums.size() - 1;
	return binarySearch(nums, l, r);
}


int main() {
	vector<int> nums = {-10, -5, 0, 3, 7};
	int res = findFixedPoint(nums);
	int ans = 3;

	cout << "Output:   " << res << endl;
	cout << "Expected: " << ans << endl;
}
