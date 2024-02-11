#include "globals.h"

bool isAnagram(string s, string t) {

	unordered_map<char,int> freqS;
	unordered_map<char,int> freqT;

	if(s.length() != t.length()) {
		return false;
	}

	// Insert into frequency map
	for(int i = 0; i < s.length(); i++) {
		freqS[s[i]]++;
		freqT[t[i]]++;
	}

	// Compare both frequency maps
	for(auto it = freqS.begin(); it != freqS.end(); it++) {
		if(it->second != freqT[it->first]) {
			return false;
		}
	}
	return true;
}