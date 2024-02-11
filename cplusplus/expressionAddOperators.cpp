/*
    No zeros
    Operators limited to only + and -
    THREE DIFFERENT PATHS:
    1) +
    2) -
    3) Extend current number

    TIME: O(N*3^N)
    --> 3^N: each digit, we consider 3 different choices
    --> substr takes O(N) operation
    SPACE: O(N)
    --> data structure is O(N) and the recursion stack is O(N)

    num="1232", target=-20
    output=["1-23+2", "12-32"]
        1232
     /  /   \   \     \
   1+    1-   12   123  1232
 /  \
1+2 1+23
*/
void dfs(const string& s, const int target, int pos, int curr_val,
            string expression, vector<string>& res) {
    if(pos == s.length() && curr_val == target) {
        res.push_back(expression);
        return;
    }
    // For each combination of digits, insert (+) or (-)
    for(int i = 1; i <= s.length() - pos; i++) {
        string t = s.substr(pos, i);
        int n = stoi(t); // string to int
        if(pos == 0) { // No previous "+" or "-" expression
            dfs(s, target, i, n, t, res);
            continue;
        }
        dfs(s, target, pos+i, curr_val+n, expression+"+"+t, res);
        dfs(s, target, pos+i, curr_val-n, expression+"-"+t, res);
    }
}
vector<string> addOperators(string num, int target) {
    vector<string> res;
    dfs(num, target, 0, 0, "", res);
    return res;
}
