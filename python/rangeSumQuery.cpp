// 1D array
class NumArray {
public:
/*
    nums = [-2,  0, 3, -5,  2, -1]
    sums = [-2, -2, 1, -4, -2, -3]

    sumRange [0,2] -> 1
    sumRange [2,5] -> [3,-5,2,-1] -> 1
        --> sums[5] - sums[2-1] = -3 - -2 = -1
*/
    NumArray(vector<int>& nums) {
        sums = vector<int>(nums.size()+1, 0);
        sums[0] = 0;
        for(int i = 1; i <= nums.size(); i++) {
            sums[i] = sums[i-1] + nums[i-1];
        }
    }

    int sumRange(int left, int right) {
        return sums[right+1] - sums[left];
    }
private:
    vector<int> sums;
};


// 2D array
