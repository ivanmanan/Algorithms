class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        auto got = ma.find(val);
        if(got == ma.end()) {
            // Insert val into back of the array
            contents.push_back(val);
            ma[val] = contents.size()-1;
            return true;
        }
        else {
            return false;
        }
    }

    bool remove(int val) {
        auto got = ma.find(val);
        if(got != ma.end()) {
            int index = got->second;
            ma.erase(val);
            if(index != contents.size()-1) {
                // Swap back of array with index
                int temp = contents.back();
                contents[index] = temp;
                ma[temp] = index;
            }
            contents.pop_back();
            return true;
        }
        else {
            return false;
        }
    }

    int getRandom() {
        int rng = rand() % contents.size();
        return contents[rng];
    }
private:
    // Key: val, value: index
    unordered_map<int,int> ma;
    vector<int> contents;
};
