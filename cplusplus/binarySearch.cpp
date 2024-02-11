int search(vector<int>& nums, int target) {

    int mid = nums.size()/2; // mid=3
    int L = 0;
    int R = nums.size()-1; // R=5

    while(L <= R) { // 0 < 5; 3 < 5

        // nums[3] = 5; target = 9; nums[4]=9; target == 9
        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target) {
            L = mid+1; // L=4
        }
        else {
            R = mid-1;
        }
        mid=(L+R)/2;
    }
    return -1;


}
