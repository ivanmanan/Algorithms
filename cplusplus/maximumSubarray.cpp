#include "globals.h"

/*
  Input: [-2,1,-3,4,-1,2,1,-5,4],
  Output: 6
  Explanation: [4,-1,2,1] has the largest sum = 6.
*/

int maxSubArray(vector<int>& nums)
{
    if(nums.empty()) {
        return 0;
    }

    int res = nums[0];
    int sum = nums[0];

    for(uint i = 1; i < nums.size(); i++) {
        sum = max(nums[i], sum+nums[i]);
        if (res < sum) {
            res = sum;
        }
    }
    return res;
}
