class TimeMap {
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        ma[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if(ma.find(key) == ma.end()) {
            return "";
        }
        auto it = ma[key].upper_bound(timestamp);
        // If iterator points to first element it means, no time <= timestamp exists.
        if(it == ma[key].begin()) {
            return "";
        }
        return prev(it)->second;
    }
private:
    // [key: [timestamp: value]]
    // Must use map to sort keys so can do binary search
    unordered_map<string,map<int,string>> ma;
};
