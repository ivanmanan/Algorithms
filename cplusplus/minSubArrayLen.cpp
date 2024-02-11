int minSubArrayLen(int target, vector<int>& nums) {
    int res = INT_MAX;
    int i = 0;
    int j = 0;
    int sum = 0;

    while(i < nums.size()) {
        sum += nums[i];


        while(sum >= target) {
            res = min(res, i - j + 1);
            sum = sum - nums[j];
            j++;
        }
        i++;
    }
    return res == INT_MAX ? 0 : res;
}
