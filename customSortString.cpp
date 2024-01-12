/*
    s = "aabcd"
    order = "cba"
    output: "cbad"

    Freq map = {
        a: aa
        b: b
        c: c
        d: d
    }
    s="aabcd"

    Iterate order "cba":
    cbaa --> then erase from map

    Append leftover elements in the map
*/
string customSortString(string order, string s) {
    // letter, frequency
    unordered_map<char,string> freq;
    for(auto& ch: s) {
        freq[ch] += ch;
    }
    string res = "";
    for(auto& ch: order) {
        auto got = freq.find(ch);
        if(got != freq.end()) {
            res += got->second;
            freq.erase(ch);
        }
    }
    // Add leftover characters
    for(auto it = freq.begin(); it != freq.end(); it++) {
        res += it->second;
    }
    return res;
}
