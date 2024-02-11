#include "globals.h"

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {

        auto got = ma.find(key);

        if(got != ma.end()) {
            int value = ma[key].first;

            // Update the cache
            dq.erase(ma[key].second);
            dq.push_front(key);
            ma[key] = make_pair(value, dq.begin());

            return value;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {

        auto got = ma.find(key);

        // Not found in cache
        if(got == ma.end()) {
            // Discard least recently used item
            if(m_capacity == dq.size()) {
                int last = dq.back();
                dq.pop_back();
                ma.erase(last);
            }
        }
        else {
            // Found in cache
            dq.erase(ma[key].second);
        }
        dq.push_front(key);
        ma[key] = make_pair(value, dq.begin());
    }

private:
    int m_capacity;
    // key:{value,iterator}
    unordered_map<int, pair<int,list<int>::iterator>> ma;
    // dq contains all the keys
    list<int> dq;
};


int main() {
	LRUCache lru(1);

	lru.put(2,1);
	int res = lru.get(2);
	int ans = 1;

	cout << "Step 1" << endl;
	cout << "Output:   " << res << endl;
	cout << "Expected: " << ans << endl;
	cout << "===========================================" << endl;

	lru.put(3,2);
	res = lru.get(2);
	ans = -1;

	cout << "Step 2" << endl;
	cout << "Output:   " << res << endl;
	cout << "Expected: " << ans << endl;
	cout << "===========================================" << endl;

	res = lru.get(3);
	ans = 2;

	cout << "Step 3" << endl;
	cout << "Output:   " << res << endl;
	cout << "Expected: " << ans << endl;
}