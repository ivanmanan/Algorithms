// Space complexity: O(K) - size of pq, where K <= N. This example in particular uses space O(N).
// Time complexity: O(N log N)
/*
    Heap time complexity:
    O(n) is the cost of running a "heapify" function to create a heap of n elements.
    And that means building a heap structure. Build a heap structure with all the elements
    inserted in a way that it satisfies the heap invariant (usually, a tree of nodes sorted
    only from top to bottom in ascending/descending order depending on the type).

    We are constructing an empty min heap and adding points one at a time. The cost of adding
    and removing elements to a heap is O(log(k)) where k is the size of the heap. This is the
    time required in the worst case to restore the heap invariant or "bubbling up/down" after
    the insertion/removal of an element. If you repeat this push/pop operation n times for each
    element in the input array, then you have roughly O(n * log(k)).
*/

// Use max heap: O(N log K)
// Use min heap: O(N log N)
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<double,pair<int,int>>> max_pq;

    // Time: O(N log N)
    // Space: O(K) - keep track of K elements
    for(auto& point: points) {
        double x = double(point[0]);
        double y = double(point[1]);
        double distance = sqrt(x*x + y*y);
        max_pq.push(make_pair(distance, make_pair(x,y)));
        while(max_pq.size() > k) {
            // Pop the largest element to retain log K heap insertion
            max_pq.pop();
        }
    }
    vector<vector<int>> res;
    while(!max_pq.empty()) {
        int x = max_pq.top().second.first;
        int y = max_pq.top().second.second;
        max_pq.pop();
        res.push_back({x, y});
    }
    return res;
}
