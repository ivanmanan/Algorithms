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

// Distance, (x,y)
typedef pair<double, vector<int>> pd;
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> res;
    priority_queue<pd, vector<pd>, greater<pd>> pq;

    for(int i = 0; i < points.size(); i++) {
        int x = points[i][0];
        int y = points[i][1];
        double distance = sqrt(double(x*x + y*y));
        cout << "(" << x << "," << y << ")" << " - " << distance << endl;
        pd m_pair = make_pair(distance, points[i]);
        pq.push(m_pair);
    }
    for(int i = 0; i < k; i++) {
        pd m_pair = pq.top();
        pq.pop();
        res.push_back(m_pair.second);
    }

    return res;
}
