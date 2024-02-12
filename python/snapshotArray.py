"""
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
"""

class SnapshotArray:

    def __init__(self, length: int):
        self.snap_id = 0
        self.historical_records = {} # {int: [(snap_id,val)]}
        for i in range(length):
            self.historical_records[i] = [(0,0)]

    def set(self, index: int, val: int) -> None:
        last_pair = self.historical_records[index][-1]
        if last_pair and last_pair[0] == self.snap_id:
            self.historical_records[index][-1] = (self.snap_id, val)
        else:
            self.historical_records[index].append((self.snap_id, val))
        return None

    def snap(self) -> int:
        curr_snap_id = self.snap_id
        self.snap_id += 1
        return curr_snap_id

    def get(self, index: int, snap_id: int) -> int:
        print(self.historical_records)
        # Binary search
        index_snaps = self.historical_records[index]
        l = 0
        r = len(index_snaps)-1
        ans = -1
        while l <= r:
            mid = int((l+r)/2)
            target_snap = index_snaps[mid][0]
            target_val = index_snaps[mid][1]
            if target_snap <= snap_id:
                # upper_bound binary search
                # if target is not found, find next element to the target
                ans = mid
                l = mid+1
            else:
                r = mid-1
        if ans == -1:
            return 0
        return index_snaps[ans][1]
