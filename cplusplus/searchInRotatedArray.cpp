int search(vector<int>& nums, int target) {

    int l = 0;
    int r = nums.size()-1;

    while(l <= r) {

        int mid = (r-l)/2 + l;

        if(nums[mid] == target) {
            return mid;
        }

        if(nums[l] <= nums[mid]) {
            // If low <= mid, then the left side is sorted
            if(nums[l] <= target && nums[mid] >= target) {
                // Go left
                r = mid-1;
            }
            else {
                // Go right
                l = mid+1;
            }
        }
        else {
            // The right side of the array is sorted
            if(nums[mid] <= target && nums[r] >= target) {
                // Go right
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
    }
    return -1;


}
