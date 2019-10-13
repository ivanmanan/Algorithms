#include <iostream>
#include <stack>

using namespace std;

string reverseWords(string s) {


	stack<string> st;

	int index = 0;
	for(uint i = 0; i < s.length(); i++) {
		// Check for delimiter
		if(s[i] == ' ') {
			st.push(s.substr(index, i - index));
			index = i+1;
		}
	}
	st.push(s.substr(index,s.length() - index));



	string reverse = "";

	while(!st.empty()) {
		reverse += st.top();
		st.pop();

		if(!st.empty()) {
			reverse += ' ';
		}
	}
	return reverse;
}

int main() {
	string s = "the sky is blue";
	string ans = reverseWords(s);
	cout << ans << endl;
}