#include "globals.h"

/*
  Count Primes in Ranges
  Given a range [L, R], we need to find the count of total numbers of
  prime numbers in the range [L, R] where 0 <= L <= R < 10000
 */

// Naive Solution
bool isPrimeNaive(int n) {
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

// Sieve of Eratosthenes Method
const int MAX = 10000;

// prefix[i] is going to store count of primes
// till i (including i).
int prefix[MAX + 1];

void buildPrefix()
{
    // Create a boolean array "prime[0..n]". A
    // value in prime[i] will finally be false
    // if i is Not a prime, else true.
    bool prime[MAX + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= MAX; p++) {

        // If prime[p] is not changed, then
        // it is a prime
        if (prime[p] == true) {

            // Update all multiples of p
            for (int i = p * 2; i <= MAX; i += p)
                prime[i] = false;
        }
    }

    // Build prefix array
    prefix[0] = prefix[1] = 0;
    for (int p = 2; p <= MAX; p++) {
        prefix[p] = prefix[p - 1];
        if (prime[p])
            prefix[p]++;
    }
}

// Returns count of primes in range from L to
// R (both inclusive).
int query(int L, int R) {
    return prefix[R] - prefix[L - 1];
}
