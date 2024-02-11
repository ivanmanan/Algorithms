#include "globals.h"

/*
  Given a non-negative integer, you could swap two digits at most
  once to get the maximum valued number. Return the maximum valued
  number you could get.

  Input: 2736
  Output: 7236
  Explanation: Swap the number 2 and the number 7.
*/

int maximumSwap(int num) {
	int maxindex = -1;
	int maxdigit = -1;
	int leftindex = -1;
	int rightindex = -1;

	string numstr = to_string(num);
	for(int i = numstr.length()-1; i >= 0; i--) {
		int value = numstr[i] - '0';
		if(value > maxdigit) {
			// i=1: max=7
			maxindex = i;
			maxdigit = value;
			continue;
		}
		if(value < maxdigit) {
			// i=2: left=2,right=3

			leftindex = i;
			rightindex = maxindex;
		}
	}
	if(leftindex == -1) {
		return num;
	}
	swap(numstr[leftindex], numstr[rightindex]);
	return stoi(numstr);
}
