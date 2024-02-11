#include "globals.h"

/*
  Given an array of integers nums, write a method that returns the
  "pivot" index of this array.

  We define the pivot index as the index where the sum of the numbers
  to the left of the index is equal to the sum of the numbers to the
  right of the index.

  If no such index exists, we should return -1. If there are multiple
  pivot indexes, you should return the left-most pivot index.
*/

int pivotIndex(vector<int>& nums) {
	int sum = 0;
	for(int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}
	int leftSum = 0;

	for(int i = 0; i < nums.size(); i++) {
		// Prefix sum
		if(leftSum == sum - leftSum - nums[i]) {
			return i;
		}
		else {
			leftSum += nums[i];
		}
	}
	return -1;
}
