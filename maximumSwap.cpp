#include "globals.h"

/*
  Given a non-negative integer, you could swap two digits at most
  once to get the maximum valued number. Return the maximum valued
  number you could get.

  Input: 2736
  Output: 7236
  Explanation: Swap the number 2 and the number 7.
*/

int maximumSwap(int num)
{
	if(num < 10) return num;
	// int to string (of digits)
	string digits = to_string(num);

	// find first ascending
	int fa = 1;
	while(fa < digits.size() && digits[fa] <= digits[fa-1]) ++fa;

	if(fa == digits.size()) return num; // all descending - this is the largest possible

	// from fa find the biggest
	int indx1 = fa;
	for(int i = fa; i < digits.size(); ++i)
		if(digits[i] >= digits[indx1]) indx1 = i; // >= not > - we want to swap from least significant position possible

	// see where to place it - the more significant, the better (they are sorted in descending order)
	int indx2 = fa-1;
	while(indx2-1 >= 0 && digits[indx2-1] < digits[indx1]) --indx2;
	swap(digits[indx1], digits[indx2]);

	// back to int
	return stoi(digits);
}
