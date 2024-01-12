/*
    [23, 2, 4, 6, 7], k=6

    23 % 6 = 5

    (23+2) % 6 = 1

    (25+4) % 6 = 5
    --> Have duplicate k remainder in the hash table

    Consider:
    [23] and [23, 2, 4] --> both subarrays have remainder 5
    We reached an index where the current sum has exact same remainder as just one element.

    Notice:
    23 % 6 = 5
    (23+2+4) % 6 = 5
    (23 + 6) % 6 = 5
    --> we reached an existing remainder, which can only happen if multiple was 6
    Take the difference between the indexes. If greater than 2, then we know
    subarray is at least length 2.

    Edge case: if have two consecutive zeros, then that is divisible by k.
    Consider: [23, 0, 0]
    --> we still insert into the hash table the duplicate remainder 5

    Must initialize hash table with: (0:-1)
    Why? Consider: [1, 2, 3, 4], k=6
    This handles edge case where the first subarray starting from index 0 is divisible by k
    Otherwise, [1,2,3,4] would return false.

    Hash Table
    remainder | index
    ----------|------
        5       0
        1       1
        5       2
        0       -1 --> initialize

*/

bool checkSubarraySum(vector<int>& nums, int k) {
    // remainder:index
    unordered_map<int,int> ma;
    // Edge case for subarray starting at idx 0 is multiple of k
    ma[0] = -1;

    int currSum = 0;
    for(int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        int remainder = currSum % k;

        auto got = ma.find(remainder);
        if(got != ma.end()) {
            if(i - ma[remainder] >= 2) {
                return true;
            }
        }
        else {
            ma[remainder] = i;
        }
    }
    return false;
}
