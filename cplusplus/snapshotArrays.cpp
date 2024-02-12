/*
    (snap_id, nums[i])
    [0, 0, 0, 0, 0]
        1, 2, 3
    [0, 1, 2, 3, 0] snap=0
           1
    [0, 1, 1, 3, 0] snap=1
           4
    [0, 2, 4, 3, 0] snap=2

    Keep an array of indexes since we are given size
    Index 0: []
    Index 1: [(0,1)]
    Index 2: [(0,2), (1,1), (1,3), (2,4)]
    Index 3: [(0,3)]
    Index 4: []

    Say we want index 3 at snap 1
    --> Go to index 3, then do binary search upper_bound for (1)
*/
class SnapshotArray {
public:
    SnapshotArray(int length) {
        snap_id = 0;
        for(int i = 0; i < length; i++) {
            historical_records[i].push_back({0,0});
        }
    }

    void set(int index, int val) {
        historical_records[index].push_back({snap_id, val});
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id) {
        // Upper bound searches for the first element greater than snap_id
        auto it = upper_bound(historical_records[index].begin(), historical_records[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
private:
    int snap_id;
    unordered_map<int,vector<pair<int,int>>> historical_records;
};
