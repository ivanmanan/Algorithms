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

int robII(vector<int>& nums) {
	vector<int> memo1;
	vector<int> memo2;
	memo1.push_back(0);
	memo2.push_back(0);
	if(!nums.empty()){
		memo1.push_back(nums[0]);
	}
	if(nums.size() > 1){
		memo2.push_back(nums[1]);
		for(int i = 2; i < nums.size(); i++){
			//choose nums[0]
			int max1 = max((memo1[0] + nums[i-1]), memo1[1]);
			memo1[0] = memo1[1];
			memo1[1] = max1;
			//don't choose nums[0]; base case already factors in nums[1]
			int max2 = max((memo2[0] + nums[i]), memo2[1]);
			memo2[0] = memo2[1];
			memo2[1] = max2;
		}
	}
	return max(memo1.back(), memo2.back());
}
