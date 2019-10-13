// Least Recently Used Cache
// SOLUTION:
// https://www.geeksforgeeks.org/lru-cache-implementation/
// Use doubly-ended queue and hash table

#include <unordered_map>
#include <iostream>
#include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity);
	int get(int key);
	void put(int key, int value);
	void display();

private:
    uint m_size;
    list<int> dq; // hold keys in queue
    unordered_map<int, list<int>::iterator> node_map;
};

LRUCache::LRUCache(int capacity) {
	m_size = capacity;
}

int LRUCache::get(int key) {
	auto got = node_map.find(key);

	// If found in hash table
	if(got != node_map.end()) {

		auto node = got->second;
		int value = *node;

		// Update reference
		dq.erase(node);
		dq.push_front(value);

		// Update hash table
		node_map[key] = dq.begin();

		return value;
	}
	else {
		return -1;
	}
}

void LRUCache::put(int key, int value) {

	// Check if already present in cache
	if(node_map.find(key) == node_map.end()) {
		// Check if cache is full
		if(dq.size() == m_size) {

			// Remove from hash table
			int old_key = dq.back();
			dq.pop_back();
			node_map.erase(old_key);
		}
	}
	else {
		dq.erase(node_map[key]);
	}
	dq.push_front(value);
	node_map[key] = dq.begin();
}

// Display contents of cache
void LRUCache::display() {
    for(auto it = dq.begin(); it != dq.end(); it++) {
        cout << (*it) << " ";
	}
    cout << endl;

	for(auto ite = node_map.begin(); ite != node_map.end(); ite++) {
		cout << "Key: " << ite->first;
		cout << endl;
	}
}

int main() {
	LRUCache cache = LRUCache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;    // prints 1
	cache.put(3, 3);                 // evicts key 2
	cout << cache.get(2) << endl;    // prints -1 (not found)
	cache.put(4, 4);                 // evicts key 1
	cout << cache.get(1) << endl;    // prints -1 (not found)
	cout << cache.get(3) << endl;    // prints 3
	cout << cache.get(4) << endl;    // prints 4
}