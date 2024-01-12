/*
    1. Find first decreasing element from right to left
    2. Starting from that element index, iterate to right to find smallest number that is larger than the element index.
    3. Reverse the numbers from the initial element and target element found.

    EXAMPLE:
    [1, 2, 4, 3] --> [1, 3, 2, 4]

    k=1, l=3
    Swap k & l: [1, 3, 4, 2]
    Reverse(nums.begin()+k+1, nums.end()):
    [1, 3, 2, 4]

*/

// [1, 2, 4, 3] --> [1, 3, 2, 4]
void nextPermutation(vector<int>& nums) {
    int k;
    int l;
    for(k = nums.size()-2; k >= 0; k--) {
        if(nums[k] < nums[k+1]) {
            break;
        }
    }
    if(k < 0) {
        // At end of permutation sequence
        reverse(nums.begin(), nums.end());
    }
    else {
        for(l = nums.size()-1; l >= 0; l--) {
            if(nums[l] > nums[k]) {
                break;
            }
        }
        swap(nums[l], nums[k]);
        reverse(nums.begin()+k+1, nums.end());
    }
}
