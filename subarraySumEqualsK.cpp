/*
    [1, -1, 1, 1, 1, 1]; k=3
    output: 4
    i=4: [1,-1,1,1,1], [1,1,1]
    i=5: [1,1,1], [-1, 1, 1, 1, 1]

    currSum - k = prefixSum if exists

    i=0: (1)-3=-2
    i=1: (0)-3=-3
    i=2: (1)-3=-2
    i=3: (2)-3=-1
    i=4: (3)-3= 0 --> prefixSum has 2
    i=5: (4)-3= 1 --> prefixSum has 2
    output: 4

    [0,1] --> must be inserted first into map
    e.g. [1,2] --> first element to sum to k

    i=1:
    PrefixSum |Count
        0        1
        1        2
    i=2:
    PrefixSum |Count
        0        2
        1        2
    i=5:
    PrefixSum |Count
        0        2
        1        2
        2        1
        3        1
*/

int subarraySum(vector<int>& nums, int k) {
    // key: prefix, value: count
    unordered_map<int,int> ma;
    ma[0] = 1;
    int currSum = 0;
    int res = 0;
    for(auto& it: nums) {
        currSum += it;
        int target = currSum - k;

        auto got = ma.find(target);
        if(got != ma.end()) {
            res += got->second;
        }
        ma[currSum]++;
    }
    return res;
}
