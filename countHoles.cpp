#include "globals.h"

/*
  Given an integer num, count the number of holes in that number
 */

int countHoles(int num) {
	//               0  1  2  3  4  5  6  7  8  9
	int holes[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

	int count = 0;

	while(num > 0) {

		// Obtain last digit in number
		int digit = num % 10;

		// Remove last digit
		num = num / 10;

		count += holes[digit];
	}
	return count;
}

int main() {
	int num = 8000;
	int ans = 5;
	cout << countHoles(num) << endl;
	cout << "Expected: " << ans << endl;
}