#include "globals.h"



ListNode* mergeKLists(vector<ListNode*>& lists) {

	// min heap
	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i = 0; i < lists.size(); i++) {
		ListNode* temp = lists[i];
		while(temp != NULL) {
			pq.push(temp->val);
			temp = temp->next;
		}
	}

	ListNode* head = NULL;
	ListNode* curr = NULL;
	while(!pq.empty()) {
		int val = pq.top();
		pq.pop();
		if(head == NULL) {
			head = new ListNode(val);
			curr = head;
		}
		else {
			curr->next = new ListNode(val);
			curr = curr->next;
		}
	}
	return head;

}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// Merge multiple linked lists but using the lists stl

typedef pair<int, list<int>::iterator> pi;


// Print out list in sorted order
void iterateLists(list<list<int>> lists) {

	// Assume that this works during in-person interview
	// Pair: value, iterator
	priority_queue<pi, vector<pi>, greater<pi>> min_pq;
	pair<int, list<int>::iterator> m_pair;

	// Initialize min_pq with beginning elements of each list
	// O(N) --- number of linked lists
	for (auto it = lists.begin(); it != lists.end(); it++) {
		m_pair.first = (*it).front(); // Value
		m_pair.second = (*it).begin(); // Iterator
		min_pq.push(m_pair);
	}

	// O(N * K)
	// N = # of linked lists
	// K = largest linked list size
	while(!min_pq.empty()) {

		// Print out and remove element top of min-heap
		m_pair = min_pq.top();
		cout << m_pair.first << ' ' << endl;

		// increment to next iterator in list
		auto ite = m_pair.second();
		++ite;
		min_pq.pop();

		// Check if iterator is valid, then update min_pq
		m_pair.first = *ite;
		m_pair.second = ite;

		min_pq.push(m_pair);
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