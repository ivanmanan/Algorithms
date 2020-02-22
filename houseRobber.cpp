#include "globals.h"

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// House Robber I

/*
  EXAMPLE

  Given: [2,7,9,3,1]
  Output: 12

  Rob house 1 (money = 2)
  Rob house 3 (money = 9)
  Rob house 5 (money = 1)


  WALKTHROUGH
  [2,7,9,3,1]

  0. prev1 = 2
     prev2 = 0

  1. prev1 = 7
     prev2 = 2

  2. prev1 = 11
     prev2 = 7

  3. prev1 = 11
     prev2 = 11

  4. prev1 = 12
     prev2 = 11

*/

int rob(vector<int>& nums) {

	int prev1 = 0;
	int prev2 = 0;

	for (int i = 0; i < nums.size(); i++) {
		int temp = prev1;
		prev1 = max(prev2 + nums[i], prev1);
		prev2 = temp;
	}
	return prev1;
}




//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// House Robber II

/*
  Constraint: Homes are arranged in a circle
*/