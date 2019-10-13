/*
  Find all anagrams in a string

  NOTE ERRORS EXIST IN THIS FILE
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// unordered_map[KEY]


bool compare(string p, unordered_map<char,int> x, unordered_map<char,int> y) {
	for (uint i = 0; i < p.size(); i++) {
		// cout << "Comparing: " << p[i] << "; x:" << x[p[i]];
		// cout << "; y: " << y[p[i]] << endl;
		if (x[p[i]] != y[p[i]]) {
			return false;
		}
	}
	return true;
}

vector<int> findAnagrams(string s, string p) {
	vector<int> solution;

	// Compare these two hash tables
	// If they are the same, then we gucci
	unordered_map<char, int> permutation_count;
	unordered_map<char, int> window_count;


	// Create permutation count and first window of s
	for (uint i = 0; i < p.size(); i++) {

		auto got = permutation_count.find(p[i]);
		auto next_got = window_count.find(s[i]);
		// If it exists in hash table, then increment
		if (got != permutation_count.end()) {
			permutation_count[p[i]] = ++(got->second);
			window_count[p[i]] = ++(next_got->second);
		}
		else {
			permutation_count.insert({p[i], 1});
			window_count.insert({s[i], 1});
		}
	}

	// Sliding window
	// Every p.size() elements in string s, check if it has same
	// frequency count as permutation_count
	// Time: O(S * P)
	// P is size of permutation string
	// S is size of string to check for permutation indices
	for (uint i = 0; i < s.size() - p.size() + 1; i++) {

		// Compare first window
		if (compare(p, permutation_count, window_count)) {
			solution.push_back(i);
		}

		// Move to next window
		cout << "Before: " << window_count[s[i]] << "; ";
		--window_count[s[i]];
		cout << "After: " << window_count[s[i]] << endl;

		auto got = window_count.find(s[i]);
		if (got != window_count.end()) {
			++window_count[s[i]];
		}
		else {
			// It's another letter outside of permutation
			// So do nothing
			continue;
		}

	}

	// Must compare last window


	return solution;
}

int main() {
	string s = "BACDGABCDA";
	string p = "ABCD";
	vector<int> ans = findAnagrams(s, p);

	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
}