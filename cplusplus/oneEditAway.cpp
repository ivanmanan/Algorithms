#include "globals.h"

// Given two string s1 and s2, find if s1 can be converted to s2
// with exactly one edit.

bool oneEditAway(string s1, string s2) {

	// Base case
	if(s1.length() != s2.length()) {
		if(abs(s1.length()+1 != s2.length()) > 1) {
			return false;
		}
	}

	int countEdits = 0;
	int i = 0;
	int j = 0;

	while(i < s1.length() && j < s2.length()) {

		// If current characters do not match
		if(s1[i] != s2[j]) {
			if(countEdits > 0) {
				return false;
			}

			// Try again based on insertion/deletion of a character
			if(s1.length() > s2.length()) {
				i++;
			}
			else {
				j++;
			}
			countEdits++;
		}
		else {
			i++;
			j++;
		}
	}
	return true;
}

int main() {
	string s1 = "ivan";
	string s2 = "van";
	string ans = "true";
	cout << "Output:   " << (oneEditAway(s1,s2) ? "true" : "false") << endl;
	cout << "Expected: " << ans << endl;
}