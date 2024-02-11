vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    auto list1 = firstList.begin();
    auto list2 = secondList.begin();
    vector<vector<int>> res;
    while(list1 != firstList.end() && list2 != secondList.end()) {
        int firstStart = (*list1)[0];
        int firstEnd = (*list1)[1];
        int secondStart = (*list2)[0];
        int secondEnd = (*list2)[1];

        if(secondStart <= firstEnd && secondEnd >= firstStart) {
            int overlap_start = max(firstStart, secondStart);
            int overlap_end = min(firstEnd, secondEnd);
            res.push_back({overlap_start, overlap_end});
        }
        if(secondEnd > firstEnd) {
            list1++;
        }
        else {
            list2++;
        }
    }
    return res;
}
