#include <math.h>
#include <iostream>
using namespace std;

int minimumMoves(int a_count, int* a, int m_count, int* m) {

    // SOLUTION: Iterate through every element in each array
    //           Take the difference between respective elements
    //           Sum individual digits together

    int moves = 0;
    for(int i = 0; i < a_count; i++) {

        int difference = abs(a[i] - m[i]);
		cout << difference << endl;

        int factor = 10;
        while(difference > 0) {
            int digit = difference % 10;
            moves += digit;
            difference = difference / factor;
            factor = factor * 10;
        }

    }
    return moves;
}

int main() {
	int a_count = 2;

	int a[2] = {1234, 4321};
	int m[2] = {2345, 3214};
	int m_count = 2;

	int x = minimumMoves(a_count, a, m_count, m);
	cout << x << endl;
}