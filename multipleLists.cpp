/*
Problem Statement:
Given N sorted linked lists, create an iterator that returns
the next element within a sorted array

Solution:

1. Start with iterators for beginning element of each list.
2. Create min-heap O(N log N) time --- pre-processing
3. If no duplicates: Create a hash table with O(N) space that has key
   as element in list and value as iterator.
   If there are duplicates, then we have to create a heap that works
   with pairs
4. Root node is minimum element. Remove root node and apply
   heapify procedure. O(h) = O(log N) b/c that is height of tree
*/


#include <iostream>
#include <list>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, list<int>::iterator> pi;


// Print out list in sorted order
void iterateLists(list<list<int>> lists) {

	// Assume that this works during in-person interview
	// Pair: value, iterator
	priority_queue<pi, vector<pi>, greater<pi>> min_heap;
	pair<int, list<int>::iterator> m_pair;

	// Initialize min_heap with beginning elements of each list
	// O(N) --- number of linked lists
	for (auto it = lists.begin(); it != lists.end(); it++) {
		m_pair.first = (*it).front(); // Value
		m_pair.second = (*it).begin(); // Iterator
		min_heap.push(m_pair);
	}

	// O(N * K)
	// N = # of linked lists
	// K = largest linked list size
	while(!min_heap.empty()) {

		// Print out and remove element top of min-heap
		m_pair = min_heap.top();
		cout << m_pair.first << ' ' << endl;

		// increment to next iterator in list
		auto ite = m_pair.second();
		++ite;
		min_heap.pop();

		// Check if iterator is valid, then update min_heap
		m_pair.first = *ite;
		m_pair.second = ite;

		min_heap.push(m_pair);
	}
}

int main() {
	list<int> one;
	list<int> two;
	list<int> three;

	one.push_back(1);
	one.push_back(4);
	one.push_back(7);
	one.push_back(10);

	two.push_back(2);
	two.push_back(5);
	two.push_back(8);
	two.push_back(11);

	three.push_back(3);
	three.push_back(6);
	three.push_back(9);
	three.push_back(12);

	list<list<int>> lists;
	lists.push_back(one);
	lists.push_back(two);
	lists.push_back(three);

	iterateLists(lists);
}