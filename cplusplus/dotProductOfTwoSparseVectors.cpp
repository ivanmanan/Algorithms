class SparseVector {
public:

    /*
    Map: indices with nonzero
    */

    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                ma[i] = nums[i];
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for(auto& it: ma) {
            res += it.second * vec.ma[it.first];
        }
        return res;
    }

    // Key: index, value: number
    unordered_map<int,int> ma;
};
