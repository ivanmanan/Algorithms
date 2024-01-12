
/*
    Time complexity: O(n * log n), where n = number of jobs.
        Jobs are inserted and sorted by start time via BST.
        For each job, use binary search to find maximum profit
        for its end time.
    Space complexity: O(n). Memoized maximum profit for each
        end time.
*/
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

    // Key: start times; value: maximum profit
    map<int, int> times;

    // Key: start times; value: [(end time1, profit1), (end time2, profit2)]
    unordered_map<int, vector<pair<int,int>>> jobs;

    // Since times in the map are sorted, process each time point
    // right to left:
    //      Lookup job information in the unordered map by start time
    //      Set the maximum profit as the greater of:
    //          - Running maximum profit
    //          - Job profit plus maximum profit at end of job
    //      Update the running maximum profit

    for(int i = 0; i < startTime.size(); i++) {
        times[startTime[i]] = 0;
        jobs[startTime[i]].push_back(make_pair(endTime[i],profit[i]));
    }
    int res = 0;

    // Reverse iterate the sorted map
    for(auto it = times.rbegin(); it != times.rend(); it++) {
        int start = it->first; // Start at 6. Next is 4.
        for(auto job : jobs[start]) { // jobs[6] --> (9, 60)/ jobs[4] --> (6, 70)
            // returns an iterator pointing to the first element that is not less (>=) than key
            auto ite = times.lower_bound(job.first); //times[>=9], which does not exist. times[>=6], which exists
            res = max(res, (ite == times.end() ? 0 : ite->second) + job.second); // res=60. res=60+70=130
        }
        it->second = res; // This pointer updates the times map. times[6]=60. times[4]=130
    }

    return res;
}
