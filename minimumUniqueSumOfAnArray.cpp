int getMinimumUniqueSum(vector<int> arr) {

    // Base case
    if(!arr.size()) {
        return 0;
    }

    sort(arr.begin(), arr.end());

    int sum = arr[0];
    int prev = arr[0];

    for(int i = 1; i < arr.size(); i++) {
        int curr = arr[i];
        if(prev >= curr) {
            curr = prev + 1;
        }
        sum += curr;
        prev = curr;
    }
    return sum;
}