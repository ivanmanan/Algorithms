#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;


int ans(int N) {
	int maxValue = INT_MIN;
	string digits = to_string(N);

	// conditional is used to test for negative numbers
    for(int i = (N >= 0)? 0 : 1; i <= digits.length(); i++) {
		string nums = to_string(N);
        string temp = nums.insert(i, "5");
		int newValue = stoi(temp);
		if(maxValue < newValue) {
			maxValue = newValue;
		}
    }
	return maxValue;
}

int main() {
	cout << ans(-999) << endl;
}