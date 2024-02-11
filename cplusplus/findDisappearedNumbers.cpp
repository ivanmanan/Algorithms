vector<int> findDisappearedNumbers(vector<int>& nums) {

    unordered_set<int> seen;
    vector<int> res;

    for(auto it = nums.begin(); it != nums.end(); it++) {
        seen.insert(*it);
    }

    for(int i = 1; i != nums.size() + 1; i++) {
        if(seen.find(i) == seen.end()) {
            res.push_back(i);
        }
    }
    return res;
}
