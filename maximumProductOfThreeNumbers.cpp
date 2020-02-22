#include "global.h"

// Given an array, find the triplet that forms the greatest product

/*
  Edge cases: duplicate numbers, all negative values

  Trivial solution: Merge sort
  O(N log N) time, O(N) space

  Compare the products of triplets
  (-,-,+) OR (+,+,+)

  If all negative values in array, then the triplet will be
  (-,-,-)


  Ex.
  Given [-1, -2, -3, -4]

  WALKTHROUGH
  max1 = -1
  max2 = -2
  max3 = -3
  min1 = -4
  min2 = -3

  max(-6, -12)

  Output: -6

*/

// Can be solved in O(N) time


/*
  1. Three greatest positive integers
  2. Two lowest negative integers and greatest positive integer
  3. If all negatives: three greatest negative integers
*/

int maximumProduct(vector<int>& nums) {

	int min1, min2;
	min1 = min2 = INT_MAX;

	int max1, max2, max3;
	max1 = max2 = max3 = INT_MIN;

	for(int i = 0; i < nums.size(); i++) {
		if(max1 < nums[i]) {
			max3 = max2;
			max2 = max1;
			max1 = nums[i];
		}
		else if(max2 < nums[i]) {
			max3 = max2;
			max2 = nums[i];
		}
		else if(max3 < nums[i]) {
			max3 = nums[i];
		}

		if(min1 > nums[i]) {
			min2 = min1;
			min1 = nums[i];
		}
		else if(min2 > nums[i]) {
			min2 = nums[i];
		}
	}

	int res = max(max1*max2*max3, min1*min2*max1);
	return res;
}