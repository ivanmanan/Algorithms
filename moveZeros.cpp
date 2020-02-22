#include "globals.h"

/*
  Ex. given [1,0,0,1]

  [1,0,0,1]
  [1]
  [1,0]
  [1,0,0]
  [1,1,0,0] --> curr pointer is at i=3,
  but lastNonZeroFoundAt is at i=1
  so we swap the two elements at i=1,i=3
*/

void moveZeroes(vector<int>& nums) {

	int lastNonZeroFoundAt = 0;
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != 0) {
			nums[lastNonZeroFoundAt++] = nums[i];
		}
	}
	for(int i = lastNonZeroFoundAt; i < nums.size(); i++) {
		nums[i] = 0;
	}
}