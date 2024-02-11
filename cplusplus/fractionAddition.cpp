#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void fractionReducer(int& a, int& b) {
	int d = gcd(a,b);
	a = a / d;
	b = b / d;
}

/*
  WALKTHROUGH

  num1 = 1
  den1 = 500

  num2 = 2
  den2 = 1500

  gcd(500, 1500) --> 500

  denominator = (500 * 1500) / 500 = 1500

  numerator = 1 * (1500/500) + 2 * (1500/1500) = 5

  reduce(5/1500) = 1/300

 */


pair<int,int> fractionAddition(int num1, int den1, int num2, int den2) {

	int numRes = 1;
	int denRes = 1;

	// Find greatest common divisor of den1 and den2
	denRes = gcd(den1, den2);

	// Denominator of final fraction obtained by finding LCM
	// of den1 and den2
	// LCM * GCD = a * b
	denRes = (den1 * den2) / denRes;

	// Since fractions changed to have same denominator,
	// we must adjust numerators accordingly
	numRes = num1 * (denRes / den1) + num2 * (denRes / den2);

	fractionReducer(numRes, denRes);


	pair<int,int> p;
	p.first = numRes;
	p.second = denRes;
	return p;
}

int main() {

	int num1, den1, num2, den2;

	num1 = 1;
	den1 = 500;

	num2 = 2;
	den2 = 1500;

	int ans1 = 1;
	int ans2 = 300;

	pair<int,int> p = fractionAddition(num1, den1, num2, den2);
	cout << "Answer:   " << p.first << "/" << p.second << endl;
	cout << "Expected: " << ans1 << "/" << ans2 << endl;
}