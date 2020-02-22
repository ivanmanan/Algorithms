#include <iostream>

using namespace std;

/*
  Given x/y, where x is divisible by y, reduce the fraction to its
  lowest form.

  Ex.
  Input:  x=16, y=10
  Output: x=8 , y=5
 */

/*
  Walkthrough of gcd function
  1. a=16  b=10
  2. a=10  b=6
  3. a=6   b=4
  4. a=4   b=2
  5. a=2   b=2
 */
int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void fractionReducer(int& x, int& y) {

	// Must find greatest common divisor
	int divisor = gcd(x,y);
	x = x / divisor;
	y = y / divisor;
}

int main() {
	int x = 16, y = 10;
	int ansX = 8, ansY = 5;
	fractionReducer(x, y);
	cout << "x = " << x << "; Expected: " << ansX << endl;
	cout << "y = " << y << "; Expected: " << ansY << endl;
}