vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Sort intervals based on start value

    // Can make an ordered map which sorts keys automatically

    if(intervals.size() == 1) {
        return intervals;
    }

    // NOTE: Permit duplicate keys with multimap
    // start, end
    multimap<int,int> ma;

    for(int i = 0; i < intervals.size(); i++) {
        ma.insert(make_pair(intervals[i][0],intervals[i][1]));
    }

    vector<vector<int>> res;

    vector<int> curr;
    for(auto it = ma.begin(); it != ma.end(); ++it) {
        int new_start = it->first;
        int new_end = it->second;
        if(curr.empty()) {
            curr = {new_start, new_end};
        }
        else {
            int prev_start = curr[0];
            int prev_end = curr[1];
            if(new_start >= prev_start && new_start <= prev_end) {
                // Compare current interval to last interval
                // If they overlap, then we merge them

                curr[0] = prev_start;
                curr[1] = max(curr[1], new_end);
            }
            else if(new_start > prev_end) {
                // If intervals do not overlap, then push curr
                // into res, and set new curr as the next interval
                res.push_back(curr);
                curr = {new_start, new_end};
            }
            if(it == prev(ma.end())) {
                // Last element in map must be pushed regardless
                res.push_back(curr);
                break;
            }
        }
    }

    return res;
}
