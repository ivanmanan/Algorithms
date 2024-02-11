/*
    s="abcdeca", k=2, N=7

    i=rows,j=cols
    memo = {
        -1 -1 -1 -1 -1 -1 -1
        -1 -1 -1 -1 -1 -1 -1
        -1 -1 -1 -1 -1 -1 -1
        -1 -1 -1 -1 -1 -1 -1
        -1 -1 -1 -1 -1 -1 -1
        -1 -1 -1 -1 -1 -1 -1
        -1 -1 -1 -1 -1 -1 -1
    }
       0123456
    s="abcdeca"
    i=0: a
    j=6: a
    Since s[0] == s[6], proceed with i+1,j-1
    i=1: b
    j=5: c
    Since s[1] != s[5], proceed with i+1,j AND i,j-1
    memo[1][5] = 1 + memo[2][5]
    memo[2][5] = memo[3][4]
    memo[3][4] = 1 + memo[3][3]
    When i=3,j=3: memo[3][3] = 0

    N = length of string
    TIME: O(N^2) find result for all combinations of i and j
    SPACE: O(N^2) to build memo table. Recursion stack goes up to O(N) depth.
*/
int isValidPalindrome(string &s, int i, int j, vector<vector<int>>& memo) {
    if(i == j) { // 1 letter remain
        return 0;
    }

    if(i == j-1) { // 2 letters remain
        return s[i] != s[j]; // 0 is false, 1 is true
    }

    if(memo[i][j] != -1) {
        return memo[i][j];
    }

    if(s[i] == s[j]) {
        memo[i][j] = isValidPalindrome(s, i+1, j-1, memo);
    }
    else {
        memo[i][j] = 1 + min(isValidPalindrome(s, i+1, j, memo), isValidPalindrome(s, i, j-1, memo));
    }
    return memo[i][j];
}
bool isValidPalindrome(string s, int k) {
    vector<vector<int>> memo(s.length(), vector<int>(s.length(), -1));
    return isValidPalindrome(s, 0, s.length()-1, memo) <= k;
}
