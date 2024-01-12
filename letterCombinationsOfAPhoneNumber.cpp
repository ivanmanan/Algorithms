vector<string> letterCombinations(string digits) {
    unordered_map<int, vector<char>> ma = {
        {2, {'a', 'b', 'c'}},
        {3, {'d', 'e', 'f'}},
        {4, {'g', 'h', 'i'}},
        {5, {'j', 'k', 'l'}},
        {6, {'m', 'n', 'o'}},
        {7, {'p', 'q', 'r', 's'}},
        {8, {'t', 'u', 'v'}},
        {9, {'w', 'x', 'y', 'z'}},
    };

    vector<string> res;

    for(int i = 0; i < digits.length(); i++) {
        int digit = digits[i] - '0';
        auto got = ma.find(digit);
        vector<char> letters = got->second;
        if(res.empty()) {
            // Initialize
            for(auto& letter: letters) {
                string curr = "";
                res.push_back(curr + letter);
            }
        }
        else {
            vector<string> temp;
            for(auto& s: res) {
                // Start with [a, b, c]
                // End with [ad, ae, af, bd, ...]
                for(auto& letter: letters) {
                    string new_s = s + letter;
                    temp.push_back(new_s);
                }
            }
            res = temp;
        }
    }
    return res;
}
