#include "globals.h"

/*
  Given a string containing just the characters '(' and ')', find the
  length of the longest valid (well-formed) parentheses substring.

  A solution does exist using O(1) space and O(N) time
*/

int longestValidParentheses(string s) {
	if (s.length() == 0){
		return 0;
	}
	vector<int> stack;
	for(int i = 0; i < s.length(); i++){
		if(stack.empty()){
			stack.push_back(i);
			continue;
		}
		if(s[i] == ')' and s[stack.back()] == '(') {
			stack.pop_back();
		}
		else{
			stack.push_back(i);
		}
	}
	int maxlen = 0, j = s.length();
	if(stack.size() == 0){
		return s.length();
	}
	while(!stack.empty()){
		maxlen = max(j - stack.back() - 1, maxlen);
		j = stack.back();
		stack.pop_back();
	}
	maxlen = max(maxlen, j - 0);
	return maxlen;
}
