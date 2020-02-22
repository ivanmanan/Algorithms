#include "globals.h"

/*
  Three problems:
  1. Simple string expression
  2. Basic Calculator I from Leetcode
  3. Basic Calculator II from Leetcode
 */


// Problem 1
/*
  Given a string like "10+4-3"
  Calculate the output - 11
 */

void add(int& sum, int value, bool addFlag) {
	if(addFlag) {
		sum = sum + value;
	}
	else {
		sum = sum - value;
	}
}

int calculator(string s) {
	int sum = 0;
	int factor = 10;
	int num = 0;

	bool addFlag = true;

	for(int i = 0; i < s.length(); i++) {

		if(isdigit(s[i])) {
			num = num * factor + (s[i] - '0');
		}
		else {
			add(sum, num, addFlag);

			if(s[i] == '+') {
				addFlag = true;
			}
			else {
				addFlag = false;
			}
			num = 0;
		}
	}

	// Do final calculation
	add(sum, num, addFlag);

	return sum;
}

int main() {
	// cout << calculator("10+4-3") << endl;
	// cout << calculator("205+310-105") << endl;
	cout << calculator("43943+439149-594+9104+4043-4399-31000+440");
}