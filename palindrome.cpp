#include <iostream>

using namespace std;

string isPalindrome(string s) {

	int j = s.length() - 1;
	for (unsigned int i = 0; i < s.length(); i++) {
		if (s[i] != s[j]) {
			return "false";
		}
		j--;
	}
	return "true";
}

int main() {
	string s = "ooloo";
	string t = "boolean";
	string u = "dood";

	string ans1 = isPalindrome(s);
	string ans2 = isPalindrome(t);
	string ans3 = isPalindrome(u);

	cout << ans1 << endl; // true
	cout << ans2 << endl; // false
	cout << ans3 << endl; // true
}