#include "globals.h"


stack<int> sortStack(stack<int> input) {
	stack<int> res;

	while(!input.empty()) {

		int temp = input.top();
		input.pop();

		while(!res.empty() && res.top() > temp) {
			input.push(res.top());
			res.pop();
		}
		res.push(temp);
	}


	return res;
}


int main() {
	stack<int> input;
	input.push(34);
	input.push(3);
	input.push(31);
	input.push(98);
	input.push(92);
	input.push(23);

	stack<int> res = sortStack(input);
	cout << "Sorted numbers: " << endl;
	while(!res.empty()) {
		cout << res.top() << endl;
		res.pop();
	}
}