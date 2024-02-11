#include <iostream>
#include <stack>

using namespace std;

string reverse(string s) {
	for(int i = 0, j = s.length()-1; i < s.length()/2; i++, j--) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	return s;
}

string reverseWords(string s) {

	string res = "";

	int lastSpace = -1;
	for(int i = 0; i < s.length(); i++) {

		// Check for delimiter
		if(isspace(s[i])) {
			string temp = reverse(s.substr(lastSpace+1, i-lastSpace-1)) + " ";
			res += temp;
			lastSpace = i;
		}
	}
	// Append last word if exists
	if(s[s.length()-1] != ' ') {
		string temp = reverse(s.substr(lastSpace, s.length()-1));
		res += temp;
	}

	// Reverse one last time
	res = reverse(res);
	return res;
}


string reverseWordsWithStack(string s) {


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



	string res = "";

	while(!st.empty()) {
		res += st.top();
		st.pop();

		if(!st.empty()) {
			res += ' ';
		}
	}
	return res;
}

int main() {
	string s = "the sky is blue";
	string res = "blue is sky the";
	string ans = reverseWords(s);
	cout << "Output:   " << ans << endl;
	cout << "Expected: " << res << endl;
}