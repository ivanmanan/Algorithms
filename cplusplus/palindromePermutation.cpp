#include "globals.h"

/*
 Given a string, determine if a permutation of the string could form
 a palindrome.

 SOLUTION
 Use a set
 Every iteration - insert character into a set. If element exists in
 the set, then remove it - this indicates even number of characters
 if they do not exist in the set.
*/

bool canPermutePalindrome(string s) {
	unordered_set<char> charMap;

	for(int i = 0; i < s.length(); i++) {

		auto got = charMap.find(s[i]);

		if(got != charMap.end()) {
			charMap.erase(s[i]);
		}
		else {
			charMap.insert(s[i]);
		}
	}
	return charMap.size() < 2;
}