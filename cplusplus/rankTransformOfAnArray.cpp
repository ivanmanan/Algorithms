vector<int> arrayRankTransform(vector<int>& arr) {
    // Use min-heap & map
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_pq;
    for(int i = 0; i < arr.size(); i++) {
        min_pq.push({arr[i], i});
    }
    int prev = INT_MAX;
    int rank = 0;
    while(!min_pq.empty()) {
        int value = min_pq.top().first;
        int index = min_pq.top().second;
        min_pq.pop();
        if(prev != value) {
            prev = value;
            rank++;
        }
        arr[index] = rank;
    }
    return arr;
}
