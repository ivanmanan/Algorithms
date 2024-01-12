int majorityElement(vector<int>& nums) {
    int curr = nums[0];
    int votes = 1;
    if(nums.size() == 1) {
        return curr;
    }
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != curr) {
            votes--;
        }
        else {
            votes++;
        }
        if(votes <= 0) {
            votes = 1;
            curr = nums[i];
        }
    }
    return curr;
}
