// NOTE: Sorting requires O(N log N) time. Use a linked list and just print!
vector<int> findBuildings(vector<int>& heights) {
    vector<int> res;
    list<int> dq;

    int obstruction = INT_MIN;
    for(int i = heights.size()-1; i >= 0; i--) {
        if(heights[i] > obstruction) {
            dq.push_front(i);
        }
        obstruction = max(obstruction, heights[i]);
    }

    while(!dq.empty()) {
        res.push_back(dq.front());
        dq.pop_front();

    }
    return res;
}

vector<int> findBuildings(vector<int>& heights) {
    vector<int> res;
    int right_max = INT_MIN;

    for(int i = heights.size()-1; i >= 0; i--) {
        if(heights[i] > right_max) {
            res.push_back(i);
            right_max = heights[i];
        }
    }
    sort(res.begin(), res.end());
    return res;
}
