#include <iostream>

using namespace std;

string reverseString(string s) {
	string reversed = "";

	for (int i=s.length() - 1; i >= 0; i--) {
		reversed += s[i];
	}

	return reversed;
}

int main() {
	string s = "Hello";

	string r = reverseString(s);

	cout << "Input string: " << s << endl;
	cout << "Reversed string: " << r << endl;
}