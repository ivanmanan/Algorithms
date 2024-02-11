int lengthOfLongestSubstring(string s) {

    unordered_set<char> letters;

    int i = 0; // Index to the start of the subsequence
    int j = 0;
    int res = 0;

    while(j < s.size()) {
        if(letters.find(s[j]) == letters.end()) {
            // Does not exist in set
            letters.insert(s[j]);
            res = max(res, j-i+1);
            j++;
        }
        else {
            // Exists in set
            letters.erase[s[i]];
            i++;
        }
    }

    return res;
}
