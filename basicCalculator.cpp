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



int basicCalculatorII(string s) {
	stack<int> st;
	int curr = 0;
	char op = '+';
	s += '+'; // Finale is necessary

	for(int i = 0; i < s.length(); i++) {
		if(isdigit(s[i])) {
			curr = curr * 10 + int(s[i] - '0');
		}
		else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') {
			if(op == '+') {
				st.push(curr);
			}
			else if(op == '-') {
				st.push(-curr);
			}
			else if(op == '*') {
				int num = st.top() * curr;
				st.pop();
				st.push(num);
			}
			else if(op == '/') {
				int num = st.top() / curr;
				st.pop();
				st.push(num);
			}
			op = s[i];
			curr = 0;
		}

	}

	int res = 0;
	while(!st.empty()) {
		res += st.top();
		st.pop();
	}
	return res;
}

int main() {
	// cout << calculator("10+4-3") << endl;
	// cout << calculator("205+310-105") << endl;

// 	int ans = basicCalculatorII("3+2*2");
// 	cout << "INPUT: 3+2*2; OUTPUT: " << ans << "; EXPECTED: 7";

	int ans = basicCalculatorII("1337");
	cout << "INPUT: 1337; OUTPUT: " << ans << "; EXPECTED: 1337";
}
