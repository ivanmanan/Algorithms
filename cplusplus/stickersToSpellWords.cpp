/*
stickers = ["with","example","science"]
    "thehat"
    /       \
with [th]    example

--> ehat
    /
    example

--> ht


TIME: O(N * 2^N)
SPACE: O(N)
*/

// t = subsequence of target string
// sticker = current sticker being used right now
int dfs(string t, unordered_map<char,int> sticker, unordered_map<string,int>& memo, vector<unordered_map<char,int>>& stickCount) {
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

/*
    Terrible memoization below
*/


void dfs(int number_stickers, unordered_set<string>& memo, unordered_map<char,int>& have, int& res) {
    if(have.empty()) {
        res = min(res, number_stickers);
        return;
    }
    for(auto& s: memo) {
        unordered_map<char,int> original = have;
        bool use_sticker = false;
        for(auto& ch: s) {
            if(have.find(ch) != have.end()) {
                use_sticker = true;
                have[ch]--;
                if(have[ch] == 0) {
                    have.erase(ch);
                }
            }
        }
        if(use_sticker) {
            dfs(number_stickers+1, memo, have, res);
        }
        have = original;
    }
}

int minStickers(vector<string>& stickers, string target) {
    int res = INT_MAX;

    // Convert target string to its character-frequency map
    unordered_map<char,int> have;
    for(auto& ch: target) {
        have[ch]++;
    }

    // preprocess each sticker with characters found in the word
    unordered_set<string> memo;
    for(auto& s: stickers) {
        string characters_found = "";
        for(auto& ch: s) {
            if(have.find(ch) != have.end()) {
                characters_found += ch;
            }
        }
        if(characters_found != "") {
            memo.insert(characters_found);
        }
    }

    dfs(0, memo, have, res);

    if(res == INT_MAX) {
        return -1;
    }
    return res;
}
