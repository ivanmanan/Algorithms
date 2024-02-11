int longestConsecutive(vector<int>& nums) {
    unordered_set<int> se(nums.begin(), nums.end());

    int res = 0;
    for(auto it = nums.begin(); it != nums.end(); it++) {
        if(se.find((*it)-1) == se.end()) {
            // Start of the sequence
            int length = 0;
            while(se.find((*it)+length) != se.end()) {
                ++length;
            }
            res = max(res, length);
        }
    }
    return res;
}

int longestConsecutive(vector<int>& nums) {

    // Insert all numbers into the set
    unordered_set<int> set(nums.begin(), nums.end());

    // The start of each sequence has no n-1 left neighbor

    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
        // Check if the element is the start of the sequence
        int temp = nums[i]-1;
        if(set.find(temp) == set.end()) {
            // This is the start of a sequence
            temp = nums[i];
            int curr_length = 1;
            while(set.find(temp+1) != set.end()) {
                // If next elmeent exists, then increment
                curr_length++;
                temp++;
            }
            res = max(res, curr_length);
        }
    }
    return res;
}
