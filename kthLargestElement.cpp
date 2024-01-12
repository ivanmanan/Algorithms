/*
    [3, 2, 1, 5, 6, 4], k=2, output=5

    min_pq: [1, 2, 3] --> [2, 3] --> [5, 6]
    max_pq: [2, 1]
    --> have to use min_pq!!!
*/
// TIME: O(N log K) --> Only sort K elements
// SPACE: O(K) -> heap size
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> min_pq;

    for(auto& num: nums) {
        min_pq.push(num);
        while(min_pq.size() > k) {
            min_pq.pop();
        }
    }
    return min_pq.top();
}

// In a stream: Note may be better to use min_pq instead of max_pq to have O(K) space

KthLargest(int k, vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
    }
    m_k = k;
}

int add(int val) {
    pq.push(val);

    // Do not want to modify the original data
    priority_queue<int> temp_pq = pq;

    int res = 0;
    for(int i = 0; i < m_k; i++) {
        res = temp_pq.top();
        temp_pq.pop();
    }
    return res;
}
