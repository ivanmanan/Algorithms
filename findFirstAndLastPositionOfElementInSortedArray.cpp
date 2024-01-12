/*
nums = [5,7,7,8,8,10], target = 8
output: [3,4]

l=0,r=5,mid=2
Go right
l=3,r=5,mid=4



Binary search to target element
Then do two pointers spreading out left and right
*/
vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while(l <= r) {
        int mid = (r+l)/2;

        if(nums[mid] == target) {
            int i = mid;
            int j = mid;
            while(i-1 >= 0 && nums[i-1] == target) {
                i--;
            }
            while(j+1 < nums.size() && nums[j+1] == target) {
                j++;
            }
            return {i, j};
        }
        else if(nums[mid] > target) {
            // Go left
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return {-1, -1};
}
