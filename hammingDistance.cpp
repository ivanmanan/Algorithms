class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        int n = x ^ y; // x XOR y

        while (n) {
            ++dist;
            n &= n - 1; // bitwise AND
        }
        return dist;
    }
};

/*
  Considering this example. Let’s say n = 10101, and dist = 0.

  Before we go into the while loop. n = 10101, dist = 0
  Loop 1. dist = 1, n = 10101 & 10100 = 10100
  Loop 2. dist = 2, n = 10100 & 10011 = 10000
  Loop 3. dist = 3, n = 10000 & (0)1111 = 0 --> this relies on signed integer; since n=0, then while loop breaks
  Loop ends. dist = 3
  The change of n :

  10101
  10100
  10000
  00000
  Conclusion: n & (n-1) converts the right most 1 to 0 .
  This is the key idea solving the problem. By counting how many times we can perform this operation, we know how many 1 exists in the binary representation of n
*/

/* Bitwise Operators */
// &, |, ^, ~, <<, >>