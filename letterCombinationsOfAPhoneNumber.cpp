vector<string> letterCombinations(string digits) {
    int n = digits.length();
    vector<string> res;
    vector<char> cs[8]  = {
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    };
    for(int i=0; i<n; i++) {
        vector<char> x = cs[digits[i]-'0' - 2];
        if(i == 0) {
            for(auto c:x) {
                string s = "";
                res.push_back(s + c);
            }
        }
        else {
            vector<string> v(res);
            res.clear();
            for(auto ss: v) {
                for(auto c:x) {
                    res.push_back(ss+c);
				}
            }
        }
    }
    return res;
}