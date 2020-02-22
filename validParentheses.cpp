#include "globals.h"

bool isValid(string s) {
	stack<char> st;

	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
			st.push(s[i]);
		}
		else {
			if(st.empty()) {
				return false;
			}
			char complement = st.top();
			st.pop();
			switch(s[i]) {
			case ')':
				if(complement != '(') {
					return false;
				}
				break;
			case ']':
				if(complement != '[') {
					return false;
				}
				break;
			case '}':
				if(complement != '{') {
					return false;
				}
				break;
			default:
				return false;
			}
		}
	}
	return st.empty();
}