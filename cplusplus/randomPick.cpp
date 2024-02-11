// Random Pick Index
class RandomPickIndex {
public:
    RandomPickIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            ma[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto got = ma.find(target);
        if(got != ma.end()) {
            // vector of indices: got->second
            int rng = rand() % got->second.size();
            return got->second[rng];
        }
        else {
            // Don't know what to do
            return INT_MIN;
        }
    }
private:
    // Key: integer, value: indexes
    unordered_map<int,vector<int>> ma;
};

// Random Pick with Weight
class RandomPickWithWeight {
public:
    /*
        Consider input: [1, 3, 4, 6]

        Probability of:
        index 0 --> 1/14
        index 1 --> 3/14
        index 2 --> 4/14
        index 3 --> 6/14

        Transformation from input: [1, 1+3, 1+3+4, 1+3+4+6]
        v: [1, 4, 8, 14]

        Get random integer in the range:
        [0,v[3]) --> [0,14) AKA 0-13

        upper bound: Do binary search for first element greater than rng number
        [1, 4, 8, 14]

        rng:
        0: index 0
        1: index 1
        2: index 1
        3: index 1
        4: index 2
        5: index 2
        6: index 2
        7: index 2
        8: index 3
        ...
        13: index 3

        If input 0:
        [1, 0, 4, 6] --> [1, 1, 5, 7]; rng: [0,7)
        index 0: 1/7
        index 1: 0/7
        index 2: 4/7
        index 3: 6/7
    */
    RandomPick(vector<int>& w) {
        v.push_back(w[0]);
        for(int i = 1; i < w.size(); i++) {
            v.push_back(v[i-1] + w[i]);
        }
    }

    int pickIndex() {
        int n = rand() % v[v.size()-1];
        auto it = upper_bound(v.begin(),v.end(),n);
        return it - v.begin(); // Return index of this iterator
    }

private:
    vector<int> v;
};
