vector<int> productExceptSelf(vector<int>& nums) {

    /*
        [1, 2, 3, 4] -> [24, 12, 8, 6]

        leftProducts = [1, 1, 2, 6]
        rightProducts = [24, 12, 4, 1]
    */

    int size = nums.size();
    vector<int> res(size);
    vector<int> leftProducts(size);
    vector<int> rightProducts(size);

    leftProducts[0] = 1;
    for(int i = 1; i < size; i++) {
        leftProducts[i] = nums[i-1] * leftProducts[i-1];
    }
    rightProducts[size-1] = 1;
    for(int i = size-2; i >= 0; i--) {
        rightProducts[i] = nums[i+1] * rightProducts[i+1];
    }
    for(int i = 0; i < size; i++) {
        res[i] = leftProducts[i] * rightProducts[i];
    }
    return res;
}

vector<int> optimizedProductExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n);
    output[0] = 1;
    for(int i=1; i<n; i++){
        output[i] = output[i-1] * nums[i-1];
    }
    int right = 1;
    for(int i=n-1; i>=0; i--){
        output[i] *= right;
        right *= nums[i];
    }
    return output;
}
