/*
Sliding window with two pointers
1) Expand to longest subarray with flips enabled
2) If we reach a 0 with no more flips, then contract
3) Record longest subarray length
*/
int longestOnes(vector<int>& nums, int k) {
    int l = 0;
    int r = 0;
    int flips = 0;
    int res = 0;

    while(l < nums.size() && r < nums.size()) {
        while(flips < k && r < nums.size()) {
            // Expand the array
            if(nums[r] == 1) {
                r++;
            }
            else if(nums[r] == 0) {
                flips++;
                r++;
            }
        }
        // Hit maximum flips, so keep expanding with 1s
        while(r < nums.size() && nums[r] == 1) {
            r++;
        }

        res = max(res, r-l);

        // Contract array by updating l
        while(flips >= k && l < nums.size()) {
            while(nums[l] == 1) {
                l++;
            }
            if(nums[l] == 0) {
                flips--;
                l++;
            }
        }
    }

    return res;
}
