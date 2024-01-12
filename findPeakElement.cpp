int findPeakElement(vector<int>& nums) {

    int l = 0;
    int r = nums.size()-1;

    while(l < r) {
        int mid = (r-l)/2 + l;
        if(nums[mid] > nums[mid+1]) {
            // 1 2 3 2 1
            // Go left
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    return l;

}
