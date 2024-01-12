/*
    2^100 = (2 * 2)^50
    4^50 = (4*4)^25
    16^25 = 16 * (16)^24
    16^25 = 16 * (16*16)^12
    16*256^12 = 16 * (256 * 256)^6

    Time: O(log N)

    2^-2 = 1/2 * 1/2 = 1/4
*/
double myPow(double x, int n) {
    if(n == 0) {
        return 1;
    }

    if(n < 0) {
        return 1.0 / myPow(x, -1 * n);
    }

    if(n % 2 == 1) {
        // If n is odd, exp for n-1 and multiply by x
        return x * myPow(x*x, (n-1)/2);
    }
    else {
        // If n is even, evenly divided
        return myPow(x*x, n/2);
    }
}
