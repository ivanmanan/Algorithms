/*
  Solution:
  https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
 */

// Recursive Solution
class Solution {
public:

    int rob(vector<int>&nums, int i) {
        if (i < 0) {
            return 0;
        }
        int temp1 = rob(nums, i-2) + nums[i];
        int temp2 = rob(nums, i-1);

        return std::max(temp1, temp2);
    }

    int rob(vector<int>& nums) {
        return rob(nums, nums.size()-1);
    }
};

// Dynamic Programming Solution
public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int[] memo = new int[nums.length + 1];
    memo[0] = 0;
    memo[1] = nums[0];
    for (int i = 1; i < nums.length; i++) {
        int val = nums[i];
        memo[i+1] = Math.max(memo[i], memo[i-1] + val);
    }
    return memo[nums.length];
}


class Solution {
public:
    int rob(vector<int>& nums) {

        int prev1 = 0;
        int prev2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            int temp = prev1;
            prev1 = std::max(prev2 + num[i], prev1);
            prev2 = temp;
        }
        return prev1;
    }
};