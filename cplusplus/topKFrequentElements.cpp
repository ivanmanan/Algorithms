vector<int> topKFrequent(vector<int>& nums, int k) {

    vector<int> res;

    // Key: integer, value: frequency
    unordered_map<int,int> ma;

    // Time: O(N)
    // Space: O(N) - each integer is unique
    for(int i = 0; i < nums.size(); i++) {
        ma[nums[i]]++;
    }

    // 1st: Frequency, 2nd: value
    priority_queue<pair<int,int>> pq;


    // Time: O(N log N) - each element insertion is O(log N) time due to heap insertion, and then multiply by N
    // Space: O(N)
    for(auto it = ma.begin(); it != ma.end(); it++) {
        pq.push(make_pair(it->second, it->first));
    }

    // Time: O(K), where K <= N
    // Space: O(N)
    for(int i = 0; i < k; i++) {
        res.push_back(pq.top().second);
        pq.pop();
    }

    // FINAL TIME: O(N log N); SPACE: O(N)

    return res;
}
