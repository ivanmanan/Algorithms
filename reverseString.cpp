#include "globals.h"

string reverseStringInPlace(string s) {
	for(int i = 0, j = s.length()-1; i < s.length()/2; i++, j--) {
		char temp = s[j];
		s[j] = s[i];
		s[i] = temp;
	}
	return s;
}

string reverseStringWithExtraSpace(string s) {
	string reversed = "";

	for (int i=s.length() - 1; i >= 0; i--) {
		reversed += s[i];
	}

	return reversed;
}

int main() {
	string s = "Hello";

	string r = reverseStringInPlace(s);

	cout << "Input string: " << s << endl;
	cout << "Reversed string: " << r << endl;
}