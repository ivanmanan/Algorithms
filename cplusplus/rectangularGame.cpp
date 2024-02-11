#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// The input upRight is a series of coordinates
// e.g. ["1 4", "2 3", "4 1"]

/*
  We want to find the number of occurrences of the maximum value

  EXAMPLE

  0 0 0 0 0
  0 0 0 0 0
  0 0 0 0 0
  0 0 0 0 0
  0 0 0 0 0

  0 0 0 0 0
  0 0 0 0 0
  0 0 0 0 0
  0 0 0 0 0
  1 1 1 1 1

  0 0 0 0 0
  0 0 0 0 0
  0 0 0 0 0
  1 1 1 0 0
  2 2 2 1 1

  0 0 0 0 0
  1 0 0 0 0
  1 0 0 0 0
  2 1 1 0 0
  3 2 2 1 1

  Output: 1
  Explanation: 3 is the highest integer value, and it appears once.

  WALKTHROUGH

  Given coordinate pairs (1,4), (2,3), (4,1)

  minR = 1
  minC = 1

  minR * minC = 1

  Notice if we change the last coordinate pair from (4,1) to (4,2), the final grid becomes:
  0 0 0 0 0
  1 0 0 0 0
  1 0 0 0 0
  2 1 1 0 0
  3 3 2 1 1

  So,
  minR * minC = 1 * 2 = 2 occurrences of max value 3

  I am calculating the area of where the largest values occur beause
  the area always starts from the origin and only expands outwards.

 */

long optimalCountMax(vector<string> upRight) {
	long minR = INT_MAX;
    long minC = INT_MAX;

	for(int i = 0; i < upRight.size(); i++) {

		// Parse the string to find the coordinates (r,c)
		string s = upRight[i];
        string delimiter = " ";
        long r = stol(s.substr(0, s.find(delimiter)));
        long c = stol(s.substr(s.find(delimiter)+1));

        if(minR > r) {
            minR = r;
        }
        if(minC > c) {
            minC = c;
        }
	}
    return minR * minC;
}

