#include "globals.h"

// Recursive
int factorialRecursive(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorialRecursive(n - 1);
}

// Iterative
int factorialIterative(unsigned int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

// Ternary operator
int factorialTernary(int n)
{
    return (n == 1 || n == 0) ? 1 : n * factorialTernary(n - 1);
}
