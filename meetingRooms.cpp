/*
    Given an array of meeting time intervals consisting of
    start and end times [[s1,e1],[s2,e2],...] (si < ei),
    determine if a person could attend all meetings.

    Input: intervals = [(0,30),(5,10),(15,20)]
    Output: false
    Explanation:
    (0,30), (5,10) and (0,30),(15,20) will conflict
*/

// Meeting Rooms I
bool canAttendMeetings(vector<Interval> &intervals) {
    // start, end
    multimap<int,int> ma;
    for(int i = 0; i < intervals.size(); i++) {
        ma.insert(make_pair(intervals[i].start, intervals[i].end));
    }

    int prev_start = INT_MIN;
    int prev_end = INT_MIN;
    for(auto it = ma.begin(); it != ma.end(); it++) {
        int new_start = it->first;
        int new_end = it->second;
        if(new_start > prev_start && new_start < prev_end) {
            return false;
        }
        else {
            prev_start = new_start;
            prev_end = new_end;
        }
    }
    return true;
}


// Meeting Rooms II
/*
    Sort the starts array as one array.
    Sort the ends array as a separate array.

    Iterate through starts first. i=0, j=0
    If start[i] < ends[j], then increment i. Meeting conflicts. Increment count
    If starts[i] >= ends[j], then increment j. Meeting just ended. Decrement count.

    EXAMPLE:
    Starts: [0, 5, 10]
    Ends: [10, 15, 30]
*/
int minMeetingRooms(vector<Interval> &intervals) {
    vector<int> starts;
    vector<int> ends;
    for(auto& it: intervals) {
        starts.push_back(it.start);
        ends.push_back(it.end);
    }
    int res = 0;
    int count = 0;
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int i = 0;
    int j = 0;
    while(i < starts.size()) {
        if(starts[i] < ends[j]) {
            // Meeting started
            i++;
            count++;
        }
        else {
            // Meeting ended
            j++;
            count--;
        }
        res = max(res, count);
    }
    return res;
}
