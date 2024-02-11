#include "globals.h"

// Check if unordered maps have identical frequencies
bool compareMaps(unordered_map<char,int>& original, unordered_map<char,int> window) {

	for(auto it = original.begin(); it != original.end(); it++) {
		if(it->second != window[it->first]) {
			return false;
		}
	}
	return true;
}

vector<int> findAnagrams(string s, string p) {

	vector<int> indices;

	// Base case
	if(s.length() < p.length()) {
		return indices;
	}

	unordered_map<char,int> freqMap;
	unordered_map<char,int> window;

	// Start with first window of s
	for(int i = 0; i < p.length(); i++) {
		freqMap[p[i]]++;
		window[s[i]]++;
	}

	if(compareMaps(freqMap, window)) {
		indices.push_back(0);
	}

	// s="abab" --> length=4
	// p="ab"   --> length=2
	// s.length() - p.length() = 4-2 = 2 --> max index to look at

	// Start at index 1 and determine any further anagrams
	// Sliding window
	// Every p.size() elements in string s, check if it has same
	// frequency count as permutation_count
	// Time: O(S * P)
	// P is size of permutation string
	// S is size of string to check for permutation indices
	for(int i = 1; i <= s.length() - p.length(); i++) {

		// Update window
		window[s[i+p.length()-1]]++;
		window[s[i-1]]--;

		if(compareMaps(freqMap, window)) {
			indices.push_back(i);
		}
	}
	return indices;
}

int main() {
	string s = "abab";
	string p = "ab";

	vector<int> ans = findAnagrams(s,p);

	cout << "Expected Output: [0, 1, 2]" << endl;
	cout << "Output: [";
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if(i != ans.size()-1) {
			cout << ",";
		}
	}
	cout << "]" << endl;
}