#include "globals.h"

// Compare hash tables
bool sameFrequency(unordered_map<char,int>& m1, unordered_map<char,int>& m2) {

	// Compare values of hash table
	for(auto it = m1.begin(); it != m1.end(); it++) {
		if(it->second != m2[it->first]) {
			return false;
		}
	}

	return true;
}

bool checkInclusion(string s1, string s2) {

	if(s1.length() > s2.length()) {
		return false;
	}

	// Sliding window technique
	unordered_map<char,int> freqCount;
	unordered_map<char,int> currCount;

	// Initialize hash table for s1
	// Also do the first string for s2
	for(int i = 0; i < s1.length(); i++) {
		freqCount[s1[i]]++;
		currCount[s2[i]]++;
	}

	if(sameFrequency(freqCount, currCount)) {
		return true;
	}

	for(int i = 1; i < s2.length() - s1.length() + 1; i++) {

		currCount[s2[i-1]]--;
		int index = i + s1.length() - 1;
		currCount[s2[index]]++;

		if(sameFrequency(freqCount, currCount)) {
			return true;
		}

		cout << s2[i-1] << "," << s2[index] << endl;
	}
	return false;
}

int main() {
	string s1 = "horse";
	string s2 = "ros";

	string res = checkInclusion(s1, s2) ? "true" : "false";
	string ans = "true";

	cout << "Output:   " << res << endl;
	cout << "Expected: " << ans << endl;
}