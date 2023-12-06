///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Stickers to Spell Words dynamic programming

/*
memoization or memoisation is an optimization technique used primarily to speed up
 computer programs by storing the results of expensive function calls to pure functions
 and returning the cached result when the same inputs occur again

stickers = ["with","example","science"]
"thehat"
/       \
with     example

TIME: O(N * 2^N)
SPACE: O(N * 2^N)
--> stack recursion call goes as far down as length of string N
--> memo size is number of key entries. Hence, 2^N number of entries of size N
*/

// t = subsequence of target string
// sticker = current sticker being used right now
int dfs(string t, unordered_map<char,int> sticker, unordered_map<string,int>& memo,
        vector<unordered_map<char,int>>& stickCount) {
    if(memo.find(t) != memo.end()) {
        // Exists in cache
        return memo[t];
    }

    int res = 0;
    if(!sticker.empty()) { // A sticker has been used
        res = 1;
    }
    string remainder = "";
    for(auto& ch: t) {
        if(sticker.find(ch) != sticker.end() && sticker[ch] > 0) {
            sticker[ch]--;
        }
        else {
            remainder += ch;
        }
    }
    int used = INT_MAX;
    if(remainder != "") {
        for(auto& ma: stickCount) {
            if(ma.find(remainder[0]) == ma.end()) {
                // first character in remainder does not exist in sticker
                // skip, we are not interested yet
                continue;
            }
            used = min(used, dfs(remainder, ma, memo, stickCount));
        }
        // We found the minimum number of stickers it takes to reach this point
        memo[remainder] = used;
        if(used == INT_MAX) {
            res = INT_MAX;
        }
        else {
            res += used;
        }
    }
    return res;
}

int minStickers(vector<string>& stickers, string target) {
    // Transform stickers array to char-frequency map
    vector<unordered_map<char,int>> stickCount;
    for(auto& s: stickers) {
        unordered_map<char,int> ma;
        for(auto& ch: s) {
            ma[ch]++;
        }
        stickCount.push_back(ma);
    }

    // subsequence of target string : minimum number of stickers to create
    unordered_map<string,int> memo;

    int res = dfs(target, {}, memo, stickCount);
    if(res == INT_MAX) {
        return -1;
    }
    return res;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Valid Palindrome III

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
