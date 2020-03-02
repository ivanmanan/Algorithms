#include "globals.h"

bool isPalindrome(string s, int i, int j) {
	for(int k = i; k <= i + (j-i)/2; k++) {
		if(s[k] != s[j - k + i]) {
			return false;
		}
	}
	return true;
}



bool validPalindrome(string s) {


	for(int i = 0; i < s.size() / 2; i++) {

		// If the corresponding characters are not equivalent, then
		// consider the string if either characters are removed
		if(s[i] != s[s.length() - 1 - i]) {
			int j = s.length() - 1 - i;
			return (isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1));
		}
	}
	return true;
}
