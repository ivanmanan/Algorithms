// distance, original value
typedef pair<int,int> pv;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    // N = size of array
    // Creating priority queue: O(N * log N)
    // Time complexity to insert into the priority queue is log(N) - the height of the tree
    //
    priority_queue<pv, vector<pv>, greater<pv>> min_pq;
    for(int i = 0; i < arr.size(); i++) {
        int distance = abs(arr[i] - x);
        min_pq.push(make_pair(distance, arr[i]));
    }

    vector<int> res;

    // priority queue is size K
    // Time: O(K + K log K), where K <= N size of array.
    // Space: O(K), where K <= N
    while(!min_pq.empty()) {
        pv m_pair = min_pq.top();
        min_pq.pop();

        cout << "DISTANCE: " << m_pair.first << ", " << "NUM: " << m_pair.second << endl;

        if(res.size() == k) {
            // Sort: O(K log K) --> one time operation
            sort(res.begin(), res.end());
            return res;
        }
        else {
            res.push_back(m_pair.second);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
